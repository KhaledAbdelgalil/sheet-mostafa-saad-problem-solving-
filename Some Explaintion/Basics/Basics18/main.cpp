#include <bits/stdc++.h>

using namespace std;

void learn_queue()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.front()<<" "<<q.back()<<endl;
    q.push(40);
    q.pop();
    q.pop();
    cout<<q.front()<<" "<<q.back()<<endl;
}
void learn_stack()
{
    stack<int>s;
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top();
    s.pop();
}
void learn_deque()
{
    deque<int>dq;
    dq.push_back(20);
    dq.push_front(30);
    dq.push_back(10);
    cout<<dq.front()<<" "<<dq.back();
}

void learn_Priority_queue()
{
   priority_queue<int>pq;
    pq.push(20);
    pq.push(10);
    pq.push(40);
    pq.push(-1);
    pq.push(30);
    cout<<pq.top()<<" ";
    pq.pop();
    cout<<pq.top();
}
bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first*b.second>a.second*b.second;
}

void learn_pair()
{
    pair<int,char>p1=make_pair(10,'z');
    cout<<p1.first<<" "<<p1.second<<endl;
    pair< string , pair <int,char> > p2=make_pair("mostafa",p1);
    cout<<p2.first<<" : "<<p2.second.first<<" "<<p2.second.second<<endl;
    vector<pair <int,int> > vp;
    vp.push_back(make_pair(1,2));
    vp.push_back({2,3});
    vp.push_back({5,3});
    sort(vp.begin(),vp.end(),cmp);
    for(int i=0;i<3;i++)
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
}
void learn_set()
{
    set<string>strset;
    strset.insert("ahmed");
    int cnt=strset.count("ahmed");
    cout<<cnt<<endl;
    cnt=strset.count("ak");
    cout<<cnt<<endl;

    set<int> s;

    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(3);

    // iterator pointing to
    // position where 2 is
    set<int>::iterator pos = s.find(3);

    // prints the set elements
    cout << "The set elements after 3 are: ";
    for (set<int>::iterator  it = pos; it != s.end(); it++)
        cout << *it << " ";
}

void learn_map()
{
    map<string,int> mp;
    mp["mostafa"]=5;
    mp["ali"]=2;
    //convert the map to vector of pair
    vector< pair <string,int> > mptov(mp.begin(),mp.end());
   for(int i=0;i<mptov.size();i++)
        cout<<mptov[i].first<<" "<<mptov[i].second<<endl;
}
int main()
{

    //learn_queue();
    //learn_stack();
    //learn_deque();
    //learn_Priority_queue();
    //learn_pair();
    //learn_set();
    learn_map();
    return 0;
}
