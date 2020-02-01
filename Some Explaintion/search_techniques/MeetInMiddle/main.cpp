#include <bits/stdc++.h>
using namespace std;
//you have start and end state start moving from each of them to meet in middle

//problems to give you concept
//1-encryption and dycryption:
/*you have original string and double encrypted string by keys(1-N) find 2 keys which encrypted by*/
const int N=10;
string encrypt(string in,int key)
{
    for(int i=0,sz=in.size();i<sz;i++)
    {
        if(isupper(in[i]))
        {
            int k=((int)(in[i]-'A')+key)%26;
            in[i]=(char)(k+65);
        }
        else
        {
            int k=((int)(in[i]-'a')+key)%26;
            in[i]=(char)(k+97);
        }

    }
    return in;
}
string dycrypt(string in,int key)
{
    for(int i=0,sz=in.size();i<sz;i++)
    {
        int k;
        if(isupper(in[i]))
             k=((int)(in[i]-'A')-key)%26;
        else
             k=((int)(in[i]-'a')-key)%26;
        while(k<0)
        {
            k+=26;
        }
        if(isupper(in[i]))
            in[i]=(char)(k+65);
        else
            in[i]=(char)(k+97);
    }
    return in;
}
void problem1_sol1(string original,string double_enc)
{
    for(int i=0;i<N;i++)
    {
        string single_enc=encrypt(original,i);
        for(int j=0;j<N;j++)
        {
            string ans=encrypt(single_enc,j);
            if(ans==double_enc)
            {
                cout<<"first_solution: encrypt by "<<i<<" then "<<j<<endl;
            }
        }
    }
}
void problem1_sol2(string original,string double_enc)
{
    map<string,int>mem;
    for(int i=0;i<N;i++)
    {
        string single_enc=encrypt(original,i);
        mem[single_enc]=i;
    }
    for(int i=0;i<N;i++)
    {
        string single_enc=dycrypt(double_enc,i);
        if(mem.find(single_enc)!=mem.end())
        {
            cout<<"second_solution: encrypt by "<<mem[single_enc]<<" then "<<i<<endl;
        }
    }
}
void problem1()
{
    string original ="aBCD";
    cout<<original<<endl;
    cout << encrypt(encrypt(original,2),3) << endl;
    string double_enc=encrypt(encrypt(original,2),3);
    original=dycrypt(dycrypt(double_enc,3),2);
    cout<<original<<endl;
    problem1_sol1(original,double_enc);
    cout<<endl<<endl;
    problem1_sol2(original,double_enc);
}
//2-given set of integers we want to divide them to 2 equal parts in summation(solved efficiently by dp but let's solve it by meet in middle concept)
//generate 2^n here 2^2 states for each half
//search how to generate 2^n states
//split group into 2 halves and take 1st generate possible states store sum in map then second halfsum-sum

//3-group of 4 sum=0(is there is a sum=0 of group 4)
//take each pair if sum=6 found another pair sum =-6
int main()
{
    problem1();
    return 0;
}
