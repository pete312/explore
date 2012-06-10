#include <iostream>

using namespace std;

namespace hundred {
	typedef enum {ONE = 100, TWO, THREE} number_t;
}
namespace unit {
	typedef enum {ONE = 1, TWO, THREE, FOUR} numbertwo_t;
}

int main (int argv, char ** argc)
{	
	//typedef enum {ONE = 1, TWO, THREE} teir::number_t;
	

	hundred::number_t good = hundred::ONE;
	unit::numbertwo_t good_too = unit::ONE;

	unit::numbertwo_t good_three = unit::FOUR;
	//hundred::number_t compile_error = unit::FOUR; // error

	cout << "one is" << endl;

	return 0;

}
