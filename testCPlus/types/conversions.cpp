#include <stdint.h>
#include <iostream>
#include <map>
#include <boost/format.hpp>
#include <stdlib.h>
#include <sstream>


using namespace std;

int main(int argc,char *argv[])
{

    string one("1");
    string two_hundred("200");
    string two("2");
    string minus_one("-1");
    int int_five(5);
    
    string not_five("34ive");
    string another_not_five("fi5ve");
    
    if (one < two){
        cout << " one < two " << endl;
    }
    
    if ( atoi(one.c_str()) < int_five ){
        cout << " one < int_five " << endl;
    }

    if (two_hundred > one){
        cout << " two_hundred > one " << endl;
    }
    
   // if ((atoi(one.c_str()) < atoi(not_five.c_str())) and (isdigit(not_five.c_str() == false))){
   //     cout << " one < int_five " << atoi(one.c_str()) << " not_five "
   //         << not_five  << " = "  << atoi(not_five.c_str()) << endl;
   // }
   // else 
   // {
   //     cout << " NOT one < int_five " << atoi(one.c_str()) << " not_five "
   //         << not_five << " = " 
   //         << atoi(not_five.c_str()) << endl;
   // }
    
   // if ((atoi(one.c_str()) < atoi(another_not_five.c_str())) and (isdigit(another_not_five.c_str() == false))){
   //     cout << " one < int_five " << atoi(one.c_str()) << "  another_not_five " << atoi(another_not_five.c_str()) << endl;
   // }
   // else 
   // {
   //     cout << " NOT one < int_five " << atoi(one.c_str()) << " another_not_five  " 
   //         << another_not_five << " = "
   //         << atoi(another_not_five.c_str()) << endl;
   // }
    
    if (two_hundred > two){
        cout << " two_hundred > two " << endl;
    }

    stringstream ss;
	
    ss << "this";
	ss.flush();

	cout << "ss = " << ss.str() << endl;   
 
}
