class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int, int> result;
        vector<int> answer(n, 0);
        unordered_map<int, vector<int>> unor;
        for (int i = 0; i != n - 1; ++i)
        {
            unor[i].push_back(i + 1);
            unor[i + 1].push_back(i);
        }
        unor[x - 1].push_back(y - 1);
        unor[y -1].push_back(x - 1);
        int tmp = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i != n; ++i)
        {
            q.push({i, 0});
            vector<bool> visited(n, false);
            vector<int> minCost(n, INT_MAX);
            while (!q.empty())
            {
                auto top = q.front();
                q.pop();
                visited[top.first] = true;
                for (const auto &e: unor[top.first])
                {
                    if (visited[e] == false)
                    {
                        if (minCost[e] > (top.second + 1))
                        {
                            minCost[e] = top.second + 1;
                            q.push({e, top.second + 1});
                        }
                    }
                }
            }
                for (int i = 0; i != minCost.size(); ++i)
                {
                    if (minCost[i] != INT_MAX)
                    {
                        ++result[minCost[i]]; 
                    }
                }
        }
        for (const auto &e: result)
        {
            answer[e.first - 1] = e.second; 
        }
        return answer;
    }
};


int main()
{


  return 0;
}
