#ifndef _HASHBLOOD_HPP
#define _HASHBLOOD_HPP

#include<iostream>
#include <string>
#include <vector>
using namespace std;

struct BNode{
  string Btype;
  int cant;
  BNode *next;
};


class HashBlood{
private:
  BNode **table;
  int table_size;
  int count;

  int hash_blood(string key);
  BNode* search_bucket(int i,string key);

public:
  HashBlood();
  ~HashBlood();
  void clear();
  int size();
  bool empty();
  void insert(string key,int value);
  int get_blood(string key);
  void search(vector<string> V);
  string info(int i);
};

#endif
