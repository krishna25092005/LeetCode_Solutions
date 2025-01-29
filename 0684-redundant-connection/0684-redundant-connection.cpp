#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent, rank;
    
    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    // Union function with rank optimization
    bool unionSet(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; // Cycle detected
        
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        // Initialize each node to be its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Process each edge
        for (const auto& edge : edges) {
            if (!unionSet(edge[0], edge[1])) {
                return edge; // The edge creating the cycle
            }
        }
        return {}; // Should never reach here
    }
};
