#include<stdio.h>
#include<stdlib.h>



typedef struct test_s1{
    char s;
    long r;
    char t;
    short int q;
}test_t1;


typedef struct test_s{
    int* s;
    char r;
    char t;
    char q;
}test_t;

typedef struct structd_tag
{
    double      d;
    int         s;
    char        c;
} structd_t;

#define OFFSET_OFF(type, field)   (size_t)(&(((type*)0)->field))

int main(void)
{
    printf("Size: %lu s:%lu r:%lu t:%lu q:%lu \n", sizeof(test_t),
            OFFSET_OFF(test_t,s),
            OFFSET_OFF(test_t, r),
            OFFSET_OFF(test_t, t),
            OFFSET_OFF(test_t, q));

    printf("Size: %lu d:%lu s:%lu c:%lu \n", sizeof(structd_t),
            OFFSET_OFF(structd_t, d),
            OFFSET_OFF(structd_t, s),
            OFFSET_OFF(structd_t, c));
    return 0;
}

