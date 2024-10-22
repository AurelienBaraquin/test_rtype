#include "lib.hpp"
#include "engine.hpp"

int main() {
    Lib lib;
    lib.print();

    Engine engine;
    engine.print();

    engine.createWorld();
    engine.printWorld();
    return 0;
}
