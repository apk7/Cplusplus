#include "matrix.cc"
#include <cmath>
#include <limits>
#include <assert.h> 

using namespace std;

//Test function
bool compare(Matrix const& A, Matrix const& B){
    const auto epsilon = numeric_limits<double>::epsilon();
    bool equality = true;

    for (size_t i = 0; i < A.getSize(0) && equality == true; i++){
        for (size_t j = 0; j < A.getSize(1) && equality == true; j++){
            if( abs(A(i,j) - B(i,j)) > epsilon){
                equality = false;
            }
            // assert(abs(A(i,j) - B(i,j)) <= epsilon);
        }        
    }
    // if (equality == false){cout<<"Equality test: Failed\nMatrices are unequal upto "<<epsilon<<" precision."<<endl;}
    // else{cout<<"Equality test: Passed\nMatrices are equal upto "<<epsilon<<" precision."<<endl;}
    return equality;    
}

// Test functions
// Initilization testing
bool test_init(){

    size_t testRow = 2;
    size_t testCol = 10;
    size_t testVal = 1;

    Matrix testMat(testRow,testCol,testVal);

    bool init = testMat(0,0) ==  testVal && \
    testMat(testRow-1,testCol-1) == testVal && \
    testMat(0,testCol-1) == testVal && \
    testMat(testRow-1,0) == testVal;

    if(init == true){cout<<"Initialisation test: Passed"<<endl;}
    else{cout<<"Initialisation test: Failed"<<endl;}
    return init;
}

// Addition testing
bool test_add(){

    Matrix testIdenMat(3,3,{1,0,0,\
                            0,1,0,\
                            0,0,1});

    Matrix testZeroMat(3,3,{0,0,0,\
                            0,0,0,\
                            0,0,0});                        
    
    Matrix testMat1(3,3,{100,200,300,\
                        4.5,5.6,6.7,\
                        0.001,0.002,0.003});

    Matrix testMat2(3,3,{1,2,3,\
                        4,5,6,\
                        7,8,9});

    bool result = true;

    int i = 1;

    //Test1 Additive identity
    Matrix result1 = testIdenMat + testZeroMat;
    Matrix test1(3,3,{1,0,0,0,1,0,0,0,1});
    if(compare(result1,test1)){ cout<<"Addition Test"<<i<<":\tPassed"<<endl; }
    else { cout<<"Addition Test"<<i<<":\tFailed"<<endl; result = false; };
    i++;
    //Test2
    Matrix result2 = testIdenMat + testMat1;
    Matrix test2(3,3,{101,200,300,4.5,6.6,6.7,0.001,0.002,1.003});
    if(compare(result2,test2)){ cout<<"Addition Test"<<i<<":\tPassed"<<endl; }
    else { cout<<"Addition Test"<<i<<":\tFailed"<<endl; result = false; };
    i++;

    Matrix result3 = (testIdenMat + testMat1) + testMat2;
    Matrix result4 = testIdenMat + (testMat1 + testMat2) + testZeroMat;
    Matrix test3(3,3,{102,202,303,8.5,11.6,12.7,7.001,8.002,10.003});

    //Test3
    if(compare(result3,test3)&&compare(result4,test3)){ cout<<"Addition Test"<<i<<":\tPassed"<<endl; }
    else { cout<<"Addition Test"<<i<<":\tFailed"<<endl; result = false; };
    i++;

    // Test4 associativity
    if(compare(result3,result4)){ cout<<"Addition Test"<<i<<":\tPassed"<<endl; }
    else { cout<<"Addition Test"<<i<<":\tFailed"<<endl; result = false; };
    i++;

    // Test5 Commutavity
    Matrix result5 = testIdenMat + testMat1 + testMat2 + testZeroMat;
    Matrix result6 = testMat2 + testIdenMat + testZeroMat + testMat1;
    if(compare(result5,result6)){ cout<<"Addition Test"<<i<<":\tPassed"<<endl; }
    else { cout<<"Addition Test"<<i<<":\tFailed"<<endl; result = false; };
    i++;

}

bool test_access(){
    Matrix testMat(3,3,{1,2,3,\
                        4,5,6,\
                        7,8,9});

    assert(testMat(1,2) == 5);
    assert(testMat.at(2,0) == 7);
    cout<<"Access test:\tPassed"<<endl;
}


int main(){

    test_access();
    test_init();
    test_add();

}


