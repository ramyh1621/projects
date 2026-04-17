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
     //   printf("Enter the ID :");
     //   scanf("%d",&t[i].id);
       // printf("Enter the phone number :");
     //   scanf("%s",t[i].tel);
       // printf("Enter date of birth dd mm yyyy :");
     //   scanf("%d %d %d",&t[i].birth_date.day,&t[i].birth_date.month,&t[i].birth_date.year);
        printf("Enter the appointment date dd mm yyyy :");
        scanf("%d",&t[i].rnv_date.year);
      //  scanf("%d %d %d",&t[i].rnv_date.day,&t[i].rnv_date.month,&t[i].rnv_date.year);
      //  printf("Enter the appointment time hh mm :");
      //  scanf("%d %d",&t[i].rnv_time.h,&t[i].rnv_time.m);
    }
}
void display(tpatien arr[],int n){

    printf("The patiens :\n");
    for (int i=0;i<n;i++){
        printf("%d) %s\n",i+1,arr[i].name);
    }
}
void sort(tpatien a[],int n){
     int ar[100];
     int i,j;
     int temp;
     printf("the sort by the date of rnv :\n");
     for ( i=0;i<n-1;i++){
        
       // int y=a[i].rnv_date.year;
        for ( j=0;j<n-i-1;j++){
            if( a[i].rnv_date.year<a[j+1].rnv_date.year){
               temp=a[i].rnv_date.year;
               a[i].rnv_date.year=a[i+1].rnv_date.year;
               a[i+1].rnv_date.year=temp;}
               printf("%s",a[i].name);
               // a[i].rnv_date.year=ar[i];
              //  a[i].rnv_date.year=a[i-1].rnv_date.year;
              //  a[i-1].rnv_date.year=ar[i];
              //  printf("%s\n",a[i].name);
            
             
            
                // printf("%s\n",a[i].name);
                 // a[i].rnv_date.year=0;
                  
           // else{
                                     
            
                //ar[i]=a[j].rnv_date.year;
             //  printf("%s\n",a[i+1].name);
             //  a[i+1].rnv_date.year=0;;

            }
          
        }
          for(i=0;i<n;i++){
           printf("%s\n",a[i].name);
    }}
int main(){
    int n;
    tpatien t[100];
    do{
        printf("Enter N number of patiens <100 : ");
        scanf("%d",&n);
    }while(n<=0 || n>100);
    input(t,n);
    display(t,n);
    sort(t,n);
return 0;
}