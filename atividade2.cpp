#include <iostream>
#include <string>
using namespace std;

class carro {
	private:
    int chassi = 74598;
    string marca = "BMW"; 
    int velocidade = 0;
  public:             
  void acelera(){
  velocidade += 10 ;
  }
  int getvelo(){
  return velocidade;
  }
};

int main() {
  carro obj;
  
  cout << "Velocidade atual "<< obj.getvelo() << "\n";  
  obj.acelera() ;
  cout <<"Nova velocidade " << obj.getvelo() << "\n"; 
  return 0;
}