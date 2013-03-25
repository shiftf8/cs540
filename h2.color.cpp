//Lamog, Rob
//h2.Color
//Hart
//03/28/13

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class Color{
    public:
		Color( unsigned red = 0, unsigned green = 0, unsigned blue = 0 ); // ctor
		unsigned getRed() const; // accessor
		unsigned getGreen() const; // accessor
		unsigned getBlue() const; // accessor
		Color & setRed( unsigned red ); // mutator
		Color & setGreen( unsigned green ); // mutator
		Color & setBlue( unsigned blue ); // mutator
		const Color & output() const;
	
	private:
		unsigned red;
		unsigned green;
		unsigned blue;
}; // Color

Color mixture( const Color & color0, const Color & color1, double weight = 0.5 );
bool die( const string & msg );

int main(){
	Color c0;
	Color c1(1, 255, 0);
	//c1.setRed(-1);
	//c1.setGreen(256);
	c1.setBlue(33);
	cout << "]===[" << endl;
	
	cout << c1.getRed() << endl;
	cout << c0.getRed() << endl;
	cout << "]===[" << endl;

	c1.output();
	cout << "]===[" << endl;

	Color c2(0, 2, 0);
	Color c3(0, 0, 255);
	mixture(c2, c3).output(); //<0, 128, 128>
	cout << "]===[" << endl;

	return 0;
} //main()

bool die( const string & msg ){
		//cerr <<endl <<"Fatal error: " <<msg <<endl;
		//exit( EXIT_FAILURE );
		
		cout << endl << "Fatal error: " << msg << endl;
} //die( const string & msg )

Color::Color(unsigned red, unsigned green, unsigned blue){
	setRed(red);
	setGreen(green);
	setBlue(blue);
}

Color &Color::setRed(unsigned red){
	if (0 <= red && red < 256){
		this->red = red;
		return *this;
	} else die("Red out of range [0, 255]");
}

Color &Color::setGreen(unsigned green){
	if (0 <= green && green < 256){
		this->green = green;
		return *this;
	} else die("Green out of range [0, 255]");
}

Color &Color::setBlue(unsigned blue){
	if (0 <= blue && blue < 256){
		this->blue = blue;
		return *this;
	} else die("Blue out of range [0, 255]");
}

unsigned Color::getRed() const{
	return red;
}

unsigned Color::getGreen() const{
	return green;
}

unsigned Color::getBlue() const{
	return blue;
}

const Color &Color::output() const{
	cout << "<" << getRed() << ", " << getGreen() << ", " << getBlue() << ">" << endl;
	return *this;
}

Color mixture( const Color & color0, const Color & color1, double weight ){
	Color mix, temp;
	double weighted, intpart;
	
	if (color0.getRed()){
		weighted = color0.getRed() * weight;
		if (modf(weighted, &intpart) >= .5) mix.setRed(weighted + 1);
		else mix.setRed(weighted);
	}
	if (color0.getGreen()){
		weighted = color0.getGreen() * weight;
		if (modf(weighted, &intpart) >= .5) mix.setGreen(weighted + 1);
		else mix.setGreen(weighted);
	}
	if (color0.getBlue()){
		weighted = color0.getBlue() * weight;
		if (modf(weighted, &intpart) >= .5) mix.setBlue(weighted + 1);
		else mix.setBlue(weighted);
	}
	
	if (color1.getRed()){
		weighted = color1.getRed() * (1 - weight);
		if (modf(weighted, &intpart) >= .5) temp.setRed(weighted + 1);
		else temp.setRed(weighted);
	}
	if (color1.getGreen()){
		weighted = color1.getGreen() * (1 - weight);
		if (modf(weighted, &intpart) >= .5) temp.setGreen(weighted + 1);
		else temp.setGreen(weighted);
	}
	if (color1.getBlue()){
		weighted = color1.getBlue() * (1 - weight);
		if (modf(weighted, &intpart) >= .5) temp.setBlue(weighted + 1);
		else temp.setBlue(weighted);
	}

	mix.setRed(mix.getRed() + temp.getRed());
	mix.setGreen(mix.getGreen() + temp.getGreen());
	mix.setBlue(mix.getBlue() + temp.getBlue());
	
	return mix;
}
