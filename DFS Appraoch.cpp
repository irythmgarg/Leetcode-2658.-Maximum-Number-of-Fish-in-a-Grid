// Author: Ridham Garg
// Description: This code finds the maximum sum of fish that can be collected from any connected water body in a grid.
// Each cell has a certain number of fishes, and you can move in four directions: up, down, left, right.

class Solution {
public:
    // Define possible movement directions: down, left, up, right
    vector<vector<int>> directions = {{1,0}, {0,-1}, {-1,0}, {0,1}};

    // Depth-First Search (DFS) to collect fishes from connected cells
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int &cost)
    {
        grid[i][j] = 0; // Mark current cell as visited by setting it to 0
        for (int p = 0; p <= 3; p++)
        {
            int newi = i + directions[p][0];
            int newj = j + directions[p][1];
            
            // Check bounds and whether the neighboring cell has fishes
            if (newi < m && newi >= 0 && newj < n && newj >= 0 && grid[newi][newj] > 0)
            {
                cost += grid[newi][newj]; // Add the number of fishes
                dfs(newi, newj, m, n, grid, cost); // Continue DFS
            }
        }
    }

    // Main function to find the maximum fishes collected from any connected region
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        // Traverse each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0) // If the cell has fishes
                {
                    int cost = grid[i][j]; // Initialize the fish count
                    dfs(i, j, m, n, grid, cost); // Start DFS
                    ans = max(ans, cost); // Update maximum fishes collected
                }
            }
        }
        return ans;
    }
};
