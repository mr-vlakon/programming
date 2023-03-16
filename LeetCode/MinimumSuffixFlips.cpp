class Solution {
public:
    int minFlips(string target) {
        int answer = 0;
        auto it = find(target.cbegin(), target.cend(), '1');
        if (it == target.cend()) {
            return 0;
        }
        for (int i = (it - target.cbegin() + 1); i != target.size(); ++i) {
            if (target[i] != target[i - 1]) {
                answer++;
            } 
        }
        return answer + 1;
    }
};

int main() {
  
  
  
  return 0;  
}
