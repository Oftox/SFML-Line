#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <math.h>

#include "Dis.hpp"
#include "Dis.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 500), "Line");
    
    sf::CircleShape lineEndObj(3);
    lineEndObj.setFillColor(sf::Color::White);
    lineEndObj.setOrigin(1.5, 1.5);
    
    sf::CircleShape lineStartObj(3);
    lineStartObj.setFillColor(sf::Color::White);
    lineStartObj.setOrigin(1.5, 1.5);
    
    sf::Vector2f lineStart = sf::Vector2f(20.f, 20.f);
    sf::Vector2f lineEnd = sf::Vector2f(100.f, 100.f);
        
    float dist = distance(lineStart, lineEnd);
    
    sf::RectangleShape line(sf::Vector2f(dist, 5));
    line.setFillColor(sf::Color::Red);

    line.setOrigin(dist / 2, 5 / 2);
    
    line.setPosition(sf::Vector2f(dist / 2, dist / 2));
    rotateTowards(line, sf::Vector2f(100, 100));
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	    lineEnd.x -= 0.1;
	}  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
	    lineEnd.x += 0.1;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	    lineEnd.y -= 0.1;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
	    lineEnd.y += 0.1;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	    lineStart.x -= 0.1;
	}  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
	    lineStart.x += 0.1;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	    lineStart.y -= 0.1;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	    lineStart.y += 0.1;
	}    
        
        dist = distance(lineStart, lineEnd);
        line.setOrigin(dist / 2, 5 / 2);
        line.setPosition(sf::Vector2f(midpoint(lineStart, lineEnd)));        
        line.setSize(sf::Vector2f(dist, 5));                   
        rotateTowards(line, lineEnd);
                
        lineEndObj.setPosition(lineEnd);
        lineStartObj.setPosition(lineStart);

        window.clear();
        window.draw(line);
        window.draw(lineStartObj);
        window.draw(lineEndObj);
        window.display();
    }

    return 0;
}

