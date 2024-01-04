class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> shifted = mat;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        for (int i = 0; i != mat.size(); ++i) {
                int tmpK = k;
                vector<int> &shf = shifted[i];
                vector<int> newShf;
                int j = 0;
                while (tmpK) {
                    if ((i % 2) == 1) {
                        newShf.push_back(shf.back());
                        
                        for (int j = 0; j != mat[0].size() - 1; ++j) {
                            newShf.push_back(shf[j]);
                        }
                        
                    } 
                    else
                    {
                        for (int j = 1; j != mat[0].size(); ++j) {
                            newShf.push_back(shf[j]);
                        }
                        newShf.push_back(shf[0]);
                        
                                                
                    }
                    shf = newShf;
                    newShf.resize(0);
                    --tmpK;
                }
        }
        return shifted == mat;
    }
};

int main()
{



  return 0;
}
