#include<vector>
// #include <algorithm>
// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <cmath>
// #include <cstdlib>
// #include <math.h>
// #include <typeinfo>
// #include <chrono>

using namespace std;
using value_type = double;

class Polynomial{
    private:
        int deg_m;
        value_type input_m;
        vector<value_type> coeff_m;

    public:
        //constructor
        Polynomial();
        Polynomial(vector<value_type> coeff);

        //member functions
        value_type operator[](value_type coeff_i) const;
        int degree() const;
        
        // Evaluation function
        value_type operator()(value_type const& x);

        //output function for std::ostream
        // Note to self: by declaring it as 'friend', this function will have
        //                 access to all private data members
        // friend ostream& operator<<(ostream& out, Polynomial const& in);
};
