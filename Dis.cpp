#include <cmath>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>

float distance(sf::Vector2f a, sf::Vector2f b) {
    float dist = sqrt(((b.y - a.y) * (b.y - a.y)) + ((b.x - a.x) * (b.x - a.x)));
    //std::cout << "Distance:  " << dist << std::endl;
    return dist;
}

void rotateTowards(sf::RectangleShape &shape, sf::Vector2f cord) {
    sf::Vector2f shapePos = shape.getPosition();

    float angle = atan2(cord.y - shapePos.y, cord.x - shapePos.x) * 180 / 3.141;
    shape.setRotation(angle);

}

sf::Vector2f midpoint(sf::Vector2f a, sf::Vector2f b) {
    sf::Vector2f mid = sf::Vector2f((a.x + b.x) / 2, (a.y + b.y) / 2);
    return mid;
}


