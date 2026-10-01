class Solution {
public:
    bool isValid(string s) {
        vector<char> arr;
        for(char x: s){
            if(arr.empty()){
                arr.push_back(x);
            }
            else if((arr[arr.size()-1]=='(' && x==')') || (arr[arr.size()-1]=='{' && x=='}') || (arr[arr.size()-1]=='[' && x==']'))
                arr.pop_back();
            else
                arr.push_back(x);
        }
        return arr.empty();
    }
};