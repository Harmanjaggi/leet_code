#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
    int lastIdx = s.size() - 1;
    bool isEnd = false;
    for (int i = s.size() - 1; i >= 0; i--) {
        if(!isEnd) {
            if(s[i] != ' ')
                isEnd = true;
            else
                lastIdx--;
        }
        if(isEnd && s[i] == ' ') {
            return lastIdx - i;
        }
    }
    return isEnd ? lastIdx + 1 : 0;
}

int main()
{
    string s;
    getline(std::cin, s);
    cout << lengthOfLastWord(s);
}