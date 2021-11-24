#include "BST.hpp"
#include <fstream>
#include "Ip.hpp"
#include "Acceso.hpp"
#include "ListaDoble.hpp"
#include "ListaDobleCircular.hpp"

using namespace std;

int main(){
    //Leemos el archivo
    ifstream datos;
    datos.open("bitacoraPrueba.txt");
    string Ipp, mes, dia, hora, falla;
    ListaDoble<Acceso *> * ListaAccesos=new ListaDoble<Acceso *>();
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
    datos.close();

    /*NodoD<Ip*> * prueba=AccesosIp->getHead();
    do
    {
        cout<<prueba->getDato()->getDirIp()<<endl;
        cout<<prueba->getDato()->getNumAccesos()<<endl;
        prueba=prueba->getSiguiente();
    } while (AccesosIp->getHead()->getAnterior()!=prueba);
    */

    NodoD<Ip*> * nodo2=AccesosIp->getHead();
    NodoD<Acceso *> * nuevoNodo = ListaAccesos->getHead();
    while(nodo2){
        if(ListaAccesos){
            while (ListaAccesos!=nullptr)
            {
                if(nuevoNodo->getDato()->getAccesos()==nodo2->getDato()->getNumAccesos()){
                    nuevoNodo->getDato()->agregarIp(nodo2->getDato()->getDirIp());
                    nodo2=nodo2->getSiguiente();
                    nuevoNodo=nuevoNodo->getSiguiente();
                }
            }
            
        }
        else{
            int num_accesos = nodo2->getDato()->getNumAccesos();
            Acceso * nuevoObj = new Acceso(num_accesos);
            ListaAccesos->agregarFinal(nuevoObj);
            
        }
            
    }
   //BST<int> * arbol= new BST;<int>();
    //Agregamos los nodos al arbol con el ciclo for
    /*for(int dato: ){
        arbol->agregarNodo(dato);
    }*/


    return 0;
}