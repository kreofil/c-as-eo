#include <stdio.h>
#include "eo_int.h"   // Временно. Пока не включил виртуализацию размера
#include "eo_seq.h"

//==============================================================================
// Инициализация, связана с передачей массива объектов и его размера
void init_EoSeq(EoSeq* obj, EoAny* parent, EoAny** objSeq, int length) {
  obj->length = length;
  obj->objSeq = objSeq;
  init_head((EoAny*)obj, tagSeq, parent,
            eval_EoSeq, size_EoAny); // EoInt
}

// Получение (датаризация) последовательности объектов
unsigned eval_EoSeq(EoAny* obj, EoAny* result) {
EoAny* tmpAny = NULL;
  for (int i = 0; i < ((EoSeq*)obj)->length; ++i) {
    ((EoSeq*)obj)->objSeq[i]->head.eval(((EoSeq*)obj)->objSeq[i], result);
  }
  // Нужно будет изменить, вставив в цикл временнцю переменну,
  // Определяющую размер результата.
  // Видимо размер нужно будет добавит еще в список виртуализации...
  return sizeof(*(EoInt*)result);
}
