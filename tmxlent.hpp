#pragma once
#include <string>
#include <pugixml/pugixml.hpp>

struct Vec2d
{
    int x;
    int y;
};

class TMXLent
{
public:
    TMXLent();
    void loadtmx(const char* tmxfilename);
    Vec2d gridSize;
    Vec2d tileSize;
    Vec2d mapSize;

private:
    pugi::xml_node nodeMap;
    pugi::xml_node nodeTileset;
    pugi::xml_node nodeData;

    std::string fnTileset;
};
