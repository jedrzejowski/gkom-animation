#version 330 core
layout (location = 0) in vec3 iPosition;
layout (location = 1) in vec3 iColor;
layout (location = 2) in vec2 iTexCoord;

out vec3 oColor;
out vec2 oTexCoord;

uniform mat4 model;
uniform mat4 camera;
uniform mat4 projection;

void main() {
    gl_Position = projection * camera * model * vec4(iPosition, 1.0f);


    oColor = iColor;
    oTexCoord = iTexCoord;
}