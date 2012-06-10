#include <stdint.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <boost/lexical_cast.hpp>


using namespace std;



string convert_time(uint64_t t)
{
    time_t e(boost::lexical_cast<int> (t));

    tm * p;

    p = gmtime(&e);

    stringstream ss;

    ss << p->tm_year + 1900 << "/" << p->tm_mon + 1 << "/" << p->tm_mday   << " " << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec ; 
    
    return ss.str();

}

static std::string EpochToDBTime( int64_t time_epoch )
{                    

    cout  << "... EPOCH DB TIME " << time_epoch << endl; 
    uint32_t dbg = (uint32_t)(time_epoch  / 1000);
    time_t t2( (uint32_t) (time_epoch / 1000) );
    
    tm * tm_p;                                                           
    tm_p = gmtime(&t2);    

    cout << "1st transformation is  " << dbg << endl;
     
    stringstream ss;                                                           
    ss << tm_p->tm_year + 1900 << "-" 
       << tm_p->tm_mon + 1 << "-" 
       << tm_p->tm_mday  << " " 
       << tm_p->tm_hour << ":" 
       << tm_p->tm_min << ":" 
       << tm_p->tm_sec ;                                        

    return ss.str();
}



static std::string EpochToDBDate( int64_t time_epoch )
{
    std::stringstream ret_date;
    
    time_t t2( (uint32_t) (time_epoch / 1000) );
    tm * tm_p;                                                                        
    tm_p = gmtime(&t2);              
    
    ret_date << tm_p->tm_year + 1900 << "-" 
       << tm_p->tm_mon + 1 << "-" 
       << tm_p->tm_mday  << " " 
       << "00:00:00"; 

    return ret_date.str();
}


int main(int argc,char *argv[])
{

      time_t tt;
      tt = time(0);
      cout << "time form tt = time(0) " << tt << endl;
      tm * ptm;
      time(&tt);
     
      ptm = gmtime( &tt );

      cout << "time " << tt << " " << ptm->tm_hour << ":" << ptm->tm_min << endl;

      cout << convert_time(tt) << endl ;
      
      int64_t  test(1282022152432);
      int32_t  test2(1282022152);
      
      //test /= 1000;
      
      //cout << " - milliseconds " << test << endl;
      
      uint32_t dbg = (unsigned int)(test  / 1000) ;
      cout << "test is " << dbg << endl;
      
      cout << " 32 bit " << EpochToDBTime( test2 ) << endl;
      cout << " 64 bit " << EpochToDBTime( test ) << endl;
      cout << " 64 TO 32 bit " << EpochToDBTime( (uint32_t) (test / 1000) ) << endl;
      cout << " date " << EpochToDBDate(test) << endl;
      
      cout << " time from time(0) " << time(0) << endl;
      
       
		   

}
