class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int ans=abs(xCenter-x1);
        int ans2=abs(yCenter-y1);
        for(int i=x1+1;i<=x2;i++){
            if(ans>abs(xCenter-i)){
                ans=abs(xCenter-i);
            }
        }
        for(int i=y1+1;i<=y2;i++){
            if(ans2>abs(yCenter-i)){
                ans2=abs(yCenter-i);
            }
        }
        return ans * ans + ans2 * ans2 <= radius * radius;;
    }
};