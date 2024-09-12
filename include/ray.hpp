#pragma once
#include <stdint.h>
#include "ctx.hpp"

inline dsl::fvector2D normalized(dsl::fvector2D v){
    float mag = std::sqrt(v.x * v.x + v.y * v.y);
    return { v.x / mag, v.y / mag };
}

struct line{
    dsl::vector2D start;
    dsl::vector2D end;
};


class ray{//a+x*b
    public:
        dsl::vector2D start;
        dsl::fvector2D direction;
        ray(dsl::vector2D start,dsl::vector2D end){
            this->start = start;
            this->direction = normalized(dsl::fvector2D(end.x-start.x,end.y-start.y));
        }
        line rayToLine(float length) {
            return {start,{start.x+int32_t(direction.x*length),start.y+int32_t(direction.y*length)}};
        }
        dsl::vector2D castToX(float x){
            return dsl::fvector2D{x,(((x-start.x)/direction.x)*direction.y)+start.y};
        }
        dsl::vector2D castToY(float y){
            return dsl::fvector2D{(((y-start.y)/direction.y)*direction.x)+start.x,y};
        }
        dsl::vector2D precisedCastToX(float x){
            return dsl::fvector2D{x,(((x-start.x)/direction.x)*direction.y)+start.y};
        }
        dsl::vector2D precisedCastToY(float y){
            return dsl::fvector2D{(((y-start.y)/direction.y)*direction.x)+start.x,y};
        }
};