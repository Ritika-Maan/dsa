class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        // bucket[i] stores all numbers occurring i times
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Fill buckets
        for (auto &it : freq) {
            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        // Step 4: Traverse buckets from highest frequency
        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};