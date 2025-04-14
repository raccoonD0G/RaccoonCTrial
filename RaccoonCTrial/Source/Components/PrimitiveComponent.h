#pragma once
#include "SceneComponent.h"
#include "string"

class UWorld;

using namespace std;

class UPrimitiveComponent : public USceneComponent
{

private:
    bool bVisible = true;
    bool bSimulatePhysics = false;
};

