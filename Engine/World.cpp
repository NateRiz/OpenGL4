//
// Created by nathan on 6/15/19.
//

#include "World.h"
#include "Actor.h"
#include "MeshHandler.h"
#include "Renderer.h"

void World::MainLoop()
{
    while (!glfwWindowShouldClose(mWindowManager.GetWindow()))
    {
        Tick();
    }
}

void World::Tick()
{
    mLastFrameTime = mCurrentFrameTime;
    mCurrentFrameTime = glfwGetTime();
    double deltaTime = mCurrentFrameTime - mLastFrameTime;

    for (auto actor : mActors) { actor->Tick(deltaTime); }

    mRenderer.Prepare();
    for (auto mesh: mMeshHandler->getMeshes()){ mRenderer.Render(&mesh); }

    mWindowManager.Update();

    auto error = glGetError();
    if (error) std::cout << error <<std::endl;
}


void World::CreateActor(Actor *actor)
{
    mActors.push_back(actor);
}

World::World()
{
    mMeshHandler = new MeshHandler();
}

World::~World()
{
    delete mMeshHandler;
}

World &World::GetWorld()
{
    static World instance;
    return instance;
}