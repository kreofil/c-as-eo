// Реализация функций, имитирующих объект, вычисляющий число Фибоначчи

#include <stddef.h>
#include "fibonacci.h"

//==============================================================================
// Описание всех артефактов, связанных с Fibonacci

//------------------------------------------------------------------------------
// Модель объекта FibonacciRec
/*
  [n] > small
    if. > @
      n.eq 2
      1
      n

typedef struct FibonacciSmall {
  eoInt* n; // передаваемое значение
} FibonacciSmall;
*/

// Инициализация
void init_FibonacciSmall(FibonacciSmall* obj, EoAny* parent, EoInt* n) {
  init_head((EoAny*)obj, tagFibonacci, parent, eval_FibonacciSmall);
  obj->n = n;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_FibonacciSmall(EoAny* obj, EoAny* result) {
  EoInt val_2;    // константа  = 2
  init_EoInt(&val_2, NULL, 2);
  bind_EoIntEq(((Fibonacci*)obj)->n, &val_2);
  // Получение результата сравнения n == 2
  EoInt cmp_eqResult;
  eval_EoIntEq((EoAny*)(((Fibonacci*)obj)->n), (EoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    init_EoInt((EoInt*)result, NULL, 1);
  } else {
    result = (EoAny*)((Fibonacci*)obj)->n;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Модель объекта FibonacciRec
/*
  [n minus1 minus2] > rec
    if. > @
      n.eq 3
      minus1.add minus2
      rec (n.sub 1) (minus1.add minus2) minus1

typedef struct FibonacciRec {
  eoInt* n; // передаваемое значение
  // Дополнительные атрибуты
  eoInt* minus1;
  eoInt* minus2;
} FibonacciRec;
*/

// Инициализация
void init_FibonacciRec(FibonacciRec* obj,
                       EoAny* parent, EoInt* n, EoInt* minus1, EoInt* minus2)
{
  set_parent((EoAny*)obj, parent);
  ((Fibonacci*)obj)->rec.n = n;
  ((Fibonacci*)obj)->rec.minus1 = minus1;
  ((Fibonacci*)obj)->rec.minus2 = minus2;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_FibonacciRec(EoAny* obj, EoAny* result) {
  // Константа 3
  EoInt val_3;
  init_EoInt(&val_3, NULL, 3);
  bind_EoIntEq(((Fibonacci*)obj)->rec.n, &val_3);
  // Получение результата сравнения n == 3
  EoInt cmp_eqResult;
  eval_EoIntEq((EoAny*)(((Fibonacci*)obj)->rec.n), (EoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    // minus1.add minus2
    bind_EoIntAdd(((Fibonacci*)obj)->rec.minus1, ((Fibonacci*)obj)->rec.minus2);
    eval_EoIntAdd((EoAny*)((Fibonacci*)obj)->rec.minus1, result);
  } else {
    // rec (n.sub 1) (minus1.add minus2) minus1
    // Константа 1
    EoInt val_1;
    init_EoInt(&val_1, NULL, 1);
    EoInt arg1;
    bind_EoIntSub(((Fibonacci*)obj)->rec.n, &val_1);
    eval_EoIntSub((EoAny*)((Fibonacci*)obj)->rec.n, (EoAny*)&arg1);
    EoInt arg2;
    bind_EoIntAdd(((Fibonacci*)obj)->rec.minus1, (((Fibonacci*)obj)->rec.minus2));
    eval_EoIntAdd((EoAny*)((Fibonacci*)obj)->rec.minus1, (EoAny*)&arg2);
    FibonacciRec fr;
    init_FibonacciRec(&fr, NULL, &arg1, &arg2, ((Fibonacci*)obj)->rec.minus1);
    eval_FibonacciRec((EoAny*)&fr, result);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Объект, определяющий функцию Фибоначчи
/*
[n] > fibonacci
  if. > @
    n.less 3
    small n
    rec n 1 1

typedef struct Fibonacci {
  int tag; // уникальный признак внешнего объекта

  eoInt* n; // передаваемое значение
  FibonacciSmall small;
  FibonacciRec rec;
} Fibonacci;
*/

// Инициализация
void init_Fibonacci(Fibonacci* obj, EoAny* parent, EoInt* n) {
  set_parent((EoAny*)obj, NULL);
  obj->tag = tagFibonacci;
  obj->n = n;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_Fibonacci(EoAny* obj, EoAny* result) {
  // Константа 3
  EoInt val_3;
  init_EoInt(&val_3, NULL, 3);
  bind_EoIntLess(((Fibonacci*)obj)->n, &val_3);
  // Получение результата сравнения n < 3
  EoInt cmp_eqResult;
  eval_EoIntLess((EoAny*)(((Fibonacci*)obj)->n), (EoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    // small n
    init_FibonacciSmall(
      &(((Fibonacci*)obj)->small), (EoAny*)obj, ((Fibonacci*)obj)->n);
    eval_FibonacciSmall(obj, result);
  } else {
    // rec n 1 1
    // Константа 1
    EoInt val_1;
    init_EoInt(&val_1, NULL, 1);
    FibonacciRec fr;
    init_FibonacciRec(&fr, NULL, ((Fibonacci*)obj)->n, &val_1, &val_1);
    eval_FibonacciRec((EoAny*)&fr, result);
  }
}
