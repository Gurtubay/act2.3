#include "NodoD.hpp"

template<typename T>
class ListaDobleCircular{
    //Atributos
    NodoD<T> * head;
    int tam;
    //last = head->getAnterior()

    public:
    ListaDobleCircular(){
        this->head=nullptr;
        this->tam=0;
    }

    NodoD<T> * getHead(){
        return this->head;
    }

    int getTam(){
        return this->tam;
    }

    void agregarInicio(T dato){
        if(this->head){//La lista tiene nodos
            NodoD<T> * nuevo = new NodoD<T>(dato, this->head->getAnterior(),this->head);
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);
            this->head = nuevo;
        }else{//Lista vacia
            NodoD<T> * nuevo = new NodoD<T>(dato, nullptr, nullptr);
            nuevo->setSiguiente(nuevo); 
            nuevo->setAnterior(nuevo);
            this->head=nuevo;
        }
        this->tam++;
    }
    void agregarFinal(T dato){
        if(this->head){
            NodoD<T> * nuevo = new NodoD<T>(dato, this->head->getAnterior(),this->head);
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);
        }else{//Lista vacia
            NodoD<T> * nuevo = new NodoD<T>(dato, nullptr, nullptr);
            nuevo->setSiguiente(nuevo); 
            nuevo->setAnterior(nuevo);
            this->head=nuevo; 
        }
        this->tam++;
    }
    NodoD<T> * buscarNodoT(T dato){
        NodoD<T> * nodo = this->head;
        while(nodo){//Recorrer la lista
            if(nodo->getDato()==dato){
                //Se encontró el nodo
                return nodo;
            }
            nodo = nodo->getSiguiente();
        }
        //No se encontró el nodo
        return nullptr;
    }
    void update(T dato, T n_dato){
        NodoD<T> * nodo = buscarNodoT(dato);//Buscamos el nodo
        if(nodo){//El nodo que buscamos sí está en la lista
            //Creamos un nuevo nodo con el valor solicitado
            NodoD<T> * nuevo = new NodoD<T>(n_dato, nodo->getAnterior(), nodo->getSiguiente());
            //Revisamos si la lista tiene más de un elemento
            if(this->tam==1){
                this->head = nuevo;
            }else{
                //Revisar que el nodo que queremos actualizar no esté en los extremos
                if(this->head==nodo){//Es el head
                    this->head->getAnterior()->setSiguiente(nuevo);
                    this->head->getSiguiente()->setAnterior(nuevo);
                    this->head = nuevo;
                }else{//El nodo a actualizar se encuentra 
                    nodo->getAnterior()->setSiguiente(nuevo);
                    nodo->getSiguiente()->setAnterior(nuevo);
                }
            }
            nodo=nullptr;
        }
    }

    void del(T dato){
        NodoD<T> * nodo = buscarNodoT(dato);
        if(nodo){//Lista con valores
            if(this->tam==1){//La lista sólo tiene un elemento
                this->head=nullptr;
            }else{
                if(this->head==nodo){//Es el head
                    this->head->getAnterior()->setSiguiente(this->head->getSiguiente());
                    this->head->getSiguiente()->setAnterior(this->head->getAnterior());
                    this->head = nodo->getSiguiente();
                }else{//El nodo a actualizar no se encuentra en los extremos
                    nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
                    nodo->getSiguiente()->setAnterior(nodo->getAnterior());
                }
                nodo=nullptr;
            }
            this->tam--;
        }
    }
    void imprimirLista(){
        if(this->head){
            NodoD<T> * nodo = this->head;
            do{
                cout<<nodo->getDato()<<" ";
                nodo = nodo->getSiguiente();
            }while(nodo!=this->head);
        }
        cout<<endl;
    }

    NodoD<T> leerLista(NodoD<T> * nodo){
        nodo=this->nodo->getSiguiente();
        return * nodo;
    }

};