#include"ZeroOne.h"

ZeroOne ZeroOne::operator+(ZeroOne rightSide){
    if(rows == rightSide.rows && columns == rightSide.columns){
        ZeroOne resultingMatrix(rows,columns);
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < columns; c++){
                resultingMatrix[r][c] = ptrArray[r][c] | rightSide.ptrArray[r][c];
            }
        }
        return resultingMatrix;
    }else {
        throw "Error:ZeroOne Meet- matrixes not of the same size";
    }
}

ZeroOne ZeroOne::operator^(ZeroOne rightSide){
    if(rows == rightSide.rows && columns == rightSide.columns){
        ZeroOne resultingMatrix(rows,columns);
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < columns; c++){
                resultingMatrix[r][c] = ptrArray[r][c] & rightSide.ptrArray[r][c];
            }
        }
        return resultingMatrix;
    }else {
        throw "Error:ZeroOne Join- matrixes not of the same size";
    }
}