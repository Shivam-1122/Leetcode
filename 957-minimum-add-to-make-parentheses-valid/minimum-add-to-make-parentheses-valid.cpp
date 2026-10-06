class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1=0,count2=0;
        for(char x: s){
            if(x=='(')
                count1++;
            else if(x==')')
                count1--;
            if(count1<0){
                count2++;
                count1=0;
            }
        }
        int diff=abs(count1)+abs(count2);
        return diff;
    }
};