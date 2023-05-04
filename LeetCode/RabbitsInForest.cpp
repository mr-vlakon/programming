class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        for (const auto &e: answers) {
            um[e]++;
        }
        int answer = 0;
        for (const auto &e: um) {
            answer += (e.first + 1)*ceil((static_cast<double>(e.second) /(e.first + 1)));
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
