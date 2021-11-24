#ifndef ABC
#define ABC

#include <iostream>
#include <string>

using namespace std;

class Ip{
    private:
        string dirIp;
        string direccion;
        int numAccesos;
    
    public:
        Ip(string Ip){
            this->dirIp=Ip;
            this->numAccesos=1;
        }
    
    //Getter y Setters
    string getDirIp(){return this->dirIp;}
    void setDirIp(string Ip){this->dirIp=Ip;}
    string getDireccion(){return this->direccion;}
    void setDireccion(string direccion){this->direccion=direccion;}
    int getNumAccesos(){return this->numAccesos;}
    void setNumAccesos(int nAccesos){this->numAccesos=nAccesos;}

    //Metodo para adicionar 1 al numero de accesos
    void agregarAcceso(){this->numAccesos++;}
};

#endif