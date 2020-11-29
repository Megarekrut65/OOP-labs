#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "MyWindow");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    sf::RectangleShape line(sf::Vector2f(500.f, 5.f));
    line.rotate(45.f);
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);
    shape.setPosition(300.0f, 400.0f);
    line.setPosition(25.0f, 25.0f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(line);
        window.display();
    }

    return 0;
}