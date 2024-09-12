#include "gameData.hpp"
#include "calculations.hpp"
#include "object.hpp"

using namespace dsl;

vector2D relativeToCamera(int32_t pointX,int32_t pointY){
    return vector2D(pointX-x+(offset),pointY-y+(offset));
}
vector2D relativeToCamera(vector2D pos){return relativeToCamera(pos.x,pos.y);};

vector2D leftTopCameraCords(){
    return vector2D(x-(offset),y-(offset));
}