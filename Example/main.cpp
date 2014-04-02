#include <iostream>
#include <memory>
#include "Example/ShipEntity.h"
#include "EntityManager.h"
#include "Example/ShipEntitySystem.h"
using namespace std;
using namespace zmc;

enum ENTITIES {
    SHIP,
    BLOOD
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
    ShipEntity *ship = entityManager.createEntity<ShipEntity>(1, ENTITIES::SHIP);
    ShipEntity *ship1 = entityManager.createEntity<ShipEntity>(1, ENTITIES::BLOOD);
    std::unique_ptr<MovementComponent> movement(new MovementComponent(10, 150, COMPONENTS::MOVEMENT));
    movement->setGroups(1, 0);
    compoenentManager->addComponent(ship->getEntityID(), std::move(movement));
    movement.reset(new MovementComponent(100, 250, COMPONENTS::MOVEMENT));
    compoenentManager->addComponent(ship1->getEntityID(), std::move(movement));
    ShipEntitySystem sSystem;
    std::vector<int> vectora;
    vectora.push_back(COMPONENTS::MOVEMENT);
    sSystem.setRequiredComponents(vectora);
    sSystem.addEntity(*ship);
    sSystem.addEntity(*ship1);
    float x = 10, y = 10;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                compoenentManager->removeComponent(ship->getEntityID(), COMPONENTS::MOVEMENT);
                compoenentManager->removeComponent(ship1->getEntityID(), COMPONENTS::MOVEMENT);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                x += 10;
                y += 10;
                std::unique_ptr<MovementComponent> movement(new MovementComponent(x + 10, y + 10, COMPONENTS::MOVEMENT));
                compoenentManager->addComponent(ship->getEntityID(), std::move(movement));
                movement.reset(new MovementComponent(x + 10, y + 10, COMPONENTS::MOVEMENT));
                compoenentManager->addComponent(ship1->getEntityID(), std::move(movement));
            }
        }
        window->clear(sf::Color(245, 118, 243));
        sSystem.process();
        window->draw(*ship);
        window->draw(*ship1);
        window->display();
    }
    return 0;
}
