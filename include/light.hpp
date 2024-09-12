#pragma once
#include <dsl/ctx.hpp>

class lightSource{
    public:
        dsl::rgb color;
        uint8_t stregh;
        uint8_t radius;
        lightSource();
        lightSource(dsl::rgb color,uint8_t stregh,uint8_t radius);
        lightSource& operator=(int i);
};

typedef dsl::ctxTemplate<lightSource>  ctxLight;

void drawLight(dsl::vector2D pos,dsl::argb8888 color,float strengh,dsl::ctx8888& ctx);

void doLighting(ctxLight& lightMap,dsl::ctx8888& ctx);