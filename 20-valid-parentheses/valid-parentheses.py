class Solution:
    def isValid(self, s: str) -> bool:
        arr=[]
        for i in range(0,len(s)):
            if len(arr)==0:
                arr.append(s[i])
            elif s[i]==')' and arr[-1]=='(':
                arr.pop()
            elif s[i]=='}' and arr[-1]=='{':
                arr.pop()
            elif s[i]==']' and arr[-1]=='[':
                arr.pop()
            else:
                arr.append(s[i])
        if len(arr)==0:
            return True
        return False
            