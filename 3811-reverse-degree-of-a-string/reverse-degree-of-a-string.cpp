class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=(abs(s[i]-'z')+1)*(i+1);
        }
        return sum;
    }
};