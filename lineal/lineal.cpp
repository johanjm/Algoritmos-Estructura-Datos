#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);

int main() {
    ofstream archivo;
    archivo.open("lienal.txt", ios::out);
    int b[5],a,d=0;
    for (int i=0;i<5;i++){
        b[i]=ingresoP(-32767, 32768, "Ingrese un valor del arreglo: ");
        archivo<<b[i]<<" ";
    }
    a=ingresoP(-32767, 32768, "Ingrese un valor que desea buscar: ");
    archivo<<endl<<"Se desea buscar el elemento: "<<a<<endl;
    for(int i=0;i<5;i++){
        if(b[i]==a){
            cout<<"Se encontro el valor "<<a<<" en la posición :"<<i<<endl;
            archivo<<"Se encontro el valor "<<a<<" en la posición :"<<i<<endl;
            d=1;
        }
    }
    if(d==0){
        cout<<"No se encontro el elemento"<<endl;
        archivo<<"No se encontro el elemento"<<endl;
    }
    archivo.close();
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
