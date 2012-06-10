#include <iostream>
#include <map>
#include <boost/format.hpp>
#include <stdlib.h>


using namespace std;

class Test;

struct TestStruct
{
        Test * test_ptr;
        bool created;
};
 

class Test {
public:
Test(){};

void Method()
{
        cout << "at this method" << endl;
}

bool MakeStruct ( TestStruct * & r_ptr)
{
    r_ptr = new TestStruct;
    r_ptr->created = true;

    cout << "and now " << r_ptr << endl;

    return true;
}

};


int main(int argc,char *argv[])
{

        Test * t = new Test();
        TestStruct * my_obj;

        cout << "uninitialized " <<  my_obj << endl;

        t->MakeStruct(my_obj);

        cout << "initialized " << my_obj << endl;

}
