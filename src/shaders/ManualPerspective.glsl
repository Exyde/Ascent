#version 330

layout(location = 0) in vec4 iPosition;
layout(location = 1) in vec4 iColor;

smooth out vec4 oColor;

uniform vec2 offset;
uniform float zNear;
uniform float zFar;
uniform float frustrumScale;
uniform float time;

uniform mat4 perspectiveMatrix;

void main(){

    vec4 cameraPos = iPosition + vec4(offset.x, offset.y, 0.0, 0.0);

    /* Old Way...
    vec4 clipPos;

    clipPos.xy = cameraPos.xy * frustrumScale;

    clipPos.z = cameraPos.z * (zNear + zFar) / (zNear - zFar);
    clipPos.z += 2 * zNear * zFar / (zNear - zFar);

    clipPos.w = -cameraPos.z;

    clipPos.x += sin(time);
    clipPos.y += cos(time * 0.5);

    */

    gl_Position = perspectiveMatrix * cameraPos;
    oColor = iColor;
}


