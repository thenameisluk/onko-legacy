#pragma once
#include "gameData.hpp"

dsl::vector2D relativeToCamera(int32_t pointX,int32_t pointY);
dsl::vector2D relativeToCamera(dsl::vector2D pos);
dsl::vector2D leftTopCameraCords();