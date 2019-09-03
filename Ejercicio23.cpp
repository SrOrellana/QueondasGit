#include <iostream> //23
using namespace std;
  
struct Complejo {
   int real;
   int imaginario;
};
   
int main() {
   Complejo x1, x2, suma;
   
   cout << "Colocar valor de A y B  donde A + iB es el primer numero complejo\n";
   cin >> x1.real >> x1.imaginario;
     
   cout << "Colocar el valor de A y B donde A + iB es el segundo numero complejo\n";
   cin >> x2.real >> x2.imaginario;
     

   suma.real = x1.real + x2.real;
   suma.imaginario = x1.imaginario + x2.imaginario;
      
   if(suma.imaginario >= 0 )
      cout << suma.real << " + " << suma.imaginario<<"i";
   else
      cout << suma.real << " - " << suma.imaginario<<"i";
     
   return 0;
}
