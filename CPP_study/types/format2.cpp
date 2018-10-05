
#include <iostream>
#include <map>
#include <boost/format.hpp>

using namespace std;

int main(int argc,char *argv[])
{

    string one("peter");
    string two("moore");

    boost::format test("%s %s %s");


    boost::format upd_statement_call;


    upd_statement_call % "sp_trade_update";                    
    upd_statement_call % boost::format("%s") % "one" ;               
    upd_statement_call % boost::format("%s") % "two" ;          


    test % "one" ;
    test % "two" ;
    test % "three" ;

    cout << upd_statement_call << endl;


    string avalue;      
    for (int tnum = 500; tnum < 600; tnum ++) {            

        avalue = str(boost::format("test tag %d") % tnum);            
        cout << "value add " <<  avalue << endl ;

        //tr->add_tag(tnum , any(avalue.str())); 
    }           
}
