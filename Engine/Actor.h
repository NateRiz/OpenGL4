///
/// The Actor Class is the base class of all Objects in the world.
///

#ifndef VOXEL4_ACTOR_H
#define VOXEL4_ACTOR_H

#include "World.h"

class Actor {
public:
    Actor();

    /// Called every frame by World and is overridden by all children.
    virtual void Tick(double deltaTime);

    /// Adds an actor to the children of this actor.
    void AddChild(Actor actor);

private:
    std::vector<Actor> mChildren; /** All actors that are bound to this actor.*/
};


#endif //VOXEL4_ACTOR_H
