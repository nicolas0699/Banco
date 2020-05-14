#include "HashBlood.hpp"


HashBlood::HashBlood(){
  table_size=8;
  table= new BNode* [table_size];
  for(int i=0;i<table_size;++i)
    table[i]=nullptr;
  count=0;
}

HashBlood::~HashBlood() {
  clear();
  delete[] table;
}


int HashBlood::size(){
  return count;
}


bool HashBlood::empty(){
  return count==0;
}


int HashBlood::hash_blood(string key){
  int cont=0;
  if(key.at(key.length()-1)=='+')
    cont+=1;
  for(int i=0;i<key.length()-1;++i){
    if(key.at(i)=='A')
      cont+=2;
      if(key.at(i)=='B')
        cont+=4;
  }
  return cont;
}

int HashBlood::get_blood(string key){
  int ind=hash_blood(key);
  BNode* buck=search_bucket(ind,key);
  return buck->cant;
}

void HashBlood::clear() {
  BNode *cursor;
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    while(table[i] != nullptr){
      cursor = cursor->next;
      delete table[i];
      table[i] = cursor;
    }
  }
  count = 0;
}


BNode* HashBlood::search_bucket(int i,string key){
  BNode* move=table[i];
  while(move!=nullptr){
    if(move->Btype==key){
      return move;
    }
    move=move->next;
  }
  return nullptr;
}

void HashBlood::insert(string key,int value, int tipo){
  int ind=hash_blood(key);
  BNode* selec=search_bucket(ind,key);
  if(selec==nullptr){
      BNode *neww;
      neww= new BNode;
      neww->Btype=key;
      neww->cant=value;
      neww->next=table[ind];
      table[ind]=neww;
      count +=1;
  }
  else{
    if(tipo == 0)
      selec->cant=selec->cant+value;
    else if(tipo == 1)
      selec->cant = value;
  }
}

void HashBlood::search(vector<string> V){
  vector<int> vec;
  for(int i=0;i<V.size();++i){
    int id=hash_blood(V[i]);
    BNode* BB=search_bucket(id,V[i]);
    cout<<BB->Btype<<"    "<<BB->cant<<'\n';
  }
}

string HashBlood::info(int i){
  BNode* BB=table[i];
  string res=BB->Btype+" "+to_string(BB->cant);
  return res;
}
