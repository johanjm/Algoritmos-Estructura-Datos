#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);
void imprimir(double a[10]);

int main() {
    double b[10], a[10];
    for(int i=0; i<10; i++){
        cout<<"Posición ["<<i+1<<"]"<<endl;
        a[i]=ingresoP(49, 100, "Ingrese un valor entre 50 y 100: ");
        b[i]=a[i]*0.5;
    }
    cout<<"Primer arreglo:"<<endl;
    imprimir(a);
    cout<<"Segundo arreglo:"<<endl;
    imprimir(b);
}
double ingresoP(int n,int m, string c){
    int op=0;
    double a;
    while(op==0){
        cout<<c;
        cin>>a;
        if(a>n && a<=m){
            op=1;
        }else{
            cout<<"El valor ingresado no es correcto"<<endl;
        }
    }
    return a;
}
void imprimir(double a[10]){
    for(int i=0; i<10; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
