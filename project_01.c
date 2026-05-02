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
        printf("Enter the name of patien %d : ",i+1);
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
     printf("the sort by the date of appointment :\n");
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
                    else if (a[j].rnv_date.day == a[d].rnv_date.day){
                        if (a[j].rnv_time.h < a[d].rnv_time.h){
                            d=j;
                        }
                        else if (a[j].rnv_time.h < a[d].rnv_time.h){
                            if (a[j].rnv_time.m < a[d].rnv_time.m)
                                d=j; 
                        }
                    }
                }
                }}
            temp = a[d];
            a[d] = a[i];
            a[i] = temp; } 
            display(a,n);
        }
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
    (*n)++;
}
void delete(tpatien s[],int *n){
    int id;
    int i,j,found=0;
    printf("Enter the id of the patien you wanna delete :");
    scanf("%d",&id);
    for (i=0;i<*n;i++){
        if (id == s[i].id){
            for (j=i;j<(*n)-1;j++){
                s[j]=s[j+1];
            }
        (*n)--;
        found =1;
        printf("patient deleted.\n");
        break;
    }
    }
    if (!found){
        printf("ID not found.\n");
    }
}
void search(tpatien k[],int *n){
    int id;
    printf("Enter ID :");
    scanf("%d",&id);
    for(int i=0;i<*n;i++){
          if(k[i].id==id){
            printf("name : %s \n id : %d\n tel :%d\n date of birth : %d/%d/%d \n",k[i].name,k[i].id,k[i].tel,k[i].birth_date.day,k[i].birth_date.month,k[i].birth_date.year);
          }
    }

}
void count(tpatien l[],int *n){
    int day,month,year;
    int m=0;
    printf("Enter oppointment date dd/mm/yyyy:");
    scanf("%d %d %d",&day,&month,&year);
    for (int i=0;i<*n;i++){
        if (year==l[i].rnv_date.year)
          if (month==l[i].rnv_date.month)
             if (day==l[i].rnv_date.day){
                 m++;
                }
               
              
            }printf("there is %d opointments\n",m);
            
            
}
void archive(tpatien b[],int n){
    FILE *fptr = fopen("patien_data.txt","w");
    //fprintf(fptr, "id | name | phone | birth date | appointment date | appointment time\n");
    
    for(int i=0;i<n;i++){
        fprintf(fptr,"-------------------------------\n");
        fprintf(fptr,"patien %d :\n",i+1);
        fprintf(fptr,"id: %d \nname: %s \nphone %s \nbirth date: %02d /%02d /%04d \nappointment date: %02d/%02d/%04d \nappointment time: %02d : %02d\n",b[i].id,b[i].name,b[i].tel,b[i].birth_date.day,b[i].birth_date.month,b[i].birth_date.year,b[i].rnv_date.day,b[i].rnv_date.month,b[i].rnv_date.year,b[i].rnv_time.h,b[i].rnv_time.m);
    }
    fclose(fptr);
}
int main(){
    int n,id,choice=1;
    tpatien t[150];
    do{
        printf("Enter N number of patiens <100 : ");
        scanf("%d",&n);
    }while(n<=0 || n>100);
    do {
    do{
    printf("------------------------------\n");
    printf(" 1) input \n 2) display \n 3) sort \n 4) add \n 5) delete \n 6) search \n 7) count \n 8) archive\n 0) exit\n");
    printf("Enter number of function you wanna use : \n");
    scanf("%d",&choice);
    }while(choice >8 || choice <0);
    printf("------------------------------\n");
    switch (choice){
        case 1: input(t,n); break;
        case 2: display(t,n); break;
        case 3: sort(t,n); break;
        case 4: add(t,&n); break;
        case 5: delete(t,&n); break;
        case 6: search(t,&n); break;
        case 7: count(t,&n); break;
        case 8: archive(t,n); break;
        case 0: break;
        default: printf("Invalid choice.\n");
    }
        
    }while(choice != 0);
return 0;
}  