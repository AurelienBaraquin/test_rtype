#pragma once

#include <iostream>
#include <box2d/box2d.h>

class Engine {
public:
    Engine() = default;
    ~Engine() = default;

    void print();
    void createWorld();
    void printWorld();

private:
    b2WorldDef *world;
};
