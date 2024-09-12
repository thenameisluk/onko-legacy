#include "object.hpp"
#include "gameData.hpp"
#include "light.hpp"
#include "player.hpp"
#include "map.hpp"
#include "calculations.hpp"
#include "helper.hpp"

using namespace dsl;

player::player(uint32_t x,uint32_t y):obj(dsl::vector2D(2,-10),dsl::vector2D(24,24),dsl::fvector2D(0,0.3)){
    
}

void player::doWalkParticle(){
    gamePartcleMenezer.addParticleContainer(20,[&](){
        uint8_t shade = rand()%100;
        float width = (float(rand()%70)/10.0f)-3.0f;
        float len = (float(rand()&20)/10.0f)+1.0f;
        return normalParticle(8,obj.pos+obj.size-vector2D(obj.size.x/2,0),vector2D(1,1),fvector2D(width,-angleAround(len,width))/3.0f,getRGB(150+shade,150+shade,150+shade));
    });
}

void player::doPhisics(){
    bool onGround = obj.touchTop;
    if(okno.isKeyDown('w')&&onGround){
        gamePartcleMenezer.addParticleContainer(40,[&](){
            uint8_t shade = rand()%100;
            float width = (float(rand()%70)/10.0f)-3.0f;
            float len = (float(rand()&20)/10.0f)+1.0f;
            return normalParticle(15,obj.pos+obj.size-vector2D(obj.size.x/2,0),vector2D(1,1),fvector2D(width,-angleAround(len,width))/3.0f,getRGB(150+shade,150+shade,150+shade));
        });
        obj.vel.y = -6;
    }
    isWalking = true;
    if(okno.isKeyDown('a')&&!okno.isKeyDown('d')){
        obj.pos.x -= 4;
        right = false;
        if(onGround)doWalkParticle();
    }else if(okno.isKeyDown('d')&&!okno.isKeyDown('a')){
        obj.pos.x += 4;
        right = true;
        if(onGround)doWalkParticle();
    }else isWalking = false;

    obj.newFrame();
    obj.update();
    vector2D playerTileCheckStart = (inTile(obj.pos)-vector2D(1,1));
    for(int32_t ix = 0;ix<3;ix++){
        for(int32_t iy = 0;iy<3;iy++){
            uint8_t tile = getTile(playerTileCheckStart+vector2D(ix,iy));
            if(tile!=0){
                obj.colide(boxColider(vector2D(playerTileCheckStart+vector2D(ix,iy))*scale,vector2D(scale,scale)));
            }
        }
    }
    
    if(obj.pos.y>700){
        obj.pos = vector2D(2,-10);
    }
}

uint32_t pSize = 12;

vector2D walkFramesOrder[] = {
    vector2D(2*pSize,2*pSize),
    vector2D(3*pSize,2*pSize),
    vector2D(4*pSize,2*pSize),
    vector2D(5*pSize,2*pSize),
    vector2D(2*pSize,3*pSize),
    vector2D(3*pSize,3*pSize),
    vector2D(4*pSize,3*pSize),
    vector2D(5*pSize,3*pSize),
};

vector2D idleFramesOrder[] = {
    vector2D(0*pSize,0*pSize),
    vector2D(1*pSize,0*pSize),
    vector2D(0*pSize,1*pSize),
    vector2D(1*pSize,1*pSize),
};

vector2D airUpFramesOrder[] = {
    vector2D(3*pSize,0*pSize),
    vector2D(4*pSize,0*pSize),
};

vector2D airDownFramesOrder[] = {
    vector2D(3*pSize,1*pSize),
    vector2D(4*pSize,1*pSize),
};





void player::drawAnimation(ctx8888& ctx){
    vector2D playerRelativePosition = relativeToCamera(obj.pos);
    ctx.drawSprite(playerRelativePosition,animation[frame],vector2D(12,12),onkoG,2,right,false);
    timer++;
    if(timer>speed){
        timer = 0;
        frame++;
    }
    if(frame>=frameCount){
        frame=0;
    }
}

void player::drawIcyThingi(vector2D pos,ctx8888& ctx){
    ctx.fillCircle(pos,2,getRGB(200,200,255));
    drawLight(pos,getRGB(100,100,255),4.0f,ctx);
}

void player::drawIcyThingies(ctx8888& ctx,bool top){
    vector2D playerRelativePosition = relativeToCamera(obj.pos);
    float dst = float(2*obj.size.x)/float(icyThingies);
    for(uint8_t i = 0;i<icyThingies;i++){
        float posX = int32_t((dst*float(i))+icyThingiesTimer)%(obj.size.x*2);
        if(posX<obj.size.x){
            if(top)
                drawIcyThingi(playerRelativePosition+vector2D(posX,obj.size.y/2)+vector2D(0,5),ctx);
        }else{
            if(!top)
                drawIcyThingi(playerRelativePosition+vector2D(obj.size.x-(posX-obj.size.x),obj.size.y/2)+vector2D(0,3),ctx);
        }
    }
    icyThingiesTimer+=0.2f;
    if(icyThingiesTimer>obj.size.x*2)icyThingiesTimer-=obj.size.x*2;
}

void player::draw(ctx8888& ctx){
    vector2D playerRelativePosition = relativeToCamera(obj.pos);

    drawIcyThingies(ctx,false);

    //drawLight(playerRelativePosition+(obj.size/2),getRGB(255,255,255),35.0f,ctx);

    if(!obj.touchTop){
        if(obj.vel.y<0){
            if(previousAnimation!=airUP){
                frame = 0;
                frameCount = 2;
                timer = 0;
                speed = 20;
                animation = airUpFramesOrder;
                previousAnimation = airUP;
            }
        }else{
            if(previousAnimation!=airDown){
                frame = 0;
                frameCount = 2;
                timer = 0;
                speed = 20;
                animation = airDownFramesOrder;
                previousAnimation = airDown;
            }
        }
    }else if(!isWalking){
        if(previousAnimation!=idle){
            frame = 0;
            frameCount = 4;
            timer = 0;
            speed = 20;
            animation = idleFramesOrder;
            previousAnimation = idle;
        }
    }else{
        if(previousAnimation!=walk){
            frame = 0;
            frameCount = 8;
            timer = 0;
            speed = 3;
            animation = walkFramesOrder;
            previousAnimation = walk;
        }
    }
    drawAnimation(ctx);

    drawIcyThingies(ctx,true);
    
    
}