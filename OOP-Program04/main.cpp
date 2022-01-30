#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <string>
#include "ZeroOne.h"
#include <vector>

//prototypes
void openFiles (std::ifstream &, std::ofstream &);
void loadMatrixFF (std::ifstream &, Matrix &);
bool otherFileCheck();
std::string printSBS(std::string, std::string, bool level = false,int buffering = 0);

int main() {
    //Our Varibles
    bool run = true;

    //declare in and out streams
    std::ifstream in;
    std::ofstream out;

    /*------------------------------_File Loop_------------------------------*/
    //this loop runs until end is true, this is set via input from the user at the 
    //end of the loop
    while(run){
        //open in and out streams
        openFiles(in, out);
        int numDataSets,rows,columns;
        char type;

        //output our file header
        out << "Zach Kingcade & Garrett Johnson\n";
        out << "OOP Program 04\n\n";
        

        //read in our number of data sets in our input file and set
        //loop to run that many times
        in >> numDataSets;
        for(int i = 0; i < numDataSets; i++){
            //reads in the type of the next 2 matrixes
            //R = Regular Matrix
            //Z = Zero One Matrix
            in >> type;
            if (type == 'R'){


                //read in the size of our first matrixes and fill
                in >> rows >> columns;
                Matrix mat1(rows,columns);
                loadMatrixFF(in, mat1);

                //read in the size of our second matrixes and fill
                in >> rows >> columns;
                Matrix mat2(rows,columns);
                loadMatrixFF(in, mat2);

                //print our set number and Matrixes
                out << "Set Number: " << i << '\n';
                out << "Original A and B: \n";
                out << printSBS(mat1.toString(), mat2.toString(), true, 5) << '\n';

                //-----operations-----
                //Addition
                try{out << "Addition of A and B:\n" << mat1 + mat2 << '\n';}
                catch(const char *e){out << e << '\n';}

                //multiplication
                try{out << "Multiplication of A and B:\n" << mat1 * mat2 << '\n';}
                catch(const char *e){out << e << '\n';}

                //Transpose
                out << "Transpose of A and B: \n";
                out << printSBS(mat1.transpose().toString(), mat2.transpose().toString(), true, 5) << '\n';

                //Symmetric
                if(mat1.symmetric()) {out << "Matrix A is symmetric\n";}
                else {out << "Matrix A is not symmetric\n";}
                if(mat2.symmetric()) {out << "Matrix B is symmetric\n";}
                else {out << "Matrix B is not symmetric\n";}

                //end line here to both create a gap between sets and to make
                //sure to flush the stream
                out << std::endl;


            }else if (type == 'Z') {
                
                //read in the size of our first matrixes and fill
                in >> rows >> columns;
                ZeroOne mat1(rows,columns);
                loadMatrixFF(in, mat1);

                //read in the size of our second matrixes and fill
                in >> rows >> columns;
                ZeroOne mat2(rows,columns);
                loadMatrixFF(in, mat2);

                //print our set number and Matrixes
                out << "Set Number: " << i << '\n';
                out << "Original A and B: \n";
                out << printSBS(mat1.toString(), mat2.toString(), true, 5) << '\n';

                //-----operations-----
                //Meet
                try{out << "Join of A and B:\n" << mat1 + mat2 << '\n';}
                catch(const char *e){out << e << '\n';}

                //Join
                try{out << "Meet of A and B:\n" << (mat1 ^ mat2) << '\n';}
                catch(const char *e){out << e << '\n';}

                //Transpose
                out << "Transpose of A and B: \n";
                out << printSBS(mat1.transpose().toString(), mat2.transpose().toString(), true, 5) << '\n';

                //Symmetric
                if(mat1.symmetric()) {out << "Matrix A is symmetric\n";}
                else {out << "Matrix A is not symmetric\n";}
                if(mat2.symmetric()) {out << "Matrix B is symmetric\n";}
                else {out << "Matrix B is not symmetric\n";}

                //end line here to both create a gap between sets and to make
                //sure to flush the stream
                out << std::endl;
                

            }else {
                std::cout << "Error: Incorrect Formatting\n";
            }
        }

        //close in and out streams
        in.close();
        out.close();


        run = otherFileCheck();
    }
    return 0;
}

