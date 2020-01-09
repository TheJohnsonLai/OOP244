#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }

    // in_lab

    // TODO: write the implementation of display function HERE
	void Fraction::display() const {
		if (denom == -1) {
			cout << "Invalid Fraction Object!";
		}
		else if (denom == 1) {
			cout << num;
		}
		else {
			cout << num << "/" << denom ;
		}
	}


    // TODO: write the implementation of isEmpty function HERE
	bool Fraction::isEmpty() const {
		return (denom == -1);
	}

    // TODO: write the implementation of member operator+= function HERE
	Fraction& operator+= (Fraction& a, Fraction& b) {
		if (a.isEmpty() || b.isEmpty()) {
			a = Fraction();
			return a;
		}
		else {
			a.num  = a.num * b.denom + b.num * a.denom;
			a.denom = a.denom * b.denom;
			a.reduce();
			return a;
		}
	}
    
    // TODO: write the implementation of member operator+ function HERE
	Fraction operator+ (Fraction a, Fraction b) {
		//Fraction RR;
		if (a.isEmpty()) {
			return a;
		}
		else if (b.isEmpty()) {
			return b;
		}
		else {
			a.num = (a.num * b.denom) + (b.num * a.denom);
			a.denom = a.denom * b.denom;
			a.reduce();
			return a;
		}
	}
    
    // TODO: write the implementation of member operator* function HERE
	Fraction operator* (Fraction& a, Fraction& b) {
		if (a.isEmpty()) {
			return a;
		}
		else if (b.isEmpty()) {
			return b;
		}
		else {
			a.num = a.num * b.num;
			a.denom = a.denom * b.denom;
			a.reduce();
			return a;
		}
	}
}