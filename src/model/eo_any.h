#ifndef _eo_any_
#define _eo_any_

#include "tags.h"

// Любой объект на C содержит необходимые данные и не более того.
// Обработка данных может вестись внешними функциями

//==============================================================================
// Объявление вспомогательного "любого" объекта,
// используемого в качестве базового типа.
// Физически объект данного типа существовать не должен
//==============================================================================

//------------------------------------------------------------------------------
struct EoAny; // предварительное объявление структуры для любого объекта

// Головная часть любого объекта.
// Выделена в отдельную сущность для единого именования во всех объектах
typedef struct EoHead {
  Tag tag;                      // уникальный признак объекта
  struct EoAny* parent;         // указатель на родительский объект
  unsigned (*eval)(struct EoAny*, struct EoAny*);   // указатель на функцию датаризации
  unsigned (*size)(void);  // указатель на функцию размера объекта
} EoHead;

//------------------------------------------------------------------------------
// "Любой" объект
typedef struct EoAny {
  EoHead  head;           // головная часть любого объекта
} EoAny;


//------------------------------------------------------------------------------
// Функции для обработки головной части любого объекта.
// Предполагается, что идентчность головных частей позволит применять их
// за счет явного и ненадежного приведения типов

// Установка признака (тега) для любого объекта
void set_tag(EoAny* obj, Tag tag);
// Получение признака объекта
Tag get_tag(EoAny* obj);

// Установка указателя на родительский объект
void set_parent(EoAny* child, EoAny* parent);
// Получение родителя объекта
EoAny* get_parent(EoAny* obj);

// Установка указателя на функцию датаризации
void set_eval(EoAny* obj, unsigned (*eval)(struct EoAny*, struct EoAny*));

// Установка указателя на функцию получения размера объекта
void set_size(EoAny* obj, unsigned (*size)(void));

// Привязка операнда-объекта к любому объекту, указанному в качестве первого
// операнда.Позволяет не плодить данную сущность для каждого вида объектов и
// подобъектов.
void bind_Eo(EoAny* objDst, EoAny* objSrc);


// Иницилизация головной части любого объекта
void init_head(EoAny* obj, Tag tag, EoAny* parent,
               unsigned (*eval)(struct EoAny*, struct EoAny*),
               unsigned  (*size)(void));

// Возрат размера объекта
unsigned size_EoAny(void);

#endif  // _eo_any_
