class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int pr = 1;

            while (x != 0) {
                pr *= x % 10;
                x /= 10;
            }

            if (pr % t == 0)
                return n;

            n++;
        }
    }
};