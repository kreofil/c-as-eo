#include <stdio.h>
#include "tags.h"
#include "eo_objects.h"
#include "poly.h"

//==============================================================================
// Инициализация существующего целочисленного объекта
void init_eoInt(eoInt* obj, int value) {
  obj->tag = tagInt;
  obj->value = value;
}

// Инициализация объекта add (привязка второго операнда)
void init_eoIntAdd(eoInt* obj, eoInt* opd2) {
  obj->add.opd2 = opd2;
}

// Инициализация объекта sub (привязка второго операнда)
void init_eoIntSub(eoInt* obj, eoInt* opd2) {
  obj->sub.opd2 = opd2;
}

// Инициализация объекта eq (привязка второго операнда)
void init_eoIntEq(eoInt* obj, eoInt* opd2) {
  obj->eq.opd2 = opd2;
}

// Инициализация объекта less (привязка второго операнда)
void init_eoIntLess(eoInt* obj, eoInt* opd2) {
  obj->less.opd2 = opd2;
}

//------------------------------------------------------------------------------
// Получение (датаризация) целочисленного объекта
void get_eoInt(eoAny* obj, eoAny* result) {
  // Тестовый вывод информации о целочисленном объекте
  printf("eoInt = %d\n", ((eoInt*)obj)->value);
  // Непосредственное отображение целочисленного объекта
  result = obj;
}

// Получение (датаризация) строки для целочисленного объекта
void get_eoIntAsString(eoAny* obj, eoAny* result) {
  sprintf(((eoInt*)obj)->asString.str, "%d", ((eoInt*)obj)->value);
  // Тестовый вывод информации о преобразованной строке
  printf("eoInt.asString = %s\n", ((eoInt*)obj)->asString.str);
  // Преобразование в строку пока не отработано как надо
  // result должент быть строковым объектом
  result = obj;   // Просто заглушка
}

// Сложение целочисленного объекта с объектом, привязанным к add
void get_eoIntAdd(eoAny* obj, eoAny* result) {
  ((eoInt*)result)->value =
    ((eoInt*)obj)->value + ((eoInt*)obj)->add.opd2->value;
}

// Вычитание из целочисленного объекта объекта, привязанного к sub
void get_eoIntSub(eoAny* obj, eoAny* result) {
  ((eoInt*)result)->value =
    ((eoInt*)obj)->value - ((eoInt*)obj)->sub.opd2->value;
}

// Сравнение eq
void get_eoIntEq(eoAny* obj, eoAny* result) {
  ((eoInt*)result)->value =
    ((eoInt*)obj)->value == ((eoInt*)obj)->eq.opd2->value;
}

// Сравнение less
void get_eoIntLess(eoAny* obj, eoAny* result) {
  ((eoInt*)result)->value =
    ((eoInt*)obj)->value < ((eoInt*)obj)->less.opd2->value;
}

//==============================================================================
// Инициализация существующего действительного объекта двойной точности
void init_eoDouble(eoDouble* obj, double value) {
  obj->tag = tagDouble;
  obj->value = value;
}

// Получение (датаризация) действительного объекта двойной точности
void get_eoDouble(eoAny* obj, eoAny* result) {
  // Тестовый вывод информации о целочисленном объекте
  printf("eoDouble = %g\n", ((eoDouble*)obj)->value);
  result = obj;
}

// Получение (датаризация) строки для действительного объекта двойной точности
void get_eoDoubleAsString(eoAny* obj, eoAny* result) {
  sprintf(((eoDouble*)obj)->asString.str, "%g", ((eoDouble*)obj)->value);
  // Тестовый вывод информации о преобразованной строке
  printf("eoDouble.asString = %s\n", ((eoDouble*)obj)->asString.str);
  result = obj;
}

//==============================================================================
// Инициализация, связана с передачей массива объектов и его размера
void init_eoSeq(eoSeq* obj, eoAny** objSeq, int length) {
  obj->length = length;
  obj->objSeq = objSeq;
}

// Получение (датаризация) последовательности объектов
void get_eoSeq(eoAny* obj, eoAny* result) {
  eoAny* tmpAny = NULL;
  for (int i = 0; i < ((eoSeq*)obj)->length; ++i) {
    get_eoAny(((eoSeq*)obj)->objSeq[i], result);
  }
}
