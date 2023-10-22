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