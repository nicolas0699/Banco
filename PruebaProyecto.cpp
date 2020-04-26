#include <fstream>
#include "BloodArray.hpp"
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

int main(){
/*esta seccion del codigo crea el archivo de texto (cant_tipo.txt) donde se guardará la informacion
de los tipos de sangre y la cantidad que hay en en el banco, solo se debe correr una vez
despues se comenta y se corre el programa para que actualice los valores en el mismo archivo*/

/*
  vector<string> TS{"A+","B+","O+","AB+","A-","B-","O-","AB-"};
  vector<int> cant{120,320,450,65,124,231,432,43};
  ofstream in("cant_tipo.txt",ios::app);
  if(in.good()){
    for(int i=0;i<TS.size();++i){
      in<<TS[i]<<" "<<cant[i]<<'\n';
    }
  }
  in.close();
*/

//se crea el objeto de tipo BloodArray
  BloodArray bodega;
  vector<string> intr;

// se lee el archivo y se extrae la informacion para insertarla en el objeto BloodArray
  ifstream in("cant_tipo.txt");
  string line="";
  if(in.good()){
    while(!in.eof()){
      getline(in,line);
      intr.push_back(line);
    }
  }
  in.close();
//insertando la informacion en el ojeto BloodArray
  for(int i=0;i<intr.size()-1;i++){
    vector<string> save=split(intr[i]," ");
    bodega.insert_data(save[0],stoi(save[1]));
  }
//se pregunta al usuario si necesita sangre
  string ans="";
  cout<<"Necesita sangre? Responda si o no: ";
  cin>>ans;
  if(ans=="si"){
      bool t=true;
      while(t){
        string info="";
        cout<<"Escriba el tipo de sangre del paciente: ";
        cin>>info;
        vector<string> matchh=match(info);
        cout<<"estos son los tipos de sangre de los que puede recibir el paciente y lo que hay"<<'\n';
        bodega.search(matchh);
        string info2="";
        cout<<"Escriba cual elige y cuanto necesita (separados por ','): ";
        cin>>info2;
        vector<string> ll=split(info2,",");
        if(stoi(ll[1])>bodega.get_blood(ll[0])){
          cout<<"lo siento! pero hacen falta "<<stoi(ll[1])-bodega.get_blood(ll[0])<<" litros por entregar"<<'\n';
          bodega.insert_data(ll[0],0);
        }
        else{
          bodega.insert_data(ll[0],bodega.get_blood(ll[0])-stoi(ll[1]));
        }
        //se escribe en el archivo de texto para actulizar los valores de cantidad de sangre
        ofstream of("cant_tipo.txt",ios::trunc);
        if(of.good()){
          for(int i=0;i<8;++i){
            vector<string> inff=bodega.info(i);
            of<<inff[0]<<" "<<inff[1]<<'\n';
          }
        }
        of.close();
        cout<<"listo, ya puede reclamar la sangre."<<'\n';
        string ans2="";
        cout<<"desea mas sangre? ";
        cin>>ans2;
        if(ans2=="no"){
          t=false;
        }
      }
  }
  else{
    cout<<"Gracias por venir"<<'\n';
  }

  return 0;
}
