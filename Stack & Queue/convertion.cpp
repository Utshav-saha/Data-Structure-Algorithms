#include<bits/stdc++.h>
using namespace std;

// Priority order
int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }

        else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

void reverse(string &s)
{
    for(int i=0, j = s.size()-1; i<j; i++, j--)
    {   
        char ch;

        if(s[i] == '(')
        {
            ch = ')';
        }
        else if(s[i] == ')')
        {
            ch = '(';
        }

        else ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
}

string infixToPrefix(string s)
{   
    // reverse with brackets
    reverse(s);

    // infix to postfix
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }

        else {
            while (!st.empty() && priority(c) < priority(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // again reverse
    reverse(result);

    return result;

}


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) { 
            string operand(1, c); 
            st.push(operand);
        }
        else if (isOperator(c)) {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();

            string infix = "(" + operand1 + c + operand2 + ")";

            st.push(infix);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}
