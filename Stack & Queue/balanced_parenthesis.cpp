#include<bits/stdc++.h>
using namespace std;

class Solution { // Better Solution
    public:
        bool isValid(string str) {
            stack<char> s;
            for(const char &ch : str) {    
                switch(ch) {
                    case '(':
                        s.push(')');
                        break;
                    case '{':
                        s.push('}');
                        break;
                    case '[':
                        s.push(']');
                        break;
                    default:
                        
                        if(s.empty())
                            return false;
                        else if(ch == s.top()) 
                            s.pop();
                        else
                            return false;
                        break;       
                }
            }
            
            return s.empty();
        }
    };

int main()
{
    string s = "()[{}(]";
    stack <int> st;

    int i=0;
    while(s[i])
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            i++;
        }

        else if((s[i] == ')' && st.top() == '(')
        ||(s[i] == '}' && st.top() == '{')||
        (s[i] == ']'&& st.top() == '['))

        {
            st.pop();
            i++;
        }

        else{
            cout << "Not balanced";
            return 0;
        }
    }

    if(st.empty()) cout << "Balanced";
    else cout << "Not Balanced";
}