#pragma once
#include "Core/Collision/CollisionChannel.h"
#include "CoreMinimal.h"
#include "iostream"

struct FCollisionResponseContainer
{
    TMap<ECollisionChannel, ECollisionResponse> ResponseMap;
    ECollisionChannel MyChannel = ECollisionChannel::None;

    FCollisionResponseContainer()
    {
        for (int i = 0; i <= static_cast<int>(ECollisionChannel::None); i++)
        {
            ResponseMap.Add(static_cast<ECollisionChannel>(i), ECollisionResponse::Ignore);
        }
    }

    explicit FCollisionResponseContainer(ECollisionChannel InMyChannel) : MyChannel(InMyChannel)
    {
        for (int i = 0; i <= static_cast<int>(ECollisionChannel::None); i++)
        {
            ResponseMap.Add(static_cast<ECollisionChannel>(i), ECollisionResponse::Ignore);
        }

        ResponseMap[MyChannel] = ECollisionResponse::Block;
    }

    FCollisionResponseContainer(const FCollisionResponseContainer& Other) : ResponseMap(Other.ResponseMap), MyChannel(Other.MyChannel)
    {
    }

    ~FCollisionResponseContainer()
    {
        ;
    }

    FCollisionResponseContainer& operator=(const FCollisionResponseContainer& Other)
    {
        if (this != &Other)
        {
            ResponseMap = Other.ResponseMap;
            MyChannel = Other.MyChannel;
        }
        return *this;
    }

    FCollisionResponseContainer(FCollisionResponseContainer&& Other) noexcept : ResponseMap(std::move(Other.ResponseMap)), MyChannel(Other.MyChannel)
    {
        Other.MyChannel = ECollisionChannel::None;
    }

    FCollisionResponseContainer& operator=(FCollisionResponseContainer&& Other) noexcept
    {
        if (this != &Other)
        {
            ResponseMap = std::move(Other.ResponseMap);
            MyChannel = Other.MyChannel;
            Other.MyChannel = ECollisionChannel::None;
        }
        return *this;
    }

    void SetResponseToChannel(ECollisionChannel Channel, ECollisionResponse Response)
    {
        ResponseMap[Channel] = Response;
    }

    ECollisionResponse GetResponseToChannel(ECollisionChannel Channel) const
    {
        const ECollisionResponse* Found = ResponseMap.Find(Channel);
        return Found ? *Found : ECollisionResponse::Ignore;
    }

    ECollisionChannel GetChannel() const
    {
        return MyChannel;
    }
};
