class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, size_t> um;
        for (const auto &e: text) {
            ++um[e];
        }
        int answer = 0;
        
        while (true) {
            if( um['b'] >= 1) {
                --um['b'];
            } else {
                break;
            }
            
            if ( um['a'] >= 1) {
                --um['a'];
            } else {
                break;
            }
            
            if ( um['l'] >= 2) {
                um['l'] -= 2;
            } else {
                break;
            }
            
            if (um['o'] >= 2) {
                um['o'] -= 2;
            } else {
                break;
            }
            
            if (um['n'] >= 1) {
                --um['n'];
            } else {
                break;
            }
            ++answer;    
        }        
        return answer;        
    }
};

int main() {
  
  
  
  return 0;  
}
