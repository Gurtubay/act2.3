#ifndef NODED
#define NODED

#include <iostream>
using namespace std;

template <typename T>//T va a almacenar el tipo de dato 

class NodoD{
    private:
        T dato;
        NodoD<T> * siguiente;
        NodoD<T> * anterior;

    public:
    //Getters y Setters
    T getDato(){return this->dato;}
    void setDato(T valor){this->dato=valor;}

    NodoD<T> * getSiguiente(){return this->siguiente;}
    void setSiguiente(NodoD<T> * nodo){this->siguiente=nodo;}

    NodoD<T> * getAnterior(){return this->anterior;}
    void setAnterior(NodoD<T> * nodo){this->anterior=nodo;}

    NodoD<T>(T dato, NodoD<T> * anterior, NodoD<T> * siguiente){
        this->dato=dato;
        this->siguiente=siguiente;
        this->anterior=anterior;
    }
};

#endif