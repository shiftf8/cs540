//Lamog, Rob
//h2.Transaction
//Hart
//04/11/13

#include <iostream>
#include <string>
using namespace std;

class Transaction{
    public:
		Transaction( unsigned doughnuts, unsigned carburetors = 0, unsigned racquets = 0 );
		unsigned getDoughnuts() const;  // return the number of doughnuts purchased in this transaction
		unsigned getCarburetors() const;  // return the number of carburetors purchased in this transaction
		unsigned getRacquets() const;  // return the number of racquets purchased in this transcation
		double getSubtotal() const;  // return the total cost of this purchase, excluding sales tax
		double getTotal() const;  // return the total cost of this purchase, including sales tax
	
	private:
		static const double eachDoughnut = .4;
		static const double eachCarburetor = 200;
		static const double eachRacquet = 75;
		static const double salesTax = 1.09;
	
		unsigned doughnuts;
		unsigned carburetors;
		unsigned racquets;
		double subtotal;
		double total;
}; // class Transaction

void report( const Transaction transaction[], unsigned elements );

int main(){

	return 0;
} //main()

Transaction::Transaction( unsigned doughnuts, unsigned carburetors, unsigned racquets ){
	this->doughnuts = doughnuts;
	this->carburetors = carburetors;
	this->racquets = racquets;
}

unsigned Transaction::getDoughnuts() const{
	return doughnuts;
}

unsigned Transaction::getCarburetors() const{
	return carburetors;
}

unsigned Transaction::getRacquets() const{
	return racquets;
}

double Transaction::getSubtotal() const{
	return (getDoughnuts() * eachDoughnut) + (getCarburetors() * eachCarburetor) + (getRacquets() * eachRacquet);
}

double Transaction::getTotal() const{ //???
	return (getDoughnuts() * eachDoughnut * salesTax) + (getCarburetors() * eachCarburetor * salesTax) + (getRacquets() * eachRacquet);
}

void report( const Transaction transaction[], unsigned elements ){
	unsigned reportDoughnuts = 0;
	unsigned reportCarburetors = 0;
	unsigned reportRacquets = 0;
	double reportSubtotal = 0.0;
	double reportTotal = 0.0;
		
	for (int i = 0; i < elements; i++){
		reportDoughnuts += transaction[i].getDoughnuts();
		reportCarburetors += transaction[i].getCarburetors();
		reportRacquets += transaction[i].getRacquets();
		reportSubtotal += transaction[i].getSubtotal();
		reportTotal += transaction[i].getTotal();
	}
	
	cout << "doughnuts: " << reportDoughnuts << endl
		<< "carburetors: " << reportCarburetors << endl
		<< "racquets: " << reportRacquets << endl
		<< "$ without tax: $" << reportSubtotal << endl
		<< "$ with tax: $" << reportTotal << endl;
}
