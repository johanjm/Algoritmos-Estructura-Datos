#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);
void ordenar(int arr[], int pinicial, int pfinal);
void imp(int a[],int n);
void heapSort(int a[], int n);
ofstream archivo;
int main() {
    int n=0;
    archivo.open("heapsort.txt", ios::app);
    n= ingresoP(0, 10000, "¿Cuántos elementos va a ingresar?: ");
    int a[n];
    for (int i=0; i<n; i++) {
        cout<<"Posición ["<<i+1<<"]"<<endl;
        a[i]= ingresoP(-10000, 1000000, "Ingrese un número: ");
    }
    archivo<<"Arreglo de elementos originales:"<<endl;
    imp(a, n);
    archivo<<"Arreglo de elementos ordenados:"<<endl;
    heapSort(a, n);
    archivo<<"Se utilizó el metodo de HeapSort"<<endl;
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

void imp(int a[],int n){
    for(int i=0; i<n; i++){
        archivo<<a[i]<<" ";
    }
    archivo<<endl;
}

void heapSort(int a[], int n){
   int valor,temp,b;
    for(int i=n; i>0; i--){
        for(int j=1; j<=i; j++){
            valor=a[j];
            b=j/2;
            while(b>0 && a[b]<valor){
                a[j]=a[b];
                j=b;
                b=b/2;
            }
            a[j]=valor;
        }
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
    }
    imp(a,n);
}

