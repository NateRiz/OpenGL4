//
// Created by nathan on 6/15/19.
//

#include "Actor.h"

Actor::Actor() {
    World::GetWorld().CreateActor(this);
}

void Actor::Tick(double deltaTime)
{

}

void Actor::AddChild(Actor actor)
{
    mChildren.push_back(actor);
}
