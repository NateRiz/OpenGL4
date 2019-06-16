#ifndef VOXEL4_RENDERER_H
#define VOXEL4_RENDERER_H

#include <glad/glad.h>

class Mesh;

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    /// Clears the screen.
    void Prepare();

    /// Renders a mesh to the screen.
    void Render(Mesh* mesh);

};

#endif //VOXEL4_RENDERER_H
