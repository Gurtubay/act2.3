#include <string>
#include <iostream>

using namespace std;

class Falla{
    private:
        string nombre;
        int ocurrencias;
    
    public:
        Falla(string nombre){
            this->nombre=nombre;
            this->ocurrencias=1; 
        }

        void agregarOcurrencia(){
            this->ocurrencias ++;
        }
        string getNombre(){return this->nombre;}
        void setNombre(string nombre){this->nombre=nombre;}

        int getOcurrencias(){return this->ocurrencias;}
        void setOcurrencias(int ocu){this->ocurrencias=ocu;}

        void imprimirFalla(){
            cout << "Falla : " << this->nombre << endl;
        }


};