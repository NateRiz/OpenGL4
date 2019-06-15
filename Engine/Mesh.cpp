//
// Created by nathan on 6/9/19.
//

#include "Mesh.h"

unsigned int Mesh::getVao() const {
    return VAO;
}

Shader Mesh::getShader() const{
    return mShader;
}

Mesh::Mesh(unsigned int vao, unsigned int vertexCount, const char *vertexShader = "DefaultVertex.glsl",
           const char *fragmentShader = "DefaultFragment.glsl")
           : Actor(),
           VAO(vao), vertexCount(vertexCount),
           mShader(vertexShader, fragmentShader){}

unsigned int Mesh::getVertexCount() const {
    return vertexCount;
}

