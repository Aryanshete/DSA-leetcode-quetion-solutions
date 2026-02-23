#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // to store number -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // check if complement exists in map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};  // found pair
            }
            
            // store current number with its index
            mp[nums[i]] = i;
        }
        
        return {};  // no solution found 
    }
};