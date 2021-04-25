#ifndef PAL_CONFIG_H
# define PAL_CONFIG_H

# define PAL_HAS_JOYSTICKS     1
# define PAL_HAS_MOUSE         0
# define PAL_HAS_MP3           0
# define PAL_HAS_OGG           0
# define PAL_HAS_OPUS          0
# define PAL_HAS_NATIVEMIDI    0
# define PAL_PREFIX            "ux0:data/sdlpal/"
# define PAL_SAVE_PREFIX       "ux0:data/sdlpal/"

# define PAL_DEFAULT_WINDOW_WIDTH   640
# define PAL_DEFAULT_WINDOW_HEIGHT  480

# define PAL_VIDEO_INIT_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)
# define PAL_SDL_INIT_FLAGS   (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK)
# define PAL_SCALE_SCREEN     TRUE

# define PAL_PLATFORM         "PS Vita"
# define PAL_CREDIT           "usineur"
# define PAL_PORTYEAR         "2017"

# define PAL_FILESYSTEM_IGNORE_CASE         1
# define PAL_HAS_PLATFORM_SPECIFIC_UTILS    1
# define PAL_HAS_PLATFORM_STARTUP           1

# include <strings.h>
# include <psp2/kernel/clib.h>

# define printf sceClibPrintf
# define fprintf(stderr, ...) sceClibPrintf(__VA_ARGS__)

# define VITA_SCREEN_W 960
# define VITA_SCREEN_H 544

# define BTN_TRIANGLE 0
# define BTN_CIRCLE 1
# define BTN_CROSS 2
# define BTN_SQUARE 3
# define BTN_LTRIGGER 4
# define BTN_RTRIGGER 5
# define BTN_DOWN 6
# define BTN_LEFT 7
# define BTN_UP 8
# define BTN_RIGHT 9
# define BTN_SELECT 10
# define BTN_START 11
# define STICK_UP 0
# define STICK_DOWN 1
# define STICK_LEFT 2
# define STICK_RIGHT 3

#endif
