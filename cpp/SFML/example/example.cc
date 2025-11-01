#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Example");

  sf::CircleShape circle(50.0f);
  circle.setFillColor(sf::Color::Cyan);
  circle.setPosition({100.f, 100.f});

  sf::Vector2f velocity(100.f, 80.f);  // pixels per second
  sf::Clock clock;

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    float dt = clock.restart().asSeconds();

    sf::Vector2f pos = circle.getPosition();
    pos += velocity * dt;

    if (pos.x < 0 || pos.x + circle.getRadius() * 2 > 800) {
      velocity.x = -velocity.x;
    }
    if (pos.y < 0 || pos.y + circle.getRadius() * 2 > 600) {
      velocity.y = -velocity.y;
    }

    circle.setPosition(pos);

    window.clear(sf::Color::Black);
    window.draw(circle);
    window.display();
  }

  return 0;
}
