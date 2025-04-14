#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Interfaces/IWorldInterface.h"
#include "Core/Object.h"
#include "Core/DynamicArray.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"

class UWorld;

class AActor : public UObject, public IRenderInterface, public IWorldInterface
{
protected:
    FVector2 CurrentLocation;
    UWorld* World;

// Rendering Section
public:
    virtual string GetScreenString() override;

// Location Section
public:
    virtual FVector2 GetLocation() override;
    virtual void SetLocation(FVector2 NewLocation) override;

// World Section
public:
    virtual void SetWorld(UWorld* InWorld) override;
    virtual UWorld* GetWorld() override;

// Component Section
private:
    TArray<UActorComponent*> ActorComponents;
    TArray<USceneComponent*> SceneComponents;

public:
    template<typename T>
    T* AddComponent()
    {
        static_assert(is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        T* NewComponent = new T();
        NewComponent->SetOwner(this);

        if constexpr (is_base_of<USceneComponent, T>::value)
        {
            SceneComponents.Add(NewComponent);
        }

        ActorComponents.Add(NewComponent);
        return NewComponent;
    }

    template<typename T>
    UActorComponent* GetComponents()
    {
        static_assert(is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        for (UActorComponent* Comp : ActorComponents)
        {
            if (T* Casted = dynamic_cast<T*>(Comp))
            {
                return Casted;
            }
        }

        return nullptr;
    }


};

