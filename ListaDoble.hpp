#include "NodoD.hpp"

template<typename T>
class ListaDoble{
    //Atributos
    NodoD<T> * head;
    int tam;

    //Metodos
    public:
        ListaDoble(){
            this->head=nullptr;
            this->tam=0;
        }
        int getTam(){
            return this->tam;
        }

        NodoD<T> * getHead(){
            return this->head;
        }
        void agregarInicio(T dato){
            //Crear el nuevo nodo
            NodoD<T> * nuevo = new NodoD<T>(dato, nullptr, this->head);
            //Actualizar los atributos de head
            if(this->head){
                this->head->setAnterior(nuevo);
            }
            //Actualizar el head de la lista al nuevo nodo
            this->head = nuevo;
            //Actualizar el tamaño
            this->tam++;
        }
        void agregarFinal(T dato){
            //Crear el nuevo nodo
            NodoD<T> * nuevo = new NodoD<T>(dato, nullptr, nullptr);
            if(this->head){//La lista tiene valores
                NodoD<T> * nodo = this->head;
                while(nodo->getSiguiente()){
                    nodo=nodo->getSiguiente();
                }
                nodo->setSiguiente(nuevo);
                nuevo->setAnterior(nodo);
            }else{//La lista está vacía
                //El head es igual al nuevo nodo
                this->head=nuevo;
            }
            //Actualizar el tamaño
            this->tam++;
        }
        NodoD<T> * buscarNodoT(T dato){
            NodoD<T> * nodo = this->head;
            while(nodo){//Recorrer la lista
                if(nodo->getDato()==dato){
                    return nodo;
                }
                nodo = nodo->getSiguiente();
            }
            return nullptr;
        }
        void update(T dato, T n_dato){
            NodoD<T> * nodo = buscarNodoT(dato);//Buscamos el nodo
            if(nodo){//El nodo que buscamos sí está en la lista
                //Creamos un nuevo nodo con el valor solicitado
                NodoD<T> * nuevo = new NodoD<T>(n_dato, nodo->getAnterior(), nodo->getSiguiente());
                //Revisamos si la lista tiene más de un elemento
                if(this->tam==1){//Si solo tiene un elemento actualizamos el head
                    this->head = nuevo;
                }else{
                    if(nodo->getAnterior() && nodo->getSiguiente()){//Revisar que el nodo que queremos actualizar no esté en los extremos
                        nodo->getAnterior()->setSiguiente(nuevo);
                        nodo->getSiguiente()->setAnterior(nuevo);
                    }else{
                        if(nodo->getAnterior()){//Es el last
                            nodo->getAnterior()->setSiguiente(nuevo);
                            nuevo->setSiguiente(nullptr);
                        }else{//Es el head
                            nodo->getSiguiente()->setAnterior(nuevo);
                            nuevo->setAnterior(nullptr);
                            this->head=nuevo; //Actualizar el head
                        }
                    }
                }
                nodo=nullptr;
            }
        }

        void del(T dato){
            //Buscamos el nodo en la lista
            NodoD<T> * nodo = buscarNodoT(dato);
            if(nodo){//Lista con valores
                if(this->tam==1){//La lista sólo tiene un elemento
                    this->head=nullptr;
                }else{
                    if(nodo->getAnterior() && nodo->getSiguiente()){//Revisar que el nodo que queremos actualizar no esté en los extremos
                        nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
                        nodo->getSiguiente()->setAnterior(nodo->getAnterior());
                    }else{
                        if(nodo->getAnterior()){//Es el last
                            nodo->getAnterior()->setSiguiente(nullptr);
                        }else{//Es el head
                            nodo->getSiguiente()->setAnterior(nullptr);
                            this->head=nodo->getSiguiente();
                        }
                    }
                    nodo=nullptr;
                }
                this->tam--;//Actualizar el tamaño de la lista
            }
        }
        
        void imprimirLista(){
            NodoD<T> * nodo = this->head;
            while(nodo){
                cout<<nodo->getDato()<<" ";
                nodo=nodo->getSiguiente();
            }
            cout<<endl;
        }
};