class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int answer = 0;
        int prevP = 0;
        int prevM = 0;
        int prevG = 0;
        for (int i = 0; i != garbage.size(); ++i) {
            unordered_map<char, int> um;
            for (const auto &e: garbage[i]) {
                ++um[e];
            }
            if (um['P'] != 0) {
                answer += um['P'] + prevP;
                prevP = 0;
            }
            if (um['M'] != 0) {
                answer += um['M'] + prevM;
                prevM = 0;
            }
            if (um['G'] != 0) {
                answer += um['G'] + prevG;
                prevG = 0;
            }
            if (i < travel.size()) {
                prevP += travel[i];
                prevG += travel[i];
                prevM += travel[i];
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
