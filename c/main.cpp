#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>

using namespace std::chrono; 
using namespace std;


const long iterations = 10000;	
const int testCount = 25;


struct fbRun{
	int fizz = 0;
	int buzz = 0;
	int fb = 0;
	int na = 0;
	int total = 0;
	int time = 0;
};
struct fbData {
	string data[iterations];
	int duration = 0;
	string approach="";
};


string fizzbuzz (int n)
{
	int fizz = n % 3;
	int buzz = n % 5;
	string fs = "";
	if (fizz==0){
		fs += "Fizz";
	}
	if (buzz==0){
		fs += "Buzz";
	}
	return fs;
}

fbData fizzbuzzMod(int m=iterations){
	fbData rset;
	for(int x=0; x<m; x++){
		int m15 = x % 15;
		if (m15==1 || m15 ==2 || m15 == 4 || m15 == 7|| m15 == 11|| m15 == 13|| m15 == 14){
			rset.data[x]="";
		}
		else if (m15==3 || m15 ==6  || m15 == 9 || m15 == 12){
			rset.data[x]= "Fizz";
		}
		
		else if (m15==5 || m15 ==10  ){
			rset.data[x]= "Buzz";
		}
		else{
			rset.data[x]= "FizzBuzz";
		};
		}
	return rset;
}

fbData fizzbuzzClassic(int m=iterations){
	fbData fset;
	for(int x=0; x<m; x++){
		int m5 = x % 5;
		int m3 = x % 3;
		string r = "";
		if (m3==0){
			r="Fizz";
		}
		if (m5==0){
			r+= "Buzz";
		}		
		fset.data[x]=r;
	}
	return fset;
}


fbData simpleClassic(int m=iterations){
	fbData fset;
	for(int x=0; x<=m; x++){
		if (x % 15 == 0){
			fset.data[x]="FizzBuzz";
		}
		else if (x % 3 == 0){
			fset.data[x]="Fizz";
		}	
		else if (x % 5 == 0){
			fset.data[x]="Buzz";
		}	
		else {
			fset.data[x]="";
		}	
	}
	return fset;
}

	

// void calcbuzz (int n ){
// 	for(int x=0; x<n; x++){
// 		//results[x]=fizzbuzz(x);		
// 		//cout << x <<": "<< results[x] << "\n";
// 		// cout << to_string(x) <<": " << fizzbuzz(x) << "\n";
// 	}
// 	return;
// }

fbData fbLookup(int m=iterations){
	const string fb[15] = { "FizzBuzz", "", "", "Fizz", "", "Buzz", "Fizz", "", "", "Fizz", "Buzz", "", "Fizz", "", ""};
	fbData rset;
	for(int x=0; x<m; x++){
		rset.data[x]=fb[x % 15];	
	}
	return rset;
}

fbData fbClassicMod(int m=iterations){
	fbData rset;
	for(int x=0; x<m; x++){
		if(x % 15 == 0){
			rset.data[x]="FizzBuzz"	;
		}
		else if(x % 3 == 0){
			rset.data[x]="Fizz"	;
		}
		else if(x % 5 == 0){
			rset.data[x]="Buzz"	;
		}
		else{
			rset.data[x]="";
		}
		
	}
	return rset;
}

template<class T>
fbData funcRunner (T func, int n, char* label){
	string stringLabel = std::string(label);
	auto t1 = std::chrono::steady_clock::now().time_since_epoch();
	fbData fbresults = func(n);
	auto t2 = std::chrono::steady_clock::now().time_since_epoch();	
	fbresults.duration = int(std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count());
	fbresults.approach = std::string(stringLabel); 
	// printf("%s:  %dμs for %d iterations\n", label , fbresults.duration , n); 
	std::cout << stringLabel << ": " << fbresults.duration<< "μs for "<< n << " iterations.\n";
	return fbresults;
}

