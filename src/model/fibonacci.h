#ifndef _fibonacci_
#define _fibonacci_

#include "eo_int.h"

// Вычисление числа Фибоначчи с использованием модели EO
// Пока с целыми из Си. В дальнейшем нужно поменять на объект eoInt,
// добавив в него необходимые операции обработки

/*
[n] > fibonacci
  if. > @
    n.less 3
    small n
    rec n 1 1

  [n] > small
    if. > @
      n.eq 2
      1
      n

  [n minus1 minus2] > rec
    if. > @
      n.eq 3
      minus1.add minus2
      rec (n.sub 1) (minus1.add minus2) minus1
*/

//==============================================================================
struct Fibonacci;   // Предварительное объявление внешнего объекта

//------------------------------------------------------------------------------
// Модель объекта FibonacciSmall
typedef struct FibonacciSmall {
  EoHead head;        // базовая часть для идентификации и связи объектов
  EoInt* n; // передаваемое значение
} FibonacciSmall;

// Инициализация
void init_FibonacciSmall(FibonacciSmall* obj, EoAny* parent, EoInt* n);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_FibonacciSmall(EoAny* obj, EoAny* result);

//------------------------------------------------------------------------------
// Модель объекта FibonacciRec
typedef struct FibonacciRec {
  EoHead head;        // базовая часть для идентификации и связи объектов
  EoInt* n; // передаваемое значение
  // Дополнительные атрибуты
  EoInt* minus1;
  EoInt* minus2;
} FibonacciRec;

// Инициализация
void init_FibonacciRec(FibonacciRec* obj,
                       EoAny* parent, EoInt* n, EoInt* minus1, EoInt* minus2);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_FibonacciRec(EoAny* obj, EoAny* result);

//------------------------------------------------------------------------------
// Объект, определяющий функцию Фибоначчи
typedef struct Fibonacci {
  EoHead head;        // базовая часть для идентификации и связи объектов
  int tag; // уникальный признак внешнего объекта

  EoInt* n; // передаваемое значение
  FibonacciSmall small;
  FibonacciRec rec;
} Fibonacci;

// Инициализация
void init_Fibonacci(Fibonacci* obj, EoAny* parent, EoInt* n);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
int eval_Fibonacci(EoAny* obj, EoAny* result);


#endif  // _fibonacci_
