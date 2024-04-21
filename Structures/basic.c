#include <stdio.h>
struct students
{
    char *name;
    int usn;
    int sem;
};
int newadm()
{
    struct students newadm;
    newadm.sem = 2;
    if(newadm.sem == 2)
    {
        newadm.usn = 29;
    }
    else{
        newadm.usn = 30;
    }
    return newadm.usn;
}
int main()
{
    struct students s1;
    struct students s2;
    printf("Enter the usn of student 1: ");
    scanf("%d",&s1.usn);
    printf("Enter the usn of student 2: ");
    scanf("%d",&s2.usn);
    printf("Usn of student 1 is %d\n",s1.usn);
    printf("Usn of student 2 is %d\n",s2.usn);
    printf("Usn of new admission student is %d\n",newadm());

}