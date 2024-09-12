#include "text.hpp"
#include <string>
#include <functional>
#include "gameData.hpp"
#include "ctx.hpp"

using namespace dsl;

uint32_t frame = 0;
uint32_t textLenght = 0;
std::string text;
char* textNow = nullptr;

bool textBox = false;

std::function<void()> cb;

void drawText(ctx8888& ctx){
    if(!textBox)return;
    frame++;
    if(frame%5==0){
        if(textLenght<text.length()){
            frame = 0;
            textNow[textLenght] = text.at(textLenght);
            textLenght++;
        }
    }
    ctx.fillRect(0,windowHeight-35,windowWidth,35,getRGB(0,0,0));
    ctx.drawRect(0,windowHeight-35,windowWidth,35,getRGB(255,255,255));
    ctx.print(textNow,10,windowHeight-30,getRGB(255,255,255),3);
    if(okno.isKeyDown(' ')){
        textBox = false;
        cb();
        cb = [](){};
    }
}

void triggerText(std::string txt,std::function<void()> callback){
    cb = callback;
    textBox = true;
    text = txt;
    frame = 0;
    textLenght = 0;
    delete [] textNow;
    textNow = new char[text.length()+1];
    for(uint32_t i = 0;i<text.length()+1;i++){
        textNow[i] = '\0';
    }
}