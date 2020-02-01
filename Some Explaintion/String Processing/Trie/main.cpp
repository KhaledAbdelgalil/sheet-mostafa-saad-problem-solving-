//we can using trie search for word/its frequency :: search for prefix/its freq
//search in O(L) length of prefix/string
#include <bits/stdc++.h>
using namespace std;
const int MAX=26;
struct trie{
struct trie* child[MAX];
bool isleaf;
trie()
{
    memset(child,0,sizeof child);
    isleaf=0;
}
void insert(char *str)
{
    if(*str=='\0')
        isleaf=1;
    else
    {
        int curr=*str-'a';
        if(child[curr]==0)
            child[curr]=new trie();
        child[curr]->insert(str+1);
    }
}

bool wordExist(char *str)
{
    if(*str=='\0')
        return isleaf;
    int curr=*str-'a';
    if(child[curr]==0)
        return false;//no such path
    return child[curr]->wordExist(str+1);
}
bool prefixExist(char *str)
{
    if(*str=='\0')
        return true;
    int curr=*str-'a';
    if(child[curr]==0)
        return false;//no such path
    return child[curr]->prefixExist(str+1);
}
};



int main()
{
    trie root;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout<<root.wordExist("xyz")<<"\n";
	cout<<root.wordExist("xy")<<"\n";

	cout<<root.prefixExist("xyz")<<"\n";

	return 0;
}
