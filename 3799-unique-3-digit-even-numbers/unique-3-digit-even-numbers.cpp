class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> arr;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==0)
                continue;
            for(int j=0;j<digits.size();j++){
                if(i==j)
                    continue;
                for(int k=0;k<digits.size();k++){
                    if(k==j || k==i)
                        continue;
                    if(((digits[i]*100)+(digits[j]*10)+(digits[k]))%2==0)
                        arr.insert((digits[i]*100)+(digits[j]*10)+(digits[k]));
                }
            }
        }
        return arr.size();
    }
};