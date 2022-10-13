#include <stdio.h>
#include "eo_int.h"
#include "eo_double.h"
#include "fibonacci.h"

EoInt int_obj;
EoDouble double_obj;

int main() {
  EoAny* tmpAny = NULL;
  // Непосредственная датаризация объектов

  init_EoInt (&int_obj, NULL, 10);
  eval_EoInt((EoAny*)&int_obj, tmpAny);
  eval_EoIntAsString((EoAny*)&int_obj, tmpAny);

  init_EoDouble (&double_obj, NULL, 100.10);
  eval_EoDouble((EoAny*)&double_obj, tmpAny);
  eval_EoDoubleAsString((EoAny*)&double_obj, tmpAny);

  // Прямой анализ и выбор функции, связанной с конкретным объектом
  printf("\n--- Direct analysis ---\n");

  EoAny* a1 = (EoAny*)&int_obj;
  if (a1->head.tag == tagInt) {
    eval_EoInt(a1, tmpAny);
    eval_EoIntAsString(a1, tmpAny);
  } else if (a1->head.tag == tagDouble) {
    eval_EoDouble(a1, tmpAny);
    eval_EoDoubleAsString(a1, tmpAny);
  } else { printf("Error! Tag = %d\n", a1->head.tag); }

  a1 = (EoAny*)&double_obj;
  if (a1->head.tag == tagInt) {
    eval_EoInt(a1, tmpAny);
    eval_EoIntAsString(a1, tmpAny);
  } else if (a1->head.tag == tagDouble) {
    eval_EoDouble(a1, tmpAny);
    eval_EoDoubleAsString(a1, tmpAny);
  } else { printf("Error! Tag = %d\n", a1->head.tag); }

  // Использование полиморфных (обобщенных) функций,
  // проверяющих подставляемые объекты
  printf("\n--- Polymorphic analysis ---\n");

  eval_EoInt((EoAny*)&int_obj, tmpAny);
  eval_EoDouble((EoAny*)&double_obj, tmpAny);

  eval_EoIntAsString((EoAny*)&int_obj, tmpAny);
  eval_EoIntAsString((EoAny*)&double_obj, tmpAny);

  // Проверка сложения
  printf("\n--- Int addition test ---\n");

  EoInt int_obj2;
  init_EoInt(&int_obj2, NULL, 101);
  bind_EoIntAdd(&int_obj, &int_obj2);
  EoInt add_result;
  eval_EoIntAdd((EoAny*)&int_obj, (EoAny*)&add_result);
  eval_EoInt((EoAny*)&add_result, tmpAny);
  eval_EoIntAsString((EoAny*)&add_result, tmpAny);

  // Проверка вычитания
  printf("\n--- Int subtract test ---\n");

  bind_EoIntSub(&int_obj, &int_obj2);
  EoInt sub_result;
  eval_EoIntSub((EoAny*)&int_obj, (EoAny*)&sub_result);
  eval_EoInt((EoAny*)&sub_result, tmpAny);
  eval_EoIntAsString((EoAny*)&sub_result, tmpAny);

  // Проверка сравнения eq
  printf("\n--- Int eq test ---\n");

  bind_EoIntEq(&int_obj, &int_obj2);
  EoInt eq_result;
  eval_EoIntEq((EoAny*)&int_obj, (EoAny*)&eq_result);
  eval_EoInt((EoAny*)&eq_result, tmpAny);
  eval_EoIntAsString((EoAny*)&eq_result, tmpAny);

  bind_EoIntEq(&int_obj, &int_obj);
  eval_EoIntEq((EoAny*)&int_obj, (EoAny*)&eq_result);
  eval_EoInt((EoAny*)&eq_result, tmpAny);
  eval_EoIntAsString((EoAny*)&eq_result, tmpAny);

  // Проверка сравнения less
  printf("\n--- Int less test ---\n");

  bind_EoIntLess(&int_obj, &int_obj2);
  EoInt less_result;
  eval_EoIntLess((EoAny*)&int_obj, (EoAny*)&less_result);
  eval_EoInt((EoAny*)&less_result, tmpAny);
  eval_EoIntAsString((EoAny*)&less_result, tmpAny);

  bind_EoIntLess(&int_obj2, &int_obj);
  eval_EoIntLess((EoAny*)&int_obj2, (EoAny*)&less_result);
  eval_EoInt((EoAny*)&less_result, tmpAny);
  eval_EoIntAsString((EoAny*)&less_result, tmpAny);

  // Проверка вычисления функции Фибоначчи
  printf("\n--- Fibonacci test ---\n");

  EoInt fiboResult;
  init_EoInt(&fiboResult, NULL, 0);
  Fibonacci fibo;
  EoInt n;

  init_EoInt(&n, NULL, 1);  // 0
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 2);  // 1
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 3);  // 2
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 4);  // 3
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 5);  // 5
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 6);  // 6
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  init_EoInt(&n, NULL, 10);  // 10
  init_Fibonacci(&fibo, NULL, &n);
  eval_Fibonacci((EoAny*)&fibo, (EoAny*)&fiboResult);
  eval_EoInt((EoAny*)&fiboResult, tmpAny);
  eval_EoIntAsString((EoAny*)&fiboResult, tmpAny);

  return 0;
}
