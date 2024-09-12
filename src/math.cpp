#include "math.hpp"

using namespace dsl;

void drawMathFunction(ctx8888& ctx,vector2D pos,std::function<int32_t(int32_t)> f){
    int32_t size = 20;
    ctx.drawRect(pos.x,pos.y,(size*2)+1,(size*2)+1,getRGB(255,255,255));
    ctx.drawLineLeftRight(pos.x,pos.y+size,(size*2)+1,getRGB(255,255,255));
    ctx.drawLineUpDown(pos.x+size,pos.y,(size*2)+1,getRGB(255,255,255));
}