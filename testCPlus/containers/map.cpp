#include <boost/shared_ptr.hpp>
#include <iostream>
#include <map>

using namespace std;

enum TestEnum {
	ONE,
	TWO,
	THREE
};

int main(int argc,char *argv[])
{
	//cout << "here" << endl;


	map<int, char>  *mp;
	map<int, string> mm;
	boost::shared_ptr<map<int, string > > i_str;

	mp = new map<int, char>;
	i_str.reset(new map<int, string>);

	mm[100] = "one hundred";
	mm[5] = "five";
	mm[10] = "ten";

	(*mp)[1] = 'I';
	(*mp)[5] = 'V';
	(*mp)[10] = 'X';
	(*mp)[50] = 'L';
	(*mp)[100] = 'C';


	(*i_str)[1] = "one";
	(*i_str)[9] = "nine";
	(*i_str)[4] = "four";

	
	cout << "count " << mm.size() << endl;
	for( map<int, string >::iterator ii=mm.begin() ; ii != mm.end(); ++ii){
		std::cout << (*ii).first << ":" << (*ii).second << endl;
	}
	
	for (map<int, char>::iterator ii=mp->begin() ; ii != mp->end(); ++ii){
		cout << ii->first << ":" << ii->second << endl;
	}

	cout << "test find" << mm.find(5)->second << endl;
	cout << "test find" << mm.find(45)->first << endl;


	//for (map<int, string>::iterator  iter = i_str->begin(); iter < i_str->end() ; iter++ )
	//{
//		cout << iter << endl;
//	}	
 
	// deleting one of the members
	for ( map<int, char>::iterator it = mp->begin(); it != mp->end(); it++ )
	{	
		if (it->first == 10 || it->first == 100)
		{
			cout << " found 10 " <<endl;
		        mp->erase(it);
			
		}
		else 
		{
			cout << it->first << endl;
		}	
	}


}
