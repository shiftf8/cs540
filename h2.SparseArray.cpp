//Lamog, Rob
//h2.SparseArray
//Hart
//04/11/13

#include <iostream>
#include <string>
using namespace std;

class SparseArray{
    public:
		SparseArray(); // construct an SparseArray with no nonzero elements
		unsigned get( unsigned long long index ); // return an element from the array
		SparseArray & set( unsigned long long index, unsigned value ); // set array element to value
	private:
		unsigned nonZeroElements;
		unsigned long long indexArr[20];
		unsigned valueArr[20];
}; // SparseArray

bool die( const string & msg );

int main() {

    return 0;
} //main()

bool die( const string & msg ){
		cerr <<endl <<"Fatal error: " <<msg <<endl;
		exit( EXIT_FAILURE );
		
		//cout << endl << "Fatal error: " << msg << endl << endl;
} //die( const string & msg )

SparseArray::SparseArray(){
	this->nonZeroElements = 0;
	this->indexArr[0] = 0;
	this->valueArr[0] = 0;
}

unsigned SparseArray::get( unsigned long long index ){	
	for (int i = 0; i < 20; i++){
		if (indexArr[i] == index) return valueArr[i];
	}
	
	return 0;
}

SparseArray &SparseArray::set( unsigned long long index, unsigned value ){
	if (index > 1e17) die("Number is not less than 1e17.");
	if ((value == 0) && (get(index))){
		int i = 0;
		for (i; i < 20; i++){
			if (indexArr[i] == index) break;
		}
		for (i; i < 20; i++){
			if (i == 19){
				this->indexArr[i] = 0, this->valueArr[i] = 0;
				break;
			}
			this->indexArr[i] = this->indexArr[i + 1];
			this->valueArr[i] = this->valueArr[i + 1];
		}
		if (nonZeroElements != 0) this->nonZeroElements--;
		//cout << "Found Index to Zero: " << index << " / " << value << " setZero " << get(index) << " -- NonZeroes Now = " << nonZeroElements << endl;

		return *this;
	}
	if (get(index)){
		int i = 0;
		for (i; i < 20; i++){
			if (indexArr[i] == index) break;
		}
		this->valueArr[i] = value;
		//cout << "Found Index to Change: " << index << " / " << value << " resetValue " << get(index) << " -- NonZeroes Now = " << nonZeroElements << endl;			

		return *this;
	}
	if (nonZeroElements >= 20) die("Cannot add another value. There are already 20 nonzero values assigned.");
	this->indexArr[nonZeroElements] = index;
	this->valueArr[nonZeroElements] = value;
	if (get(index)) this->nonZeroElements++;
	//cout << index << " / " << value << " setIndex/Value " << "NonZeroes Now = " << nonZeroElements << " -- get(" << index << ") returns " << get(index) << endl << endl;

	return *this;
}