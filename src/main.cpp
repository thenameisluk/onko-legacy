#include "simpleWindow.hpp"
#include "gameData.hpp"
#include "ray.hpp"
#include "object.hpp"
#include "data.hpp"
#include "player.hpp"
#include "map.hpp"
#include "helper.hpp"
#include "calculations.hpp"
#include "light.hpp"
#include "particle.hpp"
#include "math.hpp"
#include "background.hpp"
#include "helper.hpp"
#include "text.hpp"

using namespace dsl;

const int32_t windowWidth = 300;
const int32_t windowHeight = 300;

int32_t mousePosX = 0;
int32_t mousePosY = 0;

ray aim(vector2D(0,0),vector2D(0,0));


//map
int32_t x = 0, y = 0;
int32_t offset = 150;
//graphic
int32_t scale = 32;
uint8_t outline = 4;

simpleWindow okno(windowWidth,windowHeight,"onko",false,false,false);

ctxLight lightMap(windowWidth,windowHeight);
particleMenezer gamePartcleMenezer;

map mapNow(15,7,dmap);

player zoz(10,-10);

int main(){
    okno.setFrame([&](ctx8888& ctx){
        zoz.doPhisics();
        repositionWindow();
        ctx.fill(getARGB(0,0,0,0));
        drawBackground(ctx);
        doLighting(lightMap,ctx);
        gamePartcleMenezer.draw(ctx);
        drawMap(ctx);
        zoz.draw(ctx);
        drawText(ctx);
        if(okno.isKeyDown('q'))triggerText("hi my friend",[](){});
        drawDebugInfo(ctx);
    }).setMouseDown([](dsl::mousePos pos){
        int i = 0;
    }).setMouseMove([](dsl::mousePos mousePos){
        vector2D mousePosition  = leftTopCameraCords();
        mousePosX = mousePosition.x+mousePos.x;
        mousePosY = mousePosition.y+mousePos.y;
    });
    okno.wait();
}