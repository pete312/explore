#include <iostream>

using namespace std;

template <typename T> 
T GimmeAType(T thisthing)
{
	T mything(thisthing);
                   
	return mything;
}

template <class T>  
Morphing2
{                 
public: 
    
	Morphing2( std::string  name ,  T  thing) {
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




