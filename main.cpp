#include "header.h"

//Mohamed Al-zadjali || 6/11/2020 || The purpose of this program is to have the user build their own plan for solving problems

int main() {
  char info [MAX]; //Statically allocated arrays for the user input to pass them in as an argument 
  char step [MAX];
  int index; //for the user to input
  int i;
  int s; //Hold the returned value
  int choice; //User's choice from the menu

  table my_table; //Class object

  cout<<"Welcome!! In this program you will be able to sort your own steps of solving a problem. \n Have Fun!! \n";


//Menu
  while(choice != 5){
    cout<<"             MENU \n (1) Insert a step. \n (2) Connect steps. \n (3) Display connected step for each one. \n (4) Display all steps. \n (5) Quit the program. \nBy entering the number of the option, what do you want to do: ";
    cin>>choice;
    cin.ignore(100,'\n');

    //If the user wanted to insert a vertex
    if(choice == 1){
      cout<<"\n Enter the step: "; //Get the step
      cin.get(step,MAX,'\n');
      cin.ignore(100,'\n');
      my_table.add_vertex(step);
    }
    if(choice == 2){//The user wanted to add an edge
      s=my_table.display_each(); //Display the options for the user
    
      
      cout<<"What is the number of the step that you want to build a connection for: ";
      cin>>i;
      cin.ignore(100,'\n');
      i -= 1;
      cout<<"\n Connect it to what step: ";
      cin>>index;
      cin.ignore(100,'\n');
      index -= 1;

      s = my_table.add_edge(index,i); 
      if(s == 1){
        cout<<"Success!";
      }
      else
        cout<<"Failure!";
      
    }
    //If the user wanted to display a single step
    if(choice == 3){
      if(my_table.display_each()){
        cout<<"\n What step do you want to display: ";
        cin>>i;
        cin.ignore(100,'\n');
        i = i - 1;
        if(my_table.display_step(i))
          cout<<" \n";
        else
          cout<<"Failure!!";
      }
      else
        cout<<"Nothing to display!";
      
    }
    //If the user wanted to display all the steps
    if(choice == 4){
      if(my_table.display_all())
        cout<<'\n';
      else
        cout<<"Failure!!";
    }

  }
}
