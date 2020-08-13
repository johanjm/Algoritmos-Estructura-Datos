#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);

int main() {
    ofstream archivo;
    archivo.open("Venta_Uvas.txt", ios::out);
    int op=0,tipo=0,tamaño=0,b;
    double precio, uvas, total,inicial=0;
    char a;
    precio= ingresoP(0, 32767, "Ingrese el precio en dólares por kilo de uvas: ");
    uvas= ingresoP(0, 32767, "Ingrese el número de kilo de uvas: ");
    while(op==0){
        cout<< "de qué tipo desea las uvas (A/B): ";
        cin>> a;
        if(a=='A' || a=='a'){
            a='A';
            tipo=1;
            op=1;
        }else{
            if(a=='B' || a=='b'){
                a='B';
                tipo=2;
                op=1;
            }
        }
    }
    op=0;
    while(op==0){
        b=ingresoP(0, 2, "de qué tamaño desea las uvas (1 / 2): ");
        if(b==1){
            tamaño =1;
            op=1;
        }else{
            if(b==2){
                tamaño=2;
                op=1;
            }
        }
    }
    switch (tipo) {
        case 1:
            if(tamaño==1){
                inicial= 0.2;
            }else{
                inicial= 0.3;
            }
            break;
        case 2:
            if(tamaño==1){
                inicial= -0.3;
            }else{
                inicial= -0.5;
            }
            break;
    }
    total=precio*uvas+inicial;
    if (inicial<0){
        inicial=-inicial;
        cout<< "el precio total es: $"<<total<<endl<<"El productor tiene una perdida  de: $"<<inicial<<endl;
        archivo<<"el precio total es: $"<<total<<endl<<"El productor tiene una perdida  de: $"<<inicial<<endl;
    }else{
        cout<< "el precio total es: $"<<total<<endl<<"El productor tiene una ganancia de: $"<<total<<endl;
        archivo<<"el precio total es: $"<<total<<endl<<"El productor tiene una ganancia de: $"<<total<<endl;
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
