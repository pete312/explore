#include <stdint.h>
#include <vector>
#include <iostream>


using namespace std;


struct MultipleInt {    
	std::string id;     
	uint32_t version;    
};

struct MultipleStr {    
	std::string id;     
	string item;    
};


void ImplicitOverloadedString(string const & a, string const & b){
	
    cout << a << " " << b << endl;
}


int main(int argc,char *argv[])
{

	ImplicitOverloadedString( string("one") ,string("two" ) );
	ImplicitOverloadedString( "two" ,string("three") );
	ImplicitOverloadedString( "three" , "three"  );


}
