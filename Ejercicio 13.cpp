//EJercicio 13

#include <iostream>
using namespace std;


int func(int);

int main(){
    int n;
    cout<<"Digite un numero: ";
    cin>>n;
    //cout<<func(n)
    
    int i=n+1;
    if(i==0){
        return 0;
    }
    while(i>=0)
    {
        n = n + 1;
        i--;
    }
    cout<< n <<endl;
    return 0;
}
/*int func(int n)
{ 
    if(n==0)
    return(0);
    return(n+ func(n-1);
}*/
