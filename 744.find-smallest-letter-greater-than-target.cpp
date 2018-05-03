class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(letters[mid] <= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if(letters[l] > target) {
            return letters[l];
        }
        if(letters[r] > target) {
            return letters[r];
        }
        return letters[0];
    }
};
