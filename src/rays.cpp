#include "ray.hpp"
#include "calculations.hpp"
#include "gameData.hpp"
#include "rays.hpp"
#include "map.hpp"

using namespace dsl;


boxColision trowMyRay(ray r,ctx8888& ctx){
    boxColision col;

    vector2D camTopLeft = leftTopCameraCords();

    bool up = r.direction.y > 0;
    bool rigth = r.direction.x > 0;

    bool moreLeft = std::abs(r.direction.x) > std::abs(r.direction.y);

    fvector2D worldPosition = r.start+camTopLeft;

    r.start = worldPosition;
    
    vector2D in = inTile(worldPosition);

    col.side = 0;

    bool ver = 0;

    for(uint32_t i = 0;i<scale;i++){
        if(in.x<=-1||in.y<=-1||in.x>=mapNow.mapWidth||in.y>=mapNow.mapHeight)break;
        drawTileSide(ctx,in,0,getARGB(i*16,i*16,i*16));
        
        if(moreLeft){
            fvector2D tempPos = r.precisedCastToX((in.x*scale)+scale-((scale+2)*!rigth));
            vector2D tempIn = inTile(tempPos);
            if(std::abs(tempIn.y-in.y)>=1){
                tempPos = r.precisedCastToY((in.y*scale)+scale-((scale+2)*!up));
                tempIn = inTile(tempPos);
                worldPosition = tempPos;
                in = tempIn;
                ver = true;
            }else{
                worldPosition = tempPos;
                in = tempIn;
                ver = false;
            }
        }else{
            fvector2D tempPos = r.precisedCastToY((in.y*scale)+scale-((scale+2)*!up));
            vector2D tempIn = inTile(tempPos);
            if(std::abs(tempIn.x-in.x)>=1){
                tempPos = r.precisedCastToX((in.x*scale)+scale-((scale+2)*!rigth));
                tempIn = inTile(tempPos);
                worldPosition = tempPos;
                in = tempIn;
                ver = false;
            }else{
                worldPosition = tempPos;
                in = tempIn;
                ver = true;
            }
        }
        if(getTile(in.x,in.y)!=0){
            if(in.x>=mapNow.mapWidth||in.y>=mapNow.mapHeight)break;
            col.box = in;
            col.position = relativeToCamera(worldPosition);
            if(ver&&up)col.side = 1;
            if(ver&&!up)col.side = 2;
            if(!ver&&rigth)col.side = 3;
            if(!ver&&!rigth)col.side = 4;
            return col;
        }
        r.start = worldPosition;
    }
    
    col.side = 0;
    col.position = relativeToCamera(worldPosition);
    return col;
}

void drawPlayerMouseRay(ctx8888& ctx){
    vector2D playerRelativePosition = relativeToCamera(zoz.obj.pos);
    vector2D mousePosCalculeted = relativeToCamera(mousePosX,mousePosY);

    aim = ray(playerRelativePosition,mousePosCalculeted);

    auto trow = trowMyRay(aim,ctx);

    if(trow.side){
        drawTileSide(ctx,trow.box,trow.side);
    }

    vector2D borderIntersectionPosition = trow.position;

    ctx.drawLine(playerRelativePosition,borderIntersectionPosition,getRGB(0,0,255));
    
    if(!okno.isMouseDown())ctx.drawCircle(mousePosCalculeted.x,mousePosCalculeted.y,5,getRGB(255,0,0));
    else ctx.fillCircle(mousePosCalculeted.x,mousePosCalculeted.y,5,getRGB(255,0,0));
    
}