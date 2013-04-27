//Lamog, Rob
//Hart
//Practice Test h2.Point
//April 25, 2013

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool die( const string & msg );

class Point{
    public:
		Point( double x = 0, double y = 0 );
		double getX() const;
		double getY() const;
		Point & setX( double x );    //  mutator, returning reference to self
		Point & setY( double y );
		const Point & output() const;
		double distance( const Point & other ) const;
	
	private:
		double x;
		double y;
}; //must remember syntax for classes!!!! forgot semi-colon and compiler complained

double area( const Point & a, const Point & b, const Point & c );
double maxArea(const Point a[], unsigned elements);

int main() {
	Point a;
	a.output();
	cout << endl;
	
	Point b(4, 0);
	cout << a.distance(b) << endl;
	cout << endl;
	
	Point c(0, 3);
	cout << area(a, b, c) << endl;
	cout << endl;
	
	Point setOfPoints[10] = {
		Point(0, 0),
		Point(-1, 5),
		Point(-1, -5),
		//Point(5, 0),
		Point(0, 5),
		Point(-1, -5),
		Point(10, 10),
		Point(2, 3),
		Point(4, 4),
		Point(11, 11)
	};
	cout << maxArea(setOfPoints, 10) << endl;
//	cout << endl;
//	cout << area(setOfPoints[1], setOfPoints[2], setOfPoints[3]) << endl;
	
	cout << endl;
	//system("pause");
	return 0;
}

bool die( const string & msg ){
	//cerr <<"Fatal error: " <<msg << endl;
	//exit( EXIT_FAILURE );
	
	cout <<"Fatal error: " << msg << endl;
}

Point::Point(double x, double y){
	setX(x);
	setY(y);
}

double Point::getX() const{
	return this->x;
}

double Point::getY() const{
	return this->y;
}

Point & Point::setX( double x ){
	this->x = x;
	return *this;
}

Point & Point::setY( double y ){
	this->y = y;
	return *this;
}

const Point & Point::output() const{
	cout << "(" << getX() << ", " << getY() << ")" << endl;
	return *this;
}

double Point::distance( const Point & other ) const{
	return sqrt(pow(abs(this->x - other.getX()), 2) + pow(abs(this->y - other.getY()), 2));
}

double area( const Point & a, const Point & b, const Point & c ){ //special area function. returns 0 if the three points lie in a straight line.
	double s; //triangle perimeter
	
	if (((b.getY() - a.getY()) / (b.getX() - a.getX())) != ((c.getY() - b.getY()) / (c.getX() - b.getX()))){
		s = (a.distance(b) + b.distance(c) + c.distance(a)) / 2;
		//cout << "(" << a.distance(b) << " + " << b.distance(c) << " + " << c.distance(a) << ") / 2 = " << perimeter << endl;
		return sqrt(s * (s - a.distance(b)) * (s - b.distance(c)) * (s - c.distance(a))); //Heron's formula
	} else {
		//cout << "These three points lie in a straight line" << endl;
		return 0;
	}
}

double maxArea(const Point a[], unsigned elements){
	double greatestArea = 0;
	double temp;
	
	for (unsigned i = 0; i < elements - 1; i++){
		for(unsigned j = 0; j < elements; j++){
			temp = area(a[i], a[i + 1], a[j]);
			if (temp > greatestArea) greatestArea = temp;
			//cout << j << ", " << temp << " / " << greatestArea << " -- temp / greatestArea" << endl;
			//if (j == elements) cout << endl;
		}
		//cout << temp << " / " << greatestArea << " -- temp / greatestArea" << endl;
		//cout << endl;
	}
	
	return greatestArea;
}
