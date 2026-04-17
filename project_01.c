#include <stdio.h>
#include <string.h>
typedef struct{
    int day;
    int month;
    int year;
}tdate;
typedef struct {
    int h;
    int m;
}ttime;
typedef struct{
    int id;
    char name[20];
    char tel[20];
    tdate birth_date;
    tdate rnv_date;
    ttime rnv_time;
}tpatien;
void input(tpatien t[100],int n){
    int i;
    for (i=0;i<n;i++){
        printf("The patien number %d :",i+1);
        printf("Enter the name of the patien : ");
        scanf("%s",name.t[i]);
        printf("Enter the ID :");
        scanf("%d",%id.t[i]);
        printf("Enter the phone number :");
        scanf("%s",tel.t[i]);
        printf("Enter date of birth dd mm yyyy :");
        scanf("%d %d %d",&t[i].birth_date.day,&t[i].birth_date.month,&t[i].birth_date.year);
        printf("Enter the appointment date dd mm yyyy :");
        scanf("%d %d %d",&t[i].rnv_date.day,&t[i].rnv_date.month,&t[i].rnv_date.year);
        printf("Enter the appointment time hh mm :");
        scanf("%d %d",&t[i].rnv_time.h,&t[i].rnv_time.m);
    }
}
void display(int n,tpatien arr[]){

    printf("The patiens :\n");
    for (int i=0;i<n;i++){
        printf("%d) %s\n",i+1,arr[i].name);
    }
}