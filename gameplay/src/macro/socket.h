#ifndef MACRO_SOCKET_H
#define MACRO_SOCKET_H

#include "node.h"
#include "socket.h"

class MacroSocket : public Socket {

public:

    MacroSocket();
    ~MacroSocket();

    virtual void TickSocket(float deltaTime, Action& action) = 0;

    void SetNode(UMacroNode *);

    const UMacroNode * GetNode() const;

protected:

    UMacroNode * node;
};

// Player to obj

class OppositeMacroSocket : public MacroSocket {

public:

    OppositeMacroSocket();
    ~OppositeMacroSocket();

    virtual void TickSocket(float deltaTime, Action& action) = 0;

    void SetSource(USceneComponent *);

    const USceneComponent * GetSource() const;

private:

    USceneComponent * source;
};

class AttractMacroSocket : public OppositeMacroSocket {

public:

    AttractMacroSocket();
    ~AttractMacroSocket();

    void TickSocket(float deltaTime, Action& action);
};

class RepulseMacroSocket : public OppositeMacroSocket {

public:

    RepulseMacroSocket();
    ~RepulseMacroSocket();

    void TickSocket(float deltaTime, Action& action);
};

// Object to Object

class RelativeMacroSocket : public MacroSocket {

public:

    RelativeMacroSocket();
    ~RelativeMacroSocket();

    virtual void TickSocket(float deltaTime, Action& action) = 0;

    void SetAlpha(UMacroNode *);
    void SetBeta(UMacroNode *);

    const UMacroNode * GetAlpha() const;
    const UMacroNode * GetBeta() const;

private:

    UMacroNode * dest_node;
};

class ConvergeMacroSocket : public RelativeMacroSocket {

public:

    ConvergeMacroSocket();
    ~ConvergeMacroSocket();

    void TickSocket(float deltaTime, Action& action);
};

class DivergeMacroSocket : public RelativeMacroSocket {

public:

    DivergeMacroSocket();
    ~DivergeMacroSocket();

    void TickSocket(float deltaTime, Action& action);
};

// Player guides object

class FixMacroSocket : public MacroSocket {

public:

    FixMacroSocket();
    ~FixMacroSocket();

    void TickSocket(float deltaTime, Action& action);
};

#endif