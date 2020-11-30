#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

bool readFont(sf::Font& font)
{
    std::ifstream myFont{ "arial.ttf", std::ifstream::binary };
    char* buffer = nullptr;
    std::size_t length = 0;
    if (myFont.is_open()) {
        // get length of file:
        myFont.seekg(0, myFont.end);
        length = myFont.tellg();
        if (length < 1) {
            std::cerr << "Cannot load zero byte font file" << std::endl;
            return false;
        }
        buffer = new char[length]; // reserve space

        myFont.seekg(0, myFont.beg);

        myFont.read(buffer, length);
        myFont.close();
    }
    else {
        std::cerr << "Could not open font file" << std::endl;
        return false;
    }


    if (!font.loadFromMemory(&buffer[0], length)) {
        std::cerr << "Font load failed" << std::endl;
        return false;
    }
    return true;
}
int main()
{
    sf::Font font;
    if (!readFont(font)) return 1;
    sf::RenderWindow window(sf::VideoMode(500, 600), "MyWindow");
    sf::CircleShape shape(40.f);
    sf::CircleShape shape2(40.f);
    //sf::RectangleShape line(sf::Vector2f(500.f, 5.f));
    //line.rotate(45.f);
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);
    shape.setPosition(300.0f, 400.0f);

    sf::Text text;
    text.setFont(font);
    text.setString("10");
    text.setCharacterSize(20);
    text.setPosition(40.f, 40.f);
   
   // text.setFillColor(sf::Color::Red);
    //text.setScale(sf::Vector2f(5.f, 5.f));
    //line.setPosition(25.0f, 25.0f);
    sf::Vertex line2[] =
    {
        sf::Vertex(sf::Vector2f(40.f, 40.f)),
        sf::Vertex(sf::Vector2f(340.f, 440.f))
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
        window.draw(line2, 2, sf::Lines);
        window.draw(shape);
        window.draw(shape2);
        window.draw(text);
        window.display();
    }

    return 0;
}