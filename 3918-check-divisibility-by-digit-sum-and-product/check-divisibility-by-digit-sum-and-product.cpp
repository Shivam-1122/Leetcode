class Solution {
public:
    bool checkDivisibility(int n) {
        int n2=n;
        int sum=0;
        int product=1;
        while(n2!=0){
            int a=n2%10;
            sum=sum+a;
            product=product*a;
            n2=n2/10;
        }
        sum=sum+product;
        if(n%sum==0){
            return true;
        }
        return false;
    }
};