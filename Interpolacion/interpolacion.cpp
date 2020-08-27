#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);
void busc(int n,int a[],int b);
void orden(int n,int a[]);
void imp(int a[],int n);
void suma(int a[],int n);
ofstream archivo;
int main() {
    int n=0;
    archivo.open("interpolacion.txt", ios::app);
    n= ingresoP(0, 10000, "¿Cuántos elementos va a ingresar?: ");
    int a[n];
    for (int i=0; i<n; i++) {
        cout<<"Posición ["<<i+1<<"]"<<endl;
        a[i]= ingresoP(-10000, 1000000, "Ingrese un número: ");
    }
    archivo<<"Arreglo de elementos originales:"<<endl;
    imp(a, n);
    archivo<<"Arreglo de elementos ordenados:"<<endl;
    orden(n,a);
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
void orden(int n,int a[]){
    int aux,b;
    for (int i=0; i<n; i++)
    {
        aux=a[i];
        int p=i;
        while (p>0)
        {
           if (a[p-1]>aux)
            {
                a[p]=a[p-1];
                a[p-1]=aux;
            }
            p--;
        }
    }
    imp(a, n);
    b=ingresoP(-10000, 100000, "Ingrese el valor que desea buscar: ");
    busc(n, a, b);
}
void busc(int n,int a[],int b){
    int primero=0,ultimo = n-1,medio,contador=0;
    while (a[primero]!=b && contador < 7)
    {
        medio = primero + ((b-a[primero])*(ultimo -primero))/(a[ultimo]-a[primero]);
        if(a[medio]<b)
            ultimo =medio+1;
        else if (a[medio]>b)
            ultimo = medio -1;
        else
            primero = medio;
        contador++;
        break;
    }
    if (a[primero]==b)
    {
        archivo<<"ELEMENTO ENCONTRADO"<<endl;
        archivo<<"El elemento se encontro en la posición: ["<<primero+1<<"]"<<endl;
    }
    else
    {
         archivo<<"ELEMENTO NO ENCONTRADO"<<endl;
    }
}

void imp(int a[],int n){
    for(int i=0; i<n; i++){
        archivo<<a[i]<<" ";
    }
    archivo<<endl;
}

