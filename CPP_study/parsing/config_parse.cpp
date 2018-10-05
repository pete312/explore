#include <iostream>
#include <boost/format.hpp>



using namespace std;



int main(int argc,char *argv[])
{

    if (argc < 1)
        cout << " require file" << endl;

    string sample(
           "map{@internal_arg1, core.arg1}"
           "map{@internal_arg2, core.arg2}"
           "map{@internal_arg3, core.arg3}"
           "map{@internal_arg4, core.arg4}"
           "map{@internal_arg5, core.arg5}"
           "map{@internal_arg6, core.arg1}"
           "map{@internal_arg7, core.arg1}"
           "map{@internal_arg8, core.arg1}");


}
