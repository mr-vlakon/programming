class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<int> q;
        int start = -2;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i != grid.size(); ++i) 
        {
            for (int j = 0; j != grid[0].size(); ++j)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    q.push(i*grid[0].size() + j);
                    while (!q.empty())
                    {
                        auto top = q.front();
                        q.pop();
                        int x = top / grid[0].size();
                        int y = top % grid[0].size();
                        grid[x][y] = start;
                        if (visited[x][y] == true) continue;
                        visited[x][y] = true;
                        if ((x + 1) < grid.size() && visited[x + 1][y] == false && grid[x + 1][y] == 1)
                        {
                            grid[x + 1][y] = start;
                            q.push((x + 1)*grid[0].size() + y);
                        }
                       if ((x - 1) >= 0 && visited[x - 1][y] == false && grid[x - 1][y] == 1)
                        {
                            grid[x - 1][y] = start;
                            q.push((x - 1)*grid[0].size() + y);
                        }
                       if ((y + 1) < grid[0].size() && visited[x][y + 1] == false && grid[x][y + 1] == 1)
                        {
                            grid[x][y + 1] = start;
                            q.push(x*grid[0].size() + y + 1);
                        }
                       if ((y - 1) >= 0 && visited[x][y - 1] == false && grid[x][y - 1] == 1)
                        {
                            grid[x][y - 1] = start;
                            q.push(x*grid[0].size() + y - 1);
                        }
                    }
                    ++start;
                }
            }
        }
        int answer = INT_MAX;
        for (int i = 0; i != grid.size(); ++i)
        {
            for (int j = 0; j != grid[0].size(); ++j)
            {
                if (grid[i][j] == -2)
                {
                    q.push(i*grid[0].size() + j);
                }
                if (grid[i][j] >= 0)
                {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top / grid[0].size();
            int y = top % grid[0].size();
            if (grid[x][y] == -1)
            {
                continue;
            }
            if (visited[x][y] == true) continue;
            visited[x][y] = true;
            if ((x + 1) < grid.size() && grid[x + 1][y] != -2)
            {
                if (grid[x + 1][y] == -1 )
                {
                    answer = min(answer, grid[x][y]);   
                }
                else
                {
                    if (grid[x][y] >= 0)
                    {
                        grid[x + 1][y] = min(grid[x][y] + 1, grid[x + 1][y]);
                    }
                    else
                    {
                        grid[x + 1][y] = min(1, grid[x + 1][y]);    
                    }
                    q.push((x + 1)*grid[0].size() +  y);
                
                }
            }
            if ((x - 1) >= 0 && grid[x - 1][y] != -2)
            {
                if (grid[x - 1][y] == -1)
                {
                    answer = min(answer, grid[x][y]);   
                }
                else
                {
                    if (grid[x][y] >= 0)
                    {
                        grid[x - 1][y] = min(grid[x][y] + 1, grid[x - 1][y]);
                    }
                    else
                    {
                        grid[x - 1][y] = min(1, grid[x - 1][y]);    
                    }
                    q.push((x - 1)*grid[0].size() +  y);
                
                }
            }
            if ((y + 1) < grid[0].size() && grid[x][y + 1] != -2)
            {
                if (grid[x][y + 1] == -1)
                {
                    answer = min(answer, grid[x][y]);   
                }
                else
                {
                    if (grid[x][y] >= 0)
                    {
                        grid[x][y + 1] = min(grid[x][y] + 1, grid[x][y + 1]);
                    }
                    else
                    {
                        grid[x][y + 1] = min(1, grid[x][y + 1]);    
                    }
                    q.push(x*grid[0].size() +  y + 1);
                }
            }
            if ((y - 1) >= 0 && grid[x][y - 1] != -2)
            {
                if (grid[x][y - 1] == -1)
                {
                    answer = min(answer, grid[x][y]);   
                }
                else
                {
                    if (grid[x][y] >= 0)
                    {
                        grid[x][y - 1] = min(grid[x][y] + 1, grid[x][y - 1]);
                    }
                    else
                    {
                        grid[x][y - 1] = min(1, grid[x][y - 1]);    
                    }
                    q.push(x*grid[0].size() +  y - 1);
                }
            }
        }
        return answer;
    }
};

int main()
{



  return 0;
}
