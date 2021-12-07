#pragma once

#include <string>
#include <vector>
#include <pair>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Graph.h"

using std::string;
using std::vector;
using std::pair;
using cs225::PNG;
using cs225::HSLAPixel;

class ForceDirectedDraw {
  public:
    // constructs a force directed object
    ForceDirectedDraw(const Graph& graph, int width, int height);

    // draws the graph on a png and saves to file "filename"
    vector<pair<int, int>> drawGraph(const string& filename, int iterations);

    // draws a subgraph that is a connected graph of all games connected to game at game_index
    // and saves it as a png and saves to file "filename"
    void drawGameSimilarGraph(string filename, int game_index);

  private:
    const Graph& graph_;
    int width_, height_;

    // helper functions

    // draws the positions of each vertex on a png
    void drawPositions(const vector<pair<int, int>>& positions, const string& filename);

    // calculates the repulsive force
    float repulsiveForce(float force, float k);

    // calculates the attractive force
    float attrForce(float force, float k);

    // finds the difference/unit vector of 2 vectors (unit when unit == true) (different when unit == false)
    pair<float, float> unitVector(const pair<int, int>& pos1, const pair<int, int> pos2, bool unit);

    // generates a random sequence of positions in the image to draw a vertices (nodes) of size
    vector<pair<int, int>> generateRandomPositions(int size);
};