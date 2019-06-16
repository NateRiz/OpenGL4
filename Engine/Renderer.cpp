//
// Created by nathan on 6/9/19.
//

#include "Renderer.h"
#include "Mesh.h"

void Renderer::Render(Mesh* mesh){
    glBindVertexArray(mesh->getVao());
    glEnableVertexAttribArray(0); // TODO How many attributes does the vbo have (eg 1 position)
    mesh->getShader().Use();
    glDrawElements(GL_TRIANGLES, mesh->getVertexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Prepare()
{
    glClearColor(.2f, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}
