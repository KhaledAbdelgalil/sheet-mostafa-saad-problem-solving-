#include <bits/stdc++.h>

using namespace std;
string s1,s2;
double answer=1.0;
int correctPos,currentPos,unknown,diff;
int possiblities;
int main()
{
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='+') correctPos++;
        else correctPos--;

        if(s2[i]=='+') currentPos++;
        else if(s2[i]=='-') currentPos--;
        else unknown++;
    }
    if(correctPos==currentPos&&unknown==0)
    {
        cout<<answer<<endl;
        return 0;
    }

    diff=abs(correctPos-currentPos);
    if(diff>unknown)
        {
            cout<<0<<endl;
            return 0;
        }
/*we need difference between plus and minus (difference between 1 and 0) to be diff which means plus-minus=diff and plus+minus=unknown so
plus or minus 1 or 0 in unknown must be (unknown+diff)/2;*/
int must=(unknown+diff)/2;
for(int i=0;i<int(pow(2,unknown));i++)
{
    if(__builtin_popcount(i)==must) possiblities++;
}
cout.precision (20) ;
cout<<double(possiblities)/pow(2,unknown);

    return 0;
}
