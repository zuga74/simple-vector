# simple-vector
simple vector 


Example

```

#include "vector.h"

int main()
{
  vector_t v;
  int val, * pval;
  size_t i;

  vector_init(&v, sizeof(int));

  val = 10;
  vector_push(&v, &val); //push 10

  val = 20;
  vector_push(&v, &val); //push 20

  val = 30;
  vector_push(&v, &val); //push 30

  val = 40;
  vector_push(&v, &val); //push 40


  for (i = 0 ; i < vector_count(&v); ++i) {
     pval = (int *)vector_get_at(&v, i); //get pointer to 10 20 30 40
  }


  vector_pop(&v, &val); //pop 10

  vector_pop(&v, &val); //pop 20

  vector_free(&v);

}

```
