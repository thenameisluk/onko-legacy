/*
a great pice of code part of
dsl diffrent standard library
(wip as i write it so no links)

coded and delivered by L team
code by luk the oop programmer
debbugged by zoz the glaceon
(not really since he is just
pokemon in the game but we
can treat him as a rubber
duck right?)

it may break everything it touches
or something i dont know why
some people state that in their
comment thingies but yes

also no touch touch credits
without premission but if
you want you can modify code
itself so yes i hope it's
helpfull my guy and you
will be able to make great
things with it
*/

#pragma once

#include <stdint.h>
#include <functional>
#include <cmath>
#include <iostream> //can be removed

#include "data.hpp" //inny nagłówek dsl

// ascii

#pragma once
inline bool characters[][5][5] = {
    {{false, false, false, false, false}, // spacja
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, false, true, false, false}, //!
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, //"
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, true, false, true, false}, // #
     {true, true, true, true, true},
     {false, true, false, true, false},
     {true, true, true, true, true},
     {false, true, false, true, false}},

    {{false, true, true, true, false}, //$
     {true, false, true, false, false},
     {false, true, true, true, false},
     {false, false, true, false, true},
     {false, true, true, true, false}},

    {{true, false, false, false, true}, //%
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false},
     {true, false, false, false, true}},

    {{false, false, true, false, false}, //&
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, true, false, true, false},
     {false, false, true, false, true}},

    {{false, false, true, false, false}, //'
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, false, true, false, false}, //(
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, //)
     {false, false, false, true, false},
     {false, false, false, true, false},
     {false, false, false, true, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, //*
     {false, true, true, true, false},
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, false, false, false, false}, //+
     {false, false, true, false, false},
     {false, true, true, true, false},
     {false, false, true, false, false},
     {false, false, false, false, false}},

    {{false, false, false, false, false}, //,
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, false, false, false}, //-
     {false, false, false, false, false},
     {false, true, true, true, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, false, false, false, false}, //.
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false}},

    {{false, false, false, true, false}, ///
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, true, false, false, false}},

    {{false, false, true, false, false}, // 0
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // 1
     {false, true, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // 2
     {false, true, false, true, false},
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, true, true, true, false}},

    {{false, true, true, false, false}, // 3
     {false, false, false, true, false},
     {false, true, true, false, false},
     {false, false, false, true, false},
     {false, true, true, false, false}},

    {{false, false, false, true, false}, // 4
     {false, false, true, true, false},
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, false, false, true, false}},

    {{false, true, true, true, false}, // 5
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false},
     {false, true, true, false, false}},

    {{false, false, true, true, false}, // 6
     {false, true, false, false, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, true, true, false}, // 7
     {false, false, false, true, false},
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // 8
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // 9
     {false, true, false, true, false},
     {false, false, true, true, false},
     {false, false, false, true, false},
     {false, true, true, false, false}},

    {{false, false, false, false, false}, //:
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false},
     {false, false, false, false, false}},

    {{false, false, false, false, false}, //;
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, false, true, false}, //<
     {false, false, true, false, false},
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false}},

    {{false, false, false, false, false}, //=
     {false, true, true, true, false},
     {false, false, false, false, false},
     {false, true, true, true, false},
     {false, false, false, false, false}},

    {{false, false, false, true, false}, //>
     {false, false, true, false, false},
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false}},

    {{false, true, true, false, false}, //?
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, //@
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // a
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, true, false, false}, // b
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, true, false, false}},

    {{false, false, true, true, false}, // c
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, false, true, true, false}},

    {{false, true, true, false, false}, // d
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, false, false}},

    {{false, true, true, true, false}, // e
     {false, true, false, false, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, true, true, false}},

    {{false, true, true, true, false}, // f
     {false, true, false, false, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false}},

    {{false, false, true, true, false}, // g
     {false, true, false, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // h
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // i
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // j
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, true, false, false, false}},

    {{false, true, false, true, false}, // k
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // l
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, true, false}},

    {{false, true, false, true, false}, // m
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // n
     {false, true, true, true, false},
     {false, true, true, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // o
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, true, false, false}, // p
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false}},

    {{false, false, true, false, false}, // q
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, true, false}},

    {{false, true, true, false, false}, // r
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, true, false}, // s
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false},
     {false, true, true, false, false}},

    {{false, true, true, true, false}, // t
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // u
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, true, false}},

    {{false, true, false, true, false}, // v
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // w
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // x
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // y
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, true, true, true, false}, // z
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, true, false, false, false},
     {false, true, true, true, false}},

    {{false, true, true, false, false}, //[
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, true, true, false, false}},

    {{false, true, false, false, false}, //\-
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false}},

    {{false, false, true, true, false}, //]
     {false, false, false, true, false},
     {false, false, false, true, false},
     {false, false, false, true, false},
     {false, false, true, true, false}},

    {{false, false, true, false, false}, //^
     {false, true, false, true, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    {{false, false, false, false, false}, //_
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, true, true, true, false}},

    {{false, true, false, false, false}, //`
     {false, false, true, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},

    // repeat for small letters

    {{false, false, true, false, false}, // a
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, true, false, false}, // b
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, true, false, false}},

    {{false, false, true, true, false}, // c
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false},
     {false, false, true, true, false}},

    {{false, true, true, false, false}, // d
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, false, false}},

    {{false, true, true, true, false}, // e
     {false, true, false, false, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, true, true, false}},

    {{false, true, true, true, false}, // f
     {false, true, false, false, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false}},

    {{false, false, true, true, false}, // g
     {false, true, false, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // h
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // i
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, false, true, false, false}, // j
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, true, false, false, false}},

    {{false, true, false, true, false}, // k
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // l
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, true, false}},

    {{false, true, false, true, false}, // m
     {false, true, true, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // n
     {false, true, true, true, false},
     {false, true, true, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false}},

    {{false, false, true, false, false}, // o
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, true, false, false}, // p
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, false, false},
     {false, true, false, false, false}},

    {{false, false, true, false, false}, // q
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, true, false}},

    {{false, true, true, false, false}, // r
     {false, true, false, true, false},
     {false, true, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, false, true, true, false}, // s
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, false, false, true, false},
     {false, true, true, false, false}},

    {{false, true, true, true, false}, // t
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // u
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, true, false}},

    {{false, true, false, true, false}, // v
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, // w
     {false, true, false, true, false},
     {false, true, false, true, false},
     {false, true, true, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // x
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, true, false, true, false},
     {false, true, false, true, false}},

    {{false, true, false, true, false}, // y
     {false, true, false, true, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false}},

    {{false, true, true, true, false}, // z
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, true, false, false, false},
     {false, true, true, true, false}},

    {{false, false, true, false, false}, //{
     {false, true, false, false, false},
     {false, false, true, false, false},
     {false, true, false, false, false},
     {false, false, true, false, false}},

    {{false, false, false, false, false}, //|
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, true, false, false},
     {false, false, false, false, false}},

    {{false, false, true, false, false}, //}
     {false, false, false, true, false},
     {false, false, true, false, false},
     {false, false, false, true, false},
     {false, false, true, false, false}},

    {{false, true, false, true, false}, //~
     {false, false, true, false, true},
     {false, false, false, false, false},
     {false, false, false, false, false},
     {false, false, false, false, false}},
};

