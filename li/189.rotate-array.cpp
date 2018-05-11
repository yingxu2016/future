class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // Reverse the first n - k numbers.
        reverse(nums.begin(), nums.begin() + n - k);

        // Reverse tha last k numbers.
        reverse(nums.begin() + n - k, nums.end());

        // Reverse all the numbers.
        reverse(nums.begin(), nums.end());
    }
};