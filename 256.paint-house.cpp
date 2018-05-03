class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int red = costs[0][0];
        int blue = costs[0][1];
        int green = costs[0][2];
        for(int i = 1; i < costs.size(); i++) {
            int tmpR = red, tmpB = blue, tmpG = green;
            red = min(tmpB, tmpG) + costs[i][0];
            blue = min(tmpR, tmpG) + costs[i][1];
            green = min(tmpR, tmpB) + costs[i][2];
        }
        return min(red, min(blue, green));
    }
};
