#include "vector.h"
#include <string.h>


void vector_init(vector_t *v, size_t data_size)
{
    v->first = NULL;
    v->data_size = data_size;
    v->count = 0;
    v->busy = FALSE;
}


BOOL vector_push(vector_t *v, void * data)
{
  vector_item_t * item;
  size_t alloc_size;

  alloc_size = sizeof(vector_item_t) + v->data_size;

  if (v->first) {
     item = v->first;
     while (item->next) {
       item = item->next;
     }
     item->next = (vector_item_t  *)malloc(alloc_size);
     item = item->next;
  }
  else {
     v->first = (vector_item_t  *)malloc(alloc_size);
     item = v->first;
  }

  if (!item)  return FALSE;

  memcpy(item->data, data, v->data_size);
  item->next = NULL;
  v->count++;

  return TRUE;
}


size_t vector_count(vector_t *v)
{
   return v->count;
}

void * vector_get_at(vector_t *v, size_t index)
{
  size_t i;
  vector_item_t * item;


  item = v->first;
  i = 0;
  while (item) {
     if (i == index) return item->data;
     i++;
     item = item->next;
  }

  return NULL;
}

BOOL vector_set_at(vector_t *v, size_t index, void * data)
{
  size_t i;
  vector_item_t * item;


  item = v->first;
  i = 0;
  while (item) {
     if (i == index) {
       memcpy(item->data, data, v->data_size);
       return TRUE;
     }
     i++;
     item = item->next;
  }

  return FALSE;
}


void vector_free(vector_t *v)
{
  vector_item_t * item, * next;

  item = v->first;
  while (item) {
     next = item->next;
     free(item);
     item = next;
  }
  v->first = NULL;
  v->count = 0;
}


BOOL vector_pop(vector_t *v, void * data)
{
  vector_item_t * item;

  if (!v->first) return FALSE;

  memcpy(data, v->first->data, v->data_size);
  item = v->first->next;
  free(v->first);
  v->first = item;
  v->count--;
  return TRUE;
}

BOOL vector_delete_at(vector_t *v, size_t index)
{
  size_t i;
  vector_item_t * item, * next, * prev;

  if (!v->first) return FALSE;

  item = v->first;
  prev = NULL;
  i = 0;
  while (item) {
     if (i == index) {
       next = item->next;
       free(item);
       if (prev) prev->next = next;
       else v->first = next;
       v->count--;
       return TRUE;
     }
     i++;
     prev = item;
     item = item->next;
  }

  return FALSE;

}
