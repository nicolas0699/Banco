#include "datos.hpp"
//#include <iostream>
#include<vector>
#include<fstream>

vector<string> split(string cad,string lim){
  vector<string> vec;
  while (cad.length()>0){
    int pos=cad.find(lim);
    if(pos==-1){
      vec.push_back(cad);
      cad="";
    }
    else{
    vec.push_back(cad.substr(0,pos));
    cad=cad.substr(pos+1,cad.length()-(pos+1));
    }
  }
  return vec;
}

int main(){
    Datos x;
    //string y;
    //cout << "ingrese los datos separados por coma: ";
    //std::cin  >> y;
    //vector<string> infor=split(y,",");

    //x.insertar(infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6], infor[7],stoi(infor[8]));
    //x.insertar("1085345980", "nicole", "andrea", "caicedo", "garzon", "17/10/1999", "f", "b+", 20);
    //x.insertar("108345980", "nicolas", "giovanny", "caicedo", "ramirez", "17/06/1960", "m", "o+", 68);
    //x.insertar("108345980", "andres", "felipe", "gamez", "vargas", "13/10/1998", "m", "b+", 21);
    x.insertar("108345980", "camilo", "andres", "salazar", "martinez", "17/12/1960", "m", "AB-", 62);
    x.insertar("108345980", "sebastian", "rodirgo", "gamez", "jiminez", "16/04/1964", "m", "A+", 11);
    x.insertar("108345980", "adrian", "german", "pimiento", "ratoeez", "21/11/1976", "m", "o-", 120);
    ofstream in("DataBase.txt",ios::app);
    if(in.good()){
      in << setw(15) <<left << "ID" << setw(15) << left << "identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" << setw(15) << left <<  "Distancia" <<  '\n';
      in<<"=================================================================================================================================================="<<'\n';
      for(int i=1;i <= x.tamano();++i){
        in<<setw(15) << left << i << setw(15) << left << x.get_ident(i) << setw(15) << left << x.get_nom1(i) << setw(15) << left << x.get_nom2(i) << setw(15) << left << x.get_apel1(i) << setw(15) << left << x.get_apel2(i) << setw(15) << left << x.get_nac(i) << setw(15) << left << x.get_sexo(i) << setw(15) << left << x.get_rh(i) << setw(15) << left << x.get_dist(i) << "\n";
      }
    }
    in.close();
    //cout<<x.search_info(0)<<'\n';

    return 0;
}
