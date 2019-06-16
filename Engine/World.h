///
/// The world class contains all actors, the window context and the meshhandler.
/// Handles drawing every frame and delta time.
///
#ifndef VOXEL4_WORLD_H
#define VOXEL4_WORLD_H

#include "WindowManager.h"
#include "Renderer.h"
#include <vector>
class MeshHandler;
class Actor;

class World{
public:

    ///The world should only be constructed once. Static for all actors to access.
    static World& GetWorld();

    /// The main game loop. Quits when the glfw_window_should_close is set.
    void MainLoop();

    /// Calls Tick of all handled actors and renders meshes.
    void Tick();

    /// All constructed actors are first added to mActors.
    void CreateActor(Actor* actor);

    /// Returns the current WindowManager
    WindowManager GetWindowManager() { return mWindowManager; }


private:
    /// Private constructor as outsiders should only call the GetWorld to get the singleton
    World();

    /// Destructor called automatically and does not get inherited
     virtual ~World() final;

    WindowManager mWindowManager; /** WindowManaager singleton manages glfwwindow */
    MeshHandler* mMeshHandler; /** MeshHandler singleton holds all meshes */
    Renderer mRenderer; /** Renderer singleton takes a mesh and renders it. */
    std::vector<Actor*> mActors; /** Holds all actors currently in the world */
    double mCurrentFrameTime=0; /** Time since the frame started. Used for delta time calculation. */
    double mLastFrameTime=0; /** Time when the last frame started. Used for delta time calculation. */
};


#endif //VOXEL4_WORLD_H
