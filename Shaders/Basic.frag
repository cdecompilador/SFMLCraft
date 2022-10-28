#version 330

in vec2 passTextureCoord;
out vec4 outColor;

uniform sampler2D texSampler;

void main()
{
    outColor = texture(texSampler, passTextureCoord);
}
