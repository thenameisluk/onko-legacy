#pragma once
#include "ctx.hpp"

void repositionWindow();

uint8_t getTile(int32_t x,int32_t y);

uint8_t getTile(dsl::vector2D pos);

dsl::vector2D inTile(dsl::vector2D pos);

void drawTileSide(dsl::ctx8888& ctx,dsl::vector2D tile,uint8_t side,dsl::argb8888 color = dsl::getRGB(0,255,0));

void drawTile(dsl::ctx8888& ctx,dsl::vector2D tile,dsl::vector2D pos);

void drawMap(dsl::ctx8888& ctx);

bool colides(int32_t x,int32_t y,int32_t w,int32_t h,int32_t x2,int32_t y2,int32_t w2,int32_t h2);

bool colidesWithTile(int32_t x,int32_t y,int32_t w,int32_t h,int32_t tilex,int32_t tiley);

class map
{
    public:
        int32_t mapWidth;
        int32_t mapHeight;
        uint8_t* data;
        map(uint32_t width,uint32_t height,uint8_t* data);
};