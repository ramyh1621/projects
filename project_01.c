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
    tdate vertl[];
}tpatien;
void input(tpatien t[100],int n){
    int i;
    for (i=0;i<n;i++){
        printf("The patien number %d :\n",i+1);
        printf("Enter the name of the patien : ");
        scanf("%s",t[i].name);
        printf("Enter the ID :");
        scanf("%d",&t[i].id);
        printf("Enter the phone number :");
        scanf("%s",t[i].tel);
        printf("Enter date of birth dd mm yyyy :");
        scanf("%d %d %d",&t[i].birth_date.day,&t[i].birth_date.month,&t[i].birth_date.year);
        printf("Enter the appointment date dd mm yyyy :");
        scanf("%d %d %d",&t[i].rnv_date.day,&t[i].rnv_date.month,&t[i].rnv_date.year);
        printf("Enter the appointment time hh mm :");
        scanf("%d %d",&t[i].rnv_time.h,&t[i].rnv_time.m);
    }
}
void display(tpatien arr[],int n){

    printf("The patiens :\n");
    for (int i=0;i<n;i++){
        printf("%d) %s\n",i+1,arr[i].name);
    }
}
void sort(tpatien a[],int n){
     int i,j,d;
     tpatien temp;
     printf("the sort by the date of rnv :\n");
       
     for ( i=0;i<n;i++)
        {
         d=i;
        for ( j=i+1;j<n;j++){
             if( a[j].rnv_date.year<a[d].rnv_date.year){
                 d=j;
                 }
                else if(a[j].rnv_date.year == a[d].rnv_date.year){
                      if(a[j].rnv_date.month < a[d].rnv_date.month){
                      d=j;}
                else if(a[j].rnv_date.month == a[d].rnv_date.month){
                    if (a[j].rnv_date.day < a[d].rnv_date.day){
                        d=j;
                    }
                }

                }}
            temp = a[d];
            a[d] = a[i];
            a[i] = temp;  
        for(i=0;i<n;i++){
                 printf("in %d/%d/%d there is :%s\n",a[i].rnv_date.day,a[i].rnv_date.month,a[i].rnv_date.year,a[i].name);
                 
        }
                           
          
}}
void add(tpatien v[],int *n){
      
          
        printf("Enter name of a new patien : ");
        scanf("%s",v[*n].name);
        printf("Enter the ID :");
        scanf("%d",&v[*n].id);
        printf("Enter the phone number :");
        scanf("%s",v[*n].tel);
        printf("Enter date of birth dd mm yyyy :");
        scanf("%d %d %d",&v[*n].birth_date.day,&v[*n].birth_date.month,&v[*n].birth_date.year);
        printf("Enter the appointment date dd mm yyyy :");
        scanf("%d %d %d",&v[*n].rnv_date.day,&v[*n].rnv_date.month,&v[*n].rnv_date.year);
        printf("Enter the appointment time hh mm :");
        scanf("%d %d",&v[*n].rnv_time.h,&v[*n].rnv_time.m);
        
}
    
int main(){
    int n;
    tpatien t[150];
    do{
        printf("Enter N number of patiens <100 : ");
        scanf("%d",&n);
    }while(n<=0 || n>100);
    input(t,n);
    display(t,n);
    sort(t,n);
    add(t,&n);
     display(t,n);  
return 0;
}