#include <stdio.h>
#include "tags.h"
//#include "ext_tags.h"
#include "eo_objects.h"
#include "poly.h"
#include "fibonacci.h"

eoInt int_obj;
eoDouble double_obj;

int main() {
  eoAny* tmpAny = NULL;
  // Непосредственная датаризация объектов

  init_eoInt (&int_obj, NULL, 10);
  get_eoInt((eoAny*)&int_obj, tmpAny);
  get_eoIntAsString((eoAny*)&int_obj, tmpAny);

  init_eoDouble (&double_obj, 100.10);
  get_eoDouble((eoAny*)&double_obj, tmpAny);
  get_eoDoubleAsString((eoAny*)&double_obj, tmpAny);

  // Прямой анализ и выбор функции, связанной с конкретным объектом
  printf("\n--- Direct analysis ---\n");

  eoAny* a1 = (eoAny*)&int_obj;
  if (a1->tag == tagInt) {
    get_eoInt(a1, tmpAny);
    get_eoIntAsString(a1, tmpAny);
  } else if (a1->tag == tagDouble) {
    get_eoDouble(a1, tmpAny);
    get_eoDoubleAsString(a1, tmpAny);
  } else { printf("Error! Tag = %d\n", a1->tag); }

  a1 = (eoAny*)&double_obj;
  if (a1->tag == tagInt) {
    get_eoInt(a1, tmpAny);
    get_eoIntAsString(a1, tmpAny);
  } else if (a1->tag == tagDouble) {
    get_eoDouble(a1, tmpAny);
    get_eoDoubleAsString(a1, tmpAny);
  } else { printf("Error! Tag = %d\n", a1->tag); }

  // Использование полиморфных (обобщенных) функций,
  // проверяющих подставляемые объекты
  printf("\n--- Polymorphic analysis ---\n");

  get_eoAny((eoAny*)&int_obj, tmpAny);
  get_eoAny((eoAny*)&double_obj, tmpAny);

  get_eoAnyAsString((eoAny*)&int_obj, tmpAny);
  get_eoAnyAsString((eoAny*)&double_obj, tmpAny);

  // Проверка сложения
  printf("\n--- Int addition test ---\n");

  eoInt int_obj2;
  init_eoInt(&int_obj2, NULL, 101);
  init_eoIntAdd(&int_obj, &int_obj2);
  eoInt add_result;
  get_eoIntAdd((eoAny*)&int_obj, (eoAny*)&add_result);
  get_eoInt((eoAny*)&add_result, tmpAny);
  get_eoIntAsString((eoAny*)&add_result, tmpAny);

  // Проверка вычитания
  printf("\n--- Int subtract test ---\n");

  init_eoIntSub(&int_obj, &int_obj2);
  eoInt sub_result;
  get_eoIntSub((eoAny*)&int_obj, (eoAny*)&sub_result);
  get_eoInt((eoAny*)&sub_result, tmpAny);
  get_eoIntAsString((eoAny*)&sub_result, tmpAny);

  // Проверка сравнения eq
  printf("\n--- Int eq test ---\n");

  init_eoIntEq(&int_obj, &int_obj2);
  eoInt eq_result;
  get_eoIntEq((eoAny*)&int_obj, (eoAny*)&eq_result);
  get_eoInt((eoAny*)&eq_result, tmpAny);
  get_eoIntAsString((eoAny*)&eq_result, tmpAny);

  init_eoIntEq(&int_obj, &int_obj);
  get_eoIntEq((eoAny*)&int_obj, (eoAny*)&eq_result);
  get_eoInt((eoAny*)&eq_result, tmpAny);
  get_eoIntAsString((eoAny*)&eq_result, tmpAny);

  // Проверка сравнения less
  printf("\n--- Int less test ---\n");

  init_eoIntLess(&int_obj, &int_obj2);
  eoInt less_result;
  get_eoIntLess((eoAny*)&int_obj, (eoAny*)&less_result);
  get_eoInt((eoAny*)&less_result, tmpAny);
  get_eoIntAsString((eoAny*)&less_result, tmpAny);

  init_eoIntLess(&int_obj2, &int_obj);
  get_eoIntLess((eoAny*)&int_obj2, (eoAny*)&less_result);
  get_eoInt((eoAny*)&less_result, tmpAny);
  get_eoIntAsString((eoAny*)&less_result, tmpAny);

  // Проверка вычисления функции Фибоначчи
  printf("\n--- Fibonacci test ---\n");

  eoInt fiboResult;
  init_eoInt(&fiboResult, NULL, 0);
  Fibonacci fibo;
  eoInt n;

  init_eoInt(&n, NULL, 1);  // 0
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 2);  // 1
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 3);  // 2
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 4);  // 3
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 5);  // 5
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 6);  // 6
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  init_eoInt(&n, NULL, 10);  // 10
  init_Fibonacci(&fibo, NULL, &n);
  get_Fibonacci((eoAny*)&fibo, (eoAny*)&fiboResult);
  get_eoInt((eoAny*)&fiboResult, tmpAny);
  get_eoIntAsString((eoAny*)&fiboResult, tmpAny);

  return 0;
}
