#include <boost/date_time/gregorian/gregorian.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/date_time/time_duration.hpp>
#include <boost/any.hpp>

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

typedef map<int, string> normmap;

std::string Resolve(map<int , string > tags , int tag_no) {
    if ( tags.find(tag_no) == tags.end() ) {
        stringstream ss ;
        ss << "Tag not found convert tag " << tag_no ;
    }
    else{
        cout << "debug link id:" <<tags[tag_no]  << endl ;
        return boost::lexical_cast<std::string>( tags[tag_no] );
    }
}

int main(int argc,char *argv[])
{

    using namespace boost::posix_time;
    using namespace boost::gregorian;

    normmap m;

    m[1] ="this";
    m[4] = "that";
    cout << "test this " << boost::any(5) << endl;

    int i = 123;

    cout << Resolve(m, 4) ;

    return 0;

}
          


