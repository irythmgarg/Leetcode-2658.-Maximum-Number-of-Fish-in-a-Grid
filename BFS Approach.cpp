// Author: Ridham Garg
// Description: This code finds the maximum sum of fish that can be collected from any connected water body in a grid.
// Movement is allowed in four directions: up, down, left, right, using Breadth-First Search (BFS).

class Solution {
public:
    // Define possible movement directions: down, left, up, right
    vector<vector<int>> directions = {{1,0}, {0,-1}, {-1,0}, {0,1}};

    // Breadth-First Search (BFS) to collect fishes from connected cells
    void bfs(int i, int j, int m, int n, vector<vector<int>>& grid, int &cost)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = 0; // Mark the starting cell as visited by setting it to 0

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            // Explore all four directions
            for (auto direction : directions)
            {
                int newi = top.first + direction[0];
                int newj = top.second + direction[1];

                // Check if the new cell is within bounds and has fishes
                if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] > 0)
                {
                    cost += grid[newi][newj]; // Add fishes from the neighboring cell
                    grid[newi][newj] = 0; // Mark neighboring cell as visited
                    q.push({newi, newj}); // Add the neighboring cell to the queue
                }
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
                    bfs(i, j, m, n, grid, cost); // Start BFS
                    ans = max(ans, cost); // Update maximum fishes collected
                }
            }
        }
        return ans;
    }
};
