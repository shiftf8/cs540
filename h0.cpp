//Lamog, Rob
//h0
//Hart
//02/24/13

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool die( const string & msg );
void input( unsigned a[], unsigned elements );
bool isNumber(const string &userInput); //my own function
void output( const unsigned a[], unsigned elements );
unsigned howMany( const unsigned a[], unsigned elements, unsigned min, unsigned max );
bool allSame( const unsigned a[], unsigned elements );
bool allDifferent( const unsigned a[], unsigned elements );
unsigned changes( const unsigned a[], unsigned elements );
void f( unsigned result[], const unsigned data[], unsigned dataElements, const unsigned index[], unsigned indexElements );
unsigned g( const unsigned a[], unsigned elements );

int main() {
    	unsigned a[3];
		unsigned b[20] = {3, 5, 10, 9, 50, 100, 1000, 14, 15};
		unsigned r[20];
		const unsigned d[] = {1000, 3000, 5000, 3000, 8888};
		const unsigned i[] = {2, 0, 2, 3, 4, 0};
		const unsigned x[] = {10, 10, 8, 8, 5, 5, 5, 5, 3};
		const unsigned y[] = {5, 4, 5, 5};
		const unsigned z[] = {10, 9, 2};

		input(a, 3);
		output(a, 3);
		output(b, 3);
		cout << "howMany: " << howMany(b, 3, 1, 13) << endl;
		cout << "allSame: " << allSame(b, 3) << endl;
		cout << "allDifferent: " << allDifferent(a, 3) << endl;
		cout << "changes: " << changes( b, 8 ) << endl;
		f( r, d, 5, i, 6 );
		cout << "array code: " << g(x, 9) << endl;
		cout << "array code: " << g(y, 4) << endl;
		cout << "array code: " << g(z, 1) << endl;
		
		cout << endl;
		return 0;
}

bool die( const string & msg ){
		//cerr <<endl <<"Fatal error: " <<msg <<endl;
		//exit( EXIT_FAILURE );
		
		cout << endl << "Fatal error: " << msg << endl;
}

void input( unsigned a[], unsigned elements ){
		string inputStr;
		string nan = "NAN entered.";
		int userInt;
		
		for (int i = 0; i < elements; i++){
				cout << "[" << i << "]: ";
				//cin >> a[i];
				getline (cin, inputStr);
				
				/* \\Test code
				int x = isNumber(inputStr);
				cout << inputStr << " / " << x << endl;
				*/
				
				if (isNumber(inputStr)) {
						stringstream(inputStr) >> userInt;
						a[i] = userInt;
				}	else die(nan);
				
				//cout << userInt;
				cout << endl;
		}
		
		/* \\Test code
		cout << "{";
		for (int j = 0; j < elements; j++){
				cout << a[j];
				if (j == elements - 1) cout << "}" << endl;
				else cout << ", ";
		}
		*/
}

bool isNumber(const string &userInput){
		bool isNum;
		
		for (int i = 0; i < userInput.length(); i++){
				if (isdigit(userInput[i])) isNum = 1;
				else {
						isNum = 0;
						break;
				}
		}
		return isNum;
}

void output( const unsigned a[], unsigned elements ){
		for (int i = 0; i < elements; i++){
				cout << a[i];
				if (i == elements - 1) cout << endl;
				else cout << ", ";
		}		
}

unsigned howMany( const unsigned a[], unsigned elements, unsigned min, unsigned max ){
		int count = 0;
		
		for (int i = 0; i < elements; i++){
				if ((a[i] >= min) && (a[i] <= max)) count++;
		}
		return count;
}

bool allSame( const unsigned a[], unsigned elements ){
		int count = 0;
		
		for (int i = 0; i < elements; i++){
				//cout << a[i] << " / " << a[elements - 1] << endl;
				if (a[i] == a[elements - 1]) count++;
		}
		return count == elements ? 1 : 0;
}

