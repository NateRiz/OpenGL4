#ifndef VOXEL4_MESHHANDLER_H
#define VOXEL4_MESHHANDLER_H

#include <vector>

#include "Mesh.h"

enum class VAOType {
    POSITION = 0 // x, y, z floats
};


//Singleton
class MeshHandler {
public:
    MeshHandler();
    ~MeshHandler();

    Mesh CreateMesh(std::vector<float> &data, std::vector<unsigned int>& indices, int vaoType);

    const std::vector<Mesh> &getMeshes() const;

private:
    std::vector<unsigned int> mVAOs{}; /// Index corresponds to the VAOType
    std::vector<unsigned int> mVBOs{}; /// Meshes that currently exist
    std::vector<Mesh> mMeshes{};
};


#endif //VOXEL4_MESHHANDLER_H
