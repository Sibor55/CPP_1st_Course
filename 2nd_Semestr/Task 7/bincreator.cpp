#include <iostream>
#include <fstream>

int main(){

    std::ofstream out("input3.binf", std::ios::binary);
    unsigned char buf[6];
    buf[0] = 5.4f;
    for (size_t i = 0; i < 5; i++)
    {
        buf[i+1] = (i+1.f);
    }
    out.write((char*)buf,6);
}