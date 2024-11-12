#include "console.hpp"

void Console::init() {
    inputThread = std::thread([this] {
        while (running) {
            if (std::cin.eof()) {
                running = false;
                break;
            }
            std::lock_guard<std::mutex> lock(inputMutex);
            if (!input.empty())
                continue;
            std::getline(std::cin, input);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });
}

void Console::update() {
    std::lock_guard<std::mutex> lock(inputMutex);
    if (!input.empty()) {
        if (input == "exit") {
            eventManager->publish(std::make_shared<Events::Shutdown>());
            return;
        }
        if (input == "print all") {
            auto view = registry.view<Components::Transform, Components::Mesh>();
            for (auto entity : view) {
                auto& transform = view.get<Components::Transform>(entity);
                auto& mesh = view.get<Components::Mesh>(entity);
                std::cout << "Entity: " << mesh.name << " Transform: (" << transform.x << ", " << transform.y << ", " << transform.z << ")" << std::endl;
            }
        }
        input.clear();
    }
}

void Console::shutdown() {
    running = false;
    inputThread.join();
}
