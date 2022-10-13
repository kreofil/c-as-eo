#include <stdio.h>
#include "eo_double.h"

//==============================================================================
// Инициализация существующего действительного объекта двойной точности
void init_EoDouble(EoDouble* obj, EoAny* parent, double value) {
  obj->value = value;
  init_head((EoAny*)obj, tagDouble, parent,
            eval_EoDouble, size_EoDouble); // EoDouble
  init_head((EoAny*)(&obj->asString), tagIntAsString, (EoAny*)obj,
            eval_EoDoubleAsString, size_EoDouble);
}

// Получение (датаризация) действительного объекта двойной точности
unsigned eval_EoDouble(EoAny* obj, EoAny* result) {
  // Тестовый вывод информации о целочисленном объекте
  printf("EoDouble = %g\n", ((EoDouble*)obj)->value);
  result = obj;
  return size_EoDouble();
}

// Получение (датаризация) строки для действительного объекта двойной точности
unsigned eval_EoDoubleAsString(EoAny* obj, EoAny* result) {
  sprintf(((EoDouble*)obj)->asString.str, "%g", ((EoDouble*)obj)->value);
  // Тестовый вывод информации о преобразованной строке
  printf("EoDouble.asString = %s\n", ((EoDouble*)obj)->asString.str);
  // Преобразование в строку пока не отработано как надо
  // result должент быть строковым объектом
  result = obj;   // Просто заглушка
  return size_EoDouble();
}

// Возрат размера объекта
unsigned size_EoDouble(void) {
  return sizeof(EoDouble);
}
