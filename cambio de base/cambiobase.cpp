/* (C) Programmed by:
   Antonio Jimenez Martínez

Sotware:cambio de base
Version:0.1

Este programa es capaz de realizar cambios de base, lo aplicamos sobre numeros naturales.
Escribe letras mayusculas en la representación de bases >10.
*/
#include <iostream>
#include <string>

using namespace std;
string cambiode10abase(int numero,const int & base);
string convertir(const int &a);
int convertir(const char &a);
int cambiodebasea10(const string &numero,const int &base);

int main()
{
    int baseE,baseS;//base de entrada y de salida
    cout<<"Introduce la base de entrad y de salida:\n";
    cin>>baseE>>baseS;
    if(baseE!=baseS) {
        if(baseE==10) {
            //numero es int ya que esta en base 10
            //cambiado es string ya que puede estar en base 16 y tener letras
            int numeroE;
            string cambiado;
            cout << "Introduce el numero en base 10:\n" << endl;
            cin>>numeroE;
            cambiado=cambiode10abase(numeroE,baseS);
            cout<<"\nEl numero en base "<<baseS<<" es: "<<cambiado<<endl;
        }
        else if(baseS==10) {
            //numero es un string ya que puede estar en base 16 y tener letras
            //base10 es un numero ya que sabemos que esta en base 10.
            string numero;
            int base10;
            cout << "Introduce el numero en base "<<baseE<<":\n" << endl;
			cin.ignore();		//  Needed in order to allow new input.
            getline(cin,numero);
            base10=cambiodebasea10(numero,baseE);
            cout<<"\nEl numero en base 10 es: "<<base10<<endl;
        }
		else{//baseE!=10 && baseS!=10
			//numero es un string ya que puede estar en base 16 y tener letras
            //base10 es un numero ya que sabemos que esta en base 10.
            //cambiado es string ya que puede estar en base 16 y tener letras
            string numero,cambiado;
            int base10;
            cout << "Introduce el numero en base "<<baseE<<":\n" << endl;
			cin.ignore();		//  Needed in order to allow new input.
            getline(cin,numero);
            base10=cambiodebasea10(numero,baseE);
            cambiado=cambiode10abase(base10,baseS);
            cout<<"\nEl numero en base "<<baseS<<" es: "<<cambiado<<endl;
		}
    }
    else {
        cout<<"La base de entrada y salida no pueden ser la misma."<<endl;
    }
}
string convertir(const int & a)
{
    string aux;
    if(a>=0 && a<=9)
        aux='0'+a;
    if(a==10)
        aux='A';
    if(a==11)
        aux='B';
    if(a==12)
        aux='C';
    if(a==13)
        aux='D';
    if(a==14)
        aux='E';
    if(a==15)
        aux='F';
    return aux;
}

int convertir(const char &a)
{
    int aux;
    if(a>='0' && a<='9')
        aux=a-'0';
    if(a=='A')
        aux=10;
    if(a=='B')
        aux=11;
    if(a=='C')
        aux=12;
    if(a=='D')
        aux=13;
    if(a=='E')
        aux=14;
    if(a=='F')
        aux=15;
    return aux;
}
//de atras a adelante, vamos tomando los numero y multiplicandolos por el parametro
//el parametro es base^posicion
int cambiodebasea10(const string &numero,const int &base) {
    int suma=0,parametro=1,aux;
    char a;
    for(int i=numero.size()-1; i>=0; i--) {
        a=numero.at(i);
        aux=convertir(a);
        suma+=parametro*aux;
        parametro*=base;
    }
    return suma;

}

string cambiode10abase(int numero,const int &base)
{
    string salida,aux;
    int a;
    while(numero!=0) {
        //mientras el numero sea distinto de 0, vamos tomando su resto dividiendolo por la base.
        a=numero%base;
        aux=convertir(a);
        salida=aux+salida;
        numero/=base;
    }
    return salida;
}
