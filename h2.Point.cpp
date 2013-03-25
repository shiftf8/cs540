//Lamog, Rob
//h2.Point
//Hart
//04/11/13

#include <cmath>
#include <iostream>
using namespace std;

class Point{
    public:
		Point( double x = 0, double y = 0 );
		double getX() const;
		double getY() const;
		Point & setX( double x ); // mutator, returning reference to self
		Point & setY( double y );
		const Point & output() const;
		double distance( const Point & other ) const;
	
	private:
		double x;
		double y;
};

double area( const Point & a, const Point & b, const Point & c );

int main(){

	return 0;
} //main()

Point::Point( double x, double y ){
	setX(x);
	setY(y);
}

double Point::getX() const{
	return x;
}

double Point::getY() const{
	return y;
}

Point &Point::setX( double x ){
	this->x = x;
	return *this;
}

Point &Point::setY( double y ){
	this->y = y;
	return *this;
}

const Point &Point::output() const{
	cout << "(" << getX() << ", " << getY() << ")" << endl;
	return *this;
}

double Point::distance( const Point & other ) const{
	double lengthX, lengthY, distanceXY;
	
	lengthX = abs(getX() - other.getX());
	lengthY = abs(getY() - other.getY());
	distanceXY = sqrt(pow(lengthX, 2) + pow(lengthY, 2));
	//cout << distanceXY << endl;
	return distanceXY;
}

double area( const Point & a, const Point & b, const Point & c ){
	double lengthAB, lengthBC, lengthCA, halfPerimeter, areaOfTriangle;
	
	lengthAB = a.distance(b);
	lengthBC = b.distance(c);
	lengthCA = c.distance(a);
	halfPerimeter = (lengthAB + lengthBC + lengthCA) / 2;
	areaOfTriangle = sqrt(halfPerimeter * (halfPerimeter - lengthAB) * (halfPerimeter - lengthBC) * (halfPerimeter - lengthCA));
	return areaOfTriangle;
}