// declaration
typedef std::function<void(int32_t, int32_t)> pointAction;

namespace dsl
{
    struct rgb
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };
    struct argb
    {
        uint8_t a;
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };
    class rgb565
    {
    public:
        uint16_t color;
        rgb565(){
            color = 0;
        }
        rgb565(uint16_t rgb) : color(rgb){};
        rgb565(uint32_t argb)
        {
            set((argb >> 16) & 0xFF, (argb >> 8) & 0xFF, argb & 0xFF);
        }
        rgb565(uint8_t r, uint8_t g, uint8_t b)
        {
            set(r, g, b);
        }
        rgb565(rgb c)
        {
            set(c.r, c.g, c.b);
        }
        rgb565(argb c)
        {
            set(c.r, c.g, c.b);
        }
        void set(uint8_t r, uint8_t g, uint8_t b)
        {
            color = 0;
            color |= r >> 3;
            color <<= 6;
            color |= g >> 2;
            color <<= 5;
            color |= b >> 3;
        }
        rgb get()
        {
            return rgb{uint8_t((color & 0x1F) << 3), uint8_t(((color >> 5) & 0x3F) << 2), uint8_t(((color >> 11) & 0x1F) << 3)};
        }
        uint16_t operator()()
        {
            return color;
        }
    };
    class argb8888
    {
    public:
        uint32_t color;
        argb8888(){
            color = 0;
        }
        // argb8888(uint16_t rgb)
        // {
        //     set(uint8_t((color & 0x1F) << 3), uint8_t(((color >> 5) & 0x3F) << 2), uint8_t(((color >> 11) & 0x1F) << 3));
        // };
        argb8888(uint32_t argb) : color(argb){};
        argb8888(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        {
            set(r, g, b, a);
        }
        argb8888(rgb c)
        {
            set(c.r, c.g, c.b);
        }
        argb8888(argb c)
        {
            set(c.r, c.g, c.b, c.a);
        }
        void set(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        {
            color = 0;
            color |= a;
            color <<= 8;
            color |= r;
            color <<= 8;
            color |= g;
            color <<= 8;
            color |= b;
        }
        argb get()
        {
            return argb{uint8_t((color >> 24) & 0xFF), uint8_t((color >> 16) & 0xFF), uint8_t((color >> 8) & 0xFF), uint8_t(color & 0xFF)};
        }
        uint32_t operator()()
        {
            return color;
        }
        void operator=(uint32_t argb){
            color = argb;
        }
        void operator=(argb8888 argb){
            color = argb.color;
        }
        bool operator==(argb8888 argb){
            return color == argb.color;
        }
        bool operator==(uint32_t argb){
            return color == argb;
        }
    };
    class fvector2D;

    class vector2D{
        public:
            int32_t x;
            int32_t y;
            vector2D();
            vector2D(int32_t x,int32_t y);
            vector2D(fvector2D v);
            vector2D operator+(vector2D v);
            vector2D operator-(vector2D v);
            vector2D operator*(int32_t v);
            vector2D operator/(int32_t v);
            vector2D operator*(vector2D v);
            vector2D operator/(vector2D v);
            float distance(vector2D v);
    };

    class fvector2D{
        public:
            float x;
            float y;
            fvector2D();
            fvector2D(float x,float y);
            fvector2D(vector2D v);
            fvector2D operator+(fvector2D v);
            fvector2D operator-(fvector2D v);
            fvector2D operator*(int32_t v);
            fvector2D operator/(int32_t v);
            float distance(fvector2D v);
    };

    inline vector2D::vector2D(fvector2D v){
        x = v.x;
        y = v.y;
    }

    inline constexpr argb getARGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
    {
        return {a, r, g, b};
    }
    inline constexpr rgb getRGB(uint8_t r, uint8_t g, uint8_t b)
    {
        return {r, g, b};
    }
    class symbol{
        //to-do
    };
    class image{
        //to-do
    };
    class sprite{
            uint32_t width;
            uint32_t height;
            argb8888 pallet[15] = {0};
            uint8_t* data;
        public:
            sprite(uint32_t width,uint32_t height);
            sprite(dataArray& data);
            sprite(sprite& other);
            ~sprite();
            void resize(uint32_t width, uint32_t height);
            uint32_t getWidth();
            uint32_t getHeight();
            argb8888 getColor(uint8_t id);
            void setColor(uint8_t id,argb8888 color);
            uint8_t getPixelColorId(uint32_t x,uint32_t y);
            argb8888 getPixelColor(uint32_t x,uint32_t y);
            void draw(int32_t x,int32_t y,uint8_t colorID);
            dataArray expot(bool rle);
    };

    template <typename color>
    class ctxTemplate
    {
        uint32_t height;
        uint32_t width;
        color *img;
        constexpr bool isInside(uint32_t x, uint32_t y);//not safety checks
        constexpr color& point(uint32_t x, uint32_t y);//not safety checks
    public:
        ctxTemplate(int width, int height);
        ctxTemplate(ctxTemplate<color> &cp);
        ~ctxTemplate();
        // get data
        color* getData();
        
        uint32_t getHeight();
        uint32_t getWidth();
        // size manipulation
        void resize(int32_t width, int32_t height);
        // entier screen
        void fill(color c);
        // points
        void drawPoint(int32_t x, int32_t y, color c);
        void drawPoint(vector2D pos, color c);
        // rectangles
        void fillRect(int32_t x, int32_t y, uint32_t w, uint32_t h, color c);
        void fillRect(vector2D pos, vector2D size, color c);
        void drawRect(int32_t x, int32_t y, uint32_t w, uint32_t h, color c);
        void drawRect(vector2D pos, vector2D size, color c);
        // circle
        void drawCircle(int32_t x, int32_t y, uint32_t radius, color c);
        void drawCircle(vector2D pos, uint32_t radius, color c);
        void fillCircle(int32_t x, int32_t y, uint32_t radius, color c);
        void fillCircle(vector2D pos, uint32_t radius, color c);
        // lines
        void drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color c);
        void drawLine(vector2D pos1, vector2D pos2, color c);
        void drawLineThick(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t scale, color c);
        void drawLineThick(vector2D pos1, vector2D pos2, uint32_t scale, color c);
        void drawLineUpDown(int32_t x, int32_t y, int32_t l, color c);
        void drawLineLeftRight(int32_t x, int32_t y, int32_t l, color c);
        // other ctx
        void drawCtx(int32_t x, int32_t y, ctxTemplate<color> &context,uint8_t scale = 1);
        void drawCtx(vector2D pos, ctxTemplate<color> &context,uint8_t scale = 1);
        // triangle
        void drawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, color c);
        void drawTriangle(vector2D pos1, vector2D pos2, vector2D pos3, color c);
        void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, color c);
        void fillTriangle(vector2D pos1, vector2D pos2, vector2D pos3, color c);
        // symbols
        void drawSymbol(int32_t x, int32_t y, symbol& sym, color c, uint32_t scale,bool leftRightFlip = false,bool upDownflip = false);
        void drawSymbol(vector2D pos,symbol& sym, color c, uint32_t scale,bool leftRightFlip = false,bool upDownflip = false);
        // sprites
        void drawSprite(int32_t x, int32_t y, sprite& spr, uint32_t scale = 1,bool leftRightFlip = false,bool upDownFlip = false);
        void drawSprite(vector2D pos,sprite& spr, uint32_t scale = 1,bool leftRightFlip = false,bool upDownFlip = false);
        void drawSprite(int32_t destX,int32_t destY,int32_t formX,int32_t formY,uint32_t width,uint32_t height,sprite& spr,uint32_t scale = 1,bool leftRightFlip = false,bool upDownFlip = false);
        void drawSprite(vector2D pos,vector2D from,vector2D size,sprite& spr, uint32_t scale = 1,bool leftRightFlip = false,bool upDownFlip = false);
        // letters
        void drawLetter(char ch, int32_t x, int32_t y, color c, int32_t scale = 1);
        void drawLetter(char ch, vector2D pos, color c, int32_t scale = 1);
        void print(const char *text, int32_t x, int32_t y, color c, uint32_t scale = 1);
        void print(const char *text, vector2D pos, color c, uint32_t scale = 1);
        void print(int32_t number, int32_t x, int32_t y, color c, uint32_t scale = 1);
        void print(int32_t number, vector2D pos, color c, uint32_t scale = 1);
        //advanced
        //Circel
        void fillCircleAdvance(int32_t x, int32_t y, uint32_t radius,std::function<color(color,float)> f);
        void fillCircleAdvance(vector2D pos, uint32_t radius,std::function<color(color,float)>f);
        void fillCircleAdvance(int32_t x, int32_t y, uint32_t radius,std::function<color(color)> f);
        void fillCircleAdvance(vector2D pos, uint32_t radius,std::function<color(color)>f);
        //RoundRect
        void fillRoundedRectAdvance(int32_t x, int32_t y, uint32_t w, uint32_t h,uint32_t r,std::function<color(color)> f);//to-implement
        void fillRoundedRectAdvance(vector2D pos, vector2D size, uint32_t r,std::function<color(color)> f);//to-implement
        void fillRoundedRectAdvance(int32_t x, int32_t y, uint32_t w, uint32_t h,uint32_t r,std::function<color(color,float)> f);//to-implement
        void fillRoundedRectAdvance(vector2D pos, vector2D size, uint32_t r,std::function<color(color,float)> f);//to-implement
    private:
        // helpfull
        void drawTwistLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, pointAction function);
        void mirrorDrawPoint(int32_t x, int32_t y, uint32_t ox, uint32_t oy, color c);
    };
    typedef ctxTemplate<rgb565> ctx565;
    typedef ctxTemplate<argb8888> ctx8888;
}

