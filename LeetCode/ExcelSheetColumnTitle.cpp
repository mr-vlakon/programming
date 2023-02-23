class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer;
        while (columnNumber) {
            answer.push_back(((columnNumber % 26 == 0) ? 26 : (columnNumber % 26)) + 64);
            columnNumber -= (((columnNumber % 26) == 0) ? 26 : (columnNumber % 26)); 
            columnNumber /= 26;
        }
        reverse(answer.begin(), answer.end());
        return answer;        
    }
};

int main() {
  
  
  return 0;  
}
