#include <iostream>
#include <cmath>
using namespace std;

long double raizEntero(int num,long double r);
int main(void){
	int entero=0, semilla=0;
	ingresarEntero:
	cout<<"Ingrese el valor del cual desea conocer la raiz cuadrada:";
	cin>>entero;
	
	if(entero<0){
		goto ingresarEntero;
	}
	ingresarSemilla:
		cout<<"Ingresar el valor de la semilla:";
		cin>>semilla;
		if(semilla<0){
			goto ingresarSemilla;
			
		}
		cout<<raizEntero(entero, semilla);
		return 0;
}
long double raizEntero(int num,long double r){
	long double r2 = (((num/r)+r)/2);
	if(abs(r-r2)<0.0001){
		return r2;
		
	}else{
		return raizEntero(num,r2);
		
	}
}
