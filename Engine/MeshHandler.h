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
    std::vector<unsigned int> mVAOs{}; /** All created VAOs. The index corresponds to the enum: VAOType. */
    std::vector<unsigned int> mVBOs{}; /** All vbos of meshes that currently exist. */
    std::vector<Mesh> mMeshes{}; /** All existing meshes.*/
};

#endif //VOXEL4_MESHHANDLER_H
