class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i<N;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1;j<N;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int m = j+1;
                int n = N-1;
                while(m<n){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[m];
                    sum += nums[n];
                    if(sum ==  target){
                        vector<int> vec = {nums[i],nums[j],nums[m],nums[n]};
                        ans.push_back(vec);
                        m++; n--;

                        while(m<n && nums[m]==nums[m-1]) m++;
                        while(m<n && nums[n]==nums[n+1]) n--;
                    }
                    else if(sum<target) m++;
                    else n--;
                }
            }
        }
        return ans;
    }
};
