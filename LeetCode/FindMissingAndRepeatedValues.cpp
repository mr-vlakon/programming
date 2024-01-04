class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> answer(2, 0);
        unordered_map<int, int> hash;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0;j != grid[0].size(); ++j) {
                ++hash[grid[i][j]];
            }
        }
        for (int i = 1; i <= (grid.size()*grid.size()); ++i)
        {
            auto it = hash.find(i);
            if (it == hash.cend()) {
                answer[1] = i;
            }
            else
            {
                if (it->second == 2) 
                {
                    answer[0] = i;
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
