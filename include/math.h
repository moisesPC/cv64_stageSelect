#ifndef MATH_H
#define MATH_H

#include "n64types.h"

typedef struct {
    f32 x;
    f32 y;
} vec2;

typedef struct {
    s16 x;
    s16 y;
} vec2_s16;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} vec3f;

typedef struct {
    s16 pitch;
    s16 yaw;
    s16 roll;
} angle;

#endif
