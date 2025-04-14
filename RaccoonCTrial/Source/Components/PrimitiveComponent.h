#pragma once
#include "SceneComponent.h"
#include "string"

using namespace std;

class UPrimitiveComponent : public USceneComponent
{

private:
    bool bVisible = true;
    bool bSimulatePhysics = false;
};

