#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);
void ordenar(int arr[], int pinicial, int pfinal);
void imp(int a[],int n);
int mitad (int arr[], int pinicial,  int pfinal);
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
    ordenar(a,0,n-1);
    imp(a,n);
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
void ordenar(int arr[], int pinicial, int pfinal){
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(arr,pinicial,pfinal);
    do{
        while(arr[i]<piv){
            i++;
        }while(arr[j]>piv){
            j--;
        }if(i<=j){
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);

    if(pinicial<j)
        ordenar(arr,pinicial,j);
    if(i<pfinal)
        ordenar(arr,i,pfinal);
}

void imp(int a[],int n){
    for(int i=0; i<n; i++){
        archivo<<a[i]<<" ";
    }
    archivo<<endl;
}

int mitad (int arr[], int pinicial,  int pfinal){
    return arr[(pinicial+pfinal)/2];
}
