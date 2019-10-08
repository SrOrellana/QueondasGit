#include <iostream>
#include <string>

using namespace std;

struct libro{
	string titulo;
	int numPag;
	
	libro* sig;
};

void insertarDatos(libro** pInicio);
void imprimirMenu(void);
void imprimirDatos(libro* lista, int cuenta);
void buscarTitulo(libro** lista, string busq, int cuenta);
//void actualizarDatos(libro** lista, string busq, int cuenta);

int main(void) {
	int opcion=0;
	string busca="";
	libro* pInicio = NULL;
	do{
		imprimirMenu(); cin >> opcion;

		switch (opcion) {
		case 1:
			insertarDatos(&pInicio);
			break;
		case 2:
			cout<<"Ingrese el titulo del libro del cual desea conocer el num de pag: ";cin>>busca;
			cout<<endl;
			buscarTitulo(&pInicio, busca, 0);
			break;
		/*case 3: 
		    cout<<"Ingrese el nombre de la persona a la que desea actualizar sus datos: ";cin>>busca;
			cout<<endl;
			actualizarDatos(&pInicio, busca, 0);
			break;*/
		case 3:
			imprimirDatos(pInicio, 0);
			break;
		}
		

	} while (opcion != 0);

	return 0;
}
void insertarDatos(libro** pInicio){
	libro* nuevo = new libro;
	cout << "Ingrese el titulo: "; cin >> nuevo->titulo;
	cout << "Ingrese el numero de paginas: "; cin >> nuevo->numPag;
	nuevo->sig = NULL;

	if(!*pInicio){
		*pInicio = nuevo;
	}
	else{
		nuevo->sig = *pInicio;
 		*pInicio = nuevo;
	}
}

void imprimirMenu(void) {
	cout<<endl;
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Introducir datos del libro (titulo y numero de pag)..." << endl;
	cout << "2. Mostrar numero de pag de un determinado libro..." << endl;
	cout << "3. Mostrar los libros que contiene la pila..." << endl;
	cout << "0. Salir.....Su opcion: ";
}

void imprimirDatos(libro* lista, int cuenta){
	if(!lista){
	    if(cuenta==0){
	    	cout<<endl;
	    	cout<<"Lista Vacia"<<endl;
		}
		return;
	}
	else{
		cout<<endl;
		cout << "Titulo: "<< lista->titulo<<endl;
		cout << "Num de pag: "<< lista->numPag<<endl;
		imprimirDatos(lista->sig, cuenta+1);		 
	}	
}

void buscarTitulo(libro** lista, string busq, int cuenta) {
	if (*lista ) {
		if ((*(*lista)).titulo == busq) {
			cout<<"Num de paginas: "<< (*(*lista)).numPag;
			cout<<endl;
			//buscarTitulo(lista, busq, cuenta+1);
		}
		else {
			buscarTitulo(&(*(*lista)).sig, busq, cuenta+1);
		}
	}else{
		if(cuenta==0)
		cout<<"Lista vacia"<<endl;
	}
}

