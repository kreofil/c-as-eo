#ifndef _eo_double_
#define _eo_double_

#include "eo_any.h"

//==============================================================================
// Объявление действительного атомарного объекта двойной точности
// и вложенных в него подобъектов

// Объект, непосредственнов вложенный в eoInt
typedef struct EoDoubleAsString {
  EoHead head;        // базовая часть для идентификации и связи объектов
  char str[30];
} EoDoubleAsString;

// Тэг действительного объекта
//const int tagDouble = 2;

// Внешний атомарный действительный объект
typedef struct EoDouble {
  EoHead head;        // базовая часть для идентификации и связи объектов
  double value;
  EoDoubleAsString asString; // Объект, формирующий строку символов по значению
} EoDouble;

// Инициализация существующего действительного объекта
void init_EoDouble(EoDouble* obj, EoAny* parent, double value);

// Получение (датаризация) действительного объекта
unsigned eval_EoDouble(EoAny* obj, EoAny* result);
// Получение (датаризация) строки для действительного объекта
unsigned eval_EoDoubleAsString(EoAny* obj, EoAny* result);

// Возрат размера объекта
unsigned size_EoDouble(void);

#endif  // _eo_double_
