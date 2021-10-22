

#include "ListaDoble.hpp"
#include "ListaDobleCircular.hpp"
#include "bitacora.hpp"
#include "Falla.hpp"
//#include <iostream>
//#include <vector>
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;


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
    NodoD<Falla *> * nombreFalla;//Nueva variable
    ListaDoble<Falla *> fallas;//Se crea una lista doble con apuntadores de clase falla
    NodoD<Bitacora *> * nodoPasadaB= new NodoD<Bitacora*>(registro.getHead()->getDato(),registro.getHead()->getSiguiente(),registro.getHead()->getAnterior()); 
    do{
        
        Falla * datoFalla = new Falla (nodoPasadaB->getDato()->getFalla());
        nombreFalla=fallas.buscarNodoT(datoFalla);
        if (nombreFalla)//Se busca el nodoFalla en la lista de fallas
        {
            fallas.buscarNodoT(datoFalla)->getDato()->agregarOcurrencia(); //Si existe, se obtiene la clase y se la llama a la funcion que agrega 1 a las ocurrencias
        }
        else
            fallas.agregarFinal(datoFalla); //Si no existe se agrega el nodo completo al final 
            nodoPasadaB=nodoPasadaB->getSiguiente();//Se le pone el nombre de la falla para su posterior busqueda
    } while(nodoPasadaB != registro.getHead());//While para que pase por todos los valores del registro

    
    string tipoFalla;//Inicializamos nueva variable tipo falla
    cout<<"Ingrese el tipo de falla: "<< endl;
    cin>>tipoFalla;//Aqui esta el input 
    cout << endl;
    nombreFalla = fallas.getHead();//Actualizamos el nodo pasada para que este en el ultimo elemento de la lista falas
    ofstream miConsulta("consulta.txt");
    do
    {
        if(nombreFalla->getDato()->getNombre()==tipoFalla)//
            cout<<"Numero de ocurrencias de la falla: "<<nombreFalla->getDato()->getOcurrencias(); 
            miConsulta<<"Falla: "<<tipoFalla<<"\n";
            miConsulta<<"Ocurrencias: "<<nombreFalla->getDato()->getOcurrencias()<<endl;
            miConsulta.close();

    } while (tipoFalla!=nombreFalla->getDato()->getNombre());
    
    
    //Hacer otra lista Doble Cirular con en nombre de las fallas sin repetir y el numero de sucesos
    //Hacer clase falla en otro documento .hpp
    //Solicite al usuario el tipo de falla y muestre el número de ocurrencias totales
    //y la información del número de ocurrencias divididos por mes. 
    //Almacenar en un archivo el resultado de la consulta anterior

    //Cuando se le solicite al usuario la hora, se debera obtener el atributo hora de cada objeto de cada nodo 
    //de la lista doble circular, y posteriormente utilizar string.remove(3,6) para quedarse unicamente con la hora
    return 0;
}