#include <iostream>
using namespace std;

struct Nodo{
	int n;
	Nodo *sig;
};
struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};

class ABB{
private:
    nodo *pArbol;
public:
    ABB(void);
    void operaciones(Nodo *lista);
    void mostrarPre(void);
    void mostrarIn(void);
    void mostrarIn(nodo *);
    void mostrarLista(Nodo *lista);
    void insNodo(int);
    void insNodo(nodo **, int);

};

ABB::ABB(void){
    pArbol = NULL;
}
void ABB::insNodo(int DATE){
    insNodo(&PARBOL, DATE);
}
void ABB::insNodo(nodo **p, int DATE){
    if(!(*p)){
        *p = new nodo;
        (*p)->DATE = DATE;
        (*p)->izq = (*p)->der = NULL;
    }
    else
        if(DATE < (*p)->DATE){
            insNodo(&((*p)->izq), DATE);
        }
        else
            if(DATE > (*p)->DATE){
                insNodo(&((*p)->der), DATE);
            }
            else
                cout << "El nodo ya existe\n";
}
void ABB::mostrarIn(void){
	mostrarIn(PARBOL);
}
void ABB::mostrarIn(nodo *p){
	if(p != NULL){
        mostrarIn(p->izq);
        cout << " " << p ->DATE;
        mostrarIn(p->der);
    }
}
void ABB::mostrarLista(Nodo *lista){
	if(!lista){
		return;
	}else{
		cout << " " << lista->n << endl;
		mostrarLista(lista->sig);
	}
}
void ABB::Operator(Nodo *lista){
    int DATE=0,cont=0;
    while(cont<5){
        DATE = lista->n;
		insNodo(DATE);
		lista = lista->sig;
		cont++;
    }
	cout << "\nMostrar in-orden:" << endl;
    mostrarIn();
}

int main(){
    ABB Arbol;
	int n=0,cont=0;
	
	Nodo *pInicio = NULL;
	do{
		Nodo *nuevo = new Nodo;
		cout << "Ingrese un numero: "; cin >> n;
		cont++;
		nuevo->sig = NULL;
		nuevo->n = n;
		if(!pInicio){
			pInicio = nuevo;
		}else{
			Nodo *aux = pInicio;
			
			while(aux->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}
	}while(cont<5);
	cout << "LISTA: "<< endl;
	Arbol.mostrarLista(pInicio);
	Arbol.Operator(pInicio);

    return 0;
}
