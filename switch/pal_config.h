#ifndef PAL_CONFIG_H
# define PAL_CONFIG_H

# define PAL_HAS_GLSL          1
# define PAL_HAS_JOYSTICKS     1
# define PAL_HAS_MOUSE         0
# define PAL_HAS_MP3           0
# define PAL_HAS_OGG           0
# define PAL_HAS_OPUS          0
# define PAL_HAS_NATIVEMIDI    0
# define PAL_PREFIX            "."
# define PAL_SAVE_PREFIX       "."

# define PAL_DEFAULT_WINDOW_WIDTH   640
# define PAL_DEFAULT_WINDOW_HEIGHT  480

# define PAL_VIDEO_INIT_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)
# define PAL_SDL_INIT_FLAGS   (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK)
# define PAL_SCALE_SCREEN     TRUE

# define PAL_PLATFORM         "Nintendo Switch"
# define PAL_CREDIT           "usineur"
# define PAL_PORTYEAR         "2020"

# define PAL_FILESYSTEM_IGNORE_CASE         1
# define PAL_HAS_PLATFORM_SPECIFIC_UTILS    1
# define PAL_HAS_PLATFORM_STARTUP           1

# include <strings.h>
# include <switch.h>

# define SWITCH_SCREEN_W 1280
# define SWITCH_SCREEN_H 720

# define BTN_A       0
# define BTN_B       1
# define BTN_X       2
# define BTN_Y       3
# define BTN_L       6
# define BTN_R       7
# define BTN_ZL      8
# define BTN_ZR      9
# define BTN_PLUS   10
# define BTN_MINUS  11
# define BTN_LEFT   12
# define BTN_UP     13
# define BTN_RIGHT  14
# define BTN_DOWN   15
# define STICK_UP    0
# define STICK_DOWN  1
# define STICK_LEFT  2
# define STICK_RIGHT 3

#endif
