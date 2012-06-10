#include <iostream> 

using namespace std; 

class Engine { 
public: 
  virtual void start(); 
}; 

void Engine::start() 
{ 
  cout << "starting Engine\n"; 
} 

class FordTaurus { 
public: 
  virtual void start(); 
protected: 
  Engine engine_;    // An Engine is part of a FordTaurus 
}; 

void FordTaurus::start() 
{ 
  cout << "starting FordTaurus\n"; 
  engine_.start(); 
} 

int main() 
{ 
  FordTaurus taurus; 
  taurus.start(); 
} 