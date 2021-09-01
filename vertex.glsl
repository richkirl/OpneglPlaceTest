//#version 330 core
//layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;
//layout (location = 2) in vec2 aTexCoord;
//
//out vec3 ourColor;
//out vec2 TexCoord;
//
//void main()
//{
//    gl_Position = vec4(aPos, 1.0);
//    //ourColor = aColor;
//    TexCoord = vec2(aTexCoord.x,aTexCoord.y);
//}
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;
out float visibility;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


//const float density = 0.07;
//const float gradient = 1.5;

void main()
{
	vec4 positionRelativeToCam = view * model * vec4(aPos, 1.0f);
	gl_Position = projection * positionRelativeToCam;
	ourColor = aColor;
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);

	//float distance = length(positionRelativeToCam.xyz);

	//visibility = exp(-pow((distance*density),gradient));
	//visibility = clamp(visibility,0.05,0.3f);
}