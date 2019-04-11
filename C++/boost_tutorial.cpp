#include <boost/lexical_cast.hpp>
#include <boost\variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <string>
#include <ostream>
#include <sstream>
#include <deque>
#include <vector>
using namespace std;

/*
Disadvantage: 
	not possible to remember of all function (some begin with a, some begin with s) 
	convert to string: using stringstream or sscanf(but not safe) 

Boost provide safe and convenient way to do the conversion from and to the text format

convet from string 
	atof     Convert string to double (function)
	atoi     Convert string to integer
	atol     Convert string to long integer
	atoll    Convert string to long long integer
	strtod   Convert string to double
	strtof   Convert String to float 
	strtol   Convert String to long integer
	strtold  Convert String to long double
	strtoll  Convert String to long long integer
	stroul   Convert string to unsigned long integer
	strtoull Convert String to unsigned long long integer 

	Convert to string
	stringstream strm;
	strm << int_val;
	string s = strm.str();
	inefficient
	
union {int i; float f;} u; // then the same storage flow can be saved as intger or flow
but not both at the same time

 the problem of union works must be plain of all data
 比如 union{int i; string f}u; //会报错的, not compiled
 
 variant: like union in C++
 boost::variant<int, string>u1, u2; //us store int, u2 string
 不能是 u1*=2; 因为* 没有overload for operator *
 需要get function:   u1 = boost::get<int>(u1)*2 //make sure int not wrong for the type
 string st = boost::get<string>(u1); //throw exception of bad_get 
 
 u1 = "good"; //u1 become string
 u1 = 32; // u1 become int 
 can used for different type of data at different time
 
 variant can be only to stored limited number of data,  //use static storage
 any can be used to store any type of data //use dynamic storage
 variant 更加efficient 对于memory, 
 but 不能用cout << 来print any variable, it is not overloaded, 需要any_cast<char>(y);
 
 difference between any_cast and get:
 Get the reference of data. any_cast get the copy of the data

 
*/
class DoubleVistor: public boost::static_visitor<>
{
	public:
		void operator() (int & i ) const{
		i+= 1;
	}

	void operator() (string & str) const{
		str += str;
	}

};

deque<char> queue;
//char get_async_data(){
boost::optional<char> get_async_data(){
// get data from queue, and return char
	if (!queue.empty())
		return boost::optional<char>(queue.back());
	else
		return boost::optional<char>(); // return empty optional'\0';
	//boost::variant<nullptr_t,char>v; this can be one of function return type
}

void sum (int & N){
	N = N+1;
}

