#version 330 core
layout (location = 0) out vec4 out_color;
in vec3 v_color;
in vec2 v_tex;

uniform sampler2D tex0;



void main()
{
   //out_color = vec4(v_color, 1.0f);
   out_color = texture(tex0, v_tex);
   //out_color.rgb *= 10;
   //out_color.rgb = floor(out_color.rgb);
   //out_color.rgb /= 10;

};