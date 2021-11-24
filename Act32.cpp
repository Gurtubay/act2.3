#include "BST.hpp"
#include <fstream>
#include "Ip.hpp"
#include "ListaDoble.hpp"
#include "ListaDobleCircular.hpp"

int main(){
    //Leemos el archivo
    ifstream datos;
    datos.open("bitacoraPrueba.txt");
    string Ip, mes, dia, hora, falla;
    ListaDoble<string> * listaIps= new ListaDoble<string>();
    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,Ip,' ');
        getline(datos,falla);
        if(!(listaIps->buscarNodoT(Ip)))
            listaIps->agregarFinal(Ip);
            
    }

    return 0;
}