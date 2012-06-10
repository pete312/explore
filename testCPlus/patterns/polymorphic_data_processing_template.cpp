//polymorphic_data_processing.cpp
#include <iostream>

using namespace std;



class DataSupplier 
{
public:
    DataSupplier(){}
    
};

template <class T>
class WriteAdapter
{
public:
    
    WriteAdapter()
    {
    }
    
    virtual void Write( T value ) = 0;
    
    
    string special_message_;
}; 

template <class T>
class Writer : public WriteAdapter <T>
{
public:
    
    Writer()
    {
        //setWriterClient( WriteFunction<T> function );
    }
    
    void Write( T value )
    {
       cout << "writer " << value << endl;
    }
  
};


// template class T>
// class DataWriter 
// {
// public:

    // template <typename T>
    // void setWriter( WriteAdapter<T> * writer_ )
    // {
        // writer_ = writer;
    // }
    
    // WriteAdapter<T> * writer_;
// };



class DataConsumer 
{
public:

    
    DataConsumer()
    {
        intWriter_ = new Writer<int>() ; 
        dblWriter_ = new Writer<double>() ; 
        strWriter_ = new Writer<string>() ; 
        boolWriter_ = new Writer<bool>() ; 
        
        //intWriter_->setMessage("somthing");

    }
    
    ~DataConsumer()
    {
        //wait for porocessing to finish before closing 
    }
    
    
    void Write(int value)
    {
        intWriter_->Write(value);
    }

    
    void Write(double value)
    {
        dblWriter_->Write(value);
    }
    
    void Write(string value)
    {
        strWriter_->Write(value);
    }
    
    
private:   

    //std::map<type_info , void * >;
    WriteAdapter<int> * intWriter_; 
    WriteAdapter<double> * dblWriter_; 
    WriteAdapter<string> * strWriter_; 
    WriteAdapter<bool> * boolWriter_; 
    
};



int main(int argc , char * argv[])
{
    //DataSupplier supply();
    DataConsumer consumer;
    
    
    Writer<int> * writer = new Writer<int>();
    
    writer->Write(42);
    
    Writer<double> * writer2 = new Writer<double>();
    
    writer2->Write(42.73);
    
   
    consumer.Write(42);
    consumer.Write(42.42);
    consumer.Write(string("string thing"));
    consumer.Write("char thing");
    
    consumer.Write(false);
    consumer.Write(true);
    
    
}

