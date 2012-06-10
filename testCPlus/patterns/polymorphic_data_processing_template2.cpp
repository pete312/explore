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
        //special_message_ = "writer ";
    }
    
    // WriteAdapter(string message) 
    // {
        // special_message_ = message;
    // }
    
    void setMessage(string s)
    {
        special_message_ = s;
    }
    
    void setWriter ( WriteAdapter<T> * functor )
    {   
        writeAdapter_ = functor;
    }
    
    
    virtual void Write( T value ) = 0;
    
    WriteAdapter <T> * writeAdapter_;    
    
    string special_message_;
}; 

template <class T>
class Writer : public WriteAdapter <T>
{
public:
    
    
    Writer() 
    {
    
    }
    
    // Writer()
    // {
        // //setWriterClient( WriteFunction<T> function );
        // setWriter( WriteAdapter<T> * functor );
    // }
    
    
    void Write( T value )
    {
       //cout << "writer " << value << endl;
    }
    
    
    // void setWriter( T * writer )
    // {
        // writeAdapter_ = writer;
    // }
    

    //string special_message_;
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
    // void setIntWriter( WriteAdapter * writeint )
    // {
        // writeint_ = writeint;
    // }
    // template <typename T> void setWriter<T> ()
    // {
    
    // }
    
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
    
    //template < typename T > setWriter()
    
    
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
    
    void setWriter ( WriteAdapter<int> * functor )
    {
      //  /intWriter_->setWriter(WriteAdapter<int>  * functor);
    }
    
    
    // template <typename T> void Write(<T> value_)
    // { 
        // writer_->Write( );
    // }
    
    
private:   
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
    
    
    string test("this");
    
    consumer.Write(42);
    consumer.Write(42.42);
    consumer.Write(string("string that"));
    consumer.Write("char that");
    consumer.Write(false);
    consumer.Write(true);
    
    
    //consumer.setWriter<T> ( new Writer<T> );
    
    
    // consumer.Write();
    
    //WriteAdapter ;
}

