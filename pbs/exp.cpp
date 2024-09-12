#include "dsl/data.hpp"
#include "dsl/simpleWindow.hpp"
#include "dsl/json.hpp"
#include "bitmap.hpp"

uint32_t pallet[16] = {
    0
};
uint32_t color[16] = {
    0
};

uint8_t count = 0;

uint8_t colorId(uint32_t col){
    for(uint8_t i = 0;i<count;i++){
        if(pallet[i]==col){
            return i;
        }
    }
    return 0;
}

void add(uint32_t col){
    if(count>=16){
        std::cout << "to many colors" << std::endl;
        abort();
    }
    for(uint8_t i = 0;i<count;i++){
        if(pallet[i]==col){
            color[i]++;
            return;
        }
    }
    pallet[count] = col;
    color[count] = 1;
    count++;
}

dsl::ctx8888 ctx(1,1);

int main() {
    Bitmap bm;
    std::cout << "image name\n>";
    std::string name;
    std::cin >> name;
    std::cout << "loading image" << std::endl;
    bm.open(name);

    PixelMatrix pm = bm.toPixelMatrix();

    uint32_t height = pm.size();
    uint32_t width = pm[0].size();

    ctx.resize(width,height);

    uint32_t it = 0;

    std::cout << "decoding" << std::endl;
    for(auto row : pm){
        for(auto pixel : row){
            add(dsl::argb8888(pixel.red,pixel.green,pixel.blue).color);
            ctx.getData()[it] = dsl::getRGB(pixel.red,pixel.green,pixel.blue);
            it++;
        }
    }

    std::cout << "wirteing header" << std::endl;

    dsl::PbWriter out;
    //size
    out.writeStatic(width,32);
    out.writeStatic(height,32);
    std::cout << "writing pallet" << std::endl;
    //pallet
    for(uint8_t i = 1;i<16;i++){
        out.writeStatic(pallet[i],32);//color
    }
    std::cout << "writing pixels" << std::endl;
    //pixels
    for(uint32_t i = 0;i<height*width;i++){
        out.writeStatic(colorId(ctx.getData()[i].color),4);//pixels
    }
    std::cout << "saving image" << std::endl;
    out.exportData().save((name+".pbs").c_str());

    std::cout << "saved to : " << name << ".pbs" << std::endl;

    std::cout << "done" << std::endl;

    dsl::argb8888 aplha = dsl::argb8888(pallet[0]);

    std::cout << width << "x" << height << std::endl;
    std::cout << "colors : " << (int)count << std::endl;
    std::cout << "aplha : " << (int)aplha.get().r << " " << (int)aplha.get().g << " " << (int)aplha.get().b << std::endl;

    dsl::simpleWindow okno(width*10,height*10);
    okno.setFrame([&](dsl::ctx8888& c){
        c.drawCtx(0,0,ctx,10);
    });
    okno.wait();
}