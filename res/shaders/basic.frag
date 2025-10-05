#version 330 core
layout (location = 0) out vec4 out_color;
in vec3 v_color;
void main()
{
   out_color = vec4(v_color, 1.0f);
   //out_color.rgb *= 10;
   //out_color.rgb = floor(out_color.rgb);
   //out_color.rgb /= 10;

};