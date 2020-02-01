//halfs space into 2 halves
//we can use binary search with 1 7 9 15 6 4 2(sequance increase decrease)
//choose every two numbers and check on sides

#include <bits/stdc++.h>
//1 3 4 6 8 9 11 , x=4
using namespace std;

int arr[]={1,3,4,6,8,9,11};
int BS(int start,int finish,int key)
{
    if(start > finish) return -1;
    int mid=start+(finish-start)/2;
    if(arr[mid]<key) return BS(mid+1,finish,key);
    if(arr[mid]>key) return BS(start,mid-1,key);
    return mid;
}

//for first match and last match
//code could stuck in infinite loop (//use mid=start+(end-start)/2 or mid=(end-start+1)/2)
//use 1 2 and see if code terminates if not for both formulas don't trust your code
int arr2[10]={4,4,4,4,4,4,4,4,4,4};
int BSFirstMatch(int start,int finish ,int key)
{
    if(start== finish) return finish;
    if(start>finish) return -1;
    int mid=start+(finish-start)/2;
    if(arr2[mid]<key) return BSFirstMatch(mid+1,finish,key);
    if(arr2[mid]>key) return BSFirstMatch(start,mid-1,key);
    return BSFirstMatch(start,mid,key);//be careful of that condition
}
int BSLastMatch(int start,int finish ,int key)
{
    if(start== finish) return start;
    if(start>finish) return -1;
    int mid=start+(finish-start+1)/2;
    if(arr2[mid]<key) return BSLastMatch(mid+1,finish,key);
    if(arr2[mid]>key) return BSLastMatch(start,mid-1,key);
    return BSLastMatch(mid,finish,key);//be careful of that condition
}
//in double domain
//terminate when start==finish compare by epislon and make start w finish = mid not mid+1 and mid-1

//ternery search with binary
//1 5 9 15 9 4 2
//get max 15
int arr3[]={1,5,9,15,9,4,2};
int BSMax(int start,int finish)
{

    int mid=start+(finish-start+1)/2;
    if(arr2[mid]>=arr2[mid+1]&&arr2[mid]>=arr2[mid-1]) return mid;
    if(arr2[mid]>=arr2[mid+1]&&arr2[mid]<=arr2[mid-1]) return BSMax(start,mid-1);
    return BSMax(mid+1,finish);//be careful of that condition
}
int main()
{
    cout << BS(0,6,2) << endl;
    cout<<binary_search(arr,arr+7,2)<<endl;
    cout<<BSFirstMatch(0,9,4)<<" "<<BSLastMatch(0,9,4)<<endl;
    cout<<BSMax(0,6);
    return 0;
}
