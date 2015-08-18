#include "tmxlent.hpp"
#include <iostream>
#include <vector>

TMXLent::TMXLent()
{

}

void TMXLent::loadtmx(const char *tmxfilename)
{
    pugi::xml_document mapDoc;
    mapDoc.load_file(tmxfilename);

    this->nodeMap = mapDoc.child("map");
    this->nodeTileset = this->nodeMap.child("tileset");
    this->nodeData = this->nodeMap.child("layer").child("data");

    // How many tiles width/height the map is
    this->gridSize.x = this->nodeMap.attribute("width").as_int();
    this->gridSize.y = this->nodeMap.attribute("height").as_int();

    // How big each tile is
    this->tileSize.x = this->nodeTileset.attribute("tilewidth").as_int();
    this->tileSize.y = this->nodeTileset.attribute("tileheight").as_int();

    // Size of the map in pixels
    this->mapSize.x = this->gridSize.x * this->tileSize.x;
    this->mapSize.y = this->gridSize.x * this->tileSize.y;

    // Vector to hold vector of rows
    std::vector<std::vector<int>> grid;
    // Vector of tile ids
    std::vector<int> row;

    int gX = 1;

    for (pugi::xml_node tile: this->nodeData.children("tile"))
    {
        // Add tile id to row vector
        row.push_back(tile.attribute("gid").as_int());

        // If at the end of the current row
        if (gX == this->gridSize.x)
        {
            // Add the row to the grid vector and clear the row
            grid.push_back(row);
            row.clear();
            gX=0;
        }
        gX++;
    }

//    for(const auto& row: grid)
//    {
//        for(const auto& tid: row)
//        {
//            std::cout << tid;
//        }
//        std::cout << std::endl;
//    }

}


