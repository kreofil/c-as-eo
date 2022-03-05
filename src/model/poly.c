// Определения обобщенных функций для всех объектов, моделирующих
// семантику EO

#include <stdio.h>
#include "tags.h"
//#include "ext_tags.h"
#include "eo_objects.h"

//==============================================================================
// Определение обобщенной функции get_eoAny
void get_eoAny(eoAny* obj, eoAny* result) {
  switch (obj->tag) {
    case tagInt:
      get_eoInt(obj, result);
      break;
    case tagDouble:
      get_eoDouble(obj, result);
      break;
    default:
      printf("Error! Get action not defined. Incorrect tag = %d\n", obj->tag);
  }
}

//==============================================================================
// Определение обобщенной функции get_eoAnyAsString
void get_eoAnyAsString(eoAny* obj, eoAny* result) {
  switch (obj->tag) {
    case tagInt:
      get_eoIntAsString(obj, result);
      break;
    case tagDouble:
      get_eoDoubleAsString(obj, result);
      break;
    default:
      printf("Error! aString not defined. Incorrect tag = %d.\n", obj->tag);
  }
}
