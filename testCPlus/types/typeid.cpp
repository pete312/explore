#include <stdint.h>
#include <iostream>
#include <typeinfo>
#include <map>
#include <vector>


using namespace std;




int main(int argc,char *argv[])
{

    long long longlong(1);

    

    cout << "typeid(double).name() is '" << typeid(double).name() << "'"  << endl;
    //cout << "typeid(* double).name() is '" << typeid(* double).name() << "'"  << endl;
    //cout << "typeid(* int).name() is '" << typeid(* int ).name() << "'"  << endl;
    cout << "typeid(int).name() is '" << typeid(int).name() << "'"  << endl;
    cout << "typeid(long).name() is '" << typeid(long).name() << "'"  << endl;
    cout << "typeid(long long).name() is '" << typeid(longlong).name() << "'"  << endl;
    cout << "typeid(int32_t).name() is '" << typeid(int32_t).name() << "'"  << endl;
    cout << "typeid(int64_t).name() is '" << typeid(int64_t).name() << "'"  << endl;
    cout << "typeid(bool).name() is '" << typeid(bool).name() << "'"  << endl;
    cout << "typeid(float).name() is '" << typeid(float).name() << "'"  << endl;
    
    

    std::vector<double> doubles ;
    std::vector<int> ints ;
    std::vector<int64_t > longs64 ;
    
}
