#include "randomize_parameter.h"

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <boost/random.hpp>
                           
//dlsk

using namespace std;

/*double RandomParameter::Modulus(double a, double b)
{
    int result = static_cast<int>( a / b );
    return a - static_cast<double>( result ) * b;
}

*/

RandomParameter::RandomParameter(char *name,  int seed, int min, int max) :
    debug_(false)
{

    if ( min > max ) throw "min val higher than low " ;
    
    rand48_ =  new boost::rand48(seed);

    this->name_ = name;
    this->rnd_type_ = PT_INT;
    this->range_ = max - min;
    this->min_int_ = min;
    this->max_int_ = max;
   
}

RandomParameter::RandomParameter(char *name, int seed, double min, double max) :
    debug_(false)
{

    rand48_ = new boost::rand48(seed);
   
    this->name_ = name;
    this->rnd_type_ = PT_DOUBLE;
    this->drange_ = max - min;
    this->min_dbl_ = min;
    this->max_dbl_ = max;

}


RandomListParameter::RandomListParameter <typename T> (char *name, int seed, T &list)
{
    list_ = list;
	rand48_ = new boost::rand48(seed);
	drange_ = list_.size();
}                          
  


RandomParameter::~RandomParameter() 
{
    if (this->debug_) {
        cout << "RandomParameter::~RandomParameter()" << endl;
    }
}

/* T RandomListParameter::Rand()
{
    
	if (this->rnd_type_ == PT_VECTOR_STRING){
        
        int size = list_.size();
        this->current_string_ = list_[(*rand48_)() % size]; 
        
	}
    else
    {
        //throw std::Exception("Random list is not a string vector.");
    }
    
    return this->current_string_; 
        
}
*/

double RandomParameter::Rand(double increment)
{
    if (this->rnd_type_ != PT_DOUBLE){
        cout << "Error : RandomParameter::Rand(double) not initialized as an double generator." << endl;
        throw "RandomParameter::Rand(double) not initialized as an double generator";
    }
    
    if (increment == 0.0 ) {
        increment = this->increment_dbl_;
    }
    else {
        this->increment_dbl_ = increment;
    }
    

    int r = (*rand48_)();
    //cout << "pre drange_=" << drange_ << " inc= "<<increment << endl;
    
    int divisions = static_cast<int>( drange_ / increment );
    
    if (divisions == 0) {
        this->current_dbl_ =  this->min_dbl_;
    }
    else{
        this->current_dbl_ = (static_cast<double>(r % divisions) * increment) + this->min_dbl_; 
    
        // cout << "debug inc=" << increment
            // << ",  divisions=" << divisions
            // << ",  drange_=" << drange_
            // << "  result = " << this->current_dbl_ << endl;
    }
    return this->current_dbl_;
} 


int RandomParameter::Rand(int increment)
{                              
    if (this->rnd_type_ != PT_INT){
        cout << "Error : RandomParameter::Rand(int) not initialized as an int generator." << endl;
        throw "RandomParameter::Rand(int) not initialized as an int generator";
    }
    
    int r = (*rand48_)();
   
    if (increment == 0 ) {
        increment = this->increment_int_;
    }
    else {
        this->increment_int_ = increment;
    }
    
    int divisions = this->range_ / increment ;
    if (divisions == 0){
        this->current_int_ = this->min_int_;
    }
    else {
        this->current_int_ = ( ( r % divisions ) * increment ) + this->min_int_ ;
        
        //nextint -= nextint % increment;
        //this->current_int_ = nextint; 
    }
    return this->current_int_;
}

void RandomParameter::Reseed(int seed) 
{
    //boost::rand48 rand48_(seed);
    rand48_ = new boost::rand48(seed);
}





