class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        size_t i = right - left + 1;
        while(i) {
            vector<int> q;
            int curr = left;
            while(curr) {
                int j = 0;
                j = curr % 10;
                curr = curr / 10;
                q.push_back(j);
            }
            bool status = true;
            for (const auto &e: q) {
                if(e == 0 || left % e != 0)
                    status = false;
            }
            if (status)
                result.push_back(left);
            left++;
            --i;
        }
        return result;
    }
};

int main()  {
  
  return 0;  
}
