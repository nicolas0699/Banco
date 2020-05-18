#include "datos.hpp"
#include <fstream>
#include <iomanip>
#include "HashBlood.hpp"
#include <fcntl.h>
using namespace std;

/*la funcion split() recibe una string (cad) y un delimitador (lim) y parte la
cadena de acuerdo a las veces que encuentra el delimitador y va agregando esas
particiones en un vector y lo retorna*/
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

/*la funcion match() recibe un string que es un tipo de sangre (cad) y retorna un vector
con los tipos de sangre que pueden donarle a una persona de tipo de sangre cad*/
vector<string> match(string cad){
  vector<string> matches{cad};
  if(cad!="O-")
    matches.push_back("O-");
  if(cad.at(cad.length()-1)=='-'){
    if(cad.length()==3){
      matches.push_back("A-");
      matches.push_back("B-");
    }
  }
  else{
    if(cad!="O+"){
      matches.push_back("O+");
      string n=cad.substr(0,cad.length()-1)+"-";
      matches.push_back(n);
      if(cad.length()==3){
        matches.push_back("A-");
        matches.push_back("B-");
        matches.push_back("A+");
        matches.push_back("B+");
      }
    }
  }
  return matches;
}
/*la función in_datos() lee la cadena que se le ingrese y la separa por sus respectivas palabras, 
por lo que los espacios quedan eliminados y cada dato es guardado en un arreglo en el cuál
se utiliza para poder insertar en la estructura los pacientes que ya exisitian en el archivo .txt*/
Datos in_datos(string str, Datos x){
    string arr [11];
    int i = 0;
    istringstream ss(str);

    for(int i = 0; i < 11; i++){
        string word;
        ss >> word;

        arr[i] = word;
    }
    x.insertar(arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], stod(arr[10]));
    return x;
}

/*La función mayusculas() resive una cadena de string y la retorna en mayusculas*/
string mayusculas(string cadena){
    int size = cadena.size();
    for(int i=0; i< size; i++)
        cadena[i] = toupper(cadena[i]);
    return cadena;
}


