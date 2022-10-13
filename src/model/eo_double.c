#include <stdio.h>
#include "eo_double.h"

//==============================================================================
// Инициализация существующего действительного объекта двойной точности
void init_EoDouble(EoDouble* obj, EoAny* parent, double value) {
  obj->value = value;
  init_head((EoAny*)obj, tagDouble, parent, eval_EoDouble); // EoDouble
  init_head((EoAny*)(&obj->asString), tagIntAsString,
            (EoAny*)obj, eval_EoDoubleAsString);
}

// Получение (датаризация) действительного объекта двойной точности
int eval_EoDouble(EoAny* obj, EoAny* result) {
  // Тестовый вывод информации о целочисленном объекте
  printf("EoDouble = %g\n", ((EoDouble*)obj)->value);
  result = obj;
  return sizeof(*(EoDouble*)result);
}

// Получение (датаризация) строки для действительного объекта двойной точности
int eval_EoDoubleAsString(EoAny* obj, EoAny* result) {
  sprintf(((EoDouble*)obj)->asString.str, "%g", ((EoDouble*)obj)->value);
  // Тестовый вывод информации о преобразованной строке
  printf("EoDouble.asString = %s\n", ((EoDouble*)obj)->asString.str);
  // Преобразование в строку пока не отработано как надо
  // result должент быть строковым объектом
  result = obj;   // Просто заглушка
  return sizeof(*(EoDouble*)result);
}


