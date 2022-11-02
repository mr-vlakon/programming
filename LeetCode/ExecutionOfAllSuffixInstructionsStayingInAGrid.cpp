class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        vector<int> answer;
        for (decltype(s.size()) i = 0; i != s.size(); ++i) {
            auto startRow = startPos[0];
            auto startCol = startPos[1];
            int cnt = 0;
            
            for (decltype(s.size()) j = i; j != s.size(); ++j) {
                switch(s[j]){
                    case 'R': 
                    {
                        startCol++;
                        break;
                    }
                    case 'L':
                    {
                        startCol--;
                        break;
                    }
                    case 'U':
                    {
                        startRow--;
                        break;
                    }
                    case 'D':
                    {
                        startRow++;
                        break;
                    }
                    default:
                    {
                        break;    
                    }
                }
                if (startCol >= n || startCol < 0 || startRow >= n || startRow < 0) {
                    break;
                } else {
                    ++cnt;
                }
            }
            
            answer.push_back(cnt);
            
            
        }
        
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
