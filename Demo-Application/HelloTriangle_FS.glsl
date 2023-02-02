#version 330 core

layout(location=0) out vec4 FragColor;

void main()
{
    float x = gl_FragCoord.x;
    float y = gl_FragCoord.y;

    float ypos = (sin(x) + 1)/2;

    vec4 col = vec4(0,0,0,1);

    if(ypos < y){
        col = vec4(0,1,0,1);
    }


    FragColor = col;
} 