// definition

#define swap_int(a, b) \
    {                  \
        int32_t t;     \
        t = a;         \
        a = b;         \
        b = t;         \
    }


inline dsl::vector2D::vector2D(){
    x = 0;
    y = 0;
}
inline dsl::vector2D::vector2D(int32_t x,int32_t y){
    this->x = x;
    this->y = y;
}
inline dsl::vector2D dsl::vector2D::operator+(vector2D v){
    return vector2D(x+v.x,y+v.y);
}
inline dsl::vector2D dsl::vector2D::operator-(vector2D v){
    return vector2D(x-v.x,y-v.y);
}
inline dsl::vector2D dsl::vector2D::operator*(int32_t v){
    return vector2D(x*v,y*v);
}
inline dsl::vector2D dsl::vector2D::operator/(int32_t v){
    return vector2D(x/v,y/v);
}
inline dsl::vector2D dsl::vector2D::operator*(vector2D v){
    return vector2D(x*v.x,y*v.y);
}
inline dsl::vector2D dsl::vector2D::operator/(vector2D v){
    return vector2D(x/v.x,y/v.y);
}
inline float dsl::vector2D::distance(vector2D v){
    return sqrt(pow(x-v.x,2)+pow(y-v.y,2));
}

inline dsl::fvector2D::fvector2D(){
    x = 0;
    y = 0;
}
inline dsl::fvector2D::fvector2D(float x,float y){
    this->x = x;
    this->y = y;
}
inline dsl::fvector2D::fvector2D(vector2D v){
    x = v.x;
    y = v.y;
}
inline dsl::fvector2D dsl::fvector2D::operator+(fvector2D v){
    return fvector2D(x+v.x,y+v.y);
}
inline dsl::fvector2D dsl::fvector2D::operator-(fvector2D v){
    return fvector2D(x-v.x,y-v.y);
}
inline dsl::fvector2D dsl::fvector2D::operator*(int32_t v){
    return fvector2D(x*v,y*v);
}
inline dsl::fvector2D dsl::fvector2D::operator/(int32_t v){
    return fvector2D(x/v,y/v);
}
inline float dsl::fvector2D::distance(fvector2D v){
    return sqrt(pow(x-v.x,2)+pow(y-v.y,2));
}

