#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "types.h"

struct staticArr {
  int* arr;
  int size;
};


class BaseObject {
  vec2 pos;
  vec2 size;
  void draw();
};

staticArr& get_list();

#endif
