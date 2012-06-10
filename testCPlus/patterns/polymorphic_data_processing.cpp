//polymorphic_data_processing.cpp
#include <iostream>

using namespace std;



class DataSupplier 
{
public:
    DataSupplier(){}
    
};


class WriteAdapter
{
public:
    WriteAdapter(){}
    virtual void Write() = 0;
}; 

class IntWriter : public WriteAdapter 
{
public:
    void Write(  )
    {
        cout << "Int writer "  << endl;
    }
        
};


class DataWriter 
{
public:
    void setWriter( WriteAdapter * writer )
    {
        writer_ = writer;
    }
    
    WriteAdapter * writer_;
};



class DataConsumer : public DataWriter
{
public:
    // void setIntWriter( WriteAdapter * writeint )
    // {
        // writeint_ = writeint;
    // }
    
    void Write(  )
    { 
        writer_->Write( );
    }
    
// private:    
    // WriteAdapter * writer_;
    
};



int main(int argc , char * argv[])
{
    //DataSupplier supply();
    DataConsumer consumer;
    
    
    IntWriter * writer = new IntWriter();
    
    
    consumer.setWriter( writer );
    
    
    consumer.Write();
    
    //WriteAdapter ;
}

