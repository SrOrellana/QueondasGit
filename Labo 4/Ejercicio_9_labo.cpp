#include <iostream>
#include <string>

using namespace std;

struct nombre{
	string Nombre, Apellido, Carnet, Telefono, Correo;
	int edad;
	
	nombre* sig;
};

void insertarDatos(nombre** pInicio);
void imprimirMenu(void);
void imprimirDatos(nombre* lista, int cuenta);
void eliminarNombre(nombre** lista, string busq, int cuenta);
void eliminarLista(nombre** lista, int cuenta);
void actualizarDatos(nombre** lista, string busq, int cuenta);

int main(void) {
	int opcion=0;
	string busca="";
	nombre* pInicio = NULL;
	do{
		imprimirMenu(); cin >> opcion;

		switch (opcion) {
		case 1:
			insertarDatos(&pInicio);
			break;
		case 2:
			cout<<"Ingrese el nombre que desea eliminar: ";cin>>busca;
			cout<<endl;
			eliminarNombre(&pInicio, busca, 0);
			break;
		case 3: 
		    cout<<"Ingrese el nombre de la persona a la que desea actualizar sus datos: ";cin>>busca;
			cout<<endl;
			actualizarDatos(&pInicio, busca, 0);
			break;
		case 4:
			imprimirDatos(pInicio, 0);
			break;	
		}
		

	} while (opcion != 0);

	return 0;
}
void insertarDatos(nombre** pInicio){
	nombre* nuevo = new nombre;
	cout << "Ingrese un nombre: "; cin >> nuevo->Nombre;
	cout << "Ingrese un apellido: "; cin >> nuevo->Apellido;
	cout << "Ingrese un carnet: "; cin >> nuevo->Carnet;
	cout << "Ingrese un telefono: "; cin >> nuevo->Telefono;
	cout << "Ingrese un correo: "; cin >> nuevo->Correo;
	cout << "Ingrese edad: "; cin >> nuevo->edad;
	nuevo->sig = NULL;

	if (!*pInicio)
		* pInicio = nuevo;
	else {
		nombre* aux = *pInicio;
		
		while (aux->sig)
			aux = aux->sig;

		aux->sig = nuevo;
	}
}

void imprimirMenu(void) {
	cout<<endl;
	cout << "CUADRO DE OPCIONES:" << endl << endl;
	cout << "1. Colocar datos (nombres y apellidos sin espacio) . . " << endl;
	cout << "2. Borrar datos de una persona por nombre. . ." << endl;
	cout << "3. Actualizar datos de una persona por nombre . . ." << endl;
	cout << "4. Mostrar Datos" << endl;
	cout << "0. Salir....Su opcion: ";
}

void imprimirDatos(nombre* lista, int cuenta){
	if(!lista){
	    if(cuenta==0){
	    	cout<<endl;
	    	cout<<"Lista Vacia"<<endl;
		}
		return;
	}
	else{
		cout<<endl;
		cout << "Nombre: " << lista->Nombre <<endl;
		cout<< "Apellido: " << lista->Apellido<<endl;
		cout<< "Carnet: " << lista->Carnet<<endl;
		cout<< "Correo: " << lista->Correo<<endl;
		cout<< "Telefono: " << lista->Telefono<<endl;
		cout<< "Edad: " << lista->edad<<endl;
		imprimirDatos(lista->sig, cuenta+1);		 
	}	
}
void actualizarDatos(nombre** lista, string busq, int cuenta) {
	if (*lista){
		if ((*(*lista)).Nombre == busq) {
			(*(*lista)).Apellido="";
			cout << "Ingrese un apellido: "; cin >> (*(*lista)).Apellido;
			cout << "Ingrese un carnet: "; cin >> (*(*lista)).Carnet;
			cout << "Ingrese un telefono: "; cin >> (*(*lista)).Telefono;
			cout << "Ingrese un correo: "; cin >> (*(*lista)).Correo;
			cout << "Ingrese edad: "; cin >> (*(*lista)).edad;
		}
		else {
			actualizarDatos(&(*(*lista)).sig, busq, cuenta+1);
		}
	}else{
		if(cuenta==0)
		cout<<"Lista vacia"<<endl;
	}
}

void eliminarNombre(nombre** lista, string busq, int cuenta) {
	if (*lista ) {
		if ((*(*lista)).Nombre == busq) {
			*lista = (*(*lista)).sig;
			eliminarNombre(lista, busq, cuenta+1);
		}
		else {
			eliminarNombre(&(*(*lista)).sig, busq, cuenta+1);
		}
	}else{
		if(cuenta==0)
		cout<<"Lista vacia"<<endl;
	}
}
