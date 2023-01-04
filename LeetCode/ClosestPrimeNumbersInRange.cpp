class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> s;
        vector<int> answer = {-1, -1};
        int min = 100000;
        while(left <= right) {
            if (left > 10) {
                if ((left % 2) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                } else if ((left % 3) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                } else if ((left % 4) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                } else if ((left % 5) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                }  else if ((left % 6) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                }  else if ((left % 7) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                }  else if ((left % 8) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                }  else if ((left % 9) == 0) {
                    ++left;
                    if (left > right)
                        break;
                    continue;
                }
                            
            }
            int e = left;
            unordered_map<int, int> um;
            bool status = true;
            if (e > 1) {
                for (int i = 2; (i * i) <= e; ++i) {
                    while ((e % i) == 0) {
                            if (um[i] == 0) {
                                status = false;
                                break;
                            }
                            e /= i;
                    }
                    if (!status)
                        break;
                }
                if (status) {
                    s.push_back(left);
                    if (s.size() > 1 && abs(s[s.size() - 2] - s.back()) < min) {
                        min = abs(s[s.size() - 2] - s.back());
                        answer = {s[s.size() - 2], s.back()};
                        if (min <= 2) {
                            break;
                        }
                        
                        
                    }
                }
            }
            ++left;
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
