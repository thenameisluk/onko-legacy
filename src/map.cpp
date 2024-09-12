#include "gameData.hpp"
#include "object.hpp"
#include "map.hpp"
#include "calculations.hpp"
#include "gameData.hpp"

using namespace dsl;

void repositionWindow(){
    x += (zoz.obj.pos.x-x)/8;
    y += (zoz.obj.pos.y-y)/8;
    okno.move({x+offset-(windowWidth/2),y+offset-(windowHeight/2)});
}

map::map(uint32_t width,uint32_t height,uint8_t* data){
    mapWidth = width;
    mapHeight = height;
    this->data = data;
}

uint8_t getTile(int32_t x,int32_t y){
    if(x >= 0 && y >=0 && x < mapNow.mapWidth && y < mapNow.mapHeight){
        return mapNow.data[(y*mapNow.mapWidth)+x];
    }
    return 1;
}

uint8_t getTile(vector2D pos){
    return getTile(pos.x,pos.y);
}

vector2D inTile(vector2D pos){
    return vector2D(pos.x/scale,pos.y/scale);
}

void drawTileSide(ctx8888& ctx,vector2D tile,uint8_t side,argb8888 color){
    tile = tile*16;
    
    switch(side){
        case 0:
            //ctx.fillRect(relativeToCamera(tile),vector2D(,16),color);
            break;
        case 1:
            ctx.fillRect(relativeToCamera(tile),vector2D(scale,2),color);
            break;
        case 2:
            tile.y += scale-3;
            ctx.fillRect(relativeToCamera(tile),vector2D(scale,2),color);
            break;
        case 3:
            ctx.fillRect(relativeToCamera(tile),vector2D(2,scale),color);
            break;
        case 4:
            tile.x += scale-3;
            ctx.fillRect(relativeToCamera(tile),vector2D(2,scale),color);
            break;
    }
}

void drawTile(ctx8888& ctx,vector2D tile,vector2D pos){
    int8_t skip = scale-outline;
    if(getTile(tile)){
        //ctx.fillRect(pos,vector2D(scale,scale),getRGB(0,0,0));
        //border
        if(!getTile(tile+vector2D(1,0)))ctx.fillRect(pos+vector2D(skip,0),vector2D(outline,scale),getRGB(255,255,255));
        if(!getTile(tile+vector2D(-1,0)))ctx.fillRect(pos+vector2D(0,0),vector2D(outline,scale),getRGB(255,255,255));
        if(!getTile(tile+vector2D(0,1)))ctx.fillRect(pos+vector2D(0,skip),vector2D(scale,outline),getRGB(255,255,255));
        if(!getTile(tile+vector2D(0,-1)))ctx.fillRect(pos+vector2D(0,0),vector2D(scale,outline),getRGB(255,255,255));
        //corners
        if(!getTile(tile+vector2D(1,1)))ctx.fillRect(pos+vector2D(skip,skip),vector2D(outline,outline),getRGB(255,255,255));
        if(!getTile(tile+vector2D(-1,-1)))ctx.fillRect(pos+vector2D(0,0),vector2D(outline,outline),getRGB(255,255,255));
        if(!getTile(tile+vector2D(1,-1)))ctx.fillRect(pos+vector2D(skip,0),vector2D(outline,outline),getRGB(255,255,255));
        if(!getTile(tile+vector2D(-1,1)))ctx.fillRect(pos+vector2D(0,skip),vector2D(outline,outline),getRGB(255,255,255));
        
    }
}

void drawMap(ctx8888& ctx){
    vector2D camTopLeft = leftTopCameraCords();
    vector2D topLeftTile = inTile(camTopLeft)-vector2D(1,1);
    vector2D topLeftTilePos = relativeToCamera(topLeftTile*scale);
    int32_t tilesWidth = (windowWidth/scale)+3;
    int32_t tilesHeight = (windowHeight/scale)+3;
    for(int32_t iy = 0;iy<tilesHeight;iy++){
        for(int32_t ix = 0;ix<tilesWidth;ix++){
            drawTile(ctx,topLeftTile+vector2D(ix,iy),topLeftTilePos+vector2D(ix*scale,iy*scale));
        }
    }
}

bool colides(int32_t x,int32_t y,int32_t w,int32_t h,int32_t x2,int32_t y2,int32_t w2,int32_t h2){
    return x >= x2 && x <= x2+w2 && y >= y2 && y <= y2+h2;
}

bool colidesWithTile(int32_t x,int32_t y,int32_t w,int32_t h,int32_t tilex,int32_t tiley){
    return colides(x,y,w,h,tilex*scale,tiley*scale,scale,scale);
}
