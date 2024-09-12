#pragma once
#include "object.hpp"

void doPlayerPhisics();

void drawPlayer(dsl::ctx8888& ctx);

class player{
    public:
        //objects
        object obj;//dsl::vector2D(2,-10),dsl::vector2D(24,24),dsl::fvector2D(0,0.3)
        //state
        bool onGround;
        bool right;
        bool isWalking;
        //icy thingies
        uint8_t icyThingies = 0;
        float icyThingiesTimer = 0;
        //animation
        uint8_t frame = 0;
        uint8_t frameCount = 0;
        uint8_t timer = 0;
        uint8_t speed = 5;
        dsl::vector2D* animation = nullptr;
        enum prev{
            non,idle,walk,airUP,airDown,laydown
        }previousAnimation;
        player(uint32_t x,uint32_t y);
        //phisics
        void doPhisics();
        //drawing
        void draw(dsl::ctx8888& ctx);
        void drawPlayer(dsl::ctx8888& ctx);
        void drawIcyThingies(dsl::ctx8888& ctx,bool top);
        void drawIcyThingi(dsl::vector2D pos,dsl::ctx8888& ctx);
        void drawAnimation(dsl::ctx8888& ctx);
        void doWalkParticle();
        //
};