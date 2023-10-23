class Solution {
public:
    bool isPowerOfFour(long n) {
        if(n == 1) return true;
    if((n&(n-1)) != 0){
        return false;
    }
    
    return (n%3 == 1);
    }
};