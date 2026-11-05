typedef struct {

  int *array;
  int size;
} Dyn_Arr;

Dyn_Arr *initarr(int s);
void pusharr(Dyn_Arr *array, int ind, int val);
