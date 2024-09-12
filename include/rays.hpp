#pragma once
#include "object.hpp"
#include "gameData.hpp"

struct boxColision{
    dsl::vector2D box;
    dsl::vector2D position;
    int8_t side;
};

boxColision trowMyRay(ray r,dsl::ctx8888& ctx);

void drawPlayerMouseRay(dsl::ctx8888& ctx);