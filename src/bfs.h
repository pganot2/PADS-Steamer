#include "graph.h"
#include <iostream>
#include <list>
using namespace std;
class BFSg {
  int vert;      // number of vertices
  list<int> *al; // points to adjacency lists
public:
  BFSg(Graph *graphx); // constructor
  void BFS(int s);     // prints BFS traversal
};
