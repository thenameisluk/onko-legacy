#pragma once
#include <list>
#include <functional>
#include "ctx.hpp"

float angleAround(float len,float width);

template<typename T>
void iterateOverList(std::list<T>& list, std::function<bool(T&)> f){
    auto i = list.begin();
    while(i != list.end()){
        if (f(*i))
        {
            list.erase(i++);
        }else{
            i++;
        }
    }
}

void drawDebugInfo(dsl::ctx8888& ctx);

class rng{
    long long int seed;
    long long int mnum;
    public:
        rng(int sed = rand()){
            seed=sed;
            mnum = sed;
            if(seed<1000){
                seed = (sed*1000)+sed;
                mnum = seed;
            }
        };
        long long int getSeed(){
            return seed;
        }
        int r(int to){
            //std::cout << mnum << std::endl;
            mnum = mnum*(mnum+seed);//xxxxaaaaxxxx
            //std::cout << mnum << std::endl;
            mnum = (((mnum%10000000000)-(mnum%100000)))/100000;
            return (mnum%to);
        }
};

class exetuer{
    public:
        exetuer(std::function<void()> f){
            f();;
        }
};