#include <bits/stdc++.h>
using namespace std;
char str1[101],str2[101];
int sz1,sz2;
int mem[101][101];
int edit_min_operations(int i,int j)
{
    if(i==sz1) return sz2-j;//str1 is finished so add from str2
    if(j==sz2) return sz1-i;//str2 is finished so remove reminder of str1;
    int &ret=mem[i][j];
    if(ret!=-1)
        return ret;
    if(str1[i]==str2[j])//no operations needed
        return ret=edit_min_operations(i+1,j+1);

    int c1=1+edit_min_operations(i,j+1);//add str2[j] to i in str1
    int c2=1+edit_min_operations(i+1,j);//remove str1[i] in str1
    int c3=1+edit_min_operations(i+1,j+1);//replace
    return ret=min(c1,min(c2,c3));
}

int op_no=0;
int idx_shift=0;
void traceoperations(int i,int j)//we don't need to memorize
{
    if(i==sz1)
    {
        int toAdd=sz2-j;
        for(int k=0;k<toAdd;k++)
            cout<<++op_no<<" Insert "<<i+k+1+idx_shift<<","<<str2[j+k]<<endl;
        idx_shift+=toAdd;
        return;
    }
    if(j==sz2)
    {
        int todelete=sz1-i;
        for(int k=0;k<todelete;k++)
            {
                cout<<++op_no<<" Delete "<<i+1+k+idx_shift<<endl;
                idx_shift--;
            }
            return;
    }
    if(str1[i]==str2[j])//no operations needed
    {
        traceoperations(i+1,j+1);
        return;
    }
    int c1=1+edit_min_operations(i,j+1);//add str2[j] to i in str1
    int c2=1+edit_min_operations(i+1,j);//remove str1[i] in str1
    int c3=1+edit_min_operations(i+1,j+1);//replace

    //let's see what actually was correct
    int optimal = edit_min_operations(i,j);



    if(optimal==c1)
    {
        cout<<++op_no<<" Insert "<<i+1+idx_shift<<","<<str2[j]<<endl;
        idx_shift++;
        traceoperations(i,j+1);
    }
    else if(optimal==c2)
    {
        cout<<++op_no<<" Delete "<<i+1+idx_shift<<endl;
        idx_shift--;
        traceoperations(i+1,j);
    }
    else
    {
        cout<<++op_no<<" Replace "<<i+1+idx_shift<<","<<str2[j]<<endl;
        traceoperations(i+1,j+1);
    }

}
bool f=0;
int main()
{
    //freopen("text2.txt","w",stdout);

   while(gets(str1))
    {
        gets(str2);
        if(f)
            cout<<endl;
        else f=1;
        memset(mem,-1,sizeof mem);
        sz1=strlen(str1);
        sz2=strlen(str2);
        cout<<edit_min_operations(0,0)<<endl;
        traceoperations(0,0);
        op_no=0;
        idx_shift=0;
    }
    return 0;
}
