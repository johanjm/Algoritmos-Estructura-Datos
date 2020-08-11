#include <iostream>
#include <fstream>
using namespace std;
string nombre;
string apellido;
int e;
char r;

void ingreso();
void otros();

int main()
{
    ingreso();
    otros();
    return 0;
}
void ingreso()
{
    ofstream archivoPrueba;
    archivoPrueba.open("datos.txt", ios::app);
   do
    {
        cout<<"\tIngrese el nombre: ";
        getline(cin, nombre,'\n');
        cout<<"\tIngrese el apellido: ";
        getline(cin, apellido,'\n');
        cout<<"\tIngresa la edad: ";
        cin>>e;
        archivoPrueba<<nombre<<" "<<apellido<<" "<<e<<"\n";
        cout<<"Desea agregar otro contacto s/n ";
        cin>>r;
        cin.ignore();
    }while(r=='s');
    archivoPrueba.close();
}

void otros()
{
    ifstream archivoLectura("datos.txt");
    string texto;
    while(!archivoLectura.eof())
    {
        archivoLectura>>nombre>>apellido>>e;
        if(!archivoLectura.eof())
        {
            getline(archivoLectura,texto);
            cout<<"Nombre es: "<<nombre<<"\n";
            cout<<"Apellido es: "<<apellido<<"\n";
            cout<<"Edad es: "<<e<<"\n";
        }
    }
    archivoLectura.close();
}
