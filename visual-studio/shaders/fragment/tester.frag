#version 330 core
out vec4 FragColor;

in vec3 oColor;
in vec2 oTexCoord;

uniform sampler2D ourTexture;

void main() {
	FragColor = vec4(1, 0, 0, 1.0f);
	//FragColor = texture(ourTexture, oTexCoord);
}