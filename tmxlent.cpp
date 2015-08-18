#include "tmxlent.hpp"

TMXLent::TMXLent()
{

}

void TMXLent::loadtmx(const char *tmxfilename)
{
    pugi::xml_document mapDoc;
    mapDoc.load_file(tmxfilename);

    this->nodeMap = mapDoc.child("map");
    this->nodeTileset = this->nodeMap.child("tileset");

    // How many tiles width/height the map is
    this->gridSize.x = this->nodeMap.attribute("width").as_int();
    this->gridSize.y = this->nodeMap.attribute("height").as_int();

    // How big each tile is
    this->tileSize.x = this->nodeTileset.attribute("tilewidth").as_int();
    this->tileSize.y = this->nodeTileset.attribute("tileheight").as_int();

    // Size of the map in pixels
    this->mapSize.x = this->gridSize.x * this->tileSize.x;
    this->mapSize.y = this->gridSize.x * this->tileSize.y;
}
