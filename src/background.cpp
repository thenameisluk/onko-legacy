#include "background.hpp"
#include "gameData.hpp"
#include "helper.hpp"
#include "light.hpp"
#include "calculations.hpp"
#include <vector>

using namespace dsl;


const uint32_t screenW = 1920;
const uint32_t screenH = 1080;

float lightCycle = 0;

struct cloud{
    vector2D pos;
    int8_t seed;
    uint8_t size;
};

cloud clouds[10];

void drawClouds(dsl::ctx8888& ctx){
    for(int i=0;i<100;i++){
        drawLight(clouds[i].pos,getRGB(clouds[i].seed,clouds[i].seed,clouds[i].seed),clouds[i].size,ctx);
    }
}

void regenerateClouds(){
    rng random(time(0));
    for(int i=0;i<10;i++){
        clouds[i].pos.x = random.r(windowWidth);
        clouds[i].pos.y = random.r(windowHeight);
        clouds[i].seed = 255;
        clouds[i].size = random.r(10)+15;
    }
}
void incrementCycle(float howMuch){
    lightCycle += howMuch;
    while(lightCycle>24){
        lightCycle-=24;
    }
}

vector2D stars[1000];

void regenerateStars(){
    rng random(time(0));
    for(int i=0;i<1000;i++){
        stars[i].x = random.r(screenW);
        stars[i].y = random.r(screenH);
    }
}

void drawStars(dsl::ctx8888& ctx,float force){
    auto color = getRGB(255.0f*force,255.0f*force,255.0f*force);
    for(int i=0;i<1000;i++){
        ctx.fillRect(relativeToCamera(stars[i]),vector2D(2,2),color);
    }
}

exetuer regstars([](){
    regenerateStars();
    regenerateClouds();
    std::cout << "ok" << std::endl;
});

argb scaleColor(argb8888 color,float force){
    auto exp = color.get();
    exp.r = std::min(float(exp.r)*force,255.0f);
    exp.g = std::min(float(exp.g)*force,255.0f);
    exp.b = std::min(float(exp.b)*force,255.0f);
    return exp;
}
argb8888 combineColor(argb8888 colorA,argb8888 colorB,float forceA,float forceB){
    float forceCombine = forceA+forceB;
    auto scaledA = scaleColor(colorA,forceA/forceCombine);
    auto scaledB = scaleColor(colorB,forceB/forceCombine);
    return argb8888(scaledA.r+scaledB.r,scaledA.g+scaledB.g,scaledA.b+scaledB.b);

}
void drawSkyColor(dsl::ctx8888& ctx){
    //0 8 14 21
    argb8888 combination;
    argb8888 color0 = getRGB(0,0,0);
    argb8888 color6 = getRGB(50,0,0);
    argb8888 color14 = getRGB(40,40,255);
    argb8888 color22 = getRGB(50,0,0);
    bool day = true;
    float starForce;
    if(lightCycle<6){
        day = false;
        starForce = (6.0f-lightCycle)/6.0f;
        combination = combineColor(color0,color6,6.0f-lightCycle,lightCycle);
    }else if(lightCycle<14){
        combination = combineColor(color6,color14,14.0f-lightCycle,lightCycle-6.0f);
    }else if(lightCycle<22){
        combination = combineColor(color14,color22,22.0f-lightCycle,lightCycle-14.0f);
    }else{
        day = false;
        starForce = (lightCycle-22.0f)/2.0f;
        combination = combineColor(color22,color0,24.0f-lightCycle,lightCycle-22.0f);
    }
    
    auto prep = combination.get();
    prep.a = 0;
    ctx.fill(prep);
    if(!day){
      drawStars(ctx,starForce);  
    }
    drawClouds(ctx);
    
}

void drawBackground(dsl::ctx8888& ctx){
    drawSkyColor(ctx);
    incrementCycle(0.01f);
};
