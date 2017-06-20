#include <chrono>
#include <iostream>
using namespace std;

/* a precision neutral library for time and date

	clock: system clock
	std::chrono::system_clock: current time according to the system 系统什么时间，返回就是什么时间
	      system clock if tell me 2 hour past, it may not be true, 因为我们可以自己更改时间
	std::chrono::steady_clock:  goes at a uniform rate it always run the same speed

	std::chrono::high_resolution_clock:  provides smallest possible tick period, 如果需要higher resolution clock 用它

	// clock frequency or period is represented in ratio

	std::chrono::duration<>: represent time duration
	say I want to represent two hours, we need a number(2) and a unit (hour)
	duration<int,ratio<1,1>> # this duration can be used as number of seconds in a int, ratio<1,1> second, default for duration template

	duration <double, ratio<60,1>> # this can be represent number of minutes stored in a double
	#nanoseconds, microseconds, milliseconds, seconds, minutes, hours

	# each clock has its own predefined duration, e.g system_clock::duration -- duration <T, system_clock::period>
	# T can be any types, long,...

	std::chrono::time_point<>: represents a point of time 
	00:00 January 1, 1970 (universal time utc) - epoch of a clock
	time_point<system_clock, millisecond> we need clock, according to system clocks, the elapsed time since epoch in milliseconds

	system_clock::time_point -- time_point <system_clock, system_clock::duration>
	steady_clock::time_point -- time_point <steady_clock, steady_clock::duration>
	
	*/

int main(){
	std::ratio<1,10>r;
	cout << r.num <<"/"<<r.den<<endl; // print out numerator and denomiator
	// so I can clock period with the name method
	cout << chrono::system_clock::period::num << "/"<<chrono::system_clock::period::den<<endl; // computer running is 100 nanoseconds

	chrono::microseconds mi(2700); // 2700 microseconds;
	cout << mi.count() << endl; //2700
	//chron::nanoseconds na = mi;
	chrono::milliseconds mill =  chrono::duration_cast<chrono::milliseconds>(mi);// higher to lower resolution might be some info lost 
	// cast microseconds to milliseconds
	// if convert from a lower resolution to higher resolution, don't need duration cast
	mi = mill + mi; //2000+2700 = 4700
	cout << mi.count() << endl;

	chrono::system_clock::time_point tp = chrono::system_clock::now(); // current system clock
	cout << tp.time_since_epoch().count() <<endl;
	tp = tp + chrono::seconds(2);
	cout << tp.time_since_epoch().count() << endl;

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	cout << " I am bored "<<endl;
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	chrono::steady_clock::duration d = end-start;
	if (d == chrono::steady_clock::duration::zero())
		cout << "no time elapsed"<<endl;
	cout << chrono::duration_cast<chrono::microseconds> (d).count() << endl;

	return 0;

}