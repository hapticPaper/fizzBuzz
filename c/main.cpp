#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono; 


using namespace std;

const string fb[15] = { "FizzBuzz", "", "", "Fizz", "", "Buzz", "Fizz", "", "", "Fizz", "Buzz", "", "Fizz", "", ""};

string fbLookup (int n){
	return fb[n];
}

string fizzbuzz (int n)
{
	int fizz = n % 3;
	int buzz = n % 5;
	string report = "";
	if (fizz==0){
		report += "Fizz";
	}
	if (buzz==0){
		report += "Buzz";
	}
	return report;
}



const int iterations = 32000;
string results[iterations];

int calcbuzz (int n ){
	for(int x=0; x<n; x++){
		results[x]=fizzbuzz(x);		
		//cout << x <<": "<< results[x] << "\n";
		// cout << to_string(x) <<": " << fizzbuzz(x) << "\n";
	}
	return 0;
}

int main()
{	
	auto t1 = std::chrono::steady_clock::now().time_since_epoch();
	calcbuzz(iterations);
	auto t2 = std::chrono::steady_clock::now().time_since_epoch();	
	auto buildTime = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

	char s[45];
	sprintf(s,"Results produced %d: %d µs\n", iterations, buildTime); //elapsed.count());
	cout << s;


	auto rstart = steady_clock::now().time_since_epoch();
	int ff=0,bb=0,ffb=0,nn=0;
	for(int r=0; r<iterations; r++){
		if (results[r] == ""){
			nn++;
		}
		else if (results[r] == "Fizz"){
			ff++;
		}
		else if (results[r] == "Buzz"){
			bb++;
		}
		else {
			ffb++;
		}
	}

	auto rstop = steady_clock::now().time_since_epoch();
	auto countTime = std::chrono::duration_cast<std::chrono::microseconds>(rstop-rstart).count();

	char counts [75];
	sprintf(counts, "Fizz:%d Buzz: %d FizzBuzz: %d Blanks:%d Total: %d\n", ff, bb, ffb, nn, ff + bb + ffb + nn) ;
	cout << counts;
	char ttt [25];
	sprintf(ttt,"Counted in %d µs\n", countTime); 
	cout << ttt;
	return 0;
}
    