//
// Created by nathan on 6/15/19.
//
#include "WindowManager.h"
#include "MeshHandler.h"
#include "Renderer.h"
class Actor;

#ifndef VOXEL4_WORLD_H
#define VOXEL4_WORLD_H


class World{
public:
    static World& GetWorld(){
        static World instance;
        return instance;
    }

    void MainLoop();
    void Tick();
    void CreateActor(Actor* actor);

private:
    World()=default;
    WindowManager mWindowManager;
    MeshHandler mMeshHandler;
    Renderer mRenderer;
    std::vector<Actor*> mActors;
    double mCurrentFrameTime=0;
    double mLastFrameTime=0;
};


#endif //VOXEL4_WORLD_H
