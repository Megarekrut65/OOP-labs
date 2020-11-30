#pragma once
#include "my_graph_structure.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
namespace pg//paint graph
{
    struct Coordinate
    {
        float x;
        float y;
        Coordinate(float x, float y);
    };
    template<typename T>
	class Graph : public gs::GraphStructure<T>
	{
    private:   
        sf::Color vertexColor;
        float vertexSize;
        //sf::Color edgeColor;
        //sf::Color textColor;
        std::vector<Coordinate> coordinatesOfVertices;
        
        void drawText(sf::RenderWindow& window, std::size_t index);
        void drawVertex(sf::RenderWindow& window, std::size_t index);
	public:
		Graph();
		void paintGraph();
	};
    bool readFont(sf::Font& font, std::string path);
}
namespace pg
{
    Coordinate::Coordinate(float x, float y) :x(x),y(y) {}
    bool readFont(sf::Font& font, std::string path)
    {
        std::ifstream myFont{ path, std::ifstream::binary };
        char* buffer = nullptr;
        std::size_t length = 0;
        if (myFont.is_open()) 
        {
            myFont.seekg(0, myFont.end);
            length = myFont.tellg();
            if (length < 1) 
            {
                std::cerr << "Cannot load zero byte font file" << std::endl;
                return false;
            }
            buffer = new char[length];
            myFont.seekg(0, myFont.beg);
            myFont.read(buffer, length);
            myFont.close();
        }
        else 
        {
            std::cerr << "Could not open font file" << std::endl;
            return false;
        }
        if (!font.loadFromMemory(&buffer[0], length)) 
        {
            std::cerr << "Font load failed" << std::endl;
            return false;
        }
        std::shared_ptr<char*> shared = std::make_shared<char*>(buffer);
        return true;
    }
	template<typename T>
	Graph<T>::Graph() : vertexSize(40.f), vertexColor(sf::Color::Red), gs::GraphStructure<T>::GraphStructure(false) {}
	/*
    * sf::CircleShape shape(40.f);
        sf::CircleShape shape2(40.f);
        //sf::RectangleShape line(sf::Vector2f(500.f, 5.f));
        //line.rotate(45.f);
        shape.setFillColor(sf::Color::Green);
        shape2.setFillColor(sf::Color::Red);
        shape.setPosition(300.0f, 400.0f);

        sf::Text text;
        text.setFont(font);
        text.setString("10");
        text.setCharacterSize(40);
        //shape2.setPosition(100.0f, 200.0f);
        text.setPosition(20.f, 20.f);
        sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(40.f, 40.f)),
            sf::Vertex(sf::Vector2f(340.f, 440.f))
        };
    * 
    * 
    *             //graph.paintGraph(window);
            window.draw(line2, 2, sf::Lines);
            window.draw(shape);
            window.draw(shape2);
            window.draw(text);
    * 
    * 
    * 
    * 
    * 
    */

    template<typename T>
	void Graph<T>::paintGraph()
	{
        unsigned wight = 1000, hight = 650;
        sf::RenderWindow window(sf::VideoMode(wight, hight), "MyWindow");
        sf::Font font;
        if (!pg::readFont(font, "arial.ttf")) return;
        std::size_t size = 48;
        for(std::size_t i = 0; i < size; i++) this->addVertex(i);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            std::vector<Coordinate> coordinates;
            bool side = true;
            float radius = 30.f;
            Coordinate coordinate1(10.f, 10.f), coordinate2(10.f, float(hight - 2* radius - 10.f));
            sf::Color colorVertex = sf::Color::Blue;
            sf::Color colorEdge = sf::Color::Red;
            window.clear();
            for (std::size_t i = 0; i < this->list.size(); i++)
            {
                
                if (side)
                {
                    side = false;
                    coordinates.push_back(coordinate1);
                    if (unsigned(coordinate1.x + 5 * radius ) < wight) coordinate1.x += 4 * radius;
                    else
                    {
                        coordinate1.x = 10.f;
                        coordinate1.y += 4 * radius;
                    }
                }
                else
                {
                    side = true;
                    coordinates.push_back(coordinate2);
                    if (unsigned(coordinate2.x + 5 * radius) < wight) coordinate2.x += 4 * radius;
                    else
                    {
                        coordinate2.x = 10.f;
                        coordinate2.y -= 4 * radius;
                    }
                }
                sf::CircleShape shape(radius);
                shape.setFillColor(colorVertex);
                shape.setPosition(coordinates[i].x, coordinates[i].y);
                sf::Text text;
                text.setFont(font);
                std::string line = ofo::toTheString(this->list[i]->value);
                sf::String sfLine = line.c_str();
                text.setString(sfLine);
                text.setCharacterSize(unsigned(radius));
                text.setPosition(coordinates[i].x + 10.f, coordinates[i].y + 10.f);
                window.draw(shape);
                window.draw(text);
            }
            window.display();
        }
        /*coordinatesOfVertices.push_back({ 100.f, 100.f });
        this->addVertex(12);
        drawVertex(window, 0);*/
	}
    template<typename T>
    void Graph<T>::drawVertex(sf::RenderWindow& window, std::size_t index)
    {
        sf::CircleShape shape(vertexSize);
        shape.setFillColor(vertexColor);
        Coordinate coo = coordinatesOfVertices[index];
        shape.setPosition(coo.x, coo.y);
        window.draw(shape);
        //drawText(window, index);
    }
    template<typename T>
    void Graph<T>::drawText(sf::RenderWindow& window, std::size_t index)
    {
        sf::Font font;
        sf::Text text;
        Coordinate coo = coordinatesOfVertices[index];
        if (readFont(font, "arial.ttf")) text.setFont(font);
        text.setString("12"/*ofo::toTheString(this->list[index]->value)*/);
        text.setCharacterSize(unsigned(vertexSize / 2));
        text.setPosition(coo.x, coo.y);
        //text.setColor(color);
        window.draw(text);
    }
}