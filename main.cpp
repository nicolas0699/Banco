#include "datos.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

int main(){
    Datos x;
    string y;

    x.insertar("8", "nicolas", "giovanny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 15);
    x.insertar("1085345950", "nicdddolas", "giovanny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 15);
    x.insertar("1085345989", "nicdddolas", "giovanwwdwny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 15);
    x.ver_pacientes();

    ofstream in("datos.txt",ios::app);
    if(in.good()){
      in << setw(15) <<left << "ID" << setw(15) << left << "identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" << setw(15) << left <<  "Distancia" <<  '\n';
      in<<"=================================================================================================================================================="<<'\n';
      for(int i=1;i <= x.tamano();++i){
        in<<setw(15) << left << i << setw(15) << left << x.get_ident(i) << setw(15) << left << x.get_nom1(i) << setw(15) << left << x.get_nom2(i) << setw(15) << left << x.get_apel1(i) << setw(15) << left << x.get_apel2(i) << setw(15) << left << x.get_nac(i) << setw(15) << left << x.get_sexo(i) << setw(15) << left << x.get_rh(i) << setw(15) << left << x.get_dist(i) << "\n";
      }
    }
    in.close();

    

    return 0;
}
