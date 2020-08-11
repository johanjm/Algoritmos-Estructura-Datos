#include <iostream>
#include <fstream>
using namespace std;
double ingresoP(int n,int m, string c);

int main() {
    ofstream archivo;
    archivo.open("piramide.txt", ios::out);
    char c;
    if(archivo.fail()){
        cout<<"No se encontro el archivo";
    }
    int a = ingresoP(0, 32768, "Ingrese un nivel: "), b=a;
    for (int i=0; b>i;i++) {
        for (int j=0; a>j; j++) {
            if (i%2==0) {
                c='*';
            }else{
                c='-';
            }
            cout<< c<<" ";
            archivo<< c<<" ";
        }
        cout<<endl;
        archivo<<endl;
        a--;
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
