#version 330 core

in vec2 TexCoord;
in vec3 FragmentPosition;

out vec4 color;

uniform sampler2D sampler;

void main()
{
  	color = texture(sampler,TexCoord);
}