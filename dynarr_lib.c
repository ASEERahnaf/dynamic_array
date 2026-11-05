#include "dynarr_lib.h"
#include <stdlib.h>
Dyn_Arr *initarr(int s) {

  Dyn_Arr *dyn_arr = malloc(sizeof(Dyn_Arr));
  dyn_arr->size = s;
  dyn_arr->array = malloc(sizeof(int) * s);
  return dyn_arr;
}

void pusharr(Dyn_Arr *array, int ind, int val) {

  int elem = array->size;
  int eind = ind + 1;
  int off = eind - elem;
  if (eind <= elem) {
    array->array[ind] = val;
  } else {
    int new_elem = elem + off;
    int *temp = realloc(array->array, new_elem * sizeof(int));
    array->array = temp;
    array->size = new_elem;
    for (int i = elem; i < eind; i++) {
      array->array[i] = 0;
    }
    array->array[ind] = val;
  }
}
