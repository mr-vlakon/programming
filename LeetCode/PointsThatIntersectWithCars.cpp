class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int answer = 0;
        vector<int> visited(100, false);
        for (const auto &e: nums) {
            for (int i = e[0]; i <= e[1]; ++i) {
                visited[i - 1] = true;
            }
        }
        return count(visited.begin(), visited.end(), true);
    }
};

int main()
{

  
  return 0;
}
