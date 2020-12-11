// gcc -o javaclass -Wall javaclass.c && ./javaclass

// class Int {
//   int val;
// }
// Int i=new Int();

#include <stdio.h>
#include <stdlib.h>

// These are the bad ways!
struct Int1 { int val; };	// a sort-of type, named "struct Int1"
struct Int1              var1;	// a variable of that sort-of type
struct Int2 { int val; } var2;	// a sort-of type and a variable, both at once
struct      { int val; } var3;	// just the variable

// This is an okay way!
typedef struct {
  int val;
} Int4;		     // a type named "Int4", which is a struct
Int4 var4;	     // a variable of that type, which is a struct

// This is the best way! It's like the Java class.
typedef struct {
  int val;
  char *s;
} *Int;		     // a type named "Int", which is a ptr to a struct
Int i;		     // a variable of that type, which is a ptr to a struct

int main() {
  Int4 var4;			// or ... ={123};
  var4.val=123;
  printf("%d\n",var4.val);

  Int i=(Int)malloc(sizeof(*i));
  i->val=456;			// foo->bar abbreviates (*foo).bar
  printf("%d\n",i->val);
  return 0;
}
