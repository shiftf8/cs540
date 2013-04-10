//Lamog, Rob
//h2.SparseArray
//Hart
//04/11/13

#include <iostream>
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
		
		//cout << endl << "Fatal error: " << msg << endl;
} //die( const string & msg )

SparseArray::SparseArray(){
	this->nonZeroElements = 0;
	this->indexArr = {0};
	this->valueArr = {0};
}

unsigned SparseArray::get( unsigned long long index ){	
	for (int i = 0; i < 20; i++){
		if (indexArr[i] == index) return valueArr[i];
	}
	
	return 0;
}

SparseArray &SparseArray::set( unsigned long long index, unsigned value ){
	if (index > 1e17) die("Number is not less than 1e17.");
	else if (nonZeroElements > 20) die("Cannot add another value. There are already 20 nonzero values assigned.");
	else if ((value == 0) && (get(index))){
		int i = 0;
		for (i; i < 20; i++){
			if (indexArr[i] == index) break;
		}
		//cout << index << " / " << value << " - " << i << endl;
		this->indexArr[i] = 0;
		this->valueArr[i] = 0;
		if (nonZeroElements != 0) this->nonZeroElements--;
		//cout << index << " / " << value << " setZero " << get(index) << endl;			
	} else {
		if (get(index)){
			int i = 0;
			for (i; i < 20; i++){
				if (indexArr[i] == index) break;
			}
			this->valueArr[i] = value;
			//cout << index << " / " << value << " resetValue " << get(index) << endl;			
		} else if (nonZeroElements >= 20) die("Cannot add another value. There are already 20 nonzero values assigned.");
		else {
			int i = 0;
			for (i; i < 20; i++){
				if (valueArr[i] == 0) break; //Edge case, it's possible for indexArr[i] to hold a value while valueArr[i] does not. Therefore utilizing valueArr[i] to check for first zero occurrence to set values, this keeps arrays parallel.
			}
			//cout << "NonZeroes - " << nonZeroElements << " indexArr[" << i << "]" << endl; //100 000 000 000 000 000
			this->indexArr[i] = index;
			//cout << index << endl;
			this->valueArr[i] = value;
			//cout << value << endl; //1 000 000 000 002
			if (get(index)) this->nonZeroElements++;
			//cout << index << " / " << value << " setIndex/Value " << "NonZeroes Now = " << nonZeroElements << " -- get(index) returns " << get(index) << endl << endl;			
		}
	}
	
	return *this;
}