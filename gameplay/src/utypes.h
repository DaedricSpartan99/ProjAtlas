#ifndef UTYPES_H
#define UTYPES_H

#include <vector>

#define uint32_t unsigned int

typedef struct {

    float x, y, z;
} FVector;

typedef struct {

    float pitch, roll, yaw;

} FRotator;

class UActorComponent {

public:

    UActorComponent();
    virtual ~UActorComponent();

    virtual void tickComponent(float deltaTime) = 0;
};

class USceneComponent : public UActorComponent {

    USceneComponent();
    virtual ~USceneComponent();

    virtual void tickComponent(float deltaTime) = 0;

    FVector GetLocation() const;
    FVector GetRelativeScale3D() const;
    FRotator GetRotator() const;

    void SetLocation(const FVector&);
    void SetRelativeScale3D(const FVector&);
    void SetRotator(const FRotator&);

private:

    FVector location, relativeScale3D;
    FRotator rotator;

    std::vector<USceneComponent*> children;
};

class AActor {

public:

    AActor();
    ~AActor();

    void tick(float deltaTime);

private:

    std::vector<UActorComponent*> children;
};

#endif