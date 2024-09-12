#pragma once
#include <stdint.h>
#include "player.hpp"
#include "simpleWindow.hpp"
#include "object.hpp"
#include "ray.hpp"
#include "particle.hpp"
#include "map.hpp"

inline uint8_t dmap[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

extern const int32_t windowWidth;
extern const int32_t windowHeight;

extern int32_t mousePosX;
extern int32_t mousePosY;

extern ray aim;

inline dsl::dataArray onkoGData("onkoG.pbs");
inline dsl::sprite onkoG(onkoGData);

inline dsl::dataArray cloudData("cloud.pbs");
inline dsl::sprite cloudr(cloudData);

//map
extern int32_t x,y;
extern int32_t offset;
//graphic
extern int32_t scale;
extern uint8_t outline;

//state
extern bool textBox;

inline enum sceeenState{
    menu,game,pause
} screenNow;



extern dsl::simpleWindow okno;
extern particleMenezer gamePartcleMenezer;

extern map mapNow;

extern player zoz;



