#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;
uniform mat4 u_MVP;
uniform float u_Scale;

void main()
{
    vec4 temp = vec4(position.x * u_Scale, position.y * u_Scale, 1.0f, 1.0f);
    gl_Position = u_MVP * temp;
    v_texCoord = texCoord;
}

#shader fragment
#version 330 core

in vec2 v_texCoord;
layout(location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D tex_slot;

void main()
{
	vec4 texColor = texture(tex_slot, v_texCoord);
    color = texColor;
}
