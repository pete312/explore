#include <vector>
#include <iostream>
#include <time.h>
#include <stdint.h>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/format.hpp>

using namespace std;
using namespace boost::posix_time;



static uint32_t ConvertToDateInt(int64_t t)
{                        
    time_t t_out;
    time_t t_modified( (int32_t) (t / 1000));
    tm * t2 = gmtime(&t_modified);

    
    t_out = (t2->tm_year + 1900) * 1000;
    t_out += (t2->tm_mon + 1) * 100;
    t_out += t2->tm_mday;
    return t_out;
}


// static string ConvertUTCToString(int64_t t, bool midnight=false, bool hide_time=false, bool hide_date=false)
// {         

    // stringstream ss;                               
    
    // time_t t_out;
    // time_t t_modified( (int32_t) (t / 1000));
    // tm * t2 = gmtime(&t_modified);

    // if (hide_date == false) {
	// ss << t2->tm_year + 1900 << "-"
           // << t2->tm_mon + 1 << "-"
           // << t2->tm_mday ;
    // }                     

    // if (! (hide_time || hide_date) )
    // {
        // ss << " ";
    // }
    
    // if (hide_time == true ){
	// return ss.str() ;
    // }

    // if (midnight == false){
       // ss << t2->tm_hour << ":"
          // << t2->tm_min << ":"
          // << t2->tm_sec ;
    // }
    // else{
	// ss << "00:00:00";
    // }
        
   // return ss.str();
// }


static string ConvertUTCToString(int64_t t, bool local=false, bool midnight=false, bool hide_time=false, bool hide_date=false)
{         
    stringstream ss_ret;
    
    if (hide_time && hide_date){
        // you asked for it.
        return ss_ret.str();
    }
     
    time_t t_out;
    time_t t_modified( (int32_t) (t / 1000));
    
    tm * t2;
    if (local){
        t2 = localtime(&t_modified);
    }
    else{
        t2 = gmtime(&t_modified);
    }
    
    if ( ! hide_date) {
        boost::format fdate("%04d-%02d-%02d");
            
        fdate % (t2->tm_year + 1900);
        fdate % (t2->tm_mon + 1) ;
        fdate % t2->tm_mday ;
        ss_ret << fdate.str();
    }   
    
    if ( !hide_date && !hide_time ) 
    {
        //add spacer
        ss_ret << " ";
    }

    if ( ! hide_time ){
        if (midnight == false){
            boost::format ftime("%02d:%02d:%02d");
            ftime % t2->tm_hour % t2->tm_min % t2->tm_sec ;
            ss_ret << ftime.str();
        }
        else{
            ss_ret << "00:00:00";
        }
    }
        
   return ss_ret.str();
}



static string ConvertDateIntToString(int64_t t, bool time_too)
{                               

    stringstream ss;
    

    //t_out = (t2->tm_year + 1900) * 1000;
    //t_out += (t2->tm_mon + 1) * 100;
    //t_out += t2->tm_mday;
    
    
   return ss.str();
}

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

    int64_t  test( time(0) * 1000 + 999 );
    //int32_t  test2(1282022152);

    //cout << "counvert_time() " <<  convert_time(test) << endl;

    uint32_t dateint = ConvertToDateInt(test); 

    cout << "dateint 64 is " << dateint << endl;
    
    cout << endl;
    cout << "test for ConvertUTCToString(int64_t t, bool local=false, bool midnight=false, bool hide_time=false, bool hide_date=false)" << endl << endl;
    cout << "conversion            flags     result:"<< endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "utcdatetime GMT       f         '" << ConvertUTCToString(test) << "'" << endl;
    cout << "utcdatetime local     t         '" << ConvertUTCToString(test, true) << "'" << endl;
    cout << "utcdatetime midnight  f t       '" << ConvertUTCToString(test, false, true) << "'" << endl;
    cout << "utcdate only          f f t f   '" << ConvertUTCToString(test, false, false, true) << "'" << endl;
    cout << "utctime only          f f f t   '" << ConvertUTCToString(test, false, false, false, true) << "'" << endl;
    cout << "utctime only midnight f t f t   '" << ConvertUTCToString(test, false, true, false, true) << "'" << endl;
    cout << "nothing               f f t t   '" << ConvertUTCToString(test, false, false, true, true) << "'" << endl;

}
