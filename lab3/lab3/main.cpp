#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "MyWindow");
    sf::CircleShape shape(100.f);
    sf::CircleShape shape2(50.f);
    //sf::RectangleShape line(sf::Vector2f(500.f, 5.f));
    //line.rotate(45.f);
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);
    shape.setPosition(300.0f, 400.0f);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setString("10000");
    text.setFont(font);
    text.setPosition(50.f, 50.f);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    //text.setScale(sf::Vector2f(10.f, 10.f));
    //line.setPosition(25.0f, 25.0f);
    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(50.f, 50.f)),
        sf::Vertex(sf::Vector2f(400.f, 500.f))
    };

    
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
        //window.draw(shape2);
        window.draw(text);
        window.draw(line2, 2, sf::Lines);
        window.display();
    }

    return 0;
}