int main()
{
	cout << "--------------------------lesson 1 lexical_cast-----------------------"<<endl;
	using boost::lexical_cast;
	using boost::bad_lexical_cast; 
	// more convenient, save
	int s = 23;
	string str = lexical_cast<string>(s);
	cout << str<<endl;
	str = "message" + lexical_cast<string>(s);
	cout << str << endl;

	array<char,64>msg = lexical_cast<array<char,64>>(23);

	s = lexical_cast<int>("3456");
	try{
		s = lexical_cast<int>("56.78"); // throw_except with bad_lexical_cast
	}
	catch(bad_lexical_cast & e){
		cout << "Exception caught:  "<<e.what() << endl;
	}

	s = lexical_cast<int>("3456yu",4); // not bad cast, only cast first 4 strings


	cout <<endl<< "--------------------------lesson 2 variant-----------------------"<<endl;
	// union
	/*
	union {int i; float f;} u; // then the same storage flow can be saved as intger or flow
	u.i =34;
	u.f = 2.3; // u.i is overwritten; the problem of union works must be plain of all data
	union {int i; string f;} u; // cannot be complier
	*/
	boost::variant<int,string>u1,u2; // u1, u2 can be stored not the same time
	u1 = 2;
	u2 = "hello";
	cout << u1<<"   "<<u2<<endl;

	//u1 = u1*2; * is not overloaded for variant
	u1 = boost::get<int>(u1)*2; // get function get integer from u1
	//string st = boost::get<string>(u1); //throw exception of bad_get()
	u1 = "get"; // u1 becomes a string
	u1 = 32; // u1 becomes a int again;
	//但variant 不能empty
	boost::variant<int,string>u3;
	cout << u3 << endl; // u3 is 0
	// using vistor to fetch 

	u1 = 2;
	boost::apply_visitor(DoubleVistor(),u1); // u1 becomes 4
	u2 = "hello ";
	boost::apply_visitor(DoubleVistor(),u2); // u2 becomes "hello hello "
	cout <<"new  "<< u1 << "  "<<u2<<endl;
	vector<boost::variant<int,string>>vec;
	vec.push_back("good");
	vec.push_back(23);
	vec.push_back("bad");
	DoubleVistor f;
	for (auto x: vec){
		boost::apply_visitor(DoubleVistor(),x);
		cout << x<<endl;
	}

	cout <<endl<< "--------------------------lesson 3 any-----------------------"<<endl;
	// any 可以为empty, 但variant 不能是empty
	// any use dynamic storage
	boost::any x,y,z; 
	x = string("hello");// x stored as a string, cannot be x = "hello";, since use char *
	x = 2.3;
	y = 'z';
	z = vector<int>();// z store as vector

	//cout << y <<endl; // will not be compiled, left shift operator cannot apply for any
	cout << boost::any_cast<char>(y)<<endl; // return a copy of y's data: 'z'
	//where variant 的 get得到的是reference，any_cast 得到的是copy of data
	cout<<boost::any_cast<double>(x) << endl;
	//cout << boost::any_cast<int> (x) <<endl; throw exception bad_any_cast
	//cout << boost::any_cast<float> (x) <<endl; throw exception bad_any_cast, type must be matched exactly

	if (x.empty())
		cout << "x is empty "<<endl; // has to use run time to check
	// variant can be checked using compile time
	if (x.type()==typeid(double))
		cout << "x is double "<<endl;


	boost::any_cast<vector<int>>(z).push_back(23);

	//int i = boost::any_cast<vector<int>>(z).back(); // crash because 因为pushback 23 是push back到copy的vector，不是真的vector

	int i;
	boost::any p = &i;
	int *pint = boost::any_cast<int *> (p);

	vector<boost::any>mm;
	mm.push_back(2);
	mm.push_back('a');
	mm.push_back(p); // push back pointer
	mm.push_back(boost::any());
	
	struct property{
		string name;
		boost::any value;
	};
	vector<property> properties;


	cout <<endl<< "--------------------------lesson 4 optional-----------------------"<<endl;

	boost::optional<char>op; //op is optional, uninitialized, no char is constructed
	op = 'A'; // op contains 'A' with optional, we can return value we need for this function 
	// if op is uninitialized, it means the value is not valid
	// if op is initialized, the value is valid
	op = get_async_data();
	if (!op) // same: if (op!=0)
	{
		cout << "No data is available "<<endl; }
	else{
		cout << "op contains "<<op.get()<<endl; // crash if op is empty
		cout << "op contains "<<*op <<endl;  // op is not modelled as pointer but similar crash if is uninitialized
	}
	op.reset(); // reset op uninitialzed state;
	//cout<<op.get_value_or("z")<<endl; // if it is initialzed it will return that value, if not initialized, return 'z'
	char *pp = op.get_ptr(); /// return null if op is empty

	//optional can store any kind of data
	struct A{string name; int value;};
	A a;
	boost::optional<A> opA0; // constructor A is not called, uninitialized
	boost::optional<A> opA( a); // a is copy consturcted into opA
	cout << opA->name<<" "<<opA->value << endl;

	//pointer
	boost::optional<A*> opAP (&a);
	(*opAP)->name = "Bob";

	// reference
	boost::optional<A&> opAR(a);
	opAR->name = "Bob" ;// this changes a.name

	//relational operator
	boost::optional<int> i1(1);
	boost::optional<int> i2(9);
	boost::optional<int> i3;
	if (i1<i2)
		cout << "i2 is bigger"<<endl; // if both are initialized, same as *i1 < *i2
	// unitialized will be considered the smallest, i3 小于 i2, i1


	return 0;
}

