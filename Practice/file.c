#include<stdio.h>
#include<stdlib.h>
 
typedef struct employee
{
    unsigned int id,sal,age;
    char name[25],dept[25]; 
 
}emp;
 
void put( char fname[] )
{
    FILE *fp = NULL;
    emp e;
    printf("Enter employee details (id,name,dept,salary,age) :  \n");
    scanf("%d%s%s%d%d",&e.id,e.name,e.dept,&e.sal,&e.age);
    if((fp = fopen(fname,"a+")) == NULL)
    {
        printf("Error in opening file\n");
        exit(1);
 
    }
    fwrite(&e,sizeof(e),1,fp);
    fclose(fp);
}
void dis(char fname[])
{
    FILE *fp = NULL;
    emp e;
 
    if((fp = fopen(fname,"r")) == NULL)
    {
        printf("Error in opening file \n");
        return;
    }
        printf("EMPLOYEE DETAILS\n");
        while(!feof)
        {
 
            fread(&e,sizeof(e),1,fp);
            printf("Employee ID : %d\nNAME : %s\nDEPARTMENT : %s\nSALARY : %d\nAGE : %d\n",e.id,e.name,e.dept,e.sal,e.age);
 
        }
        fclose(fp);
}
 
void search( char fname[] )
{
    FILE *fp = NULL;
    emp e;
 
 
    if((fp =fopen(fname,"r")) == NULL)
    {
        printf("empty file\n");
        exit(1);
 
    }
    int id;
    printf("Enter Empoyee id to be searched : ");
    scanf("%d",&id);
    while(1)
    {
        if(feof)
            break;
        fread(&e,sizeof(e),1,fp);
        if(id == e.id)
        {
            printf("EMPLOYEE ID : %d\nNAME : %s\nDEPARTMENT : %s\nSALARY : %d\nAGE : %d\n",e.id,e.name,e.dept,e.sal,e.age);
            fclose(fp);
            return;
        }
        printf("Employee not found.....\n");
 
    }
}
int main()
{
    FILE *fp = NULL;
    char fname[40];
    printf("Enter filename : ");
    scanf("%s",fname);
    int ch;
    while(1)
    {
        printf("1.READ\n2.DISPLAY\n3.SEARCH\n4.EXIT\nEmter your choice :  ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1 : put(fname);
                break;
        case 2 : dis(fname);break;
 
        case 3 : search(fname);
                    break;
        case 4:exit (0);
 
        default: printf(".....INVALID CHOICE.....");
        }
    }
}