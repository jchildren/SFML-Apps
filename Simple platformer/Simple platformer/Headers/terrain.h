#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Terrain: public sf::Drawable, public sf::Transformable {
public:
  Terrain();
  ~Terrain();

  bool load(const std::string, sf::Vector2u, const int* cells,
    unsigned int, unsigned int);

  sf::FloatRect getBounds();


private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // apply the texture
    states.texture = &m_tileset;

    // you may also override states.shader or states.blendMode if you want

    // draw the vertex array
    target.draw(m_vertices, states);
  }

sf::VertexArray m_vertices;
sf::Texture m_tileset;

// tiles that have surfaces have their co-ordinates collected
// into this member function for collisions to be detected
std::vector< unsigned int > m_yTopSurfaces;
std::vector< unsigned int > m_yBottomSurfaces;
std::vector< unsigned int > m_xLeftSurfaces;
std::vector< unsigned int > m_xRightSurfaces;
};

Terrain::Terrain(){

}

Terrain::~Terrain(){

}

bool Terrain::load(const std::string terrainSheet,
  sf::Vector2u cellSize,
  const int* cells,
  unsigned int width,
  unsigned int height){

  // load the tileset texture
  if (!m_tileset.loadFromFile(terrainSheet))
    return false;

  // resize the vertex array to fit the level size
  m_vertices.setPrimitiveType(sf::Quads);
  m_vertices.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i){
    for (unsigned int j = 0; j < height ; ++j){

      int cellNumber = cells[i + j * width];

      if(cellNumber == 0){
        //ignore the quad if the cell is empty
        continue;
      }
      else {

        /*
        // This section fills in the textures in cells that are not empty
        */

        // get a pointer to the current tile's quad
        sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

        // find its position in the tileset texture
        int tu = cellNumber % (m_tileset.getSize().x / cellSize.x);
        int tv = cellNumber / (m_tileset.getSize().x / cellSize.x);

        // define its 4 corners
        quad[0].position = sf::Vector2f(i * cellSize.x, j * cellSize.y);
        quad[1].position = sf::Vector2f((i + 1) * cellSize.x, j * cellSize.y);
        quad[2].position = sf::Vector2f((i + 1) * cellSize.x, (j + 1) * cellSize.y);
        quad[3].position = sf::Vector2f(i * cellSize.x, (j + 1) * cellSize.y);


        // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * cellSize.x, tv * cellSize.y);
        quad[1].texCoords = sf::Vector2f((tu + 1) * cellSize.x, tv * cellSize.y);
        quad[2].texCoords = sf::Vector2f((tu + 1) * cellSize.x, (tv + 1) * cellSize.y);
        quad[3].texCoords = sf::Vector2f(tu * cellSize.x, (tv + 1) * cellSize.y);

        /*
        // This section checks to see if the cell should be used for collision detection
        */

        // checks to see if the cell has non-empty neighbours in x axis
        if(((i+1)!=0) && ((i-1)!=0)){
          m_xLeftSurfaces.push_back(i);
          m_xRightSurfaces.push_back(i);
        }
        else if((i+1)!=0){
          m_xRightSurfaces.push_back(i);
        }
        else if(((i-1)!=0) && (i!=0)){
          m_xLeftSurfaces.push_back(i);
        }

        // checks to see if the cell has non-empty neighbours in y axis
        if(((j+1)!=0) && ((j-1)!=0)){
          m_yTopSurfaces.push_back(i);
          m_yBottomSurfaces.push_back(i);
        }
        else if((j+1)!=0){
          m_yBottomSurfaces.push_back(i);
        }
        else if(((j-1)!=0) && (j!=0)){
          m_yTopSurfaces.push_back(i);
        }
      }
    }
  }

  return true;
}

sf::FloatRect Terrain::getBounds(){

  sf::FloatRect bounds;

  return bounds;

}


#endif
