class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, 0);
        int start = 0;
        int i = 0;
        while (true) {
            if (visited[(start + (i + 1)*k) % (n)] == true) {
                break;
            } else {
                visited[(start + (i + 1)*k) % (n)] = true;
            }
            visited[0] = true;
            start = (start + (i + 1)*k) % (n);
            ++i;
            
        }
        vector<int> answer;
        for (int i = 0; i != visited.size(); ++i) {
            if (visited[i] == false) {
                answer.push_back(i + 1);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
