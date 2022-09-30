/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int>::iterator iter;
    vector<int> result;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums2.size(); i++){
            for(iter = nums1.begin(); iter != nums1.end(); ){
                if(nums2[i] == *iter){
                    result.push_back(nums2[i]);
                    nums1.erase(iter);
                    break;
                }
                else{
                    ++iter;
                }
            }
        }
        return result;
        
    }
};
// @lc code=end

