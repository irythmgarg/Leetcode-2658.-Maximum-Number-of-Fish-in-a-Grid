// Author: Ridham Garg
// Date: [Add the date here if you want]
// Description: This code finds the maximum sum of fish that can be collected from any connected water body in a grid.
// It uses Disjoint Set Union (DSU) or Union-Find to group connected cells and calculate fish sums.

class Solution {
public:
    vector<int> parent, cost;

    // Find function with path compression
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union function to merge two components and update the fish count
    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        parent[py] = px;
        cost[px] += cost[py];
    }

    // Main function to find the maximum fishes collected from any connected region
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        parent.resize(m * n);
        cost.resize(m * n);
        
        // Initialize parent and cost arrays
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * n + j;
                cost[idx] = grid[i][j];
                parent[idx] = idx;
            }
        }

        vector<vector<int>> directions = {{1,0}, {0,-1}, {-1,0}, {0,1}};

        // Merge adjacent cells with fishes
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                {
                    for (auto direction : directions)
                    {
                        int newi = i + direction[0];
                        int newj = j + direction[1];
                        
                        // Check bounds and whether the neighboring cell has fishes
                        if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] > 0)
                        {
                            int newidx = newi * n + newj;
                            unite(i * n + j, newidx);
                        }
                    }
                }
            }
        }

        // Find the maximum fish collected among all connected components
        int ans = 0;
        for (int i = 0; i < m * n; i++)
        {
            ans = max(ans, cost[i]);
        }
        return ans;
    }
};
