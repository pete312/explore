#include <stdint.h>
#include <iostream>
#include <map>

using namespace std;

struct Symbol {    
	uint32_t link_id;    
 	uint32_t option_id;    
	string   symbol;    
	char     option_class;  // TradeType 'C' 'P' 'F' 'S'
};

Symbol* make_symbol (uint32_t link_id, uint32_t option_id, string name, char option_class ) ;

Symbol* make_symbol (uint32_t link_id, uint32_t option_id, string name, char option_class ) {
	cout << name << endl;

	Symbol* s = new Symbol;
	s->link_id = link_id;
	s->option_id =  option_id;
	s->symbol = name;
	s->option_class = option_class;
	return s;
}

int main(int argc,char *argv[])
{
	//cout << "here" << endl;

	map<int, Symbol *>  list;


	list[1] = make_symbol ( 1231, 12315, "IBM1231", 'C') ;
	list[4] = make_symbol ( 1234, 12345, "IBM1234", 'C') ;
	list[5] = make_symbol ( 1235, 12355, "IBM1235", 'C') ;


	
//	for (map<int, char>::iterator ii=mp->begin() ; ii != mp->end(); ++ii){
//		cout << ii->first << ":" << ii->second << endl;
//	}

	cout << " test that we have one" << list[1]->symbol << endl; 

//	cout << "test find" << mm.find(5)->second->symbol << endl;
 
}
