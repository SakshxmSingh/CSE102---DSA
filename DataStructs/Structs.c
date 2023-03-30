#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[25];
    int rollno;
};

int main(){

    struct student stu1;
    // stu1.name = "kaju";
    strcpy(stu1.name , "kaju");
    stu1.rollno = 2022242;

    printf("%s\t%d\n",stu1.name,stu1.rollno);

    return 0;
}