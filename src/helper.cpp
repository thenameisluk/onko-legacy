#include "helper.hpp"
#include <cmath>
#include "gameData.hpp"

using namespace dsl;

#include <cmath>
#include <iostream>

float angleAround(float len,float width){
    return std::sqrt((len*len) - (width*width));
}

void drawDebugInfo(ctx8888& ctx){
    ctx.print(okno.getFps(),0,0,getRGB(255,255,255),5);
}