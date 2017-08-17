#ifndef SOCKET_H
#define SOCKET_H

#include "utypes.h"

typedef struct {

    float energy;
    FVector force;
    float power;
    bool enough;

} Action;

class Socket {

public:

    Socket(uint32_t id);
    ~Socket();

    virtual void TickSocket(float deltaTime, Action& action) = 0;

    uint32_t GetID() const;

    float intensity;

private:

    uint32_t id;
};

#endif