public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> index;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 1)
                index.push_back(i);
        }
        for (int i = 0; i < static_cast<int>(index.size()) - 1; ++i) {
            if (!(index[i + 1] - index[i] > k))
                return false;
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;  
}
