// constructing multisets
#include <iostream>
#include <set>
using namespace std;

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
	  bool operator() (const int& lhs, const int& rhs) const
	    {return lhs<rhs;}
};

int main ()
{
	  multiset<int> first;                          // empty multiset of ints

	    int myints[]= {10,20,30,20,20};
		  multiset<int> second (myints,myints+5);       // pointers used as iterators

		    multiset<int> third (second);                 // a copy of second

			  multiset<int> fourth (second.begin(), second.end());  // iterator ctor.

			    multiset<int,classcomp> fifth;                // class as Compare

				  bool(*fn_pt)(int,int) = fncomp;
				    multiset<int,bool(*)(int,int)> sixth (fn_pt); // function pointer as Compare

					  return 0;
}


