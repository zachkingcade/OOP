#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

int main() {
    std::string choice;
    int n,r1,r2,c1,c2,type,config;

    srand(time(NULL));

    std::ofstream out;
    std::cout << "Name of the input file to make?\n";
    std::cin >> choice;
    out.open(choice);

    n = (rand() % 8) + 2;
    out << n << '\n';

    for (int i = 0; i < n; i++){
        //Decide if our matrix is 'R'egular or 'Z'ero-one
        type = rand() % 2;
        if (!type){
            out << 'R' << '\n';
        } else {
            out << 'Z' << '\n';
        }

        //pick one of 3 possible row and column configs
        //-- Square same size
        //-- Matching row one to column two
        //-- true random

        config = rand() % 3;
        switch(config){
            //-- Square same size
            case 0:
            r1=r2=c1=c2= (rand() % 8) + 3;
            break;

            //-- Matching row one to column two
            case 1:
            r1 = c2 = (rand() % 8) + 3;
            r2 = (rand() % 8) + 3;
            c1 = (rand() % 8) + 3;
            break;

            //-- true random
            case 2:
            r1= (rand() % 8) + 3;
            c1= (rand() % 8) + 3;
            r2= (rand() % 8) + 3;
            c2= (rand() % 8) + 3;
            break;
        }

        //out our rows and columns
        out << r1 << ' ' << c1 << '\n';

        for (int i = 0; i < r1 ; i++){
            for (int j = 0; j < c1 ; j++){
                if (!type){
                    out << rand() % 100 << ' ';
                } else {
                    out << rand() % 2 << ' ';
                }
            }
            out << std::endl;
        }

        //out our rows and columns
        out << r2 << ' ' << c2 << '\n';

        for (int i = 0; i < r2 ; i++){
            for (int j = 0; j < c2 ; j++){
                if (!type){
                    out << rand() % 100 << ' ';
                } else {
                    out << rand() % 2 << ' ';
                }
            }
            out << std::endl;
        }
    }
}
