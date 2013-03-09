//Lamog, Rob
//h1
//Hart
//03/07/13

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Address{
    unsigned number;	//	e.g. 6401 (disallowing fractional addresses)
	string street;		//	e.g. “Winnetka”
	string suffix;		//	e.g. “Avenue”
	string city;		//	e.g. “Woodland Hills”
	string state;		//	e.g. “CA”
	unsigned zip;		//	e.g. 91371 (no zip+4)
};

	//	We’re not going to worry about time zones, daylight saving time, fractions of a second,
	//		seconds, leap seconds, months, years, or leap years.
	//	We’re just indicating a time in a generic week.
	//	The first time in a week is 12:00 AM Sunday, one minute later is 12:01 AM Sunday
	//	The last time in a week is 11:59 PM Saturday
	//	There are 7 * 24 * 60 == 10080 possible times,
	//		because there are 10080 minutes in a week.
struct Time{
		//	always in [0, 6]:
		//	0 means Sunday, 1 means Monday, ... , 6 means Saturday
	unsigned day;
		//	false means at or after midnight, and before the following noon (AM)
		//	true means at or after noon, and before the following midnight (PM)
	bool pm;
	unsigned hour;		//	in [1, 12], e.g. 12 for 12 o’clock
	unsigned minute;	//	in [0, 59]
};	//	struct Time

void show( const Address & address );
void show( const Address address[], unsigned elements, unsigned desiredZip );
void show( const Address address[], unsigned addressElements, const unsigned desiredZip[], unsigned desiredZipElements );
string convertDayToString(const Time &time); //my own function
void show( const Time & time );
bool ok( const Time & time );
int compare( const Time & time0, const Time & time1 );
void input( Time & time );

int main() {
	//Loading up Address structs for testing
	Address a1 = {21136, "Alaminos", "Drive", "Santa Clarita", "CA", 91350};
	Address a2 = {27007, "Santa Clarita", "Lane", "Santa Clarita", "CA", 91350};
	Address a3 = {625, "Lincoln", "Boulevard", "Venice", "CA", 90291};
	Address a4 = {2819, "Pico", "Boulevard", "Santa Monica", "CA", 90404};
	Address a5 = {750, "First", "Street", "Lake Oswega", "OR", 97034};
	Address a6 = {18212, "Chase", "Street", "Northridge", "CA", 91324};
	Address a7 = {5325, "Kester", "Avenue", "Van Nuys", "CA", 91411};
	//Loading array of Address structs for second function
	Address addyList[7] = {a1, a2, a3, a4, a5, a6, a7};
	//Loading array of desired zips for third function
	unsigned zipList[2] = {91350, 91411};
	//Loading up Time structs for testing
	Time t1 = {0, false, 12, 1};
	Time t2 = {0, 0, 12, 0};
	Time t3 = {4, true, 5, 30};
	Time t4 = {1, false, 11, 60}; //Should return false time input
	Time t5 = {7, 1, 9, 1}; //Should return false time input
	Time t6 = {0, 0, 12, 0};

/*
	//Testing Address functions
	//First function
	show(a1);
	cout << "\\/\\_[=]" << endl;
	
	//Second function
	show(addyList, 7, 91350);
	cout << "\\/\\_[=]" << endl;
	
	//Third function
	show(addyList, 7, zipList, 2);
	cout << "\\/\\_[=]" << endl;
	
	//Testing Time functions
	//Fourth function
	show(t2);
	cout << "\\/\\_[=]" << endl;
	
	//Fifth function
	cout << ok(t2) << endl;
	cout << "\\/\\_[=]" << endl;
*/
	//Sixth function
	cout << compare(t1, t2) << endl;
	cout << "\\/\\_[=]" << endl;
	
	cout << endl;
	return 0;
} //main

void show( const Address & address ) {
	cout << address.number << " " << address.street << " " << address.suffix << endl
	<< address.city << ", " << address.state << " " << address.zip << endl;
	
	//Test this line locally instead of in sourceLair. %s doesn't like dot notation in sourceLair or everywhere?
	//printf("%u %s %s/n%s %s %u", address.number, address.street, address.suffix, address.city, address.state, address.zip);
} //show( const Address & address )

void show( const Address address[], unsigned elements, unsigned desiredZip ) {
	for (int i = 0; i < elements; i++){
		if (desiredZip == address[i].zip){
			show(address[i]);
			cout << "------------------------------" << endl;
		}
	}
} //show( const Address address[], unsigned elements, unsigned desiredZip )

void show( const Address address[], unsigned addressElements, const unsigned desiredZip[], unsigned desiredZipElements ) {
	for (int i = 0; i < desiredZipElements; i++){
		for (int j = 0; j < addressElements; j++){
			if (desiredZip[i] == address[j].zip){
				show(address[j]);
				cout << "------------------------------" << endl;
			}
		}
	}
} //show( const Address address[], unsigned addressElements, const unsigned desiredZip[], unsigned desiredZipElements )

string convertDayToString(const Time &time){
	const string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	return days[time.day];
} //convertDayToString(const Time &time)

void show( const Time & time ){
	cout << convertDayToString(time) << " " << time.hour << ":";
	if (time.minute == 0) cout << "00" << " ";
	else cout << time.minute << " ";
	if (time.pm == 0) cout << "AM" << endl;
	else cout << "PM" << endl;
} //show( const Time & time )

bool ok( const Time & time ){
	if ((time.day < 0) || (time.day >= 7)) return false;
	if ((time.hour < 1) || (time.hour >= 13)) return false;
	if ((time.minute < 0) || (time.minute >= 60)) return false;
	return true;
} //bool ok( const Time & time )

int compare( const Time & time0, const Time & time1 ){
	string msg = "Time/s incorrectly entered.";
	
	if ((!ok(time0)) || (!ok(time1))){
		//cerr <<endl <<"Fatal error: " <<msg <<endl;
		//exit( EXIT_FAILURE );
		
		cout << endl << "Fatal error: " << msg << endl;
	}
	
	if (time0.day < time1.day) return -1;
	else if ((time0.day == time1.day) && (time0.pm == false) && (time1.pm == true)) return -1;
	else if ((time0.day == time1.day) && (time0.pm == time1.pm) && (time0.hour < time1.hour)) return -1;
	else if ((time0.day == time1.day) && (time0.pm == time1.pm) && (time0.hour == time1.hour) && (time0.minute < time1.minute)) return -1;
	else if ((time0.day == time1.day) && (time0.pm == time1.pm) && (time0.hour == time1.hour) && (time0.minute == time1.minute)) return 0;
	else return 1;
	return 9999; //bogus return in case of error
} //int compare( const Time & time0, const Time & time1 )

void input( Time & time ){
	
} //void input( Time & time )
