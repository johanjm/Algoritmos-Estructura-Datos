#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
ofstream archivo;
void dividir(int a[], int inicial, int final);
void fusionar(int a[], int pinicial, int pfinal, int medio);
double ingresoP(int n,int m, string c);

int main(){
    archivo.open("mergesort.txt", ios::app);
    int n=ingresoP(0, 10000, "Cuantos números va a ingresar?: ");
    int numeros[n];
    for (int i=0; i<n;i++){
        numeros[i]=ingresoP(0, 20, "Ingrese un valor entre el 1 y el 20:");
    }
    for (int i=0; i<n;i++){
        cout<<"|"<<numeros[i]<<"|";
        archivo<<"|"<<numeros[i]<<"|";
    }
    dividir(numeros,0,n);
    cout<<endl;
    archivo<<endl;
    for (int i=0; i<n;i++){
        cout<<"|"<<numeros[i]<<"|";
        archivo<<"|"<<numeros[i]<<"|";
    }
    archivo.close();
}
void dividir(int a[], int inicial, int final){
    int mitad;
    if (inicial<final){
        mitad=(inicial+final)/2;
        dividir(a,inicial,mitad);
        dividir(a,mitad+1,final);
        fusionar(a,inicial,final,mitad);
    }
    
}
void fusionar(int a[], int pinicial, int pfinal, int medio){
    int i, j, k, temp[pfinal-pinicial+1];
    i = pinicial;
    k = 0;
    j = medio + 1;
    while (i <= medio && j <= pfinal){
        if (a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= medio){
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <=pfinal){
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = pinicial; i <= pfinal; i++){
        a[i] = temp[i-pinicial];
    }
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
