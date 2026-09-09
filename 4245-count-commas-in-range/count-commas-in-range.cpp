class Solution {
public:
    int countCommas(int n) {
        if(n>=1 && n<=999)
            return 0;
        else if(n>=1000 && n<=999999)
            return n-999;
        return 0;
    }
};