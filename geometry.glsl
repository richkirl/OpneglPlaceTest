#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 4) out;

in VS_OUT {
    vec3 color;
} gs_in[];

out vec3 fColor;

void build_house(vec4 position)
{    
    fColor = gs_in[0].color; // gs_in[0] т.к. мы имеем дело только с одной вершиной
    gl_Position = position + vec4(-0.2, -0.2, 0.0, 0.0); // 1: нижн€€-лева€   
    EmitVertex();   
    gl_Position = position + vec4( 0.2, -0.2, 0.0, 0.0); // 2: нижн€€-права€
    EmitVertex();
    gl_Position = position + vec4(-0.2,  0.2, 0.0, 0.0); // 3: верхн€€-лева€
    EmitVertex();
    gl_Position = position + vec4( 0.2,  0.2, 0.0, 0.0); // 4: верхн€€-права€
    EmitVertex();
    //gl_Position = position + vec4( 0.0,  0.4, 0.0, 0.0); // 5: верхн€€
    fColor = vec3(1.0, 1.0, 1.0);
    EmitVertex();
    EndPrimitive();
}

void main() {    
    build_house(gl_in[0].gl_Position);
}

