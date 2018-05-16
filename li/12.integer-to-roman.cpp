class Solution {
public:
    string intToRoman(int num) {
        const vector<string> desc = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        const vector<int> vals =    {   1,   4,   5,    9,  10,   40,   50,  90,  100, 400,  500, 900, 1000 };
        string out;

        for (int i = desc.size() - 1; i >= 0; i--) {
            while (num >= vals[i])
            {
                out += desc[i];
                num -= vals[i];
            }
        }

        return out;
    }
};