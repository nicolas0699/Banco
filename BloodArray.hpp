#ifndef _BLOODARRAY_HPP
#define _BLOODARRAY_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BloodCell{
  string type;
  int cant;
};


class BloodArray{
private:
  BloodCell *array;
  int count;

public:
  BloodArray();
  ~BloodArray();
  void insert_data(string T, int C);
  void search(vector<string> V);
  int find_type(string T);
  int get_blood(string T);
  vector<string> info(int i);
};

#endif
