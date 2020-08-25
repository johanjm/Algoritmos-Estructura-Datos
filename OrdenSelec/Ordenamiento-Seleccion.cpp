#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);
void orden(int n, int b[]);
void imp(int a[],int n);
void suma(int a[],int n);
ofstream archivo;
int main() {
    int n=0;
    archivo.open("ordenamiento.txt", ios::app);
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
    archivo<<"La suma de los elementos es: ";
    suma(a,n);
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
    int aux;
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
}
void imp(int a[],int n){
    for(int i=0; i<n; i++){
        archivo<<a[i]<<" ";
    }
    archivo<<endl;
}
void suma(int a[],int n){
    int sum=0;
    for (int i=0; i<n; i++) {
        sum=sum+a[i];
    }
    archivo<<sum<<endl;
}
