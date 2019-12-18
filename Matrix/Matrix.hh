#include<iostream>
#include<vector>

using namespace std;
// Matrix class
class Matrix{
    private:
        double row;
        double col;
        vector < vector<double> > rows; //Vector having all values of matrix

    public:
        //constructor
        Matrix();
        Matrix(size_t r, size_t c, double const value);
        Matrix(size_t r, size_t c, vector<double> const value);

        // getter functions
        double at(std::size_t i, std::size_t j) const;
        double operator()(std::size_t i, std::size_t j) const;

        //get size of matrix
        auto getSize(int i) const;
        void printMat() const;
        
        //operator function(s)
        Matrix& operator+=(Matrix const& B);      
};



