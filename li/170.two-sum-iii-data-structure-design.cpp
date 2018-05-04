class TwoSum {
private:
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto i : m) {
            int target = value - i.first;
            if(target == i.first) {
                if(i.second > 1) {
                    return true;
                }
            }
            else {
                if(m.count(target)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class TwoSum2 {
private:
    unordered_set<int> nums;
    unordered_set<int> vals;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        for(auto i : nums) {
            vals.insert(i + number);
        }
        nums.insert(number);

    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        return vals.count(value);
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
