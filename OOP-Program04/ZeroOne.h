#pragma once
#include"Matrix.h"

class ZeroOne : public Matrix{
    //allows us to access all of our constructors
    using Matrix::Matrix;

public:
    //Name: operator +
    //Input: ZeroOne to join
    //output: Joined together Matrixes
    //purpose: checks if the current matric and passed in matrix are the same
    //size, if they are joins together the current matrix and a passed in matrix
    //using the plus operator so matrix + matrix, return the result, else it
    //throws an error that will need to caught on the user's side if they want to
    //prevent crashing
    ZeroOne operator+(ZeroOne);
    //Name: operator ^
    //Input: ZeroOne to Meet
    //output: Met Matrixes
    //purpose: checks if the current matric and passed in matrix are the same
    //size, if they are meets together the current matrix and a passed in matrix
    //using the carrot top operator so matrix ^ matrix, return the result, else it
    //throws an error that will need to caught on the user's side if they want to
    //prevent crashing
    ZeroOne operator^(ZeroOne);
};