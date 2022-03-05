#ifndef _enum_tags_
#define _enum_tags_

// Задание тэгов перечислимым типом

typedef enum Tag {
  tagAny,
  tagInt,
  tagDouble,
  tagSeq,

  // Объекты, определяемые пользователем
  tagFibonacci,
} Tag;

#endif  // _enum_tags_
