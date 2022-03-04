// Реализация функций, имитирующих объект, вычисляющий число Фибоначчи

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
void init_FibonacciSmall(struct Fibonacci* obj, eoInt* n) {
  obj->n = n;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_FibonacciSmall(eoAny* obj, eoAny* result) {
  // Константа 2
  eoInt val_2;
  init_eoInt(&val_2, 2);
  init_eoIntEq(((Fibonacci*)obj)->n, &val_2);
  // Получение результата сравнения n == 2
  eoInt cmp_eqResult;
  get_eoIntEq((eoAny*)(((Fibonacci*)obj)->n), (eoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    init_eoInt((eoInt*)result, 1);
  } else {
    result = (eoAny*)((Fibonacci*)obj)->n;
  }
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
void init_FibonacciRec(struct Fibonacci* obj, eoInt* n, eoInt* minus1, eoInt* minus2) {
  ((Fibonacci*)obj)->rec.n = n;
  ((Fibonacci*)obj)->rec.minus1 = minus1;
  ((Fibonacci*)obj)->rec.minus2 = minus2;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_FibonacciRec(eoAny* obj, eoAny* result) {
  // Константа 3
  eoInt val_3;
  init_eoInt(&val_3, 3);
  init_eoIntEq(((Fibonacci*)obj)->rec.n, &val_3);
  // Получение результата сравнения n == 3
  eoInt cmp_eqResult;
  get_eoIntEq((eoAny*)(((Fibonacci*)obj)->rec.n), (eoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    // minus1.add minus2
    init_eoIntAdd(((Fibonacci*)obj)->rec.minus1, ((Fibonacci*)obj)->rec.minus2);
    get_eoIntAdd((eoAny*)((Fibonacci*)obj)->rec.minus1, result);
  } else {
    // rec (n.sub 1) (minus1.add minus2) minus1
    // Константа 1
    eoInt val_1;
    init_eoInt(&val_1, 1);
    eoInt arg1;
    init_eoIntSub(((Fibonacci*)obj)->rec.n, &val_1);
    get_eoIntSub((eoAny*)((Fibonacci*)obj)->rec.n, (eoAny*)&arg1);
    eoInt arg2;
    init_eoIntAdd(((Fibonacci*)obj)->rec.minus1, (((Fibonacci*)obj)->rec.minus2));
    get_eoIntAdd((eoAny*)((Fibonacci*)obj)->rec.minus1, (eoAny*)&arg2);
    Fibonacci fib;
    init_FibonacciRec(&fib, &arg1, &arg2, ((Fibonacci*)obj)->rec.minus1);
    get_FibonacciRec((eoAny*)&fib, result);
  }
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
void init_Fibonacci(Fibonacci* obj, eoInt* n) {
  obj->tag = tagFibonacci;
  obj->n = n;
}

// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_Fibonacci(eoAny* obj, eoAny* result) {
  // Константа 3
  eoInt val_3;
  init_eoInt(&val_3, 3);
  init_eoIntLess(((Fibonacci*)obj)->n, &val_3);
  // Получение результата сравнения n < 3
  eoInt cmp_eqResult;
  get_eoIntLess((eoAny*)(((Fibonacci*)obj)->n), (eoAny*)&cmp_eqResult);
  // выбор последовательности обработки по условию
  // с использованием обычного if вместо объекта
  // Это наиболее простая и прямая реализация.
  if(cmp_eqResult.value) {
    // small n
    init_FibonacciSmall((Fibonacci*)obj, ((Fibonacci*)obj)->n);
    get_FibonacciSmall(obj, result);
  } else {
    // rec n 1 1
    // Константа 1
    eoInt val_1;
    init_eoInt(&val_1, 1);
    Fibonacci fib;
    init_FibonacciRec(&fib, ((Fibonacci*)obj)->n, &val_1, &val_1);
    get_FibonacciRec((eoAny*)&fib, result);
  }
}
