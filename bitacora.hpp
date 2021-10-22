#include <string>
#include <iostream>
#include <sstream> //Lectura de flujos de texto

using namespace std;

class Bitacora{
    //Atributos
    private:
        string mes;
        string dia;
        string hora;
        string ipp;
        string falla;
        int clave;
    //Métodos
    public:  //Operadores de memoria *,->, & , .
        string getFalla(){return this->falla;}
        string getMes(){return this->mes;}
        void setMes(string mes){this->mes=mes;}
        string getHora(){return this->hora;}
        
        //Tarea
        Bitacora(){
            this->mes="";
            this->dia="";
            this->hora="";
            this->ipp="";
            this->falla="";
            this->asignarClave();            
        }
        Bitacora(string mes,string dia, string hora, string ipp,string falla){
            this->mes=mes;
            this->dia=dia;
            this->hora=hora;
            this->ipp=ipp;
            this->falla=falla;
            this->asignarClave();            
        }
        string mesANumero(){
            if(!this->mes.compare("Jun")) // ! not
                return "6";
            else if(!this->mes.compare("Jul"))
                return "7";
            else if(!this->mes.compare("Aug"))
                return "8";
            else if(!this->mes.compare("Sep"))
                return "9";
            else if(!this->mes.compare("Oct"))
                return "10";
            else if(!this->mes.compare("Nov"))
                return "11";
            else if(!this->mes.compare("Dec"))
                return "12";
            else
                return "0"; 
        }

        void asignarClave(){
            //Concatenar el mes con el dia para crear la clave
            string id=this->mesANumero()+this->dia;            
            stringstream string2int(id);
            string2int>>this->clave; //Conversión de string a int
        }

        void imprimirRegistro(){
            cout<<this->clave<<" "<<this->mes<<" "<<this->dia<<" "<<this->hora<<" "<<this->ipp<<" "<<this->falla<<"\n";
        }

};