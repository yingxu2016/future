class Solution {
public:
    void reverseWords(vector<char>& str) {
        if(str.empty()) 
            return;
        int l = 0;
        int r = str.size() - 1;
        swap(str, l, r);
        l = 0, r = 0;
        while(r < str.size()) {
            if(str[r] == ' ') {
                swap(str, l, r - 1);
                r = r + 1;
                l = r;
            }
            else {
                r++;
            }
        }
        swap(str, l, r - 1);
    }
private:
    void swap(vector<char>& str, int l, int r) {
        while(l < r) {
            char tmp = str[l];
            str[l] = str[r];
            str[r] = tmp;
            l++;
            r--;
        }
    }
};
