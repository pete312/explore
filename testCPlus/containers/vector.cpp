
#include <iostream>
#include <vector>
#include <boost/format.hpp>

using namespace std;

class MyClass {

public:

	MyClass(const char *name)
	{
		name_ = name;
	}

	string get_name()
	{
		return name_;
	}

private:

	string name_;
};

struct NestStruct {
	string name;
	int someint;
};

struct NestVector {
	string name;
	vector <NestStruct> * int_v;
};

int main(int argc,char *argv[])
{
	vector<int> *v;
	vector<MyClass *> cv;

	v = new vector<int>;
	//cv = new vector<MyClass>

    cout << " size of empty " << cv.size() << endl;
    

	cv.push_back(new MyClass("one"));
    //cout << " size of one  " << cv.size() << endl;
   // cout << "access that one " << (*cv)[cv.size() -1 ] << endl;

	cv.push_back(new MyClass("two"));
	cv.push_back(new MyClass("three"));

	v->push_back( 3) ;
	v->push_back( 1) ;
	v->push_back( 4) ;
	v->push_back( 5) ;
	v->push_back( 78) ;
	

	for( vector<int>::iterator ii=v->begin() ; ii < v->end(); ++ii){
		std::cout << *ii << endl;
	}

	for( vector<MyClass * >::iterator ii=cv.begin() ; ii < cv.end(); ++ii){
                std::cout << (*ii)->get_name() << endl;
        }

	NestVector *n = new NestVector;

	//NestStruct n->int_t = new NestStruct();
	//n->name  = string("the numbers of pi");

	cout << "element 4 of v "  << (*v)[3] <<  endl;
	cout << "last element v "  << (*v->rbegin()) << endl;

	boost::format hex("%d");

	//for ( vector<int>::iterator iter= v->rbegin(); iter < v->end(); iter++) {
	//	
    //    if (iter > v->end() - 1 )
	//		cout << "last element " << (*iter) << endl;
	//}                      


 
}
