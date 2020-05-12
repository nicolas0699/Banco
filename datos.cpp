#include<iostream>
#include<string>
#include <ctype.h> 
#include "datos.hpp"
#include <iomanip>
#include <fstream>
using namespace std;

int  idd=0;

string Datos::mayusculas(string cadena){
    for(int i=0; i< cadena.size(); i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}

int Datos::tamano(){
    return count;
}

void Datos::insertar(string ident, string nom1, string nom2, string ape1, string ape2, string nac, string sexo, string rh, double dist){
    Info * informacion = new Info;
    if (paciente == nullptr){
        informacion->id=idd +1;
        informacion->identifiacion=ident;
        informacion->nombre1=mayusculas(nom1);
        informacion->nombre2=mayusculas(nom2);
        informacion->apellido1=mayusculas(ape1);
        informacion->apellido2=mayusculas(ape2);
        informacion->nacimiento=mayusculas(nac);
        informacion->sexo=mayusculas(sexo);
        informacion->rh=mayusculas(rh);
        informacion->distancia=dist;
        informacion->back=paciente;
        informacion->next=nullptr;
        paciente = informacion;
        count ++;
        idd = informacion->id;

    }else{
        informacion->id=idd +1 ;
        informacion->identifiacion= ident;
        informacion->nombre1=mayusculas(nom1);
        informacion->nombre2=mayusculas(nom2);
        informacion->apellido1=mayusculas(ape1);
        informacion->apellido2=mayusculas(ape2);
        informacion->nacimiento=mayusculas(nac);
        informacion->sexo=mayusculas(sexo);
        informacion->rh=mayusculas(rh);
        informacion->distancia=dist;
        informacion->next = paciente;
        paciente = informacion;
        informacion->back = paciente;
        count ++;
        idd = informacion->id;
    }
}



string Datos::get_ident(int i){
    Info * temp = encontrar(i);
    return temp->identifiacion;
}

string Datos::get_nom1(int i){
    Info * temp = encontrar(i);
    return temp->nombre1;
}

string Datos::get_nom2(int i){
    Info * temp = encontrar(i);
    return temp->nombre2;
}

string Datos::get_apel1(int i){
    Info * temp = encontrar(i);
    return temp->apellido1;
}

string Datos::get_apel2(int i){
    Info * temp = encontrar(i);
    return temp->apellido2;
}

string Datos::get_nac(int i){
    Info * temp = encontrar(i);
    return temp->nacimiento;
}

string Datos::get_sexo(int i){
    Info * temp = encontrar(i);
    return temp->sexo;
}

string Datos::get_rh(int i){
    Info * temp = encontrar(i);
    return temp->rh;
}

double Datos::get_dist(int i){
    Info * temp = encontrar(i);
    return temp->distancia;
}


Info* Datos::encontrar(int i){
    Info * temp = paciente;
    while (temp != nullptr){
        if(temp->id == i){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void Datos::ver_pacientes(){
    cout << setw(15) <<left << "ID" << setw(15) << left << "identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" << setw(15) << left <<  "Distancia" << endl;
    for(int i=1; i <= count; i++){
        cout << setw(15) << left << i << setw(15) << left << get_ident(i) << setw(15) << left << get_nom1(i) << setw(15) << left << get_nom2(i) << setw(15) << left << get_apel1(i) << setw(15) << left << get_apel2(i) << setw(15) << left << get_nac(i) << setw(15) << left << get_sexo(i) << setw(15) << left << get_rh(i) << setw(15) << left << get_dist(i) << "\n"; 
    } 
}



