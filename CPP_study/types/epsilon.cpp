#include <stdint.h>
#include <iostream>

using namespace std;


int main(int argc,char *argv[])
{
    int i = 0;
    uint32_t not_i = ~0;
    double not_d(0);
    not_i<<=1;
    cout << "epsilon of int " << not_i << endl;
    cout << "epsilon of double " << not_d << endl;

    return 0;
   

}
          


