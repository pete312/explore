#include <stdint.h>
#include <map>
#include <vector>
//##include <boost/format.hpp>
#include <iostream>
#include <sstream>

using namespace std;


struct MultipleInt {
    std::string id; 
    uint32_t version;
    std::vector<uint32_t> keynums;
    std::vector<uint32_t> values;
};

struct MultipleDbl {
    std::string id; 
    uint32_t version;
    std::vector<uint32_t> keynums;
    std::vector<double> values;
};

struct MultipleStr {
    std::string id; 
    uint32_t version;
    std::vector<uint32_t> keynums;
    std::vector<string> values;
};

static string build_int_statement(string procedure_name, MultipleInt &  add )
{
    stringstream ss;
    ss << procedure_name << endl;
    
    std::stringstream sskeys("'");
    std::stringstream ssvalues("'");
    
    for (int i =0 ; i < add.keynums.size(); i++ )
    {
        sskeys << add.keynums[i] << ","; 
        ssvalues  <<  add.values[i] << ","; 
    }
    
    ss << "@id = " << add.id << ", " << endl 
        << "@version = " << add.version << ", " << endl 
        << "@keynum = " << sskeys.str() << endl 
        << "@vals = " << ssvalues.str() << endl;

    return ss.str();
}

static string build_dbl_statement(string procedure_name, MultipleDbl &  add )
{
   stringstream ss;
    ss << procedure_name << endl;
    
    std::stringstream sskeys("'");
    std::stringstream ssvalues("'");
    
    for (int i =0 ; i < add.keynums.size(); i++ )
    {
        sskeys << add.keynums[i] << ","; 
        ssvalues  <<  add.values[i] << ","; 
    }
    
    ss << "@id = " << add.id << ", " << endl 
        << "@version = " << add.version << ", " << endl 
        << "@keynum = " << sskeys.str() << endl 
        << "@vals = " << ssvalues.str() << endl;

    return ss.str();
   
}


static string build_str_statement(string procedure_name, MultipleStr & add )
{
   stringstream ss;
    ss << procedure_name << endl;
    
    std::stringstream sskeys("'");
    std::stringstream ssvalues("'");
    std::stringstream slength("'");
    
    for (int i =0 ; i < add.keynums.size(); i++ )
    {
        sskeys << add.keynums[i] << ","; 
        ssvalues  <<  add.values[i] << ","; 
        slength << add.values[i].size() << ","; 

    }
    
    ss << "@id = " << add.id << ", " << endl 
        << "@version = " << add.version << ", " << endl 
        << "@keynum = " << sskeys.str() << endl
        << "@vals = " << ssvalues.str() << endl
        << "@length = " << slength.str() << endl;

    return ss.str();
   
}

int main(int argc,char *argv[])
{

    MultipleInt add_i;
    
    add_i.id = "00000-00000000-00000-00000000";
    add_i.version = 2;
    add_i.keynums.push_back(10);       
    add_i.values.push_back(1);       
    
    add_i.keynums.push_back(11);       
    add_i.values.push_back(2);  
    
    add_i.keynums.push_back(12);       
    add_i.values.push_back(3);  
    
    
    std::string sql_statement;
    sql_statement = build_int_statement( string("TPM_MultiInsterTag_Values_Int ") ,  add_i);
    
    cout << sql_statement;

    // NEXT .....
    
    MultipleDbl add_d;

    
    add_d.id = "00000-00000000-00000-00000001";
    add_d.version = 2;
    add_d.keynums.push_back(100);       
    add_d.values.push_back(1.1);       
    
    add_d.keynums.push_back(111);       
    add_d.values.push_back(2.2);  
    
    add_d.keynums.push_back(122);       
    add_d.values.push_back(3.3);  
    
    sql_statement = build_dbl_statement(string("TPM_MultiInsterTag_Values_Dbl "), add_d);
    
    cout << sql_statement;
    
    
    // NEXT ......
    
    MultipleStr add_s;

    
    add_s.id = "00000-00000000-00000-00000002";
    add_s.version = 2;
    add_s.keynums.push_back(100);       
    add_s.values.push_back("one");       
    
    add_s.keynums.push_back(111);       
    add_s.values.push_back("two");  
    
    add_s.keynums.push_back(122);       
    add_s.values.push_back("three");    
    
    sql_statement = build_str_statement(string("TPM_MultiInsterTag_Values_Str "), add_s);
    
    cout << sql_statement;
 
}
