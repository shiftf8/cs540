//Lamog, Rob
//h2
//Hart
//03/28/13

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Color
class Color{
private:
Color( unsigned red = 0, unsigned green = 0, unsigned blue = 0 ); // ctor
unsigned getRed() const; // accessor
unsigned getGreen() const; // accessor
unsigned getBlue() const; // accessor
Color & setRed( unsigned red ); // mutator
Color & setGreen( unsigned green ); // mutator
Color & setBlue( unsigned blue ); // mutator
Color & output() const;
private:

}; // Color

Color mixture( const Color & color0, const Color & color1, double weight = 0.5 );

bool die( const string & msg );

int main(){
    
	
	return 0;
}

bool die( const string & msg ){
		//cerr <<endl <<"Fatal error: " <<msg <<endl;
		//exit( EXIT_FAILURE );
		
		cout << endl << "Fatal error: " << msg << endl;
}
