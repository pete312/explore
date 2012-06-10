#include <boost/date_time/gregorian/gregorian.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/date_time/time_duration.hpp>
#include <boost/format.hpp>
//#include <boost/date_time/.hpp>

#include <iostream>
#include <vector>


using namespace std;


static string convert_to_date(boost::posix_time::ptime t)
{
    tm t2 = to_tm(t);
    boost::format newfmt("%d-%02d-%02d");
    return str(newfmt % (1900 + t2.tm_year) % (1 + t2.tm_mon) % t2.tm_mday);
}

static string convert_to_time(boost::posix_time::ptime t)
{
    tm t2 = to_tm(t);
    boost::format newfmt("%02d:%02d:%02d");
    return str(newfmt % t2.tm_hour % t2.tm_min % t2.tm_sec);
}



int main(int argc,char *argv[])
{

	using namespace boost::posix_time;
	//using namespace boost::gregorian;
	//using namespace boost::date_time;
    
	ptime tstart(second_clock::local_time());
    ptime  t1(second_clock::local_time());
    stringstream ss;
    //string fmt("%Y-%m-%d");
    //time_facet *facet( new time_facet( "%Y-%m-%d" ) );
	//std::cout.imbue(  std::locale(std::cout.getloc(), facet) );
    
    //boost::format mydate ("%d-%02d-%0.2d") % 1 % 2 % 3;

    tm t2 = to_tm(t1);
    
	//cout << str(mydate % 2007 % 7 % 8 )  << endl;
	//cout << tstart << " "  << tstart.date()  << endl;
    
    boost::format mydate("%d-%02d-%02d") ;
    //mydate % t2.tm_year % (t2.tm_mon + 1) % t2.tm_mday ;
    //string dddd(mydate % t2.tm_year % t2.tm_mon % t2.tm_mday );
    
    cout << convert_to_date(second_clock::local_time()) << " " << convert_to_time(second_clock::local_time()) << endl;
    



}


