class Solution {
public:    
    string smallestNumber(string pattern) {
        size_t n = pattern.size() + 1;
        string result;
        char set[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};        
        string str;
        for (decltype(str.size()) i = 0; i != n; ++i) {
            str.push_back('1' + i);
        } 
        
        do {
            v.push_back(str);
        } while(next_permutation(str.begin(), str.end()));

        for (decltype(v.size()) i = 0; i != v.size(); ++i) {
            bool status = true;
            for (decltype(pattern.size()) j = 0; j != pattern.size(); ++j) {
                switch(pattern[j]) {
                    case 'I': {
                        if((v[i][j] - '0') >= (v[i][j + 1] - '0')) {
                            status = false;
                        }
                        break;
                    }
                    case 'D': {
                        if((v[i][j] - '0') <= (v[i][j + 1] - '0')) {
                            status = false;
                        }
                        break;
                    }
                    default:
                        break;
                }
                if (!status)
                    break;
            }
            if (status) {
                result = v[i];
                break;
            }
        }
        return result;
    }
private:
    vector<string> v;    
};

int main() {
  
  
  return 0;  
}
