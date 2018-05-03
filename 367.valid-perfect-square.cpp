class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1;
        long r = num;
        while(l <= r) {
            long mid = (l + r) >> 1;
            if(mid * mid == num) return true;
            else if(mid * mid > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
