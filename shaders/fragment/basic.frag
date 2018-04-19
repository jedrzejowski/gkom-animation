#version 330 core
out vec4 FragColor;

in vec3 oColor;
in vec2 oTexCoord;

struct Material {
    sampler2D diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 cameraPosition;
uniform Material material;
uniform Light light;

void main() {
	//FragColor = vec4(oColor, 1.0f);
	FragColor = texture(material.diffuse, oTexCoord);
}