// Определения обобщенных функций для всех объектов, моделирующих
// семантику EO

#include <stdio.h>
#include "ext_tags.h"
#include "eo_objects.h"

//==============================================================================
// Определение обобщенной функции get_eoAny
void get_eoAny(eoAny* obj, eoAny* result) {
  if (obj->tag == tagInt) {
      get_eoInt(obj, result);
  } else if (obj->tag == tagDouble) {
      get_eoDouble(obj, result);
  } else {
      printf("Error! Get action not defined. Incorrect tag = %d\n", obj->tag);
  }
}

//==============================================================================
// Определение обобщенной функции get_eoAnyAsString
eoAny* get_eoAnyAsString(eoAny* obj, eoAny* result) {
  if (obj->tag == tagInt) {
      get_eoIntAsString(obj, result);
  } else if (obj->tag == tagDouble) {
      get_eoDoubleAsString(obj, result);
  } else {
      printf("Error! aString not defined. Incorrect tag = %d.\n", obj->tag);
  }
}
