#version 330 core

layout (location = 0) in vec3 vPosition;

out vec3 worldPosition;

uniform mat4 projection;
uniform mat4 view;

void main(){
    worldPosition = vPosition;
    gl_Position = projection * view * vec4(worldPosition, 1.0);
}