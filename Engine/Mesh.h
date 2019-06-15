//
// Created by nathan on 6/9/19.
//

#ifndef VOXEL4_MESH_H
#define VOXEL4_MESH_H

#include "Shader.h"
#include "Actor.h"

class Mesh: Actor{

public:
    Mesh(unsigned int vao, unsigned int vertexCount, const char* vertexShader, const char* fragmentShader);


public:
    unsigned int getVao() const;
    unsigned int getVertexCount() const;
    Shader getShader() const;

private:
    unsigned int VAO;
    unsigned int vertexCount;
    Shader mShader;

};


#endif //VOXEL4_MESH_H
