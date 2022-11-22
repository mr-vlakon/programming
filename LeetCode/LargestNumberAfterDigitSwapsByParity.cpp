class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        priority_queue<char> pqEven;
        priority_queue<char> pqOdd;
        for (int i = 0; i != s.size(); ++i) {
            if ((s[i] - '0') % 2 == 0) {
                pqEven.push(s[i]);
            } else {
                pqOdd.push(s[i]);
            }
        }
        string result;
        for (int i = 0; i != s.size(); ++i) {
            if (( s[i] - '0') % 2 == 0) {
                auto top = pqEven.top();
                result += top;
                pqEven.pop();
            } else {
                auto top = pqOdd.top();
                result += top;
                pqOdd.pop();
            }
        }
        return stoi(result);
    }
};

int main() {
  
  
  
  return 0; 
}
