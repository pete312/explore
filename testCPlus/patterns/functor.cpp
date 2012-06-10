#include <iostream>


using namespace std;

void ClientWriter(int i)
{
    cout << "client is writing an int " << i << endl;
}

typedef void (*ExternalWriter)(int);


void Server (ExternalWriter writer, int i) 
{
    writer(i);
}

int main(int argc , char * argv[])
{
   
    Server(ClientWriter, 45);

}