inline dsl::sprite::sprite(uint32_t width,uint32_t height){
    this->width = width;
    this->height = height;
    data = new uint8_t[width*height];
    for(uint32_t i=0;i<width*height;i++){
        data[i] = 0;
    }
    for(uint32_t i=0;i<15;i++){
        pallet[i] = 0;
    }
};
inline dsl::sprite::sprite(dataArray& data){
    PbView view(data);
    this->width = view.readStatic(32);
    this->height = view.readStatic(32);
    this->data = new uint8_t[width*height];
    for(uint32_t i = 0;i<15;i++){
        this->pallet[i] = view.readStatic(32);
    }
    for(uint32_t i = 0;i<width*height;i++){
        this->data[i] = view.readStatic(4);
    }
};
inline dsl::sprite::sprite(sprite& other){
    this->width = other.width;
    this->height = other.height;
    data = new uint8_t[width*height];
    for(uint32_t i=0;i<width*height;i++){
        data[i] = other.data[i];
    }
    for(uint32_t i=0;i<15;i++){
        pallet[i] = other.pallet[i];
    }
};
inline dsl::sprite::~sprite(){
    delete[] data;
};
inline void dsl::sprite::resize(uint32_t width, uint32_t height){
    this->width = width;
    this->height = height;
    delete[] data;
    data = new uint8_t[width*height];
    for(uint32_t i=0;i<width*height;i++){
        data[i] = 0;//to-do copy data form old one
    }
};
inline uint32_t dsl::sprite::getWidth(){
    return width;
};
inline uint32_t dsl::sprite::getHeight(){
    return height;
};
inline dsl::argb8888 dsl::sprite::getColor(uint8_t id){
    if(!id||id>15){
        return 0;
    }
    return pallet[id-1].color;
};
inline void dsl::sprite::setColor(uint8_t id,argb8888 color){
    if(!id||id>15){
        return;
    }
    pallet[id-1] = color;
};
inline uint8_t dsl::sprite::getPixelColorId(uint32_t x,uint32_t y){
    if(x<0||x>=width||y<0||y>=height){
        return 0;
    }
    return data[x+y*width];
};
inline dsl::argb8888 dsl::sprite::getPixelColor(uint32_t x,uint32_t y){
    return getColor(getPixelColorId(x,y));
};
inline void dsl::sprite::draw(int32_t x,int32_t y,uint8_t colorID){
    if(x<0||x>=width||y<0||y>=height){
        return;
    }
    data[x+y*width] = colorID;
};
inline dsl::dataArray dsl::sprite::expot(bool rle){//to-do rle
    PbWriter writer;
    writer.writeStatic(width,32);
    writer.writeStatic(height,32);
    for(uint32_t i = 0;i<15;i++){
        writer.writeStatic(pallet[i].color,32);
    }
    for(uint32_t i=0;i<width*height;i++){
        writer.writeStatic(data[i],4);
    }
    return writer.exportData();
};

