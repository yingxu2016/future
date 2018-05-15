// union-find
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> v(n, -1);
        for(auto i : edges) {
            int x = find(v, i.first);
            int y = find(v, i.second);
            if(x != y) {
                v[x] = y;
            }
        }
        int ans = 0;
        for(auto i : v) {
            if(i == -1) {
                ans++;
            }
        }
        return ans;
    }
private:
    int find(vector<int>& v, int i) {
        if(v[i] == -1) {
            return i;
        }
        return find(v, v[i]);
    }
};

// dfs
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& e: edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        stack<int> s;
        vector<bool> v(n, false);
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (v[i]) continue;
            ans++;
            s.push(i);
            while (!s.empty()) {
                auto curr=s.top();
                s.pop();
                v[curr]=true;
                for (auto nei: graph[curr])
                    if (!v[nei])
                        s.push(nei);
            }
        }
        return ans;
    }
};

// bfs
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& e: edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        queue<int> q;
        vector<bool> v(n, false);
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (v[i]) continue;
            ans++;
            q.push(i);
            while (!q.empty()) {
                auto curr=q.front();
                q.pop();
                v[curr]=true;
                for (auto nei: graph[curr])
                    if (!v[nei])
                        q.push(nei);
            }
        }
        return ans;
    }
};