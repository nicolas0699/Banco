#include "datos.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


Datos in_datos(string str, Datos x){
    string arr [11]; 
    int i = 0;
    // Used to split string around spaces. 
    istringstream ss(str); 
  
    // Traverse through all words 
    for(int i = 0; i < 11; i++){
        string word;
        ss >> word;

        arr[i] = word;
    }
    x.insertar(arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], stod(arr[10]));
    return x;
} 

string mayusculas(string cadena){
    int size = cadena.size();
    for(int i=0; i< size; i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}


int main(){
    Datos x;
    string y;

    ifstream out("datos.txt");
    int i = 0;
    getline(out, y);
    getline(out, y);

    do{
        getline(out, y);
        if(out.eof())
            break;
        else
            x = in_datos(y, x);
    }while(out.good());

    x.ver_pacientes();
    out.close();

    ofstream in("datos.txt",ios::app);
        if(x.tamano()==0){
            in << setw(15) <<left << "ID" << setw(15) << left << "identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Telefono" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" <<   "Distancia" <<  '\n';
            in<<"==============================================================================================================================================================="<<'\n';
        }
    in.close();
    
    int g;

    cout << "introduzca 1 para agregar un paciente" << "\n2 para información de RH" << "\n3 para cambiar el dato de algun paciente\n";

    cin >> g;

    if(g == 1){
        string ident;
        string nom1;
        string nom2;
        string apellido1;
        string apellido2;
        string nacimiento;
        string telefono;
        string sexo;
        string rh;
        double dist;

        cout << "Introduzca el número de identifiación: ";
        cin >> ident;

        cout << "Introduzca el primer nombre: ";
        cin >> nom1;

        cout << "Introduzca el segundo nombre: ";
        cin >> nom2;

        cout << "Introduzca el primer apellido: ";
        cin >> apellido1;

        cout << "Introduzca el segundo apellido: ";
        cin >> apellido2;

        cout << "Introduzca la fecha de nacimiento (ej: 17/06/1999): ";
        cin >> nacimiento;

        cout << "Introduzca su número de telefono o celular: ";
        cin >> telefono;

        cout << "Introduzca el sexo (F o M): ";
        cin >> sexo;

        cout << "Introduzca el tipo de sangre (ej: A+): ";
        cin >> rh;

        cout << "Introduzca la distancia promedio en kilometros de su casa al hospital (ej: 6): ";
        cin >> dist;

        ofstream in("datos.txt",ios::app);
        if(in.good()){
        x.insertar(ident, nom1, nom2, apellido1, apellido2, nacimiento, telefono, sexo, rh, dist);
        }
        if(in.good()){
            in<<setw(15) << left << x.tamano() << setw(15) << left << x.get_ident(x.tamano()) << setw(15) << left << x.get_nom1(x.tamano()) << setw(15) << left << x.get_nom2(x.tamano()) << setw(15) << left << x.get_apel1(x.tamano()) << setw(15) << left << x.get_apel2(x.tamano()) << setw(15) << left << x.get_nac(x.tamano()) << setw(15) << left <<x.get_tel(x.tamano()) << setw(15) << left << x.get_sexo(x.tamano()) << setw(15) << left << x.get_rh(x.tamano())  << x.get_dist(x.tamano()) << "\n";
        }
        in.close();
    }

    string sangre;
    if(g ==2){
        cout << "Diga que RH necesita: ";
        cin >> sangre;
        x.busqueda(mayusculas(sangre));
    }    

    cout << x.get_nom1(2) << endl;

    x.set_nom1(2, "pepito");

    cout << x.get_nom1(2) << endl;
    
    return 0;
}
