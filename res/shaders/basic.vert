#version 330 core
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_color;

layout (location = 2) in vec2 in_tex;

out vec3 v_color;
out vec2 v_tex;

uniform mat4 transform;

void main()
{
   gl_Position = transform * vec4(in_position, 1.0);
   //gl_Position.xyz *= 0.25;
   v_color = in_color;
   v_tex = in_tex;
};
