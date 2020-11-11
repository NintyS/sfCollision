//
//  CollisionClass.hpp
//  Collision Library
//
//  Created by Emil Panecki on 11/11/2020.
//  Copyright © 2020 Emil Panecki. All rights reserved.
//

#ifndef CollisionClass_hpp
#define CollisionClass_hpp

#include <SFML/Graphics.hpp>

class Collision {
    
public:
    
    //Distance from sprite to sprite or point to point
    
    float Distance(sf::Sprite spriteOne, sf::Sprite spriteTwo);
    float Distance(float x1, float y1, float x2, float y2);
    
    //Collision between of two sprites
    
    void Square(sf::Sprite spriteOne, sf::Sprite spriteTwo, float range);
    void Circle(sf::Sprite spriteOne, sf::Sprite spriteTwo, float range);
    void Rectangle(sf::Sprite spriteOne, sf::Sprite spriteTwo, float rangeX, float rangeY);
    
    //Collision between point and sprite
    
    void Square(sf::IntRect point(), sf::Sprite sprite, float range);
    void Circle(sf::IntRect point(), sf::Sprite sprite, float range);
    void Rectangle(sf::IntRect point(), sf::Sprite sprite, float rangeX, float rangeY);
    
};

#endif /* CollisionClass_hpp */
