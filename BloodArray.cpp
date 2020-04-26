#include "BloodArray.hpp"

/*el constructor de la clase BloodArray genera un arreglo con 8 celdas( uno por
 cada tipo de sangre) y el contador en 0*/
BloodArray::BloodArray(){
  array=new BloodCell[8];
  count=0;
}

//el destructor que elimina el arreglo completamente
BloodArray::~BloodArray(){
  delete[] array;
}

/* el metodo get_blood() recibe un string que es el tipo de sangre y retorna un
 entero que es la cantidad de sangre que hay de ese tipo*/
int BloodArray::get_blood(string T){
  int k=find_type(T);
  return array[k].cant;
}

/* el metodo find_type() recibe un tipo de sangre y retorna el indice del arreglo
 donde esta guardado la celda que contiene ese tipo de sangre*/
int BloodArray::find_type(string T){
  for (int i=0;i<8;++i){
    if(array[i].type==T)
      return i;
  }
  return -1;
}

/* el metodo insert_data() recibe el tipo de sangre y la cantidad de sangre
 si el arreglo esta vacio se inserta la informacion en una nueva celda pero
si el arreglo esta lleno, se actualiza solo el valor de cantidad de sangre.*/
void BloodArray::insert_data(string T,int C){
  if(count==8){
    int ind=find_type(T);
    array[ind].cant=C;
  }
  else{
    array[count].type=T;
    array[count].cant=C;
    count+=1;
  }
}

/*el metodo search() recibe un vector que contiene string que son los tipos de sangre
e imprime en la consola el tipo de sangre (ingresado en el vector) y la cantidad
del respectivo tipo.*/
void BloodArray::search(vector<string> V){
  for(int i=0;i<V.size();++i){
    int k=find_type(V[i]);
    cout<<array[k].type<<" "<<array[k].cant<<'\n';
  }
}

/*el metodo info() recibe el indice del arreglo creado y retorna un vector de string
 de dos elementos, el primero es el tipo de sangre y el segundo es el tipo de sangre
del elemento que esta en la i-ésima posicion del arreglo.*/
vector<string> BloodArray::info(int i){
  vector<string> res{array[i].type,to_string(array[i].cant)};
  return res;
}
