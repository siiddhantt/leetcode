/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = (mat.size())*(mat[0].size());
        vector<vector<int>> tmp;
        vector<int> t, rowvec;
        int cou = 0, k = 0;
        if((r*c) != n){
            return mat;
        }
        for(int j = 0; j < mat.size(); j++){
            for(int k = 0; k < mat[0].size(); k++){
                t.push_back(mat[j][k]);
            }
        }
        for(int j = 0; j < r; j++){
            for(k = 0; k < c; k++){
                rowvec.push_back(t[cou+k]);
            }
            tmp.push_back(rowvec);
            rowvec.clear();
            cou = cou+k;
        }
        return tmp;
    }
};
// @lc code=end

