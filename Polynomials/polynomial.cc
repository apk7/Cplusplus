#include<vector>
#include "Polynomial.hh"
using namespace std;
using value_type = double;

//Constructors
Polynomial::Polynomial()
    :deg_m(0),coeff_m(1,0)
    {}
Polynomial::Polynomial(vector<value_type> coeff)
    :deg_m(coeff.size()-1),coeff_m(coeff)
    {}

//member functions

//Declaration of free function power
value_type power(value_type const& val, value_type const& pow); 

//'[]' operator
value_type Polynomial::operator[](value_type coeff_i) const{
    return coeff_m[coeff_i];
}
// getter function for the degree of a polynomial
int Polynomial::degree() const{
    return deg_m;
}

// evaluation
value_type Polynomial::operator()(value_type const& x){
    value_type polval;
    for (size_t i = 0; i <= degree(); i++){
        polval += operator[](i) * power(x,i); 
    }
    return polval;
}

//output operator "std::ostream"
//Note to self: don't forget referencing '&' for out,in and function ostream
ostream& operator<< (ostream& out, Polynomial const& in){
    for (size_t i = 0; i <= in.degree(); i++)
    {
        if (i == 0){
            // out<<" "<<in.coeff_m[i]<<" +";
            out<<" "<<in[i]<<" +"; //if not declared as member function
        }
        else if (i == in.degree()){
            // out<<" "<<in.coeff_m[i]<<"x^("<<i<<")"<<endl;
            out<<" "<<in[i]<<"x^("<<i<<")"<<endl; //if not declared as member function
        }
        else {
            // out<<" "<<in.coeff_m[1] <<"x^("<<i<<") +"; 
            out<<" "<<in[i] <<"x^("<<i<<") +"; //if not declared as member function
        }
    }
    return out;
}

Polynomial operator+(Polynomial const& lhs, Polynomial const& rhs){
    int maxdeg = max(lhs.degree(),rhs.degree());
    cout<<"maximum degree = "<<maxdeg<<endl;
    vector<value_type> newCoeff(maxdeg+1,0);
    for (size_t i = 0; i <= maxdeg; i++){
        newCoeff[i] = lhs[i] + rhs[i];
        //cout<<lhs[i]<<" + "<<rhs[i]<<" = "<<newCoeff[i]<<endl;
    }
    return Polynomial(newCoeff);
}

Polynomial operator-(Polynomial const& lhs, Polynomial const& rhs){
    int maxdeg = max(lhs.degree(),rhs.degree());
    vector<value_type> newCoeff(maxdeg+1,0);
    for (size_t i = 0; i <= maxdeg; i++){
        newCoeff[i] = lhs[i] - rhs[i];
        //cout<<lhs[i]<<" - "<<rhs[i]<<" = "<<newCoeff[i]<<endl;
    }
    return Polynomial(newCoeff);
}

value_type power(value_type const& val, value_type const& pow){
    if (pow > 1){
        return (val*power(val, pow-1));
    }
    else if(pow == 0){
        return 1;
    }
    else{
        return val;
    }
}