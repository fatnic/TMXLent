#include "tmxlent.hpp"
#include <iostream>

int main()
{
    TMXLent tmx;
    tmx.loadtmx("assets/test.tmx");

    std::cout << tmx.tileSize.x << std::endl;

    return 0;
}

