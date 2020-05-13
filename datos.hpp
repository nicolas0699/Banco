#ifndef _DATOS_HPP
#define _DATOS_HPP

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Info{
    int id;
    string identifiacion;
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string nacimiento;
    string telefono;
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
    int partition(vector<Info*>& v,int left,int right);
    void quikci(vector<Info*>& v,int left,int right);
    void quicksort(vector<Info*>& v);
public:
    Datos(){paciente=nullptr, count = 0;}
    ~Datos();
    int tamano();
    void eliminar();
    Info * encontrar(int i);
    string get_ident(int i);
    string get_nom1(int i);
    string get_nom2(int i);
    string get_apel1(int i);
    string get_apel2(int i);
    string get_nac(int i);
    string get_tel(int i);
    string get_sexo(int i);
    string get_rh(int i);
    double get_dist(int i);
    void set_ident(int i, string val);
    void set_nom1(int i, string val);
    void set_nom2(int i, string val);
    void set_apel1(int i, string val);
    void set_apel2(int i, string val);
    void set_nac(int i, string val);
    void set_tel(int i, string val);
    void set_sexo(int i, string val);
    void set_rh(int i, string val);
    void set_dist(int i, double val);
    void insertar(string ident, string nom1, string nom2, string ape1, string ape2, string nac, string tel, string sexo, string rh, double dist);
    void ver_pacientes();
    void busqueda(string R);
};
#endif
