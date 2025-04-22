#pragma once
#include "string"
#include "Engine/EngineTypes.h"

struct FCollisionProfileName
{
    std::string Name;

    FCollisionProfileName() : Name("") {}
    explicit FCollisionProfileName(std::string InName) : Name(InName) {}

    bool operator==(const FCollisionProfileName& Other) const { return Name == Other.Name; }
    bool operator!=(const FCollisionProfileName& Other) const { return !(*this == Other); }

    operator std::string() const { return Name; }
};


class UCollisionProfile
{
private:
    TMap<std::string, FCollisionResponseContainer> NamedProfiles;

public:
    UCollisionProfile()
    {
        std::cout << "[UCollisionProfile] Singleton Constructor\n";
    }

    static UCollisionProfile& Get()
    {
        static UCollisionProfile Singleton;
        return Singleton;
    }

    void AddProfile(std::string ProfileName, const FCollisionResponseContainer& Container)
    {
        NamedProfiles.Add(ProfileName, Container);
    }

    bool GetResponseContainer(std::string ProfileName, FCollisionResponseContainer& OutContainer) const
    {
        const FCollisionResponseContainer* Found = NamedProfiles.Find(ProfileName);
        if (Found)
        {
            OutContainer = *Found;
            return true;
        }
        return false;
    }
};
