#include "BST.hpp"
#include <fstream>
#include "Ip.hpp"
#include "ListaDoble.hpp"
#include "ListaDobleCircular.hpp"

using namespace std;

int main(){
    //Leemos el archivo
    ifstream datos;
    datos.open("bitacoraPrueba.txt");
    string Ipp, mes, dia, hora, falla;
    ListaDoble<Ip*>* AccesosIp=new ListaDoble<Ip*>();
    ListaDoble<string> * listaIps= new ListaDoble<string>();
    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,Ipp,' ');
        getline(datos,falla);

        if(listaIps->buscarNodoT(Ipp)){
            NodoD<Ip*> * nodo=AccesosIp->getHead();
            while(nodo){
                if(Ipp==nodo->getDato()->getDirIp())
                    nodo->getDato()->agregarAcceso();
                nodo=nodo->getSiguiente();
        }}

        else{
            listaIps->agregarFinal(Ipp);
            AccesosIp->agregarFinal(new Ip(Ipp));
        }}

    NodoD<Ip*> * prueba=AccesosIp->getHead();
    do
    {
        cout<<prueba->getDato()->getDirIp()<<endl;
        cout<<prueba->getDato()->getNumAccesos()<<endl;
        prueba=prueba->getSiguiente();
    } while (AccesosIp->getHead()->getAnterior()!=prueba);


    return 0;
}