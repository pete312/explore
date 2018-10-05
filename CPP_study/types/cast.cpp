#include <stdint.h>
#include <vector>
#include <iostream>


using namespace std;


struct MultipleInt {    
	std::string id;     
	uint32_t version;    
};

struct MultipleStr {    
	std::string id;     
	string item;    
};


void MultObj(void * obj, int type){
	

	
	if(type == 1){
		MultipleInt * t_int = (MultipleInt *) obj;
		cout << "int type" << t_int->id << " "  << t_int->version << endl;

	}
	else {
		MultipleStr * t_str = (MultipleStr *) obj;
		cout << "str type" << t_str->id << " "  << t_str->item << endl;

	}
}


int main(int argc,char *argv[])
{

	MultipleInt * t_int = new MultipleInt;
	MultipleStr * t_str = new MultipleStr;

	t_int->id = "int type";
	t_int->version = 6;

	t_str->id = "str type";
	t_str->item = "six";


	MultObj((void *)t_int, 1);
	MultObj((void *)t_str, 0);

	
		   

}
