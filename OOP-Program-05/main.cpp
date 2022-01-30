//Catherine Stringfellow  AND Zachary Kingcade
//OOP Program 5ListShapesAreas
//ListShapesAreas.cpp - reads a list of shapes and their dimensions from a file and 
//outputs their areas and the cumulative area.

#include <iostream>
#include <fstream>
#include <vector>
#include "List.h"
#include "Shapes.h"
using namespace std;

//Prototypes for non-member functions

//Open streams for reading and writing
void openFiles (ifstream & infile, ofstream & outfile);

//Print name and program assignment
void printHeading (ofstream & outfile);

//Read shape info, instantiate it and return the pointer to it
void readShape(ifstream & , Shape* &);

int main () {
	
  //Declare a List of pointers to Shape and a pointer to a Shape
  List <Shape *>data;
  Shape *holder;
  double totalArea;
  //open streams for input and output
  ifstream infile;
  ofstream outfile;
  openFiles(infile, outfile);

  printHeading (outfile);
  
  //read a shape
  readShape(infile,holder);
  //while more data
  while (!infile.eof()){
		//insert the shape and advance cursor to append to the end next time
        data.InsertItem(holder);
        data.AdvanceCursor();
		//read next shapeSh
        readShape(infile,holder);
  }
    //insert last data item that is left over due to loop logic
    data.InsertItem(holder);

    //init cursor and total
    data.ResetCursor();
    totalArea = 0;

    //get each shape, print it's data and accumulate the areas
    while(!data.CursorAtEnd()){
        data.GetCurrentItem(holder);
        outfile << holder->toString() << std::endl;
        totalArea += holder->getArea();
        data.AdvanceCursor();
    }
 
    //print the cumulative area
    outfile << "\nTotal area of all shapes is " << totalArea;


  return 0;
}

//Implementations of non-member functions

//Name:openFiles
//input: input and output file streams
//Purpose: Prompts the user for output and input file names and
//uses them to open the passed in input and output file streams
void openFiles (ifstream & infile, ofstream & outfile){
    std::string choice;
    
    //Here we prompt the user for an input file and open said stream
    std::cout << "What file would you like to input data from?\n";
    std::cin >> choice;
    infile.open(choice);

    std::cout << "what would you like to name your output file?\n";
    std::cin >> choice;
    outfile.open(choice);
} //----------end of openFiles----------

//Name:readShape
// infile: input stream to read in data
// s: shape pointer to store generated data in
//Purpose: reads in a child of shape and properly determines what child the
//read in data is, creates object and stores in passed in shape pointer
void readShape(ifstream & infile, Shape* & s) {
	//declare variables
  string name;
  //non of our classes use more then 2 numbers so we save space by not enumerating all of them
  //and just using two generic varibles to hold them all;
  double num1, num2;

	//read the name of the shape
	infile >> name;
	//use a switch based on the first character in the shape, instantiate the shape
	switch(name[0]){
    case 'R':
    infile >> num1 >> num2;
    s = new Rect(name,num1,num2);
    break;
    case 'S':
    infile >> num1;
    s = new Square(name,num1);
    break;
    case 'O':
    infile >> num1 >> num2;
    s = new Oval(name,num1,num2);
    break;
    case 'C':
    infile >> num1;
    s = new Circle(name,num1);
    break;
  }
}

//Name: print heading
//Purpose: prints the heading for this proticular program, only here to prevent io in main
void printHeading (ofstream & outfile){
  outfile << "Zachary Kingcade\nProgram 05 OOP\n";
  //creates second padding space, flushes stream before exiting function
  outfile << std::endl;
}