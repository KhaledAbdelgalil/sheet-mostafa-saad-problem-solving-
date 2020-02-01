//C:malloc and free-scanf-printf-fscanf-fprintf in c++:new and delete-cin-cout-ifstream-ofstream
//to stop syncrhonization c++ with c use std::ios_base::sync_with_stdio(false) and avoid use endl
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define p 10 //preprocessor directive text replacement
#define FOR(A,B,C) for(int (A) = (B); (A) <= (C) ; (A)+=1)
void fn1()
{
    char s[30];
    scanf("%s",s);
    printf("%s\n",s);
    printf("%03d%10.2f\n",5,3.1482);
}
void fn2()
{
    //read while t
    char s2[30];
    scanf("%[t]",s2);
    printf("%s\n",s2);
}
void fn3()
{
    //read while that range
    char s2[30];
    scanf("%[A-F]",s2);
    printf("%s\n",s2);
}
void fn4()
{
    //read while that range
    char s2[30];
    scanf("%[0-9]",s2);
    printf("%s\n",s2);
}
void fn5()
{
    //read while not range
    char s2[30]="";
    scanf("%[^0-9]",s2);
    printf("%s\n",s2);
}
void fn6()
{
    char s2[30]="";
    scanf("%[^\n]",s2);
    printf("%s\n",s2);
}
void fn7()
{
    char s2[30]="";
    scanf("%s",s2);
    printf("%s\n",s2);
}
void fn8()
{
    //till 3 char
    char s2[30]="";
    scanf("%3[A-F]",s2);
    printf("%s\n",s2);
}
void fn9()//I can read from string and say how we can read
{
    char mystring[30]="63 home 15.2";
    char substring[10];
    int num;
    float numf;
    sscanf(mystring,"%d %s %f",&num,substring,&numf);
    sprintf(mystring,"%d %s",2,"mos");
    printf("%d    %f     %s\n",num,numf,substring);
    printf("%s\n",mystring);

}
void fn10()
{
    FILE* pfile=NULL;
    pfile=fopen("file.txt","r");
    if(pfile==NULL) assert(0);
    int num1,num2;
    while(fscanf(pfile,"%d %d",&num1,&num2)!=EOF)
    {
        printf("%d,%d\n",num1,num2);
    }
    printf("End\n");
}
void fn11()
{

    FOR(i,0,10) printf("%d ",i);

}

int main()
{


    //fn1();
    //fn2();
    //fn4();
    //fn5();
    //fn8();
    //fn9();
    //fn10();
    fn11();
    return 0;
}
