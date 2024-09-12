#pragma once
#include <list>
#include <vector>
#include <functional>
#include <stdint.h>
#include "ctx.hpp"


class normalParticle{
    public:
        uint8_t life;
        dsl::fvector2D pos;
        dsl::vector2D size;
        dsl::fvector2D direction;
        dsl::argb8888 color;
        normalParticle();
        normalParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color);
};
class glowParticle{
    public:
        uint8_t life;
        dsl::fvector2D pos;
        dsl::vector2D size;
        dsl::fvector2D direction;
        dsl::argb8888 color;
        uint8_t strenght;
        glowParticle();
        glowParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color,uint8_t strenght);
};
class shapeParticle{
    public:
        uint8_t life;
        dsl::fvector2D pos;
        dsl::vector2D size;
        dsl::fvector2D direction;
        dsl::argb8888 color;
        uint8_t* shape;
        shapeParticle();
        shapeParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color,uint8_t* shape);
};

class particleContainer{
        enum particel_type{
            normal,glow,shape
        } type;
        uint32_t size;
        union particlesPtr{
            normalParticle* normal;
            glowParticle* glow;
            shapeParticle* shape;
        } particles;
    public:
        particleContainer(uint32_t count,std::function<normalParticle()> generator);
        particleContainer(uint32_t count,std::function<glowParticle()> generator);
        particleContainer(uint32_t count,std::function<shapeParticle()> generator);
        ~particleContainer();
        bool draw(dsl::vector2D topLeftScreenPos,dsl::ctx8888& ctx);
};

class particleMenezer{
        std::list<particleContainer> particleContainers;
    public:
        particleMenezer();
        void addParticleContainer(uint32_t count,std::function<normalParticle()> generator);
        void addParticleContainer(uint32_t count,std::function<glowParticle()> generator);
        void addParticleContainer(uint32_t count,std::function<shapeParticle()> generator);
        void draw(dsl::ctx8888& ctx);
};