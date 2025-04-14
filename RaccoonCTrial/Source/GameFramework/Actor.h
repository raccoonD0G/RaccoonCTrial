#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Interfaces/IWorldInterface.h"
#include "Interfaces/IWorldServiceInterface.h"
#include "Core/Object.h"
#include "Core/DynamicArray.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"

class UWorld;

class AActor : public UObject, public IWorldInterface, public IWorldServiceInterface
{
public:
    virtual void PostInitializeComponents();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

protected:
    FVector2 CurrentLocation;
    UWorld* World;

// World Section
public:
    virtual void SetWorld(UWorld* InWorld) override;
    virtual UWorld* GetWorld() override;

// Component Section
protected:
    USceneComponent* RootComponent = nullptr;

private:
    TArray<UActorComponent*> ActorComponents;
    TArray<USceneComponent*> SceneComponents;

public:
    template<typename T>
    T* AddOwnedComponent()
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
    T* GetComponentByClass()
    {
        static_assert(is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        for (int i = 0; i < ActorComponents.Num(); ++i)
        {
            if (T* Casted = dynamic_cast<T*>(ActorComponents[i]))
            {
                return Casted;
            }
        }
        return nullptr;
    }

    // Location Section
public:
    inline FVector2 GetActorLocation() { return RootComponent->GetLocation(); }
    inline void SetActorLocation(FVector2 NewLocation) { RootComponent->SetLocation(NewLocation); }
};

