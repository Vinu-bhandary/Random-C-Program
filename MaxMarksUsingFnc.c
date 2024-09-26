#include<stdio.h>

struct Student {
    char name[50];
    int marks;
};

void display(struct Student stud[] ,int max) {
    printf("%s %d",stud[max].name,stud[max].marks);
}

int fnc(struct Student stud[] ,int n) {
    int max = stud[0].marks;
    for(int i=1;i<n;i++) {
        if(stud[i].marks>stud[max].marks) {
            max=i;
        }
    }
    return max;
}

void main() {
    struct Student stud[10];
    int n,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        printf("%d",i+1);
        scanf("%s",stud[i].name);
        scanf("%d",&stud[i].marks);
    }
    max = fnc(stud,n);
    display(stud,max);
}
