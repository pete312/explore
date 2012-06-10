#include <boost/date_time/gregorian/gregorian.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/date_time/time_duration.hpp>
#include <boost/unordered_map.hpp>

#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main(int argc,char *argv[])
{

    using namespace boost::posix_time;
    using namespace boost::gregorian;
    
    ptime tstart;
    ptime tend;
    time_duration m_duration;
	map<int, int > * map1 = new map<int, int >  ;
    
    const int TIMES = 10000000;
    tstart = microsec_clock::local_time(); 

	for (int i = 0; i < TIMES; i++ ){
		(*map1)[i] = i;
	}
    tend = microsec_clock::local_time(); 
    m_duration = tend - tstart;

    cout << "map1 ; " << TIMES << " took " << m_duration << endl;



	//------------------------------------------------------------

	boost::unordered_map <int, int> umap;

    tstart = microsec_clock::local_time(); 

	for (int i = 0; i < TIMES; i++ ){
		umap[i] = i;
	}
    tend = microsec_clock::local_time(); 
    m_duration = tend - tstart;

    cout << "umap ; " << TIMES << " took " << m_duration << endl;
    

	//------------------------------------------------------------

     tstart = microsec_clock::local_time(); 

	for (int i = 0; i < TIMES; i++ ){
		umap[i] = i;
	}
    tend = microsec_clock::local_time(); 
    m_duration = tend - tstart;

    cout << "umap ; " << TIMES << " took " << m_duration << endl;
     

	//------------------------------------------------------------
    tstart = microsec_clock::local_time(); 

	for (int i = 0; i < TIMES; i++ ){
		umap[i] = i;
	}
    tend = microsec_clock::local_time(); 
    m_duration = tend - tstart;

    cout << "umap ; " << TIMES << " took " << m_duration << endl;

}     