bool allDifferent( const unsigned a[], unsigned elements ){
		int count = 0;
		
		for (int i = 0; i < elements; i++){
				for (int j = 0; j < elements; j++){
						if (a[i] == a[j]) count++;
				}
		}
		return count == elements ? 1 : 0;
}

unsigned changes( const unsigned a[], unsigned elements ){
		int count = 0;
		bool isIncreasing, holdState = 0;
		
		if (a[0] < a[1]){
				isIncreasing = 1;
				holdState = 1;
		}
		
		for (int i = 0; i < elements - 1; i++){
				if (a[i] > a[i + 1]){
						isIncreasing = 0;
						if (holdState != isIncreasing){
								count++;
								holdState = isIncreasing;
								//cout << holdState << endl;
						}
						//cout << isIncreasing;
				}
				if (a[i] < a[i + 1]){
						isIncreasing = 1;
						if (holdState != isIncreasing){
								count++;
								holdState = isIncreasing;
								//cout << holdState << endl;
						}
						//cout << isIncreasing;
				}
		}
		//cout << endl;
		return count;
}

void f( unsigned result[], const unsigned data[], unsigned dataElements, const unsigned index[], unsigned indexElements ){
		int maxIndexElement = 0;
		string oor = "Index elements out of range.";
		
		for (int i = 0; i < indexElements; i++){
				if (index[i] > maxIndexElement) maxIndexElement = index[i];
		}
		
		if (maxIndexElement >= dataElements) die(oor);
		else {
				for (int j = 0; j < indexElements; j++){
						result[j] = data[index[j]];
						//cout << result[j] << " ";
				}
		}
}

unsigned g( const unsigned a[], unsigned elements ){
		if (elements < 2) return 0;
		if (elements >= 2){
				int countChangedState = 0;
				int countEqualState = 0;
				int countGreaterThanState = 0;
				int countLessThanState = 0;
				bool isGreaterThan = false;
				bool isEqual = false;
				bool greaterThanState = false;

//				cout << "before loop: " << countChangedState << endl;
			
				if (a[0] > a[1]){
						isGreaterThan = true;
						greaterThanState = true;
				}
				

				for (int i = 0; i < elements - 1; i++){
						if (a[i] > a[i + 1]){
								isGreaterThan = true;
								countGreaterThanState++;
								if (greaterThanState != isGreaterThan){
										countChangedState++;
										greaterThanState = isGreaterThan;
										//cout << "greater" << endl;
								}
						}
//				cout << "inside loop: " << countChangedState << " / spin: " << i + 1 << endl;
						if (a[i] == a[i + 1]){
								isEqual = true;
								countEqualState++;
								//cout << "equal" << endl;
						}
						if (a[i] < a[i + 1]){
								isGreaterThan = false;
								countLessThanState++;
								if (greaterThanState != isGreaterThan){
										countChangedState++;
										greaterThanState = isGreaterThan;
										//cout << "less" << endl;
								}
						}
				}
//				cout << "after loop: " << countChangedState << endl;
				if ((isGreaterThan == 1) && (countGreaterThanState == elements - 1) && (countEqualState == 0)) return 1;
				if ((isEqual == 1) && (countEqualState == elements - 1)) return 2;
				if ((countChangedState == 1) && (countGreaterThanState > 0) && (countEqualState > 0) && (countLessThanState == 0)) return 3;
				if ((isGreaterThan == 0) && (countLessThanState == elements - 1) && (countEqualState == 0)) return 4;
				if ((countLessThanState > 0) && (countGreaterThanState > 0) && (countEqualState == 0)) return 5;
				if ((countEqualState > 0) && (countGreaterThanState == 0) && (countLessThanState > 0)) return 6;
				if ((countGreaterThanState > 0) && (countEqualState > 0) && (countLessThanState > 0)) return 7;

				return 99999; //bogus return
		}
}
