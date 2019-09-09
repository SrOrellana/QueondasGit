#include <iostream>

using namespace std;

void MoverTorres(int N, char origen, char intermedio, char destino)
{
    if (N>1)
{
MoverTorres(N-1,origen, destino, intermedio);
cout<<"\nMueve el disco"<< N <<" de "<< origen <<" a " << destino << endl;
MoverTorres(N-1,intermedio,origen,destino);
}
if (1== N)
cout<<"\nMueve el disco 1 de "<< origen << " a "<< destino << endl;
}
int main()
{
    int Discos;
    cout<<"\nEste programa resuelve el problema clasico de las torres de Hanoi";
    cout<<"\nPor favor introduzca el numero de discos que quiere mover";
    cout<<"De la pila 1 a la pila 3"<< endl;
    cin>>Discos;
    MoverTorres(Discos 1,2,3 );
    cout<<endl<<endl;
    
    return 0;

}
