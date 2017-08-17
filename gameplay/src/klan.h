#ifndef KLAN_H
#define KLAN_H

#include "socket.h"

class UKlan : UActorComponent {

public:

    UKlan();
    ~UKlan();

    void tickComponent(float deltaTime);

    int PushAction(const Socket *);
    void RemoveAction(uint32_t id);
    void ClearActions();

    void SetActionsEnabled(bool value);
    void SetEnergy(float value);
    void SetMaxActions(int value);

    bool GetActionsEnabled() const;
    float GetEnergy() const;
    int GetMaxActions() const;

    void SetActionRange(float range);
    float GetActionRange() const;

private:

    float energy;
    //float temperature;
    std::vector<Socket> actions;
    int max_actions;
    bool actions_enabled;

    USceneComponent * rangeSphere;
};

#endif