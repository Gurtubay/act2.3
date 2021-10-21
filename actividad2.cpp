//#ifndef ABC
//#define ABC

#include "ListaDobleCircular.hpp"
#include "bitacora.hpp"
#include "Falla.hpp"
//#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;


template<typename T>

int main(){
    //Hacemos una lista doble circular de clases Bitacora
    ifstream datos; //Permite lectura en variable datos
    ListaDobleCircular<Bitacora *> registro; //Lista con apuntadores de clase Bitacora
    datos.open("bitacoraSecundaria-1.txt");//Abre archivo
    string mes, dia,hora,ipp,falla;//Variables de atributos en bitacora
    while(datos.good()){//Obtiene los datos del archivo y los guarda en las variables
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ipp,' ');
        getline(datos,falla);
        registro.agregarFinal(new Bitacora(mes,dia,hora,ipp,falla));//Se crea el objeto en el heap dentro de la lista 
    }
    datos.close();//Se cierra el archivo
    
    //Segunda lista doble circular con las fallas y ocurrencias
    string nombreFalla;//Nueva variable
    ListaDobleCircular<Falla *> fallas;//Se crea una segunda lista doble circular con apuntadores de clase falla
    NodoD<T> * nodoFalla = new NodoD<T>();//Se crea un nuevo nodo en el heap
    nodoFalla->setDato(Falla (registro.getHead()->getDato()->getFalla())); //Se mete el primer objeto de falla en el nodo basado en el head de la lista con la bitacora
    fallas.agregarInicio(nodoFalla);//Se mete el primer nodo en la lista de fallas
    NodoD<T> * nodoPasada = new NodoD<T>();//Se inicializa nuevo nodo para la lectura de lista registro
    nodoPasada=registro.head();//El nodo pasada sera igual al nodo del head de registro
    do
    {
        //nodoFalla=registro.leerLista(*nodoFalla);//Paso por apuntador para ir comparando valores
        nombreFalla = registro.leerLista(*nodoPasada)->getDato()->getFalla();//Se actualiza el nombre de la falla siguiente de la lista de registros
        nodoFalla->setDato(Falla(nombreFalla));//Se actualiza el nodo falla con el siguiente valor de la lectura de registro
        //?????? Nodo Falla = Nodo Bitacora?????
        if (fallas.buscarNodoT(nodoFalla))//Se busca el nodoFalla en la lista de fallas
        {
            nodoFalla->getDato()->agregarOcurrencia(); //Si existe, se obtiene la clase y se la llama a la funcion que agrega 1 a las ocurrencias
        }
        else
            fallas.agregarFinal(nodoFalla); //Si no existe se agrega el nodo completo al final 
            nodoFalla->getDato()->setNombre(nombreFalla);//Se le pone el nombre de la falla para su posterior busqueda
    } while(nodoPasada != registro.head->getAnterior());//While para que pase por todos los valores del registro

    string tipoFalla;//Inicializamos nueva variable tipo falla
    cout<<"Ingrese el tipo de falla: "<< endl;
    cin>>tipoFalla;//Aqui esta el input 
    cout << endl;
    nodoPasada = fallas.getHead()->getAnterior();//Actualizamos el nodo pasada para que este en el ultimo elemento de la lista falas
    ofstream miConsulta("consulta.txt");
    do
    {
        nodoFalla=fallas.leerLista(*nodoPasada);
        if(nodoFalla->getDato()->getNombre()==tipoFalla)//
            cout<<"Numero de ocurrencias de la falla: "<<nodoFalla->getDato()->getOcurrencias(); 
            miConsulta<<"Falla: "<<tipoFalla<<"\n";
            miConsulta<<"Ocurrencias: "<<nodoFalla->getDato()->getOcurrencias()<<endl;
            miConsulta.close();

    } while (tipoFalla!=nodoFalla()->getDato()->getNombre());
    
    
    //Hacer otra lista Doble Cirular con en nombre de las fallas sin repetir y el numero de sucesos
    //Hacer clase falla en otro documento .hpp
    //Solicite al usuario el tipo de falla y muestre el número de ocurrencias totales
    //y la información del número de ocurrencias divididos por mes. 
    //Almacenar en un archivo el resultado de la consulta anterior
    return 0;
}