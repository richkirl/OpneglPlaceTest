//#version 330 core
//out vec4 FragColor;
//
//in vec3 ourColor;
//in vec2 TexCoord;
//
//uniform sampler2D texture1;
//
//void main()
//{
//    //FragColor = vec4(ourColor, 1.0f);
//    FragColor= texture(texture1,TexCoord);
//}
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
//in float visibility;

// texture samplers
uniform sampler2D texture1;
//uniform sampler2D texture2;
//uniform vec3 skyColor;
void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = texture(texture1, TexCoord);

	//FragColor = mix(vec4(skyColor,1.0),FragColor,visibility);
}