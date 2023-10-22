//First method


lass Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(k==0) return 0;
        vector<int> copy(nums), verify;
        int sum = 0, result=0;
         sort(copy.begin(),copy.end());
        for(auto i  = 0; i< copy.size();i++){
            if(copy[i]>k) break;
            sum = copy[i];
            verify.push_back(copy[i]);
            for( auto j = i +1; j < copy.size(); j++){
                sum += copy[j];
                if(sum>k) break;
                verify.push_back(sum);
            }
            sum = 0;
        }

        for(auto l : verify)
            if(l==k) result++;
        return result;
    }
};


//Second method

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(k==0) return 0;
        vector<int> copy=nums, verify;
        int sum = 0, result=0;
         sort(copy.begin(),copy.end());
        for(auto i  = 0; i< copy.size();i++){
            sum = copy[i];
            verify.push_back(copy[i]);
            for( auto j = i +1; j < copy.size(); j++){
                sum += copy[j];
                verify.push_back(sum);
            }
        }
        for(auto l : verify)
            if(l==k) result++;
        return result;
    }
};


//Got method

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(!k) return 0;
        unordered_map<int,int> nums_map;
        int count = 0, sum = 0;
        nums_map[sum]=1;
        for(auto num : nums){
            sum += num;
            if(nums_map.find(sum - k)!=nums_map.end())
                count += nums_map[sum-k];
            nums_map[sum]++;
        }
        return count;
    }
};