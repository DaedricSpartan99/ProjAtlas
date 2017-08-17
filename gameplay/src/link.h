#ifndef LINK_H
#define LINK_H

#include "node.h"

class ULink : public UActorComponent {
    
public:

    ULink();
    ~ULink();

    virtual void tickComponent(float deltaTime) = 0;

    void SetNodes(const UNode *, const UNode *);
    void SetBreakEnergy(float value);

    UNode * GetAlphaNode() const;
    UNode * GetBetaNode() const;
    float GetBreakEnergy() const;

private:

    UNode * alpha, beta;
    float break_energy;
};

#endif