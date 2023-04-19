class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator it;
        int firstType = -1;
        int secondType = -1;
        int answer = 0;
        int consec = 1;
        int prev = -1;
        for (int i = 0; i != fruits.size(); ++i){
            it = um.find(fruits[i]);
            if (it == um.cend() && um.size() == 2) {
                answer = max(answer, um[firstType] + um[secondType]);
                if (firstType != fruits[i - 1]) {
                    um.erase(firstType);
                } else {
                    um.erase(secondType);
                }
                firstType = fruits[i - 1];
                um[firstType] = consec;
                secondType = fruits[i];
                um[secondType] = 1;
            } else if (it == um.cend() && um.size() == 0) {
                firstType = fruits[i];
                um[fruits[i]]++;
            } else if (it == um.cend() && um.size() == 1) {
                secondType = fruits[i];
                um[fruits[i]]++;
            } else {
                um[fruits[i]]++;
            }
            consec = (prev == fruits[i]) ? (consec + 1) : 1;
            prev = fruits[i];
        }
        answer = max(answer, um[firstType] + um[secondType]);
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
