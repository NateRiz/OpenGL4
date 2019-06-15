//
// Created by nathan on 6/9/19.
//

#ifndef VOXEL4_RENDERER_H
#define VOXEL4_RENDERER_H


#include <glad/glad.h>
#include "Mesh.h"

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    void prepare(){
        glClearColor(.2f, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void render(Mesh mesh){
        glBindVertexArray(mesh.getVao());
        glEnableVertexAttribArray(0); // TODO How many attributes does the vbo have (eg 1 position)
        mesh.getShader().Use();
        glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    }

};

#endif //VOXEL4_RENDERER_H
