class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> counter;
        int start = 0;
        int st = 0;
        for (const auto &e: dig) {
            counter.insert(e[1]*1000 + e[0]);
        }
        int answer = 0;
        bool status = false;
        unordered_set<int>::iterator it;
        for (int i = 0; i != artifacts.size(); ++i) {
            start = artifacts[i][0];
            status = false;
            while (start <= artifacts[i][2]) {        
                st = artifacts[i][1];
                while (st <= artifacts[i][3]) {
                    it = counter.find(st*1000 + start);
                    if (it == counter.cend()) {
                        ++answer;
                        status = true;
                        break;
                    } 
                    ++st;
                }
                if (status) {
                    break;
                }
                ++start;
            }
        }
        return artifacts.size() - answer;
  }
};

int main() {
  
  
  
  
  return 0;  
}
