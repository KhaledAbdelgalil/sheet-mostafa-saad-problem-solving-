//CF problems:(597A(div2)-336C(div2-not_solved_yet)
//UVA problems:(622(not solved),)
using namespace std;

void raisingBacteria579A_solution()
{
    int n;
    cin>>n;
    int res=0;
    while(n)
    {
        n&=(n-1);
        res++;
    }
    cout<<res;
}
int main()
{
    raisingBacteria579A_solution();

    return 0;
}
