#ifndef NODE_H
#define NODE_H

#include "utypes.h"

enum ENodeStatus {

    FREE,
    OVER,
    SELECTED
};

class UNode : public USceneComponent {

public:

    UNode();
    ~UNode();

    virtual void tickComponent(float deltaTime) = 0;

    void SetStatus(NodeMouseStatus status);
    ENodeMouseStatus GetStatus() const;

private:

    ENodeStatus status;
};

#endif