#include <cmath>
#include <math.h>
#include <SFML/Graphics.hpp>

#ifndef DIS_H
#define DIS_H

float distance(sf::Vector2f a, sf::Vector2f b);

void rotateTowards(sf::RectangleShape &shape, sf::Vector2f cord);

sf::Vector2f midpoint(sf::Vector2f a, sf::Vector2f b);

#endif
