#include <stdio.h>
#include "djui.h"
#include "src/pc/network/network.h"
#include "src/pc/utils/misc.h"
#include "src/pc/configfile.h"

#ifdef DISCORD_SDK
static char* sWarningDiscord = "\
Invite friends by right clicking their name on Discord and clicking on\n\
'\\#d0d0ff\\Invite to Game\\#c8c8c8\\'.\n\n\
You can invite channels of servers as well by clicking the \\#d0d0ff\\plus\\#c8c8c8\\ button next to the place where you enter chat.\n\n\
Game Activity \\#ffa0a0\\must be\\#c8c8c8\\ enabled in your\nDiscord user settings.\n\n\
Appearing offline \\#ffa0a0\\will prevent\\#c8c8c8\\ invites from being sent.\
";
#endif

static char* sWarningSocket = "\
Direct connections \\#ffa0a0\\require you\\#c8c8c8\\ to configure port forwarding in your router.\n\n\
Forward port '\\#d0d0ff\\%d\\#c8c8c8\\' for UDP.\
";

void djui_panel_host_message_do_host(struct DjuiBase* caller) {
    djui_panel_shutdown();
#ifndef DISCORD_SDK
    configNetworkSystem = 1;
    network_set_system(NS_SOCKET);
#else
    if (configNetworkSystem == 0) {
        network_set_system(NS_DISCORD);
    } else {
        network_set_system(NS_SOCKET);
    }
#endif
    network_init(NT_SERVER);
    extern s16 gChangeLevel;
    gChangeLevel = 16;
}

void djui_panel_host_message_create(struct DjuiBase* caller) {
    f32 warningLines = 0;
    char* warningMessage = NULL;

#ifdef DISCORD_SDK
    if (!configNetworkSystem) {
        warningLines = 13;
        warningMessage = sWarningDiscord;
    } else
#endif
    {
        warningLines = 5;
        warningMessage = malloc(sizeof(char) * 256);
        sprintf(warningMessage, sWarningSocket, configHostPort);
    }

    f32 textHeight = 32 * 0.8125f * warningLines + 8;
    f32 bodyHeight = textHeight + 16 + 64;

    struct DjuiBase* defaultBase = NULL;
    struct DjuiThreePanel* panel = djui_panel_menu_create(bodyHeight, "\\#ff0800\\I\\#1be700\\N\\#00b3ff\\F\\#ffef00\\O");
    struct DjuiFlowLayout* body = (struct DjuiFlowLayout*)djui_three_panel_get_body(panel);
    {
        struct DjuiText* text1 = djui_text_create(&body->base, warningMessage);
        djui_base_set_size_type(&text1->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
        djui_base_set_size(&text1->base, 1.0f, textHeight);
        djui_base_set_color(&text1->base, 200, 200, 200, 255);

        struct DjuiRect* rect1 = djui_rect_create(&body->base);
        djui_base_set_size_type(&rect1->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
        djui_base_set_size(&rect1->base, 1.0f, 64);
        djui_base_set_color(&rect1->base, 0, 0, 0, 0);
        {
            struct DjuiButton* button1 = djui_button_create(&rect1->base, "Back");
            djui_base_set_size_type(&button1->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
            djui_base_set_size(&button1->base, 0.485f, 64);
            djui_base_set_alignment(&button1->base, DJUI_HALIGN_LEFT, DJUI_VALIGN_TOP);
            djui_button_set_style(button1, 1);
            djui_interactable_hook_click(&button1->base, djui_panel_menu_back);

            struct DjuiButton* button2 = djui_button_create(&rect1->base, "Host");
            djui_base_set_size_type(&button2->base, DJUI_SVT_RELATIVE, DJUI_SVT_ABSOLUTE);
            djui_base_set_size(&button2->base, 0.485f, 64);
            djui_base_set_alignment(&button2->base, DJUI_HALIGN_RIGHT, DJUI_VALIGN_TOP);
            djui_interactable_hook_click(&button2->base, djui_panel_host_message_do_host);
            defaultBase = &button2->base;
        }
    }

    djui_panel_add(caller, &panel->base, defaultBase);
#ifdef DISCORD_SDK
    if (configNetworkSystem)
#endif
    {
        free(warningMessage);
    }
}
