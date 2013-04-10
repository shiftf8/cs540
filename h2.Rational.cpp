//Lamog, Rob
//h2.Rational
//Hart
//04/11/13

#include <iostream>
using namespace std;

class Rational{
    public:
		Rational( unsigned long long numerator = 0, unsigned long long denominator = 1 );
		unsigned long long getNumerator() const;
		unsigned long long getDenominator() const;
		double getFloatingValue() const;
		const Rational & output() const;
		Rational add( const Rational & other ) const;
		static unsigned long long gcf( unsigned long long a, unsigned long long b );

	private:
		unsigned long long numerator;
		unsigned long long denominator;
		void simplify();
}; // class Rational
	
bool die( const string & msg );

int main(){

	return 0;
} //main()

bool die( const string & msg ){
		cerr <<endl <<"Fatal error: " <<msg <<endl;
		exit( EXIT_FAILURE );
		
		//cout << endl << "Fatal error: " << msg << endl;
} //die( const string & msg )

Rational::Rational( unsigned long long numerator, unsigned long long denominator ){
	this->numerator = numerator;
	this->denominator = denominator;
	
	if (denominator == 0) die("Illegal operation: Cannot divide by zero.");	
	simplify();
}

unsigned long long Rational::getNumerator() const{
	return numerator;
}

unsigned long long Rational::getDenominator() const{
	return denominator;
}

double Rational::getFloatingValue() const{
    return static_cast<double>(getNumerator()) / static_cast<double>(getDenominator());
}

const Rational & Rational::output() const{
	if (getDenominator() == 1) cout << getNumerator();
	else if (getNumerator() == 0) cout << "0";
	else cout << getNumerator() << " / " << getDenominator();
	
	cout << endl;
    return *this;
}

Rational Rational::add( const Rational & other ) const{
	return Rational((getNumerator() * other.getDenominator() + other.getNumerator() * getDenominator()), (getDenominator() * other.getDenominator()));
}

unsigned long long Rational::gcf( unsigned long long a, unsigned long long b ){
	while( a > 0 ){
		unsigned long long newA = b % a, newB = a;
		a = newA, b = newB;
	}

	return b;
}

void Rational::simplify(){
	unsigned long long greatestCommonFactor;
	
	greatestCommonFactor = gcf(numerator, denominator);
	numerator = numerator / greatestCommonFactor;
	denominator = denominator / greatestCommonFactor;
	
	//cout << greatestCommonFactor << endl;
}