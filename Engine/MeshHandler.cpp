//
// Created by nathan on 6/9/19.
//

#include "MeshHandler.h"
#include <glad/glad.h>


MeshHandler::MeshHandler() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    mVAOs.push_back(vao); //TODO this shouldn't be here later. vaotype will just be passed in to createmesh()
}

MeshHandler::~MeshHandler() {
    for (unsigned int vao: mVAOs) {
        glDeleteVertexArrays(1, &vao);
    }
    for (unsigned int vbo: mVBOs) {
        glDeleteBuffers(1, &vbo);
    }
}

Mesh MeshHandler::CreateMesh(std::vector<float> &data, std::vector<unsigned int>& indices, int vaoType) {
    glBindVertexArray(mVAOs[vaoType]);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    mVBOs.push_back(vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void *) 0); // Positions

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    mVBOs.push_back(ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);

    mMeshes.emplace_back(mVAOs[vaoType], indices.size(),"vertex.glsl", "fragment.glsl");
    return mMeshes.back();
}

const std::vector<Mesh> &MeshHandler::getMeshes() const {
    return mMeshes;
}
