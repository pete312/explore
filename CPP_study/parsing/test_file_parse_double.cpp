#include <vector>
#include <istream>
#include <sstream>
#include <iostream>
#include <boost/spirit/include/qi.hpp>

#include <boost/spirit/include/classic_position_iterator.hpp>
namespace classic = boost::spirit::classic;


namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

// parse list of doubles from input stream
// throw exception (perhaps including filename) on errors
std::vector<double>
  parse(std::istream& input, const std::string& filename);

// main function
int main(int, char**)
{
  try
  {
    parse(std::cin, "STDIN");
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
    return -1;
  }
  return 0;
}

// implementation
std::vector<double>
  parse(std::istream& input, const std::string& filename)
{
    // iterate over stream input
    typedef std::istreambuf_iterator<char> base_iterator_type;
    base_iterator_type in_begin(input);

    // convert input iterator to forward iterator, usable by spirit parser
    typedef boost::spirit::multi_pass<base_iterator_type> forward_iterator_type;
    forward_iterator_type fwd_begin =
        boost::spirit::make_default_multi_pass(in_begin);
    forward_iterator_type fwd_end;


    try
    {
      qi::phrase_parse(
        // iterators over input
        position_begin, position_end,
        // recognize list of doubles
        qi::double_ > *(',' > qi::double_) >> qi::eoi,
        // comment skipper
        ascii::space | '#' >> *(ascii::char_ - qi::eol) >> qi::eol,
        // store into this object
        output);
    }
    catch(const qi::expectation_failure<pos_iterator_type>&amp; e)
    {
    }


  // return result
  return output;
}
