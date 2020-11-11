//
//  CollisionClass.cpp
//  Collision Library
//
//  Created by Emil Panecki on 11/11/2020.
//  Copyright © 2020 Emil Panecki. All rights reserved.
//

#include "CollisionClass.hpp"

float Collision::Distance(sf::Sprite spriteOne, sf::Sprite spriteTwo) {
    
    float x = pow((spriteTwo.getPosition().x - spriteOne.getPosition().x), 2.0);
    float y = pow((spriteTwo.getPosition().y - spriteOne.getPosition().y), 2.0);
    float distance = sqrt(x + y);
    
    return distance;
    
};

float Collision::Distance(float x1, float y1, float x2, float y2) {
    
    float x = pow((x2 - x1), 2.0);
    float y = pow((y2 - y1), 2.0);
    float distance = sqrt(x + y);
    
    return distance;
    
};

void Collision::Square(sf::Sprite spriteOne, sf::Sprite spriteTwo, float range) {
    
    if( ( Distance(spriteOne, spriteTwo) < range ) && ( spriteOne.getPosition().x > spriteTwo.getPosition().x ) ) {
        spriteOne.setPosition(spriteTwo.getPosition().x + range, spriteOne.getPosition().y );
        printf("debug: coll %f \n", spriteOne.getPosition().x);
    }
    
};
