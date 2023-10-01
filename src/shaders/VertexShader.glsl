#version 330 core

layout(location = 0) in vec4 iPosition;
layout(location = 1) in vec4 iColor;

uniform float loopDuration;
uniform float time;
uniform vec2 offset;
smooth out vec4 oColor;

void main(){
    gl_Position = iPosition;
    gl_Position.w = 1;
    float t = mod(time, loopDuration);
    oColor = iColor * t;

    gl_Position.x += offset.x;
    gl_Position.y += offset.y;

    return;

    float scale = (3.14159f * 2.0f) / loopDuration;

    gl_Position.x += cos(t * scale) * 0.5f;
    gl_Position.y += sin(t * scale) * 0.5f;
}