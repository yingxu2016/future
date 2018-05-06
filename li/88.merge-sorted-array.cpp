class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.empty()) {
            return;
        }
        int i = m + n - 1;
        m--;
        n--;
        for(; i >= 0 && m >= 0 && n >= 0; i--) {
            if(nums1[m] > nums2[n]) {
                nums1[i] = nums1[m];
                m--;
            }
            else {
                nums1[i] = nums2[n];
                n--;
            }
        }
        while(n >= 0 && i >= 0) {
            nums1[i] = nums2[n];
            i--;
            n--;
        }
    }
};