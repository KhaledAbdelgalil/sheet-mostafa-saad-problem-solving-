#include <iostream>
#include<stack>
using namespace std;
string input;
int count_output=0;
int main()
{
    cin>>input;
    stack<char> brackets;
    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(')
        {
         brackets.push(input[i]);
        }
        else if(input[i]==')')
            {
                if(!(brackets.empty()))
                {
                        brackets.pop();
                        count_output+=2;
                }

            }
    }

     cout<<count_output;
    return 0;
}
