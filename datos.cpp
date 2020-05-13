#include<iostream>
#include<string>
#include <ctype.h> 
#include "datos.hpp"
#include <iomanip>
#include <fstream>
using namespace std;

int  idd=0;

Datos::~Datos(){
    while(count == 0){
        Info * temp = paciente;
        paciente = paciente->next;
        delete temp;
        count --;
    }
}


string Datos::mayusculas(string cadena){
    for(int i=0; i< cadena.size(); i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}

int Datos::tamano(){
    return count;
}

void Datos::insertar(string ident, string nom1, string nom2, string ape1, string ape2, string nac, string tel, string sexo, string rh, double dist){
    Info * informacion = new Info;
    if (paciente == nullptr){
        informacion->id=idd +1;
        informacion->identifiacion=ident;
        informacion->nombre1=mayusculas(nom1);
        informacion->nombre2=mayusculas(nom2);
        informacion->apellido1=mayusculas(ape1);
        informacion->apellido2=mayusculas(ape2);
        informacion->nacimiento=mayusculas(nac);
        informacion->telefono = tel;
        informacion->sexo=mayusculas(sexo);
        informacion->rh=mayusculas(rh);
        informacion->distancia=dist;
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
        informacion->telefono = tel;
        informacion->sexo=mayusculas(sexo);
        informacion->rh=mayusculas(rh);
        informacion->distancia=dist;
        informacion->next = paciente;
        paciente = informacion;
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

string Datos::get_tel(int i){
    Info * temp = encontrar(i);
    return temp->telefono;
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

void Datos::set_ident(int i, string val){
    Info * temp = encontrar(i);
    temp->identifiacion = mayusculas(val);
}


void Datos::set_nom1(int i, string val){
    Info * temp = encontrar(i);
    temp->nombre1 = mayusculas(val);
}


void Datos::set_nom2(int i, string val){
    Info * temp = encontrar(i);
    temp->nombre2 = mayusculas(val);
}


void Datos::set_apel1(int i, string val){
    Info * temp = encontrar(i);
    temp->apellido1 = mayusculas(val);
}


void Datos::set_apel2(int i, string val){
    Info * temp = encontrar(i);
    temp->apellido2 = mayusculas(val);
}


void Datos::set_nac(int i, string val){
    Info * temp = encontrar(i);
    temp->nacimiento = mayusculas(val);
}


void Datos::set_tel(int i, string val){
    Info * temp = encontrar(i);
    temp->telefono = mayusculas(val);
}


void Datos::set_sexo(int i, string val){
    Info * temp = encontrar(i);
    temp->sexo = mayusculas(val);
}


void Datos::set_rh(int i, string val){
    Info * temp = encontrar(i);
    temp->rh = mayusculas(val);
}


void Datos::set_dist(int i, double val){
    Info * temp = encontrar(i);
    temp->distancia = val;
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
    cout << setw(15) <<left << "ID" << setw(15) << left << "Identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Telefono" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" << setw(15) << left <<  "Distancia" << endl;
    for(int i=1; i <= count; i++){
        cout << setw(15) << left << i << setw(15) << left << get_ident(i) << setw(15) << left << get_nom1(i) << setw(15) << left << get_nom2(i) << setw(15) << left << get_apel1(i) << setw(15) << left << get_apel2(i) << setw(15) << left << get_nac(i) << setw(15) << left<< get_tel(i) << setw(15) << left << get_sexo(i) << setw(15) << left << get_rh(i) << setw(15) << left << get_dist(i) << "\n"; 
    } 
}

int Datos::partition(vector<Info*>& v,int left,int right){
  int x=v[right-1]->distancia;
  int i=left-1;
  for(int j=left;j<right-1;++j){
    if(v[j]->distancia<= x){
      i++;
      Info* c=v[j];
      v[j]=v[i];
      v[i]=c;
    }
  }
  Info* c=v[i+1];
  v[i+1]=v[right-1];
  v[right-1]=c;
  return i+1;
}

void Datos::quikci(vector<Info*>& v,int left,int right){
      if(left<right){
        int id=partition(v,left,right);
        quikci(v,left,id);
        quikci(v,id+1,right);
      }
}

void Datos::quicksort(vector<Info*>& v){
    quikci(v,0,v.size());
}

void Datos::busqueda(string R){
    vector<Info*> bod;
    Info *temp=paciente;
    for (int i=0;i<count;i++){
      if(temp->rh==R)
        bod.push_back(temp);
      temp=temp->next;
    }
    quicksort(bod);
    cout << setw(15) << left << "Nombre" << setw(15) << left << "Apellido" << setw(15) << left << "Telefono" << "Distancia" << endl;
    for(int i=0;i<bod.size();++i)
      cout<<setw(15) << left << bod[i]->nombre1<< setw(15) << left<<bod[i]->apellido1<< setw(15) << left<< bod[i]->telefono << bod[i]->distancia<<'\n';
}


