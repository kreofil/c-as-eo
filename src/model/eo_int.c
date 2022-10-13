#include <stdio.h>
#include "eo_int.h"

//==============================================================================
// Инициализация существующего целочисленного объекта
void init_EoInt(EoInt* obj, EoAny* parent, int value) {
  obj->value = value;
  init_head((EoAny*)obj, tagInt, parent, eval_EoInt); // EoInt
  init_head((EoAny*)(&obj->asString), tagIntAsString,
            (EoAny*)obj, eval_EoIntAsString);
  init_head((EoAny*)(&obj->add), tagIntAdd, (EoAny*)obj, eval_EoIntAdd);
  init_head((EoAny*)(&obj->sub), tagIntSub, (EoAny*)obj, eval_EoIntSub);
  init_head((EoAny*)(&obj->eq), tagIntEq, (EoAny*)obj, eval_EoIntEq);
  init_head((EoAny*)(&obj->less), tagIntLess, (EoAny*)obj, eval_EoIntLess);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Установка значения в целочисленном объекте
void set_EoInt_value(EoInt* obj, int value) {
  obj->value = value;
}

// Привязка второго операнда подобъекта add
void bind_EoIntAdd(EoInt* obj, EoInt* opd2) {
  obj->add.opd2 = opd2;
}

// Привязка второго операнда подобъекта sub
void bind_EoIntSub(EoInt* obj, EoInt* opd2) {
  obj->sub.opd2 = opd2;
}

// Привязка второго операнда eq
void bind_EoIntEq(EoInt* obj, EoInt* opd2) {
  obj->eq.opd2 = opd2;
}

// Привязка второго операнда less
void bind_EoIntLess(EoInt* obj, EoInt* opd2) {
  obj->less.opd2 = opd2;
}

//------------------------------------------------------------------------------
// Получение (датаризация) целочисленного объекта
int eval_EoInt(EoAny* obj, EoAny* result) {
  // Тестовый вывод информации о целочисленном объекте
  printf("EoInt = %d\n", ((EoInt*)obj)->value);
  // Непосредственное отображение целочисленного объекта
  // Или должно быть клонирование?
  result = obj;
  return sizeof(*(EoInt*)result);
}

// Получение (датаризация) строки для целочисленного объекта
int eval_EoIntAsString(EoAny* obj, EoAny* result) {
  sprintf(((EoInt*)obj)->asString.str, "%d", ((EoInt*)obj)->value);
  // Тестовый вывод информации о преобразованной строке
  printf("EoInt.asString = %s\n", ((EoInt*)obj)->asString.str);
  // Преобразование в строку пока не отработано как надо
  // result должент быть строковым объектом
  result = obj;   // Просто заглушка
  return sizeof(*(EoInt*)result);
}

// Сложение целочисленного объекта с объектом, привязанным к add
int eval_EoIntAdd(EoAny* obj, EoAny* result) {
  ((EoInt*)result)->value =
  ((EoInt*)obj)->value + ((EoInt*)obj)->add.opd2->value;
  return sizeof(*(EoInt*)result);
}

// Вычитание из целочисленного объекта объекта, привязанного к sub
int eval_EoIntSub(EoAny* obj, EoAny* result) {
  ((EoInt*)result)->value =
  ((EoInt*)obj)->value - ((EoInt*)obj)->sub.opd2->value;
  return sizeof(*(EoInt*)result);
}

// Сравнение eq
int eval_EoIntEq(EoAny* obj, EoAny* result) {
  ((EoInt*)result)->value =
  ((EoInt*)obj)->value == ((EoInt*)obj)->eq.opd2->value;
  return sizeof(*(EoInt*)result);
}

// Сравнение less
int eval_EoIntLess(EoAny* obj, EoAny* result) {
  ((EoInt*)result)->value =
  ((EoInt*)obj)->value < ((EoInt*)obj)->less.opd2->value;
  return sizeof(*(EoInt*)result);
}

