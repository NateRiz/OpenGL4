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
    unsigned int getVao() const; /** Returns the stored vao type for this mesh. */
    unsigned int getVertexCount() const; /** Returns the number of vertices in the mesh. */
    Shader getShader() const; /** Returns the shader currently bound to this mesh. */

private:
    unsigned int VAO;
    unsigned int vertexCount;
    Shader mShader;

};


#endif //VOXEL4_MESH_H
