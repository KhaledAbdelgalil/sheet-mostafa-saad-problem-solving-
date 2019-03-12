#include <iostream>

using namespace std;
int r1,r2,c1,c2,d1,d2;
int out1,out2,out3,out4;
int flag_solved=0;
int main()
{
    cin>>r1>>r2>>c1>>c2>>d1>>d2;

    for(int i=1;i<=9;i++)
    {
        out1=i;
        out2=r1-out1;
        out3=c1-out1;
        out4=d1-out1;
        if (out3+out4==r2 && out2+out4==c2 &&out2+out3==d2)
        {
            flag_solved=1;
            break;
        }
    }
    if(out1==out2||out1==out3||out1==out4||out2==out3||out2==out4||out3==out4||flag_solved==0||out1>9||out2>9||out3>9||out4>9||out1<1||out2<1||out3<1||out4<1) cout<<-1;
    else cout<<out1<<" "<<out2<<endl<<out3<<" "<<out4;
    return 0;
}
