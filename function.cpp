#include "header.h"


//Constructor
table::table ()
{
  list = new vertex[SIZE] ;
  for ( int i = 0 ; i < SIZE ; ++i )
  {
    list[i].head = NULL ;
    list[i].step = NULL ;
  }
}

//Destructor
table::~table(){
  node * current;
  node * temp;
  for(int i=0; i < SIZE; ++i){
    current = list[i].head;
    while(current){
      temp = current -> next;
      delete current;
      current = temp;
      
    }
    delete list[i].step;
    
    
  }
  delete list;
}


//Add vertex
int table::add_vertex(char * step){
  int i = 0;
  while(list[i].step){ //Travese
    i = i + 1;
    if(i == SIZE)
      return 0;
  }
  list[i].step = new char[strlen(step)+1]; //Add the data into the vertex
  strcpy(list[i].step,step);

  return 1;
}
//Add an edge
int table::add_edge(int index, int i){
  
  //Temp pointer to hold the value
  node * temp = new node;
  temp -> index = index;
  //Adding in head
  temp -> next = list[i].head;
  list[i].head = temp;
  return 1;
}

//Display all function
int table::display_all()
{
  node * current;
  int i = 0;
  
  if(!list[i].step)//If list is empty
    return 0;
  while(list[i].step){//traverse and display
    current = list[i].head;
    cout<<"Step: "<<list[i].step<<'\n';
    while(current){
      cout<<"Connected to: "<<list[current -> index].step<<'\n';
      current =  current -> next;
    }
    i = i + 1;
  }
  
  return 1;
}
//Display a single step and its connection
int table::display_step(int i){
  
  node * current;
  
  
  if(!list[i].step)
    return 0;
  
  current = list[i].head;
  cout<<"Step: "<<list[i].step<<'\n';
  while(current){
    cout<<"Connected to: "<<list[current -> index].step<<'\n';
    current =  current -> next;
  }

  return 1;
}
//Only display the steps
int table::display_each(){
  int i = 0;
  while (list[i].step){
    cout<<"Step ("<<i+1<<") "<<list[i].step<<'\n';
    i = i + 1;
  }
  return 1;
}

