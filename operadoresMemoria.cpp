#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

//Paso de parámetros por valor (copia)
void funcion1(int param){
    cout<<"Valor de param"<<param<<endl;
    param=34;
    cout<<"Valor de param"<<param<<endl;
    cout<<"direccion de param"<<&param<<endl;
}

//Paso de parámetros por referencia
void funcion2(int &param){
    param=34;
    cout<<"Valor de param"<<param<<endl;
    cout<<"direccion de param"<<&param<<endl;
}

//Paso de parámetros por apuntador
void funcion3(int *param){
    *param=40;
    cout<<"Valor de param:"<<param<<endl;
    cout<<"direccion de param"<<*param<<endl;
}

//Sobrecarga del operador << para que pueda imprimir vectores
template<class T>
ostream& operator<<(ostream&stream,const vector<T>& valores){
    stream<< "{ ";
    copy(begin(valores),end(valores),ostream_iterator<T>(stream," "));
    stream<< "}";
    return stream;
}

//Paso de parametro por valor (copia)
void funcion4(vector<int> param){
    param={1,1};
    cout<<"Valor de param: "<<param<<endl;
    cout<<"direccion de param"<<&param<<endl;
}

//Paso de parametro por referencia
void funcion5(vector<int> &param){
    param={4,4};
    cout<<"Valor de param: "<<param<<endl;
    cout<<"direccion de param"<<&param<<endl;
}

//Paso de parametros por apuntador
void funcion6(vector<int> *param){
    *param={3,3};
    cout<<"Valor de param:" <<*param<<endl;
    cout<<"direccion de param"<<param<<endl;
}

class Ejemplo{
    int valor;
    public:
        int getValor(){return this->valor;}
        void setValor(int valor){this->valor=valor;}
        Ejemplo(int valor){
            this->valor=valor;
        }
        Ejemplo(){
            this->valor=45;
        }
};


int main(){
    int var1 = 48; //Crear una variable en el stack con valor de 48
    int var2 = var1; //Crear una variable nueva en el stack con el valor de var1
    int * var3; //Creando un apuntador(pointer)
    var3 = &var1; //Asignando la dirección del espacio de memoria de var1 a var3
    int &var4 = var1; //Creando una referencia a la variable var1 

    cout<<"var1: "<<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    cout<<"var2: "<<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl;
    cout<<"direccion de var1 en var3: "<<var3<<endl;
    cout<<"valor de var1 en var3: "<<*var3<<endl;
    cout<<"var4: "<<var4<<endl;
    cout<<"direccion de var4: "<<&var4<<endl;

    var1=33;

    cout<<"var1: "<<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    cout<<"var2: "<<var2<<endl;
    cout<<"direccion de var2: "<<&var2<<endl;
    cout<<"direccion de var1 en var3: "<<var3<<endl;
    cout<<"valor de var1 en var3: "<<*var3<<endl;
    cout<<"var4: "<<var4<<endl;
    cout<<"direccion de var4: "<<&var4<<endl;

    var3=&var2;
    cout<<"direccion de var2: "<<&var2<<endl;
    cout<<"direccion de var1 en var3: "<<var3<<endl;
    cout<<"valor de var1 en var3: "<<*var3<<endl;
    cout<<"var4: "<<var4<<endl;
    cout<<"direccion de var4: "<<&var4<<endl;

    cout<<"************Enteros***************"<<endl<<endl;
    funcion1(var1);
    cout<<"var1: "<<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    funcion2(var1);
    cout<<"var1: "<<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    funcion3(&var1);
    cout<<"var1: "<<var1<<endl;
    cout<<"direccion de var1: "<<&var1<<endl;
    cout<<endl<<"************Vectores***************"<<endl<<endl;
    
    vector<int> a {2,3,5,6,7,8}; //Creando un vector a con 6 valores
    vector<int> b {a}; //vector<int> b=a;  Creando un nuevo vector con los valores de a
    vector<int> * c = nullptr; // Creando un apuntador a vector<int> que a punta nullptr
    c=&b;
    c=&a;
    //c=&var1; error el apuntador no coincide con el tipo de dato
    vector<int> &d=b;

    //Hacer ejemplos de funciones de paso por valor, referencia , apuntador pero con vectores
    cout<<"-----funcion 4---"<<endl;
    cout<<"Valor de param: "<<a<<endl;
    cout<<"direccion de param"<<&a<<endl;
    funcion4(a);
    cout<<"-----funcion 5---"<<endl;
    cout<<"Valor de param: "<<a<<endl;
    cout<<"direccion de param"<<&a<<endl;
    funcion5(a);
    cout<<"-----funcion 6---"<<endl;
    cout<<"Valor de param: "<<a<<endl;
    cout<<"direccion de param"<<&a<<endl;
    funcion6(&a);
    
    //Stack allocation (memoria adminsitrada por el compilador)
    int var5=5;
    int arreglo [5]; //Arreglo  estático
    vector<string> vec ={"Hola"};
    Ejemplo obj1; //Se crea la instancia obj1 en el Stack llamando Ejemplo()
    Ejemplo obj2(22); //Se crea la instancia obj2 en el Stack llamando Ejemplo(int valor)
    
    //Acceso a valores de atributos a través de un objeto
    cout<<obj1.getValor()<<endl;
    cout<<obj2.getValor()<<endl;
    vector<Ejemplo> vec2 = {obj1,obj2};
    
    
    //Heap allocation (memoria administrada por el programador(a))
    int * arregloDinamico=new int[6]; //Crean un arreglo dinámico dentro del heap
    Ejemplo * obj3= new Ejemplo(); //Creando una instancia en el heap llamando Ejemplo() y obj3 apunta a la instancia
    Ejemplo * obj4= new Ejemplo(34); //Creando una instancia en el heap llamando Ejemplo(int valor) y obj4 apunta a la instancia

    //Acceso a valores de atributos a través de un apuntador a objeto
    cout<<obj3->getValor()<<endl;
    cout<<obj4->getValor()<<endl;
    cout<<(*obj4).getValor()<<endl;
    
    vector<Ejemplo *> vec3 = {obj3,obj4};    

    //Liberan espacio del heap
    delete [] arregloDinamico;
    delete obj3; 
    delete obj4;  
    

}