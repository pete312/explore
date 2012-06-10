#include <vector>
#include <iostream>
#include <map>



using namespace std;



int main(int argc,char *argv[])
{

    typedef std::pair<string, bool>	 test_t;
    map<int, test_t> list;

    list[1] = test_t("one ", true);
    list[2] = test_t("two ", false);
    list[3] = test_t("three ", true);
    list[4] = test_t("four ", false);


    cout << "test 1 should be one = true " << list[1].first << " = "  << list[1].second << endl;
		   

}
