#include "light.hpp"
#include "gameData.hpp"
#include "calculations.hpp"

using namespace dsl;

lightSource::lightSource(){
    color = getRGB(0,0,0);
    stregh = 0;
    radius = 0;
}

lightSource::lightSource(dsl::rgb color,uint8_t stregh,uint8_t radius){
    this->color = color;
    this->stregh = stregh;
    this->radius = radius;
}

lightSource& lightSource::operator=(int i){
    color = getRGB(0,0,0);
    stregh = 0;
    radius = 0;
    return *this;
};



void drawLight(vector2D pos,argb8888 color,float strengh,ctx8888& ctx){
    auto leColor = color.get();
    int32_t max = std::max(leColor.r,std::max(leColor.g,leColor.b));
    ctx.fillCircleAdvance(pos,strengh,[&](argb8888 col,float distance){
        auto now = col.get();
        auto apl = color.get();
        float tune = (distance/strengh)*max;
        if(apl.r)apl.r-=tune;
        if(apl.g)apl.g-=tune;
        if(apl.b)apl.b-=tune;
        apl.a = 0;

        if(!now.a)
            return argb8888((now.r>>1)+(apl.r>>1),((now.g>>1)+(apl.g>>1)),((now.b>>1)+(apl.b>>1)),0);//fix this?
        else
            return argb8888(now);
    });
}

void doLighting(ctxLight& lightMap,dsl::ctx8888& ctx){
}