//Name:openFiles
//input: input and output file streams
//Purpose: Prompts the user for output and input file names and
//uses them to open the passed in input and output file streams
void openFiles (std::ifstream &in, std::ofstream &out){
    std::string choice;
    
    //Here we prompt the user for an input file and open said stream
    std::cout << "What file would you like to input data from?\n";
    std::cin >> choice;
    in.open(choice);

    std::cout << "what would you like to name your output file?\n";
    std::cin >> choice;
    out.open(choice);
}

//Name:loadMatrixFF (Load Matrix From File) 
//input: File input stream to load from, matrix to be loaded
//Purpose: loads a matrix full of values from a passed in input
//file stream
void loadMatrixFF (std::ifstream &in, Matrix &container){
    for (int r = 0; r < container.checkRows() ; r++){
        for (int c = 0; c < container.checkColumns() ; c++){
            in >> container[r][c];
        }
    }
}

//Name: otherFileCheck
//output: returns the users choice
//Purpose: checks if the user would like to process another file
//and returns the answer
bool otherFileCheck(){
    bool result;
    bool valid;
    std::string loopChoice;
    while(valid == false){
        std::cout << "would you like to process another input file?\n";
        std::cin >> loopChoice;
        if (loopChoice == "yes" || loopChoice  == "Yes" || loopChoice  == "YES"){
            result = true;
            valid = true;
        } else if (loopChoice  == "no" || loopChoice  == "No" || loopChoice  == "NO"){
            result = false;
            valid = true;
        } else {
            std::cout << "Error: Invalid Input, Please try Again:\n";
        }
    }
    return result;
}

//Name: print side by side
//Input: 2 strings to add together
//level- determines weather to level out the length of the lines in the first string or not, false by default
//buffering- number of empty spaces to add between the lines of the strings 0 by default
//Output: resulting combined and buffered string
//Purpose: Combines strings and provides an option for buffering inbetween the two strings
//as well as leveling the first string if level is true, dosen't level the second string inbase
//your trying to add multiple strings and dont't want the resulting string and the next to be leveled
std::string printSBS(std::string string1, std::string string2, bool level,int buffering){
    std::vector <std::string> set1;
    std::vector <std::string> set2;
    std::string result = "";
    int lineNum;

    //split the string into its lines by \n
    //prime loop
    lineNum = 0;
    set1.push_back("");
    for (int i = 0; i < string1.size(); i++){
        if (string1[i] != '\n'){
            set1[lineNum] += string1[i];
        }else {
            set1.push_back("");
            lineNum++;
        }
    }

    //split the string into its lines by \n
    //prime loop
    lineNum = 0;
    set2.push_back("");
    for (int i = 0; i < string2.size(); i++){
        if (string2[i] != '\n'){
            set2[lineNum] += string2[i];
        }else {
            set2.push_back("");
            lineNum++;
        }
    }

    //here we level out the legth of the lines in the 2 strings if
    //leveling is true
    if(level == true){
        int maxLength = 0;
        //first determine what the longest line in this string is
        for (int i = 0; i < set1.size(); i ++){
            if (set1[i].size() > maxLength){
                maxLength = set1[i].size();
            }
        }
        //add spaces to level the length
        for (int i = 0; i < set1.size(); i ++){
            for (int j = set1[i].size(); j < maxLength;j++)
                set1[i] += " ";
        }
        //add lines to the level the bottom/ number of lines
        for (int i = set1.size() ; i < set2.size();i++){
            set1.push_back("");
            set1[i] += std::string(maxLength, ' ');
        }
    }

    //here we make them the same number of lines long, this may have already been done
    //in the above leveling loop but if no it wil be done here and we won't be leveling
    //here like above just making the vectors the same size
    for (int i = set1.size() ; i < set2.size();i++){
        set1.push_back("");
    }
    for (int i = set2.size() ; i < set1.size();i++){
        set2.push_back("");
    }

    //now we simply add them together for the number of lines they have which are now matching
    for (int i = 0; i < set1.size();i++){
        result += set1[i] + std::string(buffering,' ') + set2[i] + '\n';
    }

    return result;
}