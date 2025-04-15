#pragma once
#include "Interfaces/IRenderInterface.h"
#include "Interfaces/IWorldInterface.h"
#include "Core/Object.h"
#include "Core/Container/DynamicArray.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"

class UWorld;

class AActor : public UObject, public IWorldInterface
{

public:
    AActor();
    ~AActor();

public:
    virtual void PostInitializeComponents();
    virtual void BeginPlay();
    virtual void Tick(float DeltaSeconds);

protected:
    UWorld* World = nullptr;

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
    inline const USceneComponent* GetRootComponent() const { return RootComponent; }

    template<typename T>
    T* AddOwnedComponent()
    {
        static_assert(std::is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        T* NewComponent = new T();

        NewComponent->SetOwner(this);

        if constexpr (std::is_base_of<USceneComponent, T>::value)
        {
            SceneComponents.Add(NewComponent);
        }
        else
        {
            ActorComponents.Add(NewComponent);
        }

        return NewComponent;
    }

    template<typename T>
    T* GetComponentByClass()
    {
        static_assert(std::is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        for (int i = 0; i < SceneComponents.Num(); ++i)
        {
            if (T* Casted = dynamic_cast<T*>(SceneComponents[i]))
            {
                return Casted;
            }
        }
        for (int i = 0; i < ActorComponents.Num(); ++i)
        {
            if (T* Casted = dynamic_cast<T*>(ActorComponents[i]))
            {
                return Casted;
            }
        }
        
        return nullptr;
    }

    template<typename T>
    void GetComponents(TArray<T*>& OutComponents)
    {
        static_assert(std::is_base_of<UActorComponent, T>::value, "T must be derived from UActorComponent");

        for (int i = 0; i < SceneComponents.Num(); ++i)
        {
            if (T* Casted = dynamic_cast<T*>(SceneComponents[i]))
            {
                OutComponents.Add(Casted);
            }
        }

        for (int i = 0; i < ActorComponents.Num(); ++i)
        {
            if (T* Casted = dynamic_cast<T*>(ActorComponents[i]))
            {
                OutComponents.Add(Casted);
            }
        }
    }

// Location Section
public:
    inline FVector2 GetActorLocation() { return RootComponent ? RootComponent->GetLocation() : FVector2(); }
    inline void SetActorLocation(FVector2 NewLocation) { if (RootComponent) RootComponent->SetLocation(NewLocation); }
};

