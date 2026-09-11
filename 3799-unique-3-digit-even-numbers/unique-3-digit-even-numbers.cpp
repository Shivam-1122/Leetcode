class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> arr;
        for(int i=0;i<digits.size();i++){
            if(digits[i]%2==0){
                for(int j=0;j<digits.size();j++){
                    if(i!=j){
                        for(int k=0;k<digits.size();k++){
                            if(k!=j && k!=i && digits[k]!=0)
                                arr.insert((digits[i])+(digits[j]*10)+(digits[k]*100));
                        }
                    }
                }
            }
        }
        return arr.size();
    }
};