#include<iostream>
#include<vector>
#include <assert.h> 
#include "Matrix.hh"
using namespace std;

// Member function definition
// Constructor - single value
Matrix::Matrix(size_t r, size_t c, double const value):row(r),col(c){
    rows.resize(r);
    for (int i = 0; i < rows.size(); i++){
        rows[i].resize(col,value);
    }
}

// Constructor - list/vector of values
Matrix::Matrix(size_t r, size_t c, vector<double> const value):row(r),col(c){
    // if(r*c != value.size()){
    //     cout<<"Error !!"<<endl;
    //     cout<<"Total number of input values for matrix creation should be, rows*column = "<<r*c<<".\n";
    //     exit(0);
    // }
    assert(r*c == value.size());
    rows.resize(r);
    int k = 0;
    for (size_t i = 0; i < rows.size(); i++){
        rows[i].resize(c);
        for (size_t j = 0; j < c;j++){
            rows[i][j] = value[k];
            k++;
        }
    } 
}

// Matrix member access
double Matrix::at(std::size_t i, std::size_t j) const{
    // if (i >= row || j >= col){
    //     cout<<"Error!!"<<endl;
    //     cout<<"Row value should be in range [0,"<<row-1<<"]"<<endl;
    //     cout<<"Column value should be in range [0,"<<col-1<<"]"<<endl; 
    //     exit(0);
    // }
    assert ( i >= 0 && i < row &&  j >= 0 && j < col);
    return rows[i][j];
}
double Matrix::operator()(std::size_t i, std::size_t j) const{
    assert ( i >= 0 && i < row &&  j >= 0 && j < col);
    return rows[i][j];
}

// Get size of the matrix
auto Matrix::getSize(int i) const{
    if (i == 0){return row;}
    else {return col;}
}

//Printing matrix
void Matrix::printMat() const{
    cout<<"\n";
    for (size_t i = 0; i < row; i++){
        cout<<"[";
        for (size_t j = 0; j < col; j++){
            cout<<"\t"<<at(i,j);
        }
        cout<<"\t]"<<endl;
    }
    cout<<"\n";
}

// Matrix addition (member function)
Matrix& Matrix::operator+=(Matrix const& B){
    //error for matrix size not being equal
    // if (row != B.row || col != B.col)
    // {
    //     cout<<"Error!! Size of the matrix not equal.\n Ending program."<<endl;
    //     exit;
    // }
    assert(row == B.row && col == B.col);
    //addition
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            rows[i][j] += B(i,j);
        }
    }
    return *this;
}

// Free operator functions
Matrix operator+(Matrix const& lhs, Matrix const& rhs){
    Matrix templhs = lhs;
    Matrix temprhs = rhs;
    templhs += temprhs;
    return templhs;
};
