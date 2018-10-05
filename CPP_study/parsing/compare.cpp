#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;



int main(int argc,char *argv[])
{

    string t = "target of proposed update is invalid, no update is possible";

    cout << t.compare("target of proposed update is invalid, no update is possible");

    
    string sample1 = "2010-08-23 22:46:08"; 
    string sample2 = "2010-08-23 22:46:10.26000000";

    if ( sample1.compare(sample2) != 0)
    {
        cout << "Samples are different\n";
    }
    else {
        cout << "Samples are same\n";
    }
}
