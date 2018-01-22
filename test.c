#include<stdio.h>
#include<stdlib.h>



typedef struct test_s1{
    char s;
    long r;
    char t;
    short int q;
}test_t1;


typedef struct test_s{
    char r;
    char t;
    char *q;
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
    test_t arr[2];
    char *p;
    char r;
    int q;

    printf("Size %lu %p %p \n", sizeof(arr), &arr[0], &arr[1]);
    printf("%p %p %p\n", &p, &r, &q);
    printf("r-q=%p, p-r=%p\n", (char*)&r-(char*)&q, (char*)&p-(char*)&r);
    printf("Size: %lu  r:%lu t:%lu q:%lu \n", sizeof(test_t),
            OFFSET_OFF(test_t, r),
            OFFSET_OFF(test_t, t),
            OFFSET_OFF(test_t, q));

    printf("Size: %lu d:%lu s:%lu c:%lu \n", sizeof(structd_t),
            OFFSET_OFF(structd_t, d),
            OFFSET_OFF(structd_t, s),
            OFFSET_OFF(structd_t, c));
    return 0;
}

