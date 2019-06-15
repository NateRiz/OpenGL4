//
// Created by nathan on 6/15/19.
//

#include "World.h"



void World::MainLoop()
{
    while (!glfwWindowShouldClose(mWindowManager.getWindow()))
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

    mRenderer.prepare();
    for (auto mesh: mMeshHandler.getMeshes()){ mRenderer.render(mesh); }

    mWindowManager.Update();

    auto error = glGetError();
    if (error) std::cout << error <<std::endl;
}


void World::CreateActor(Actor *actor)
{
    mActors.push_back(actor);
}
