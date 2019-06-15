#version 460

layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

out vec3 color;

void main()
{
    gl_Position = vec4(aPos.xyz, 1.0);
    color = vec3(aPos.x+.5, aPos.y+.5, aPos.z);
}