fbRun fbCounter(fbData fbds, char* approach, int durr){
	fbRun newReport;
	//fbds = timer((*algo)(iterations), iterations, approach);


	auto st = std::chrono::steady_clock::now().time_since_epoch();

	for(int r=0; r<iterations; r++){
		if (fbds.data[r] == ""){
			newReport.na++;
		}
		else if (fbds.data[r] == "Fizz"){
			newReport.fizz++;
		}
		else if (fbds.data[r] == "Buzz"){
			newReport.buzz++;
		}
		else {
			newReport.fb++;
		}
		newReport.total++;
	}
	auto end = std::chrono::steady_clock::now().time_since_epoch();	
	newReport.time = int(std::chrono::duration_cast<std::chrono::microseconds>(end-st).count());
	cout << setw(15) << left << approach 
			<< "Execution: "<< setw(8) << durr 
			<< "Fizz: " << setw(8) << newReport.fizz 
			<< "Buzz: " << setw(8)  << newReport.buzz 
			<< "FizzBuzz: "<< setw(12)  << newReport.buzz
			<< "N/A: " << setw(8) << newReport.buzz 
			<< "Total: " << setw(to_string(iterations).length()+7) << newReport.buzz 
			<<  right << setw(9) << "Report: " << setw(6) << newReport.time  << "μs"
			<< "\n";
	return newReport;
}



int main()
{	
	float lookuptotal = 0;
	for (int test=0; test<25; test++){		
		fbData dta = funcRunner(fbLookup, iterations, "Lookups");	
		lookuptotal+=dta.duration;
	}
	
	float modTotal = 0;
	for (int test=0; test<25; test++){
		fbData dta2 = funcRunner(fizzbuzzMod, iterations, "fizzbuzzMod");	
		modTotal+=dta2.duration;		
	}

	for (int test=0; test<25; test++){
		fbData dta2 = funcRunner(fizzbuzzClassic, iterations, "fizzbuzzClassic");			
	}

	for (int test=0; test<25; test++){
		fbData dta2 = funcRunner(fbClassicMod, iterations, "fizzbuzzClassicMod");			
	}
	
	// for (int test=0; test<25; test++){
	// 	fbData dta2 = funcRunner(simpleClassic, iterations, "simpleClassic");			
	// }

	cout << "\n";
	cout << "Average speed for direct lookups was " << lookuptotal/testCount << "μs \n" ;
	cout << "Average speed for weird mods was " << modTotal/testCount << "μs \n";
	// cout << "Average speed for direct lookups was \n" << lookuptotal/testCount;
	// cout << "Average speed for direct lookups was \n" << lookuptotal/testCount;
	


	//fbRun lookups = fbCounter(dta, "Lookups", dta.duration);
	
	
	//fbRun lookups2 = fbCounter(dta, "fizzbuzzMod", dta.duration);
	

}
// 	lookups = fbCounter(fbLookup, "Lookups");
// 	fbRun lookups;
// 	lookups = fbCounter(results, "Lookups");



// 	// char s[45];
// 	// sprintf(s,"Results produced %d: %d µs\n", iterations, buildTime); //elapsed.count());
// 	// cout << s;


// 	auto rstart = steady_clock::now().time_since_epoch();
// 	int ff=0,bb=0,ffb=0,nn=0;
// 	for(int r=0; r<iterations; r++){
// 		if (results[r] == ""){
// 			nn++;
// 		}
// 		else if (results[r] == "Fizz"){
// 			ff++;
// 		}
// 		else if (results[r] == "Buzz"){
// 			bb++;
// 		}
// 		else {
// 			ffb++;
// 		}
// 	}

// 	auto rstop = steady_clock::now().time_since_epoch();
// 	auto countTime = std::chrono::duration_cast<std::chrono::microseconds>(rstop-rstart).count();

// 	char counts [75];
// 	sprintf(counts, "Fizz:%d Buzz: %d FizzBuzz: %d Blanks:%d Total: %d\n", ff, bb, ffb, nn, ff + bb + ffb + nn) ;
// 	cout << counts;
// 	char ttt [25];
// 	sprintf(ttt,"Counted in %d µs\n", countTime); 
// 	cout << ttt;
// 	return 0;
// }
    