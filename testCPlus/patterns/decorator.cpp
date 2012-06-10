class Computer()
{
public:
    Computer() {}

    string description()
    {   
        return "computer";
    }
};  

class ComponentDecorator : Computer
{
public:
    ComponentDecorator( Computer* );
    virtual string description();
private:
    Computer* computer_;
};


class Disk() : ComponentDecorator
{
public:
    
};

int main(int argc, char* argv[] )
{

    Computer computer();



}
