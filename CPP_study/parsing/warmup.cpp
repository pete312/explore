#include <sstream>
#include <iostream>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <complex>


using namespace std;

namespace client
{
    template <typename Iterator>
    bool parse_complex(Iterator first, Iterator last, std::complex<double>& c)
    {
        using boost::spirit::qi::double_;
        using boost::spirit::qi::_1;
        using boost::spirit::qi::phrase_parse;
        using boost::spirit::ascii::space;
        using boost::phoenix::ref;

        double rN = 0.0;
        double iN = 0.0;
        bool r = phrase_parse(first, last,

            //  Begin grammar
            (
                    '(' || 
                    '/' 
                    >> double_[ref(rN) = _1]
                        >> -(',' >> double_[ref(iN) = _1]) >> ')'
                |   double_[ref(rN) = _1]
            ),
            //  End grammar

            space);

        if (!r || first != last) // fail if we did not get a full match
            return false;
        c = std::complex<double>(rN, iN);
        return r;
    }
}


////////////////////////////////////////////////////////////////////////////
//  Main program
////////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
    if(argc < 1)
    {
        cout << "usage " << argv[1] << " <config file> " << endl;  
    }
    
    

    std::string str;
    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        std::complex<double> c;
        if (client::parse_complex(str.begin(), str.end(), c))
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << "got: " << c << std::endl;
            std::cout << "\n-------------------------\n";
        }
        else
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}
