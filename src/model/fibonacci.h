#ifndef _fibonacci_
#define _fibonacci_

#include "ext_tags.h"
#include "eo_objects.h"

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
  eoInt* n; // передаваемое значение
} FibonacciSmall;

// Инициализация
void init_FibonacciSmall(struct Fibonacci* obj, eoInt* n);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_FibonacciSmall(eoAny* obj, eoAny* result);

//------------------------------------------------------------------------------
// Модель объекта FibonacciRec
typedef struct FibonacciRec {
  eoInt* n; // передаваемое значение
  // Дополнительные атрибуты
  eoInt* minus1;
  eoInt* minus2;
} FibonacciRec;

// Инициализация
void init_FibonacciRec(struct Fibonacci* obj, eoInt* n, eoInt* minus1, eoInt* minus2);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_FibonacciRec(eoAny* obj, eoAny* result);

//------------------------------------------------------------------------------
// Объект, определяющий функцию Фибоначчи
typedef struct Fibonacci {
  int tag; // уникальный признак внешнего объекта

  eoInt* n; // передаваемое значение
  FibonacciSmall small;
  FibonacciRec rec;
} Fibonacci;

// Инициализация
void init_Fibonacci(Fibonacci* obj, eoInt* n);
// Получение (датаризация) целочисленного объекта
// с передачей значения атрибута
void get_Fibonacci(eoAny* obj, eoAny* result);


#endif  // _fibonacci_
