#include "datos.hpp"
#include <iostream>

int main(){
    Datos x;
    string y;
    cout << "ingrese su numero de cedula: "; 
    
    std::cin  >> y;

    x.insertar(y, "nicolas", "giovanny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 20);
    x.insertar("1085345980", "nicdddolas", "giovanny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 20);
    x.insertar("1085345980", "nicdddolas", "giovanwwdwny", "caicedo", "ramirez", "17/06/1999", "m", "a+", 20);
    x.ver_pacientes();

    return 0;
}