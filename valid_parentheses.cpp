#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            switch (ch)
            {
            case ')':
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
                break;
            default:
                return false;
            }
        }
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    string str;
    cin >> str;
    cout << (isValid(str) ? "true" : "false");
}