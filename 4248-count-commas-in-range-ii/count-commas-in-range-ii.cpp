class Solution {
public:
    long long countCommas(long long n) {
        if(n>=1 && n<=999)
            return 0;
        else if(n>=1000 && n<=999999)
            return n-999;
        else if(n>=1000000 && n<=999999999)
            return (n-999999)+(n-999);
        else if(n>=1000000000 && n<=999999999999)
            return (n-999999999)+(n-999999)+(n-999);
        else if(n>=1000000000000 && n<=999999999999999)
            return (n-999999999999)+(n-999999999)+(n-999999)+(n-999);
        else
            return (n-999999999999999)+(n-999999999999)+(n-999999999)+(n-999999)+(n-999);
        return 0;
    }
};