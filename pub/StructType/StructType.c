// gcc -o StructType StructType.c -g -Wall && ./StructType

// okay
struct Student1 { char *name; struct { int m,d,y; } bday; };

// good
struct Date { int m,d,y; };
struct Student2 { char *name; struct Date bday; };

// best
typedef struct { int m,d,y; } Date;
typedef struct { char *name; Date bday; } Student;

struct Student1 s1={"don",{7,28,2020}};
struct Student2 s2={"don",{7,28,2020}};
Student s={"don",{7,28,2020}};

int main() {
  return 0;
}
