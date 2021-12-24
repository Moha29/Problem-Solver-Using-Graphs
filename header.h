#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//The purpose of this program is to have the user build their own plan for solving problems


int const SIZE = 11; //Size of the array
int const MAX = 100;  //Size of the statically allocated arrays

//edge list
struct node{
  int index;
  node * next;
};

//Adj list
struct vertex{
  char * step;
  node * head;
};

//Graph operation
class table{
  public:
    table();
    ~table();
    int add_vertex(char*);
    int add_edge(int, int);
    int display_all();
    int display_step(int);
    int display_each();
  private:
    vertex * list; //List of vertcies
    
};
