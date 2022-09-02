#shader vertex
#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec3 vertColor;

out vec3 v_vertColor;
uniform mat4 u_MVP;
uniform float u_Scale;

void main()
{
    vec4 temp = vec4(position.x * u_Scale, position.y * u_Scale, 1.0f, 1.0f);
    gl_Position = u_MVP * temp;

    v_vertColor = vertColor;
}

#shader fragment
#version 330 core

in vec3 v_vertColor;
layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	vec4 texColor = vec4(v_vertColor.x, v_vertColor.y, v_vertColor.z, 1.0f);
    color = texColor;
}
