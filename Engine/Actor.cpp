//
// Created by nathan on 6/15/19.
//

#include "Actor.h"
#include "World.h"

Actor::Actor() {
    World::GetWorld().CreateActor(this);
}

void Actor::Tick(double deltaTime) {

}
