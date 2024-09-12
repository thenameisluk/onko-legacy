#pragma once
#include <stdint.h>
#include <cmath>
#include "ctx.hpp"


class boxColider{
    public:
        dsl::vector2D pos;
        dsl::vector2D size;
        boxColider(){
            pos = dsl::vector2D(0,0);
            size = dsl::vector2D(1,1);
        }
        boxColider(dsl::vector2D pos,dsl::vector2D size){
            this->pos = pos;
            this->size = size;
        }
        bool colides(boxColider other){
            int32_t startX1 = this->pos.x;
            int32_t startY1 = this->pos.y;
            int32_t endX1 = this->pos.x + this->size.x;
            int32_t endY1 = this->pos.y + this->size.y;
            int32_t startX2 = other.pos.x;
            int32_t startY2 = other.pos.y;
            int32_t endX2 = other.pos.x + other.size.x;
            int32_t endY2 = other.pos.y + other.size.y;

            return (startX1<=endX2 && startY1<=endY2 && startX2 <= endX1 && startY2 <= endY1);
        }
        bool isInside(dsl::vector2D point){
            return point.x >= pos.x && point.x <= pos.x+size.x && point.y >= pos.y && point.y <= pos.y+size.y;
        }
};

class object{
    public:
        dsl::vector2D pos;
        dsl::fvector2D vel = dsl::fvector2D(0,0);
        dsl::fvector2D acc;
        dsl::vector2D size;
        float maxSpeedY = 14;
        float maxSpeedX = 14;
        bool touchTop;
        bool touchBottom;
        bool touchLeft;
        bool touchRigth;
    object(dsl::vector2D pos,dsl::vector2D size,dsl::fvector2D acc = dsl::fvector2D(0,0)){
        this->pos = pos;
        this->size = size;
        this->acc = acc;
    }
    void newFrame(){
        touchRigth = false;
        touchLeft = false;
        touchTop = false;
        touchBottom = false;
    }
    bool colide(boxColider box){
        if(box.colides(boxColider(pos,size))){
            //not going into walls
            int32_t left = pos.x+size.x - box.pos.x;
            int32_t top = pos.y+size.y - box.pos.y;
            int32_t right = box.pos.x+box.size.x - pos.x;
            int32_t bottom = box.pos.y+box.size.y - pos.y;
            int32_t lowest = std::min(std::min(left,right),std::min(top,bottom));

            if(lowest == left){
                pos.x = box.pos.x-size.x;
            }
            if(lowest == right){
                pos.x = box.pos.x+box.size.x;
            }
            if(lowest == top){
                pos.y = box.pos.y-size.y;
            }
            if(lowest == bottom){
                pos.y = box.pos.y+box.size.y;
            }

            //reseting velocity and touchtest
            if(pos.x+size.x == box.pos.x && !(pos.y+size.y == box.pos.y||pos.y == box.pos.y+box.size.y)){
                touchRigth = true;
                if(vel.x > 0)vel.x = 0;
            }
            if(pos.x == box.pos.x+box.size.x && !(pos.y+size.y == box.pos.y||pos.y == box.pos.y+box.size.y)){
                touchLeft = true;
                if(vel.x < 0)vel.x = 0;
            }
            if(pos.y+size.y == box.pos.y && !(pos.x+size.x == box.pos.x||pos.x == box.pos.x+box.size.x)){
                touchTop = true;
                if(vel.y > 0)vel.y = 0;
            }
            if(pos.y == box.pos.y+box.size.y && !(pos.x+size.x == box.pos.x||pos.x == box.pos.x+box.size.x)){
                touchBottom = true;
                if(vel.y < 0)vel.y = 0;
            }

            return true;
        }
        return false;
    }
    void update(){
        pos.x = pos.x + vel.x;
        pos.y = pos.y + vel.y;
        vel = vel + acc;
        vel.x = std::min(vel.x,maxSpeedX);
        vel.x = std::max(vel.x,-maxSpeedX);
        vel.y = std::min(vel.y,maxSpeedY);
        vel.y = std::max(vel.y,-maxSpeedY);
    }
};


