#ifndef RANDOMIZEPARAMETER_H_
#define RANDOMIZEPARAMETER_H_

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <boost/random/linear_congruential.hpp>


namespace param {


// not bothering with templates at this time
enum ParameterType 
{
    PT_INT ,
    PT_DOUBLE,
    PT_STRING,
	PT_VECTOR_STRING

};    


typedef  std::vector< std::string > item_list_t;

template <typename T>
class RandomListParameter {
public:
	RandomListParameter<T>(char *name, int seed, T & list){
		list_ = list;
		rand48_ = new boost::rand48(seed);
		range_ = list_.size();
	}      	

	T Rand();

	T lastVal() {return current_ ;} ;
	

private:
	T current_;
	T list_;   
	boost::rand48 *rand48_;

};

 

class RandomParameter {
public:
        
    RandomParameter(char *name, int seed, double min, double max); 
    RandomParameter(char *name, int seed, int min, int max);
    ~RandomParameter();

    
    double Rand (double increment);
    
    int Rand(int increment);
    
    void Reseed(int seed);
    
	double lastDblVal() { return current_dbl_; };
	
    int lastIntVal() { return current_int_; };
    
    char *name() { return name_; };
    
    bool debug() { return debug_; }
    void debug(bool value) { debug_ = value ;}

    static double Modulus(double a, double b);   
    
    int raw_rand() { return (*rand48_)() ; };

    
private:

    char * name_;
    ParameterType rnd_type_;
    int max_int_;
    int min_int_;
    int range_;                                                
    int increment_int_;
    int current_int_;

    double max_dbl_;
    double min_dbl_;
    double drange_;
    double increment_dbl_;
    double current_dbl_;
    
    bool debug_;
    
    boost::rand48 *rand48_;
    
};


    
}

#endif // RANDOMIZEPARAMETER_H_


