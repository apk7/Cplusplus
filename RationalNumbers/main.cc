
#include<iostream>
#include<utility>
#include<typeinfo>
#include<cmath>
#include<assert.h>
using namespace std;

// GCD using euclidean algorithm
int gcd(int a, int b){
	if (a*b !=0){
		if (abs(a)<abs(b)){std::swap(a,b);}	//swapping entries
		int r = a%b;
		return gcd(b,r);
		}
	else{return a;} 
}

//Rational class
class Rational{
	public:
        // constructor
        Rational(int n = 1, int d = 1);

        int numerator() const;  		// for accessing numerator(line 60)
        int denominator() const;		// for accessing denominator 
        void printRational() const;	// for printing rational number
        void reduce(); 			// Simplification of the fraction

        Rational& operator*=(Rational const& obj);
        Rational& operator+=(Rational const& obj);
        Rational& operator-=(Rational const& obj);
        Rational& operator/=(Rational const& obj);
        bool operator==(Rational const& obj);

	private:
        int num;
        int den;	
};

// member functions ----------------------------------------------------------
//Constructor(s)
Rational::Rational(int numVal, int denVal):num(numVal),den(denVal){
    if (denVal==0){
		cout<<"Error !! Denominator can't be zero."<<endl;
		exit(0); //ending the function
	}
	//reduce(); // fraction reduction automatically reduces to simplified representation. //Disabled now
}

// To get numerator and denominator //const should be used for getter functions
int Rational::numerator() const{
	return num;
	}
int Rational::denominator() const{
	return den;
	}
// reduction function
void Rational::reduce(){
	int div = gcd(num,den);
	if(abs(div) !=0){
		int newNum = num/div;
		int newDen = den/div;
		//To get the '-' sign in numerator, if it exist in denominator.
		if (newDen<0){
			newNum *= -1;
			newDen *= -1;
		}
        num = newNum;
        den = newDen;
	}
}

// Printing rational number
void Rational::printRational() const{
	if (denominator() == 0){
		cout<< "Error" <<endl;
	}
	else{
		cout <<numerator() << "/" << denominator() << endl;
	}
}

// Operator overloading
// "*=" operator ---------------------------------------------------------------------
Rational& Rational::operator*=(Rational const& obj){
	int newNum = numerator() * obj.numerator();
	int newDen = denominator() * obj.denominator();
    num = newNum;
    den = newDen;
	reduce();
	return *this;
}

// "-=" operator ---------------------------------------------------------------------
Rational& Rational::operator-=(Rational const& obj){
	int newNum = numerator()*obj.denominator() - obj.numerator()*denominator();
	int newDen = denominator() * obj.denominator();
    num = newNum;
    den = newDen;
	reduce();
	return *this;
}
// "+=" operator ---------------------------------------------------------------------
Rational& Rational::operator+=(Rational const& obj){
	int newNum = numerator()*obj.denominator() + obj.numerator()*denominator();
	int newDen = denominator() * obj.denominator();
    num = newNum;
    den = newDen;
	reduce();
	return *this;
}

// "/=" operator ---------------------------------------------------------------------
Rational& Rational::operator/=(Rational const& obj){
	int newNum = numerator() * obj.denominator();
	int newDen = denominator() * obj.numerator();
	num = newNum;
    den = newDen;
    reduce();
	return *this;
}

// "==" operator ---------------------------------------------------------------------
bool Rational::operator==(Rational const& obj){
	return (numerator() == obj.numerator() && denominator() == obj.denominator());
}

// Definition outside classs
// "+" operator ---------------------------------------------------------------------
Rational operator+(Rational lhs, Rational rhs){
	//Using member function
	Rational templhs = lhs;
	Rational temprhs = rhs;
    templhs += temprhs;
	return templhs;
}

// "-" operator ---------------------------------------------------------------------
//lhs-rhs
Rational operator-(Rational lhs, Rational rhs){
	//Using member function
	Rational templhs = lhs;
	Rational temprhs = rhs;
	templhs -= temprhs;
	return templhs;
}

// "*" operator ---------------------------------------------------------------------
Rational operator*(Rational lhs, Rational rhs){
	//Using member function
	Rational templhs = lhs;
	Rational temprhs = rhs;
	templhs *= temprhs;
	return templhs;
}

// "/" operator ---------------------------------------------------------------------
Rational operator/(Rational lhs, Rational rhs){
	//Using member function
	Rational templhs = lhs;
	Rational temprhs = rhs;
	templhs /= temprhs;
	return templhs;
}

// assert function
void assertfunc(Rational const& a, Rational const& val){

    int anum = a.numerator();
    int aden = a.denominator();

    int valnum = val.numerator();
    int valden = val.denominator();    
}

int main(){

	Rational f1(-3,12), f2(4,3), f3(0,1);
	
	Rational fr1 = f1 + f2;
	Rational fr2 = f1 * f2;
	Rational fr3 = 4 + f2;
	Rational fr4 = f2 + 5;
	Rational fr5 = 12 * f1;
	Rational fr6 = f1 * 6;
	Rational fr7 = f1 / f2;
	
    assert(fr1==Rational(13,12));cout<<"Pass"<<endl;
    assert(fr2==Rational(-1,3));cout<<"Pass"<<endl;
    assert(fr3==Rational(16,3));cout<<"Pass"<<endl;
    assert(fr4==Rational(19,3));cout<<"Pass"<<endl;
    assert(fr5==Rational(-3));cout<<"Pass"<<endl;
    assert(fr6==Rational(-3,2));cout<<"Pass"<<endl;
    assert(fr7==Rational(-3,16)); cout<<"Pass"<<endl;
}

