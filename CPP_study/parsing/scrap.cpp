#include <iostream>
#include <fstream>
#include <boost/spirit/include/qi.hpp>
#include <string>

namespace qi = boost::spirit::qi;

using std::cout;
using std::endl;
using std::string;
using boost::spirit::ascii::space;
using boost::spirit::qi::phrase_parse;
using boost::spirit::qi::double_;


void show (double d );
void doit( string line );

void show (double d )
{
    cout << d << endl;
}

void doit( string line )
{
    using boost::spirit::qi::phrase_parse;
    using boost::spirit::qi::double_;
    
    bool r = phrase_parse(line.begin(), line.end(),
    (
        double_[&show] >> *(',' >> double_[&show])
    )
    ,
    space);

}


int main(int argc, char * argv[])
{
    
    if (argc < 2){
        cout <<" Usage: " << argv[0] << " <config file> " << endl;
        exit(1);
    }
    
    //string filename(string(argv[1]));
    std::string line;
    std::ifstream ifile;
    
    ifile.open(argv[1]);
    while (getline(ifile, line))
    {
        cout << line << endl;
        //doit(line);
    }
}


