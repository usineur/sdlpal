//
// Adapted for vanilla c by rsn8887 on 11/13/2017
// Created by cpasjuste on 18/12/16.
//

#ifndef PSP2_SHADER_H
#define PSP2_SHADER_H

#include <vita2d.h>

enum PSP2Shader {
    NONE = 0,
    LCD3X,
    SCALE2X,
    AAA,
    SHARP_BILINEAR,
    SHARP_BILINEAR_SIMPLE,
    FXAA,
};
typedef enum PSP2Shader PSP2Shader;

void clearPSP2Shader(vita2d_shader *shader);
vita2d_shader *setPSP2Shader(PSP2Shader shaderType);

#endif //PSP2_SHADER_H
