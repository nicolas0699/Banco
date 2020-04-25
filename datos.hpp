#ifndef _DATOS_HPP
#define _DATOS_HPP

#include<iostream>
#include<string>
using namespace std;

struct Info{
    int id;
    string identifiacion;
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string nacimiento;
    string sexo;
    string rh;
    double distancia;
    Info * next;
    Info * back;
};

class Datos{
private:
    Info * paciente;
    int count;
    int capacity;
    
    string mayusculas(string cadena);
public:
    Datos(){paciente=nullptr, count = 0;}
    int tamano();
    void eliminar();
    Info encontrar();
    void insertar(string ident, string nom1, string nom2, string ape1, string ape2, string nac, string sexo, string rh, double dist);
    void ver_pacientes();
};


#endif