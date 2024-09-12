#pragma once
#include "ctx.hpp"
#include <functional>

void drawMathFunction(dsl::ctx8888& ctx,dsl::vector2D pos,std::function<int32_t(int32_t)> f);