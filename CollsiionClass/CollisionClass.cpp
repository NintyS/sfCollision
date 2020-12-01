//
//  CollisionClass.cpp
//  Collision Library
//
//  Created by Emil Panecki on 11/11/2020.
//  Copyright © 2020 Emil Panecki. All rights reserved.
//

#include "CollisionClass.hpp"

float Collision::Distance(sf::Sprite &spriteOne, sf::Sprite &spriteTwo) {
    
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

void Collision::Square(sf::Sprite &spriteOne, sf::Sprite &spriteTwo, float range) {
    
    if( ( Distance(spriteOne, spriteTwo) < range ) && ( spriteTwo.getPosition().x > spriteOne.getPosition().x + range/2 ) ) {
        spriteTwo.setPosition(spriteOne.getPosition().x + range, spriteTwo.getPosition().y );
        printf("Debug: Right %f \n", spriteOne.getPosition().x);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < range ) && ( spriteTwo.getPosition().x < spriteOne.getPosition().x - range/2 ) ) {
        spriteTwo.setPosition(spriteOne.getPosition().x - range, spriteTwo.getPosition().y );
        printf("Debug: Left %f \n", spriteOne.getPosition().x);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < range ) && ( spriteTwo.getPosition().y > spriteOne.getPosition().y + range/2 ) ) {
        spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y + range );
        printf("Debug: Bottom %f \n", spriteOne.getPosition().y);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < range ) && ( spriteTwo.getPosition().y < spriteOne.getPosition().y - range/2 ) ) {
        spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y - range );
        printf("Debug: Top %f \n", spriteOne.getPosition().y);
    }
    
};

void Collision::Square(sf::Vector2f &point, sf::Sprite &sprite, float range) {
  
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < range ) && ( sprite.getPosition().x > point.x + range/2 ) ) {
        sprite.setPosition(point.x + range, sprite.getPosition().y );
        printf("Debug: Right %f \n", sprite.getPosition().x);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < range ) && ( sprite.getPosition().x < point.x - range/2 ) ) {
        sprite.setPosition(point.x - range, sprite.getPosition().y );
        printf("Debug: Left %f \n", sprite.getPosition().x);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < range ) && ( sprite.getPosition().y > point.y + range/2 ) ) {
        sprite.setPosition(sprite.getPosition().x, point.y + range );
        printf("Debug: Bottom %f \n", sprite.getPosition().y);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < range ) && ( sprite.getPosition().y < point.y - range/2 ) ) {
        sprite.setPosition(sprite.getPosition().x, point.y - range );
        printf("Debug: Top %f \n", sprite.getPosition().y);
    }
    
};

void Collision::Circle(sf::Sprite &spriteOne, sf::Sprite &spriteTwo, float range) {
    
    sf::Vector2f position;
    
    if(Distance(spriteOne, spriteTwo) < range) {
        if( spriteTwo.getPosition().x > spriteOne.getPosition().x + range/2 ) {
            spriteTwo.setPosition(spriteOne.getPosition().x + range, spriteTwo.getPosition().y );
            printf("Debug: Right %f \n", spriteOne.getPosition().x);
        }
        
        if( spriteTwo.getPosition().x < spriteOne.getPosition().x - range/2 ) {
            spriteTwo.setPosition(spriteOne.getPosition().x - range, spriteTwo.getPosition().y );
            printf("Debug: Left %f \n", spriteOne.getPosition().x);
        }
        
        if( spriteTwo.getPosition().y > spriteOne.getPosition().y + range/2 ) {
            spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y + range );
            printf("Debug: Bottom %f \n", spriteOne.getPosition().y);
        }
        
        if( spriteTwo.getPosition().y < spriteOne.getPosition().y - range/2 ) {
            spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y - range );
            printf("Debug: Top %f \n", spriteOne.getPosition().y);
        }
        
    }
    
};

void Collision::Circle(sf::Vector2f &point, sf::Sprite &sprite, float range) {
    
    sf::Vector2f position;
    
    if(Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < range) {
        position = sprite.getPosition();
        sprite.setPosition(sprite.getPosition() - position);
    }
    
};

void Collision::Rectangle(sf::Sprite &spriteOne, sf::Sprite &spriteTwo, float rangeX, float rangeY) {
    
    if( ( Distance(spriteOne, spriteTwo) < rangeX ) && ( spriteTwo.getPosition().x > spriteOne.getPosition().x + rangeX/2 ) ) {
        spriteTwo.setPosition(spriteOne.getPosition().x + rangeX, spriteTwo.getPosition().y );
        printf("Debug: Right %f \n", spriteOne.getPosition().x);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < rangeX ) && ( spriteTwo.getPosition().x < spriteOne.getPosition().x - rangeX/2 ) ) {
        spriteTwo.setPosition(spriteOne.getPosition().x - rangeX, spriteTwo.getPosition().y );
        printf("Debug: Left %f \n", spriteOne.getPosition().x);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < rangeY ) && ( spriteTwo.getPosition().y > spriteOne.getPosition().y + rangeY/2 ) ) {
        spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y + rangeY );
        printf("Debug: Bottom %f \n", spriteOne.getPosition().y);
    }
    
    if( ( Distance(spriteOne, spriteTwo) < rangeY ) && ( spriteTwo.getPosition().y < spriteOne.getPosition().y - rangeY/2 ) ) {
        spriteTwo.setPosition(spriteTwo.getPosition().x, spriteOne.getPosition().y - rangeY );
        printf("Debug: Top %f \n", spriteOne.getPosition().y);
    }
    
};

void Collision::Rectangle(sf::Vector2f &point, sf::Sprite &sprite, float rangeX, float rangeY) {
  
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < rangeX ) && ( sprite.getPosition().x > point.x + rangeX/2 ) ) {
        sprite.setPosition(point.x + rangeX, sprite.getPosition().y );
        printf("Debug: Right %f \n", sprite.getPosition().x);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < rangeX ) && ( sprite.getPosition().x < point.x - rangeX/2 ) ) {
        sprite.setPosition(point.x - rangeX, sprite.getPosition().y );
        printf("Debug: Left %f \n", sprite.getPosition().x);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < rangeY ) && ( sprite.getPosition().y > point.y + rangeY/2 ) ) {
        sprite.setPosition(sprite.getPosition().x, point.y + rangeY );
        printf("Debug: Bottom %f \n", sprite.getPosition().y);
    }
    
    if( ( Distance(point.x, point.y, sprite.getPosition().x, sprite.getPosition().y) < rangeY ) && ( sprite.getPosition().y < point.y - rangeY/2 ) ) {
        sprite.setPosition(sprite.getPosition().x, point.y - rangeY );
        printf("Debug: Top %f \n", sprite.getPosition().y);
    }
    
};
