#include <string>
#include <iostream>

using namespace std;

template <typename T> 
T GimmeAType(T thisthing)
{
	T mything(thisthing);
                   
	return mything;
}
 
template <class T>
class Morphing
{                 
public: 
         
	Morphing( std::string  name ,  T  thing) {
		name_ = name;
		thing_ = thing;
		//cout << "is a " << typeof(T) << endl;
	}

	std::string GetName() { return name_; }
	T Get() { return thing_; }

private:
	std::string name_;
	T thing_;
};           

int main (int argc, char **argv )
{

	int life(42);
	string a("string");
	char b('b');

	
	//cout << "this int is " << GimmeAType(life) << endl;
	//cout << "this Char is " << GimmeAType(b) << endl;
	//cout << "this string is " << GimmeAType(a) << endl;

	Morphing<int> m(a, life);

	cout << "name = " << m.GetName() << endl; 
	cout << "name = " << m.Get() << endl; 
	return 0;   
}
