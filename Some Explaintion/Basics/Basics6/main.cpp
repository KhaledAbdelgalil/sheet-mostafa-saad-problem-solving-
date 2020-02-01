//some problems on arrays
#include <bits/stdc++.h>

using namespace std;

int convert_str_to_int(string s)
{
    int len=s.size();
    int tens=1;
    int number=0;
    for(int i=len-1;i>=0;i--)
    {
        assert(s[i]>='0'&&s[i]<='9');
        number+=int(s[i]-'0')*tens;
        tens*=10;
    }
    return number;
}
int string_grouping(string s)
{
    int groups=1;
    int master_of_group=s[0];
    int i=1;
    while(s[i]!='\0')
    {
        if(master_of_group==s[i])
        {
            i++;
            continue;
        }
        master_of_group=s[i];
        groups++;
    }
    return groups;
}
void test_str_to_int()
{
    string s1="156";
    cout<<convert_str_to_int(s1)<<endl;
    string s2="001520";
    cout<<convert_str_to_int(s2)<<endl;

}
void test_string_grouping()
{
    string s1="222111bbbcccddd";
    cout<<string_grouping(s1)<<endl;
    string s2="HHHHH";
    cout<<string_grouping(s2)<<endl;
}


bool Compare_2_strings_using_loops(string s1,string s2)//only first less than or not
{
    int minn=min(s1.size(),s2.size());
    for(int i=0;i<minn;i++)
    {
        if(s1[i]<s2[i]) return 1;
        else if (s2[i]<s1[i]) return 0;
    }
    return s1.size()<s2.size();
}
void test_Compare_2_strings_using_loops()
{
    string s1,s2;
    for(int test=0;test<100000;test++)
    {
        s1="";
        s2="";
        for(int i=0;i<10;i++)
        {
            s1+=char(rand()%26+97);
            s2+=char(rand()%26+97);
        }
        bool correct_answer=s1<s2;
        bool myanswer=Compare_2_strings_using_loops(s1,s2);
        //cout<<test<<endl<<s1<<endl<<s2<<endl<<correct_answer<<" "<<myanswer<<endl;
        assert(correct_answer==myanswer);
    }
    cout<<"Perfect Compare"<<endl;
}
void print_word(int start,int end,string s)
{
    if(start==end) cout<<s[start]<<endl;
    else
    {
        for(int i=start;i<=end;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}

void print_all_substrings(string s)
{
    int len=s.size();
    for(int i=0;i<len;i++)
    {
       for(int j=i;j<len;j++)
        print_word(i,j,s);
    }
}
string add9999(string s)//take string add 9999 to it print
{
    int size_s=s.size();
    stringstream ss;
    int result;
    if(size_s<=8)
    {
       result=convert_str_to_int(s)+9999;

        ss << result;
        return ss.str();
    }
    string sub_s="";
    for(int i=size_s-8;i<size_s;i++)
        sub_s+=s[i];
    int res=convert_str_to_int(sub_s)+9999;
    ss<<res;
    sub_s="";
    for(int i=0;i<size_s-8;i++)
       sub_s+=s[i];
    sub_s+=ss.str();
    return sub_s;
}
void test1_add9999()
{
    string s1="129";
    cout<<add9999(s1)<<endl;
    string s2="123456";
    cout<<add9999(s2)<<endl;
    string s3="123456789123456789123456";
    cout<<add9999(s3)<<endl;

}
void test2_add9999()
{
    long long res1;
    string res2;
    string correct_answer;

    for(int test=0;test<10000;test++)
    {
        stringstream ss1,ss2;
        res1=fabs(rand()%1000000000);
        ss1<<res1;
        res2=ss1.str();
        string myanswer=add9999(res2);
        res1+=9999;
        ss2<<res1;
        correct_answer=ss2.str();
        //cout<<test<<" "<<correct_answer<<" "<<myanswer<<endl;
        assert(correct_answer==myanswer);
    }
    cout<<"Perfect add9999 GreatJob"<<endl;
}

void sum_subset_array()
{
    int* ptr;
    int n,start,finish;
    int* ptr_sum;
    int sum;
    cout<<"enter no of elements"<<endl;
    cin>>n;
    ptr=new int(n);
    ptr_sum=new int(n);
    ptr_sum[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>ptr[i];
        if(i==0) ptr_sum[i]=ptr[i];
        else ptr_sum[i]=ptr_sum[i-1]+ptr[i];
    }
    cout<<"enter no. of queries"<<endl;
    cin>>n;
    while(n--)
    {
        cout<<"start then end spaced between each other"<<endl;
        cin>>start>>finish;
        if(start==0) cout<<ptr_sum[finish]<<endl;
        else cout<<ptr_sum[finish]-ptr_sum[start-1]<<endl;
    }
    free(ptr);
    free(ptr_sum);
}
int main()
{
    //test_str_to_int();

    //test_string_grouping();
    //test_Compare_2_strings_using_loops();
    //print_all_substrings("123a");
    //test1_add9999();
    //test2_add9999();
    sum_subset_array();
    return 0;
}
