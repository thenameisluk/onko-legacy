#include "dsl/ctx.hpp"
#include "dsl/simpleWindow.hpp"
#include "iostream"

int8_t it = 0;

int main() {
    std::cout << "image name\n>";
    std::string name;
    std::cin >> name;
    dsl::dataArray img(name.c_str());
    dsl::sprite sprite = dsl::sprite(img);
    dsl::simpleWindow okno(sprite.getWidth()*10,sprite.getHeight()*10);
    okno.setFrame([&](dsl::ctx8888& ctx){
        switch (it)
        {
        case 0:
            ctx.fill(dsl::getRGB(0,0,0));
            break;
        case 1:
            ctx.fill(dsl::getRGB(255,0,0));
            break;
        case 2:
            ctx.fill(dsl::getRGB(0,255,0));
            break;
        case 3:
            ctx.fill(dsl::getRGB(0,0,255));
            break;
        }
        ctx.drawSprite(0,0,sprite,10);
    }).setMouseDown([&](dsl::mousePos pos){
        it++;
        if(it==4)it=0;
    });
    okno.wait();
}