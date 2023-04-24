class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int first = 0;
        int second = 0;
        while ((first != firstList.size() && second != secondList.size())) {
            if (firstList[first][1] <= secondList[second][1]) {
                if (firstList[first][1] >= secondList[second][0]) {
                    answer.push_back({max(firstList[first][0], secondList[second][0]), 
                    firstList[first][1]});
                }
                first++;
            } else {
                if ((secondList[second][0] >= firstList[first][0]) || (secondList[second][1] >= firstList[first][0])) {
                    answer.push_back({max(firstList[first][0], secondList[second][0]), min(firstList[first][1], secondList[second][1])});
                }
                ++second;
            }
        }
        return answer;
  }
};

int main() {
  
  
  
  
  return 0;  
}
