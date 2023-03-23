#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

void calculationInString(int val1, int val2, int pos, string &ans)
{
    int val = pow(10, pos) * val1 * val2;
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
}

string multiply(string num1, string num2)
{
    long long sol = 0;
    for (int i = num1.length() - 1; i >= 0; i--)
    {
        long long val = 0;
        for (int j = num2.length() - 1; j >= 0; j--)
        {
            val += pow(10, num2.length() - j - 1) * (num1[i] - '0') * (num2[j] - '0');
        }
        sol += pow(10, num1.length() - i - 1) * val;
    }
    return to_string(sol);
}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2);
}