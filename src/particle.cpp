#include "particle.hpp"
#include <list>
#include <vector>
#include <functional>
#include "ctx.hpp"
#include "helper.hpp"
#include "calculations.hpp"

using namespace dsl;


normalParticle::normalParticle(){

}
normalParticle::normalParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color){
    this->life = life;
    this->pos = pos;
    this->size = size;
    this->direction = direction;
    this->color = color;
}

glowParticle::glowParticle(){

}
glowParticle::glowParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color,uint8_t strenght){
    this->life = life;
    this->pos = pos;
    this->size = size;
    this->direction = direction;
    this->color = color;
    this->strenght = strenght;
}

shapeParticle::shapeParticle(){

}
shapeParticle::shapeParticle(uint8_t life,dsl::fvector2D pos,dsl::vector2D size,dsl::fvector2D direction,dsl::argb8888 color,uint8_t* shape){
    this->life = life;
    this->pos = pos;
    this->size = size;
    this->direction = direction;
    this->color = color;
    this->shape = shape;
}

particleContainer::particleContainer(uint32_t count,std::function<normalParticle()> generator){
    this->size = count;
    this->type = normal;
    particles.normal = new normalParticle[count];
    for(uint32_t i = 0; i < count; i++){
        particles.normal[i] = generator();
    }
}
particleContainer::particleContainer(uint32_t count,std::function<glowParticle()> generator){
    this->size = count;
    this->type = glow;
    particles.glow = new glowParticle[count];
    for(uint32_t i = 0; i < count; i++){
        particles.glow[i] = generator();
    }
}
particleContainer::particleContainer(uint32_t count,std::function<shapeParticle()> generator){
    this->size = count;
    this->type = shape;
    particles.shape = new shapeParticle[count];
    for(uint32_t i = 0; i < count; i++){
        particles.shape[i] = generator();
    }
}
particleContainer::~particleContainer(){
    switch (type){
        case normal:
            delete[] particles.normal;
            break;
        case glow:
            delete[] particles.glow;
            break;
        case shape:
            delete[] particles.shape;
            break;
    }
}
bool particleContainer::draw(dsl::vector2D topLeftScreenPos,dsl::ctx8888& ctx){//can be optimized. good luck future me
    bool alive = false;
    switch (type){
        case normal:
            for(uint32_t i = 0; i < size; i++){
                auto& p = particles.normal[i];
                if(p.life){
                    alive = true;
                    p.pos = p.pos + p.direction;
                    ctx.fillRect(p.pos-topLeftScreenPos,p.size,p.color);
                    p.life--;
                }
            }
            break;
        case glow:
            for(uint32_t i = 0; i < size; i++){
                //to-do
            }
            break;
        case shape:
            for(uint32_t i = 0; i < size; i++){
                //to-do
            }
            break;
    }
    return alive;
}


particleMenezer::particleMenezer(){
    
}
void particleMenezer::addParticleContainer(uint32_t count,std::function<normalParticle()> generator){
    particleContainers.emplace_back(count,generator);   
}
void particleMenezer::addParticleContainer(uint32_t count,std::function<glowParticle()> generator){
    particleContainers.emplace_back(count,generator);
}
void particleMenezer::addParticleContainer(uint32_t count,std::function<shapeParticle()> generator){
    particleContainers.emplace_back(count,generator);
}
void particleMenezer::draw(dsl::ctx8888& ctx){
    dsl::vector2D topLeftCorner = leftTopCameraCords();
    iterateOverList<particleContainer>(particleContainers,[&](particleContainer& container){
        return !container.draw(topLeftCorner,ctx);
    });
}