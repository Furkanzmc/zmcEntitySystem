#include <iostream>
#include <memory>
#include "Example/ShipEntity.h"
#include "EntityManager.h"
#include "Example/ShipEntitySystem.h"
using namespace std;
using namespace zmc;

enum ENTITIES {
    SHIP
};

enum COMPONENTS {
    MOVEMENT,
    S
};

int main()
{
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(640, 480), "SD", sf::Style::Default));
    std::unique_ptr<ComponentManager> compoenentManager(new ComponentManager());
    EntityManager entityManager(compoenentManager.get());
    ShipEntity *ship = entityManager.createEntity<ShipEntity>(ENTITIES::SHIP);
    std::unique_ptr<MovementComponent> movement(new MovementComponent(10, 150, COMPONENTS::MOVEMENT));
    compoenentManager->addComponent(ship->getEntityID(), std::move(movement));
    ShipEntitySystem sSystem;
    std::vector<int> vectora;
    vectora.push_back(COMPONENTS::S);
    sSystem.setRequiredComponentTypes(vectora);
    sSystem.addEntity(*ship);
    float x = 10, y = 10;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                compoenentManager->removeComponent(ship->getEntityID(), COMPONENTS::MOVEMENT);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                x += 10;
                y += 10;
                std::unique_ptr<MovementComponent> movement(new MovementComponent(x + 10, y + 10, COMPONENTS::MOVEMENT));
                compoenentManager->addComponent(ship->getEntityID(), std::move(movement));
            }
        }
        window->clear(sf::Color(245, 118, 243));
        sSystem.process();
        window->draw(*ship);
        window->display();
    }
    return 0;
}
