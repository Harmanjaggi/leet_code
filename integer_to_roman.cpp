#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, char> num_to_roman = {
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'},
};

string intToRomanForOneDigit(int curr_digit, int mask)
{
    string str = "";
    // cout << curr_digit << "::" << mask << endl;
    // sum
    if (curr_digit == 9)
    {
        str += num_to_roman[mask];
        str += num_to_roman[mask * 10];
        curr_digit = 0;
    }
    if (curr_digit >= 5)
    {
        str += num_to_roman[mask * 5];
        curr_digit -= 5;
    }
    // subtract
    if (curr_digit == 4)
    {
        str += num_to_roman[mask];
        str += num_to_roman[mask * 5];
        curr_digit -= 4;
    }
    if (curr_digit <= 3)
    {
        for (int i = 0; i < curr_digit; i++)
            str += num_to_roman[mask];
        curr_digit = 0;
    }
    // cout << str << endl;
    return str;
}
string intToRoman(int num)
{
    string sol;
    int digit = 3;
    while (digit >= 0)
    {
        int mask = pow(10, digit);
        if (num >= mask) {
            sol += intToRomanForOneDigit(num / mask, mask);
            num %= mask;
        }
        digit--;
    }
    return sol;
}

int main()
{
    int num;
    cin >> num;
    cout << intToRoman(num);
}