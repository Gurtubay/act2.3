#ifndef ABC
#define ABC

#include <vector>
#include "Ip.hpp"
#include <string>

using namespace std;

class Acceso{
    private:
        int numAccesos;
        vector<string> * nomIps; //Posiblemente se apunta
    public:
        Acceso(int numAccesos){
            this->numAccesos=numAccesos;
            this->nomIps= new vector<string>;//()
        }

        //Getter y Setters
        int getAccesos(){return this->numAccesos;}
        void setAccesos(int Accesos){this->numAccesos=Accesos;}
        vector<string> * getIps(){return this->nomIps;}
        void setIps(vector<string> * Ips){this->nomIps=Ips;}

        //Esto chance se borra
        void agregarIp(string nuevaIp){
            this->nomIps->push_back(nuevaIp);
        }
};

#endif