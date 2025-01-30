class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> component(n + 1, -1);
        vector<vector<int>> components;
        int compId = 0;
        
        function<void(int)> dfs = [&](int node) {
            component[node] = compId;
            components[compId].push_back(node);
            for (int neighbor : graph[node]) {
                if (component[neighbor] == -1) {
                    dfs(neighbor);
                }
            }
        };
        
        for (int i = 1; i <= n; i++) {
            if (component[i] == -1) {
                components.push_back({});
                dfs(i);
                compId++;
            }
        }
        
        auto bfs = [&](int start) {
            queue<int> q;
            unordered_map<int, int> depth;
            q.push(start);
            depth[start] = 1;
            int maxDepth = 1;
            
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    if (!depth.count(neighbor)) {
                        depth[neighbor] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[neighbor]);
                        q.push(neighbor);
                    } else if (abs(depth[neighbor] - depth[node]) != 1) {
                        return -1;
                    }
                }
            }
            return maxDepth;
        };
        
        int result = 0;
        for (auto& comp : components) {
            int maxLevel = -1;
            for (int node : comp) {
                int levels = bfs(node);
                if (levels == -1) return -1;
                maxLevel = max(maxLevel, levels);
            }
            result += maxLevel;
        }
        
        return result;
    }
};
