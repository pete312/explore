
#include <iostream>
#include <map>

using namespace std;

void str_ref(string & mystring)
{
    cout << "str_ref(" << mystring << ")" <<endl;
    mystring = "new stuff";
    return;
}

int main(int argc,char *argv[])
{
    std::string this_stuff = "old stuff";
    cout  <<" start " << this_stuff << endl;
    str_ref(this_stuff);
    cout << "end " << this_stuff << endl;
}
