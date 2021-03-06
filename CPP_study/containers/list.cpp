
// list::unique
#include <iostream>
#include <cmath>
#include <list>
using namespace std;

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
class is_near
{
public:
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main ()
{
    double mydoubles[]={ 12.15,  2.72, 3.14, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
    list<double> mylist (mydoubles,mydoubles+10);
    
    for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        cout << " " << *it;
    cout << endl;
    
    mylist.sort();
    mylist.unique(); 

    for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        cout << " " << *it;
    cout << endl;
    
    mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35
    for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        cout << " " << *it;
    cout << endl;

    mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
    for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        cout << " " << *it;
    cout << endl;

    mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0

    mylist.unique (is_near());           //  2.72, 12.15, 72.25

    cout << "mylist contains:";
    for (list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
        cout << " " << *it;
    cout << endl;

    return 0;
}