template <typename color>
inline void dsl::ctxTemplate<color>::drawPoint(vector2D pos, color c){drawPoint(pos.x, pos.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::fillRect(vector2D pos, vector2D size, color c){fillRect(pos.x, pos.y, size.x, size.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawRect(vector2D pos, vector2D size, color c){drawRect(pos.x, pos.y, size.x, size.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawCircle(vector2D pos, uint32_t radius, color c){drawCircle(pos.x, pos.y, radius, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircle(vector2D pos, uint32_t radius, color c){fillCircle(pos.x, pos.y, radius, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLine(vector2D pos1, vector2D pos2, color c){drawLine(pos1.x, pos1.y, pos2.x, pos2.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLineThick(vector2D pos1, vector2D pos2, uint32_t scale, color c){drawLineThick(pos1.x, pos1.y, pos2.x, pos2.y, scale, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawTriangle(vector2D pos1, vector2D pos2, vector2D pos3, color c){drawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::fillTriangle(vector2D pos1, vector2D pos2, vector2D pos3, color c){fillTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y, c);};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLetter(char ch, vector2D pos, color c, int32_t scale){drawLetter(ch, pos.x, pos.y, c, scale);};
template <typename color>
inline void dsl::ctxTemplate<color>::print(const char *text, vector2D pos, color c, uint32_t scale){print(text, pos.x, pos.y, c, scale);};
template <typename color>
inline void dsl::ctxTemplate<color>::print(int32_t number, vector2D pos, color c, uint32_t scale){print(number, pos.x, pos.y, c, scale);};
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircleAdvance(vector2D pos, uint32_t radius,std::function<color(color,float)>f){fillCircleAdvance(pos.x, pos.y, radius,f);};
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircleAdvance(vector2D pos, uint32_t radius,std::function<color(color)>f){fillCircleAdvance(pos.x, pos.y, radius,f);};

template <typename color>
inline constexpr bool dsl::ctxTemplate<color>::isInside(uint32_t x,uint32_t y){
    return (x < width &&y < height);
}

template <typename color>
inline constexpr color& dsl::ctxTemplate<color>::point(uint32_t x,uint32_t y){
    return img[x + width * y];
};


template <typename color>
inline dsl::ctxTemplate<color>::ctxTemplate(int width, int height) : height(height), width(width)
{

    img = new color[height * width];
    for (int32_t i = 0; i < width * height; i++)
    {
        img[i] = 0;
    }
}
template <typename color>
inline dsl::ctxTemplate<color>::ctxTemplate(ctxTemplate &cp)
{
    height = cp.height;
    width = cp.width;
    img = new color[height * width];
    for (int32_t i = 0; i < width * height; i++)
    {
        img[i] = cp.img[i];
    }
}
template <typename color>
inline dsl::ctxTemplate<color>::~ctxTemplate()
{
    delete [] img;
}
template <typename color>
inline color* dsl::ctxTemplate<color>::getData(){
    return img;
}
template <typename color>
inline uint32_t dsl::ctxTemplate<color>::getHeight(){
    return height;
}
template <typename color>
uint32_t dsl::ctxTemplate<color>::getWidth(){
    return width;
}
template <typename color>
inline void dsl::ctxTemplate<color>::resize(int32_t width, int32_t height){
    this->width = width;
    this->height = height;
    delete [] img;
    img = new color[height * width];
}
template <typename color>
inline void dsl::ctxTemplate<color>::fillRect(int32_t x, int32_t y, uint32_t w, uint32_t h, color c)
{
    for (int32_t ix = 0; ix < (int32_t)w; ix++)
    {
        for (int32_t iy = 0; iy < (int32_t)h; iy++)
        {
            drawPoint(x + ix, y + iy, c); // maybe faster
        }
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawRect(int32_t x, int32_t y, uint32_t w, uint32_t h, color c)
{
    for (int32_t i = 0; i < w; i++)
    {
        drawPoint(x + i, y, c);
        drawPoint(x + i, y + h - 1, c);
    }
    for (int32_t i = 0; i < h; i++)
    {
        drawPoint(x, y + i, c);
        drawPoint(x + w - 1, y + i, c);
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::fill(color c)
{
    for (uint32_t i = 0; (int32_t)i < (int32_t)height * (int32_t)width; i++)
    {
        img[i] = c;
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawPoint(int32_t x, int32_t y, color c)
{
    if (x >= width || x < 0 || y >= height || y < 0)
        return;
    img[x + width * y] = c;
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color c)
{
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    if (abs(dx) < abs(dy))
    {
        if (x1 > x2)
        {
            swap_int(x1, x2);
            swap_int(y1, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;
        if (dy > 0)
        {
            for (int32_t i = 0; i < dy; i++)
            {
                float p = ((float)i / (float)dy) * (float)dx;
                drawPoint(x1 + p, y1 + i, c);
            }
        }
        else
        {
            dy = abs(dy);
            for (int32_t i = 0; i < dy; i++)
            {
                float p = ((float)i / (float)dy) * (float)dx;
                drawPoint(x1 + p, y1 - i, c);
            }
        }
    }
    else
    {
        if (y1 > y2)
        {
            swap_int(x1, x2);
            swap_int(y1, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;
        if (dx > 0)
        {
            for (int32_t i = 0; i < dx; i++)
            {
                float p = ((float)i / (float)dx) * (float)dy;
                drawPoint(x1 + i, y1 + p, c);
            }
        }
        else
        {
            dx = abs(dx);
            for (int32_t i = 0; i < dx; i++)
            {
                float p = ((float)i / (float)dx) * (float)dy;
                drawPoint(x1 - i, y1 + p, c);
            }
        }
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, color c)
{
    drawLine(x1, y1, x2, y2, c);
    drawLine(x2, y2, x3, y3, c);
    drawLine(x3, y3, x1, y1, c);
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawTwistLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, pointAction function)
{
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    if (abs(dx) < abs(dy))
    {
        if (x1 > x2)
        {
            swap_int(x1, x2);
            swap_int(y1, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;
        if (dy > 0)
        {
            for (int32_t i = 0; i < dy; i++)
            {
                float p = ((float)i / (float)dy) * (float)dx;
                function(*this, x1 + p, y1 + i);
            }
        }
        else
        {
            dy = abs(dy);
            for (int32_t i = 0; i < dy; i++)
            {
                float p = ((float)i / (float)dy) * (float)dx;
                function(*this, x1 + p, y1 + i);
            }
        }
    }
    else
    {
        if (y1 > y2)
        {
            swap_int(x1, x2);
            swap_int(y1, y2);
        }
        dx = x2 - x1;
        dy = y2 - y1;
        if (dx > 0)
        {
            for (int32_t i = 0; i < dx; i++)
            {
                float p = ((float)i / (float)dx) * (float)dy;
                function(*this, x1 + i, y1 + p);
            }
        }
        else
        {
            dx = abs(dx);
            for (int32_t i = 0; i < dx; i++)
            {
                float p = ((float)i / (float)dx) * (float)dy;
                function(*this, x1 + i, y1 + p);
            }
        }
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawCircle(int32_t x, int32_t y, uint32_t radius, color c)
{
    float len = 0;
    for (int32_t i = 0; i < radius; i++)
    {
        len = sqrt((float(radius) * float(radius)) - (float(i) * float(i)));
        mirrorDrawPoint(x, y, i, len, c);
        mirrorDrawPoint(x, y, len, i, c);
        if (i == len)
            return;
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::mirrorDrawPoint(int32_t x, int32_t y, uint32_t ox, uint32_t oy, color c)
{
    drawPoint(x + ox, y + oy, c);
    drawPoint(x + ox, y - oy, c);
    drawPoint(x - ox, y - oy, c);
    drawPoint(x - ox, y + oy, c);
}
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircle(int32_t x, int32_t y, uint32_t radius, color c)
{
    auto mirroFunction = [&](int32_t x,int32_t y,int32_t ox,int32_t oy){
        if(isInside(x + ox, y + oy))
            point(x + ox, y + oy) = c;
        if(isInside(x + ox, y - oy))
            point(x + ox, y - oy) = c;
        if(isInside(x - ox, y - oy))
            point(x - ox, y - oy) = c;
        if(isInside(x - ox, y + oy))
            point(x - ox, y + oy) = c;
    };

    if(isInside(x, y))
            point(x, y) = c;

    float len = 0;
    for (int32_t i = 1; i < radius; i++)
    {
        len = sqrt((float(radius) * float(radius)) - (float(i) * float(i)));
        for (int32_t j = 1; j < len; j++)
        {   
            if(i==j)break;

            mirroFunction(x, y, i, j);
            mirroFunction(x, y, j, i);

        }
        if (i == len)
            break;
    }

    float skos = sqrt((float(radius) * float(radius))/2);
    
    for(int32_t i = 1; i < skos; i++){//skos
        mirroFunction(x, y, i, i);
    }

    for (int32_t i = 1; i < radius; i++){//pion/poziom
        if(isInside(x+i,y))
            point(x+i,y) = c;
        if(isInside(x-i,y))
            point(x-i,y) = c;
        if(isInside(x,y+i))
            point(x,y+i) = c;
        if(isInside(x,y-i))
            point(x,y-i) = c;
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircleAdvance(int32_t x, int32_t y, uint32_t radius,std::function<color(color,float)> f){
    auto mirroFunction = [&](int32_t x,int32_t y,int32_t ox,int32_t oy,float distance){
        if(isInside(x + ox, y + oy))
            point(x + ox, y + oy) = f(point(x + ox, y + oy), distance);
        if(isInside(x + ox, y - oy))
            point(x + ox, y - oy) = f(point(x + ox, y - oy), distance);
        if(isInside(x - ox, y - oy))
            point(x - ox, y - oy) = f(point(x - ox, y - oy), distance);
        if(isInside(x - ox, y + oy))
            point(x - ox, y + oy) = f(point(x - ox, y + oy), distance);
    };

    if(isInside(x, y))
            point(x, y) = f(point(x, y), 0);

    float len = 0;
    for (int32_t i = 1; i < radius; i++)
    {
        len = sqrt((float(radius) * float(radius)) - (float(i) * float(i)));
        for (int32_t j = 1; j < len; j++)
        {   
            if(i==j)break;
            float distance = sqrt((float(j) * float(j)) + (float(i) * float(i)));

            mirroFunction(x, y, i, j, distance);
            mirroFunction(x, y, j, i, distance);

        }
        if (i == len)
            break;
    }

    float skos = sqrt((float(radius) * float(radius))/2);
    float distance = sqrt(2);
    
    for(int32_t i = 1; i < skos; i++){//skos
        mirroFunction(x, y, i, i, distance*i);
    }

    for (int32_t i = 1; i < radius; i++){//pion/poziom
        if(isInside(x+i,y))
            point(x+i,y) = f(point(x+i, y),i);
        if(isInside(x-i,y))
            point(x-i,y) = f(point(x-i, y),i);
        if(isInside(x,y+i))
            point(x,y+i) = f(point(x, y+i),i);
        if(isInside(x,y-i))
            point(x,y-i) = f(point(x, y-i),i);
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::fillCircleAdvance(int32_t x, int32_t y, uint32_t radius,std::function<color(color)> f){
    auto mirroFunction = [&](int32_t x,int32_t y,int32_t ox,int32_t oy){
        if(isInside(x + ox, y + oy))
            point(x + ox, y + oy) = f(point(x + ox, y + oy));
        if(isInside(x + ox, y - oy))
            point(x + ox, y - oy) = f(point(x + ox, y - oy));
        if(isInside(x - ox, y - oy))
            point(x - ox, y - oy) = f(point(x - ox, y - oy));
        if(isInside(x - ox, y + oy))
            point(x - ox, y + oy) = f(point(x - ox, y + oy));
    };

    if(isInside(x, y))
            point(x, y) = f(point(x, y));

    float len = 0;
    for (int32_t i = 1; i < radius; i++)
    {
        len = sqrt((float(radius) * float(radius)) - (float(i) * float(i)));
        for (int32_t j = 1; j < len; j++)
        {   
            if(i==j)break;

            mirroFunction(x, y, i, j);
            mirroFunction(x, y, j, i);

        }
        if (i == len)
            break;
    }

    float skos = sqrt((float(radius) * float(radius))/2);
    
    for(int32_t i = 1; i < skos; i++){//skos
        mirroFunction(x, y, i, i);
    }

    for(int32_t i = 1; i < radius; i++){//pion/poziom
        if(isInside(x+i,y))
            point(x+i,y) = f(point(x+i, y));
        if(isInside(x-i,y))
            point(x-i,y) = f(point(x-i, y));
        if(isInside(x,y+i))
            point(x,y+i) = f(point(x, y+i));
        if(isInside(x,y-i))
            point(x,y-i) = f(point(x, y-i));
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLineThick(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t scale, color c)
{
    fillCircle(x1, y1, scale, c);
    fillCircle(x2, y2, scale, c);

    drawTwistLine(x1, y1, x2, y2, [&](int32_t x, int32_t y)
                  {
        this->drawLineLeftRight(x-scale,y,(scale<<1)+1,c);
        this->drawLineUpDown(x,y-scale,(scale<<1)+1,c);
        this->drawPoint(x,y,c); });
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLineLeftRight(int32_t x, int32_t y, int32_t l, color c)
{
    for (uint32_t i = 0; i < l; i++)
    {
        drawPoint(x + i, y, c);
    }
}
template <typename color>
inline void dsl::ctxTemplate<color>::drawLineUpDown(int32_t x, int32_t y, int32_t l, color c)
{
    for (uint32_t i = 0; i < l; i++)
    {
        drawPoint(x, y + i, c);
    }
}
template <typename color>
inline void dsl::ctxTemplate<color>::fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, color c)
{

    if (y1 > y2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if (y2 > y3)
    {
        std::swap(x2, x3);
        std::swap(y2, y3);
    }
    if (y1 > y2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    // 1<2<3
    float x1ToX2 = float(x2 - x1) / float(y2 - y1);
    float x2ToX3 = float(x3 - x2) / float(y3 - y2);
    float x1ToX3 = float(x3 - x1) / float(y3 - y1);

    bool x1tox2S = true;
    float currentLX = x1;
    float currentSX = x1;
    if (y1 == y2)
        currentSX = x2;

    for (int32_t currentY = y1; currentY <= y3; currentY++)
    {
        if (currentY == y2)
            x1tox2S = false;
        if (currentLX < currentSX)
            drawLineLeftRight(currentLX, currentY, currentSX - currentLX, c);
        else
            drawLineLeftRight(currentSX, currentY, currentLX - currentSX, c);
        if (x1tox2S)
            currentSX += x1ToX2;
        else
            currentSX += x2ToX3;
        currentLX += x1ToX3;
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawLetter(char ch, int32_t x, int32_t y, color c, int32_t scale)
{
    uint8_t id = (uint8_t)ch - ' ';
    for (uint8_t i = 0; i < 5; i++)
    {
        for (uint8_t j = 0; j < 5; j++)
        {
            if (characters[id][j][i])
                fillRect(x + i * scale, y + j * scale, scale, scale, c);
        }
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::drawCtx(int32_t x, int32_t y, ctxTemplate<color> &context,uint8_t scale)
{
    for (int32_t ix = 0; ix < context.width; ix++)
    {
        for (int32_t iy = 0; iy < context.height; iy++)
        {
            fillRect(x + ix*scale, y + iy*scale,scale,scale,context.img[ix + context.width * iy]);
        }
    }
}
template <typename color>
inline void dsl::ctxTemplate<color>::print(const char *text, int32_t x, int32_t y, color c, uint32_t scale)
{
    uint32_t place = 0;
    uint32_t line = 0;
    while (text[place] != '\0')
    {

        if (text[place] == '\n')
        {
            line++;
            continue;
        }
        else
            drawLetter(text[place], x + 6 * place * scale, y + line * scale * 6, c, scale);
        place++;
    }
};
template <typename color>
inline void dsl::ctxTemplate<color>::print(int32_t number, int32_t x, int32_t y, color c, uint32_t scale)
{
    bool negative = false;
    if (number < 0)
    {
        negative = true;
        number = -number;
    }
    uint32_t numlenght = 0;
    int32_t temp = number;
    do
    {
        temp -= temp % 10;
        temp /= 10;
        numlenght++;
    } while (temp != 0);
    numlenght += negative;
    char *txt = new char[numlenght + 1];
    txt[numlenght] = '\0';

    if (negative)
    {
        txt[0] = '-';
    }
    uint32_t itnumlenght = numlenght - 1;
    while (number != 0)
    {
        txt[itnumlenght] = number % 10 + '0';
        number /= 10;
        itnumlenght--;
    }
    print(txt, x, y, c, scale);
    delete[] txt;
}
template <>
inline void dsl::ctxTemplate<dsl::argb8888>::drawSprite(int32_t x, int32_t y, sprite& spr, uint32_t scale,bool leftRightFlip,bool upDownFlip){//to-do flip
    for(int32_t ix = 0; ix < spr.getWidth(); ix++){
        for(int32_t iy = 0; iy < spr.getHeight(); iy++){
            uint8_t id = spr.getPixelColorId(ix, iy);
            if(id){
                fillRect(x+(ix*scale),y+(iy*scale),scale,scale,spr.getColor(id));
            }
        }
    }
};
template <>
inline void dsl::ctxTemplate<dsl::argb8888>::drawSprite(vector2D pos,sprite& spr, uint32_t scale,bool leftRightFlip,bool upDownFlip){
    drawSprite(pos.x,pos.y,spr,scale,leftRightFlip,upDownFlip);
};
template <>
inline void dsl::ctxTemplate<dsl::argb8888>::drawSprite(int32_t destX,int32_t destY,int32_t formX,int32_t formY,uint32_t width,uint32_t height,sprite& spr,uint32_t scale,bool leftRightFlip,bool upDownFlip){
    for(int32_t ix = 0; ix < width; ix++){
        for(int32_t iy = 0; iy < height; iy++){
            uint8_t id;//(ix-(width-1)) (iy-(height-1))
            if(!leftRightFlip&&!upDownFlip)id = spr.getPixelColorId(ix+formX, iy+formY);
            else if(leftRightFlip&&!upDownFlip)id = spr.getPixelColorId(((width-1)-ix)+formX, iy+formY);
            else if(!leftRightFlip&&upDownFlip)id = spr.getPixelColorId(ix+formX, ((height-1)-iy)+formY);
            else if(leftRightFlip&&upDownFlip)id = spr.getPixelColorId(((width-1)-ix)+formX, ((height-1)-iy)+formY);
            if(id){
                fillRect(destX+(ix*scale),destY+(iy*scale),scale,scale,spr.getColor(id));
                
                
            }
        }
    }
};
template <>
inline void dsl::ctxTemplate<dsl::argb8888>::drawSprite(vector2D pos,vector2D from,vector2D size,sprite& spr, uint32_t scale,bool leftRightFlip,bool upDownFlip){
    drawSprite(pos.x,pos.y,from.x,from.y,size.x,size.y,spr,scale,leftRightFlip,upDownFlip);
};