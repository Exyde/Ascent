#version 330 core

smooth in vec4 oColor;
out vec4 color;

uniform float time;
uniform float fragLoopDuration;

const vec4 firstColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
const vec4 secondColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);

void main()
{
    float currTime = mod(time, fragLoopDuration);
    float currLerp = currTime / fragLoopDuration;
    
    color = mix(firstColor, secondColor, currLerp) * oColor;
}

/*
void main(){
    float lerpValue = gl_FragCoord.y /500.0;
    color = mix(oColor, vec4(1, 1, 0, 1), lerpValue);
    color = oColor;
}
*/