int main(){

    Datos x;
    string y;
/*
/*esta seccion del codigo crea los archivos de texto (cant_tipo.txt y datos.txt) donde se guardará la informacion
de los tipos de sangre y la cantidad que hay en en el banco.*/

//#################################################################################################################################################################################################################################################################################################################################################################################################################################################
// la función open() revisará si el archivo de texto existe en el area de trabajo, si no existe, creará uno.


  int fd = open("cant_tipo.txt", O_RDONLY);
  if(fd < 0){
    vector<string> TS{"O-","O+","A-","A+","B-","B+","AB-","AB+"};
    vector<int> cant{120,320,450,65,124,231,432,43};
    ofstream inss("cant_tipo.txt",ios::app);
    if(inss.good()){
      for(int i=0;i<TS.size();++i){
        inss<<TS[i]<<" "<<cant[i]<<'\n';
      }
    }
    inss.close();
  }

  int fd1 = open("datos.txt", O_RDONLY);
  if(fd1 < 0){
      ofstream in("datos.txt",ios::app);
      in << setw(15) <<left << "ID" << setw(15) << left << "identificacion" << setw(15) << left <<   "Nombre1" << setw(15) << left << "Nombre2" << setw(15) << left << "Apellido1" << setw(15) << left << "Apellido2" << setw(15) << left << "Nacimiento" << setw(15) << left << "Telefono" << setw(15) << left << "Sexo"<< setw(15) << left <<  "RH" <<   "Distancia" <<  '\n';
      in<<"==============================================================================================================================================================="<<'\n';
      in.close();
  }
//#################################################################################################################################################################################################################################################################################################################################################################################################################################################
// Antes del menú, se introduce la información en el archivo .txt a la estructura que guarda la información del donante.
  
    ifstream out("datos.txt");
    int i = 0;
    getline(out, y);
    getline(out, y);


    //Se utiliza este while porque estaba sucediendo un error al llegar a la ultima linea del archivo dado que era una linea que no tenia contenido, entonces lo que hace al llegar a la ultima linea es salir del while y antes de eso emplea la función para insertar los datos que estaban en el archivo.
    do{
        getline(out, y);
        if(out.eof())
            break;
        else
            x = in_datos(y, x);
    }while(out.good());
    out.close();

 //Comienza el menú
    int g;
    bool t=true;
    while(t){
      cout<<"============================================="<<'\n';
      cout << "Introduzca 1 para editar la base de datos" << "\n2 Si necesita sangre" <<"\n3 Para ver los donantes existentes" <<"\n4 Para salir"<<'\n';
      cin >> g;
      if(g == 1){
        int g2;
        bool t2=true;
        while(t2){
          cout<<"================================================="<<'\n';
          cout<<"Introduzca 1 si quiere agregar una persona"<<"\n2 si desea corregir algun dato"<<'\n';
          cin>>g2;

          //Se inserta un paciente a la estructura y luego se actualiza a la base de datos (datos.txt).
          if(g2 == 1){
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

              cout << "Introduzca el numero de identificacion: ";
              cin >> ident;

              cout << "Introduzca el primer nombre: ";
              cin >> nom1;

              cout << "Introduzca el segundo nombre (NA en caso de no tener): ";
              cin >> nom2;

              cout << "Introduzca el primer apellido: ";
              cin >> apellido1;

              cout << "Introduzca el segundo apellido (NA en caso de no tener): ";
              cin >> apellido2;

              cout << "Introduzca la fecha de nacimiento (ej: 17/06/1999): ";
              cin >> nacimiento;

              cout << "Introduzca su numero de telefono o celular: ";
              cin >> telefono;

              cout << "Introduzca el sexo (F o M): ";
              cin >> sexo;

              cout << "Introduzca el tipo de sangre (ej: A+): ";
              cin >> rh;

              cout << "Introduzca la distancia promedio en kilometros de su casa al hospital (ej: 6): ";
              cin >> dist;

              //Si la identidad ya existe, entonces no se ingresa 
              int id = 0;
              for(int i = 1; i < x.tamano(); i++){
                if(ident == x.get_ident(i))
                  id = i;
              }

              
              
              if(id == 0){
                ofstream in("datos.txt",ios::app);
                if(in.good()){
                x.insertar(ident, nom1, nom2, apellido1, apellido2, nacimiento, telefono, sexo, rh, dist);
                }
                if(in.good()){
                    in<<setw(15) << left << x.tamano() << setw(15) << left << x.get_ident(x.tamano()) << setw(15) << left << x.get_nom1(x.tamano()) << setw(15) << left << x.get_nom2(x.tamano()) << setw(15) << left << x.get_apel1(x.tamano()) << setw(15) << left << x.get_apel2(x.tamano()) << setw(15) << left << x.get_nac(x.tamano()) << setw(15) << left <<x.get_tel(x.tamano()) << setw(15) << left << x.get_sexo(x.tamano()) << setw(15) << left << x.get_rh(x.tamano())  << x.get_dist(x.tamano()) << "\n";
                }
                in.close();
              

              //Al ingresar un  paciente, toma su RH y aumenta el inventario de ese RH en 1
                HashBlood bodega;
                vector<string> intr;
                ifstream in1("cant_tipo.txt");
                string line="";
                if(in1.good()){
                  while(!in1.eof()){
                    getline(in1,line);
                    intr.push_back(line);
                  }
                }
                in1.close();
                for(int i=0;i<intr.size()-1;i++){
                  vector<string> save=split(intr[i]," ");
                  bodega.insert(save[0],stoi(save[1]), 1);
                }
                bodega.insert(x.get_rh(x.tamano()), 1, 0);

                /*Modifica el archivo de texto con los cambios*/
                ofstream of("cant_tipo.txt",ios::trunc);
                if(of.good()){
                  for(int i=0;i<8;++i){
                    of<<bodega.info(i)<<'\n';
                  }
                }
                of.close();

              //Si la identidad existe, unicamente aumentará los inventarios del rh que se registro con la identidad existente
              }else{
                HashBlood bodega;
                vector<string> intr;
                ifstream in1("cant_tipo.txt");
                string line="";
                if(in1.good()){
                  while(!in1.eof()){
                    getline(in1,line);
                    intr.push_back(line);
                  }
                }
                in1.close();
                for(int i=0;i<intr.size()-1;i++){
                  vector<string> save=split(intr[i]," ");
                  bodega.insert(save[0],stoi(save[1]), 1);
                }
                bodega.insert(x.get_rh(id), 1, 0);

                /*Modifica el archivo de texto con los cambios*/
                ofstream of("cant_tipo.txt",ios::trunc);
                if(of.good()){
                  for(int i=0;i<8;++i){
                    of<<bodega.info(i)<<'\n';
                  }
                }
                of.close();
              }
          }

          if(g2 == 2){
            /*Al ingresar en esta parte, se podrá modificar los datos de las personas, por si hubo algún error al digitar la informacíon. Tambien se actualiza en la base de datos.*/
            int count;
            int p;
            string val;
            cout << "1->Identificacion\n2->Nombre1\n3->Nombre2\n4->Apellido1\n5->Apellido2\n6->Nacimiento\n7->telefono\n8->sexo\n9->RH\n10->Distancia\n";
            cin >> count;
            if(count == 1){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_ident(p, val);
              
            }else if(count == 2){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_nom1(p, val);
              
            }else if(count == 3){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_nom2(p, val);

            }else if(count == 4){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_apel1(p, val);

            }else if(count == 5){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_apel2(p, val);
                
            }else if(count == 6){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_nac(p, val);

            }else if(count == 7){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_tel(p, val);

            }else if(count == 8){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_sexo(p, val);

            }else if(count == 9){
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> val;
              x.set_rh(p, val);

            }else if(count == 10){
              double dist;
              cout << "Indique la ID que desea cambiar: ";
              cin >> p;
              cout << "Escriba la información que reemplazará el dato: ";
              cin >> dist;
              x.set_dist(p, dist);
              }

             /* Cada vez que entre a este if, el archvio de texto debe modificarse, pues es la base de datos. El codigo que esta debajo de este comentario crea un archivo temporal para poder hacer la copia y modificar el archivo con los cambios realizados*/

            ifstream fs("datos.txt");
            ofstream fstemp("datostemp.txt");

            string line;

            getline(fs, line);
            fstemp << line << endl;
            getline(fs, line);
            fstemp << line << endl;

            if(x.tamano() != 0){
                for(int i =1; i <= x.tamano(); i++){
                    if(fstemp.good()){
                        fstemp << setw(15) << left << i << setw(15) << left << x.get_ident(i) << setw(15) << left << x.get_nom1(i) << setw(15) << left << x.get_nom2(i) << setw(15) << left << x.get_apel1(i) << setw(15) << left << x.get_apel2(i) << setw(15) << left << x.get_nac(i) << setw(15) << left <<x.get_tel(i) << setw(15) << left << x.get_sexo(i) << setw(15) << left << x.get_rh(i)  << x.get_dist(i) << "\n";
                    }
                }
            }
            fs.close();
            fstemp.close();
            remove("datos.txt");
            rename("datostemp.txt", "datos.txt");
          }
          string gg;
          cout<<"==================================="<<'\n';
          cout<<"Quiere seguir editando? (si o no):";
          cin>>gg;
          if(gg=="no") t2=false;
        }
      }
      if(g==2){
        HashBlood bodega;
        vector<string> intr;
        ifstream in1("cant_tipo.txt");
        string line="";
        if(in1.good()){
          while(!in1.eof()){
            getline(in1,line);
            intr.push_back(line);
          }
        }
        in1.close();
        for(int i=0;i<intr.size()-1;i++){
          vector<string> save=split(intr[i]," ");
          bodega.insert(save[0],stoi(save[1]), 1);
        }
        string g3;
        bool t3=true;
        while(t3){
          string info="";
          cout<<"========================================"<<'\n';
          cout<<"Escriba el tipo de sangre del paciente: ";
          cin>>info;
          vector<string> matchh=match(info);
          cout<<"Estos son los tipos de sangre de los que puede recibir el paciente y lo que hay"<<'\n';
          bodega.search(matchh);
          string info2="";
          cout<<"Escriba cual elige y cuanto necesita (separados por ','): ";
          cin>>info2;
          vector<string> ll=split(info2,",");
          if(stoi(ll[1])>bodega.get_blood(ll[0])){
            cout<<"Lo siento! pero hacen falta "<<stoi(ll[1])-bodega.get_blood(ll[0])<<" litros por entregar"<<'\n';
            bodega.insert(ll[0],0, 1);
            cout<<"PILAS!!! se acaba la sangre de tipo "<<ll[0]<<" estas personas podrian donar, contactese"<<'\n';
            x.busqueda(mayusculas(ll[0]));
          }
          else{
            int dif=bodega.get_blood(ll[0])-stoi(ll[1]);
            if(dif<=20){
              cout<<"PILAS!!! Se acaba la sangre de tipo "<<ll[0]<<" estas personas podrian donar, contactese"<<'\n';
              x.busqueda(mayusculas(ll[0]));
            }
            bodega.insert(ll[0],dif,1);
          }
          //se escribe en el archivo de texto para actulizar los valores de cantidad de sangre
          ofstream of("cant_tipo.txt",ios::trunc);
          if(of.good()){
            for(int i=0;i<8;++i){
              of<<bodega.info(i)<<'\n';
            }
          }
          of.close();
          cout<<"Listo, ya puede reclamar la sangre!!!!"<<'\n';
          string ans2="";
          cout<<"=============================="<<'\n';
          cout<<"Desea mas sangre? (si o no): ";
          cin>>ans2;
          if(ans2=="no") t3=false;
        }
      }
      if(g==3){
        bool t=true;
        while(t){
          x.ver_pacientes();
          string ans1="";
          cout<<"=============================="<<'\n';
          cout<<"Para salir introduzca 3: ";
          cin>>ans1;
          if(ans1 == "3") t = false;
        }
      }

      if(g==4){
        t=false;
      }
    }

    return 0;
}
