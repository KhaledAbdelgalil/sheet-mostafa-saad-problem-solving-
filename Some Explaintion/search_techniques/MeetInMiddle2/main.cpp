//problems::spoj(SUMFOUR - 4 values whose sum is 0)

#include <bits/stdc++.h>
using namespace std;
//brute force will time limit exceed(N^4)
void SUMFOUR1()
{
    int A[2500],B[2500],C[2500],D[2500];
    unsigned int countt=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        {
        cin>>A[i];
        cin>>B[i];
        cin>>C[i];
        cin>>D[i];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int l=0;l<n;l++)
                    if(A[i]+B[j]+C[k]+D[l]==0)
                        countt++;
    cout<<countt;
}
//here meet in middle 2*N^2(this is also time limit try to think better)
void SUMFOUR2()
{
    map<int,int>mp;//sum countt
int A[2500],B[2500],C[2500],D[2500];
    unsigned int countt=0;
    int n;

    cin>>n;
    for(int i=0;i<n;i++)
        {
        cin>>A[i];
        cin>>B[i];
        cin>>C[i];
        cin>>D[i];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[A[i]+B[j]]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            countt+=mp[-(C[i]+D[j])];
    cout<<countt;

}

//MeetInMiddle +BinarySearch
int a[4001],b[4001],c[4001],d[4001];
int A[16000002];
int B[16000002];
void SUMFOUR3()
{

    unsigned long long countt=0;
    int n;
    long t1=0;

    cin>>n;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
        cin>>d[i];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            A[t1++]=a[i]+b[j];

    t1=0;
    //meetInmiddle and binary search
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            {
                B[t1++]=-c[i]-d[j];
            }
    sort(A,A+t1);
    sort(B,B+t1);
    for(long i=0;i<t1;){
		long size1=0;
		int no=A[i];
		while(A[i]==no&&i<t1){
			size1++;
			i++;
		}
		long low=0;
		long high=t1;
		long mid;
		long size=0;
		while(low<=high){
			mid=(low+high)/2;
			if(B[mid]==no){
                    long l(mid),r(mid);
                size=1;
				while(r+1<t1&&B[r+1]==no){
					size++;
					r++;
				}
				while(l>0&&B[l-1]==no){
					size++;
					l--;
				}
				break;
			}
			else if(B[mid]<no){
				low=mid+1;
			}
			else if(B[mid]>no){
				high=mid-1;
			}
		}
		countt+=size1*size;
	}
	cout<<countt;

}
int main()
{
    //SUMFOUR1();
    //SUMFOUR2();
    SUMFOUR3();
    return 0;
}
