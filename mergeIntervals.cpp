class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int i=1;
            int n=intervals.size();
            sort(begin(intervals), end(intervals));
            vector<vector<int>> result;
            result.push_back(intervals[0]);
            while(i<n){
                //here we used '=' because we are also considering the condition of equal intervals index, like-{1,5}, {5,7} will result in {1,7}.
              if(intervals[i][0]<=result.back()[1]){//means ye overlapping intervals hai
                result.back()[1]=max(result.back()[1], intervals[i][1]);
                //Here we do not need to find minimum as we had alredy sorted the intervals.
              }else{
                result.push_back(intervals[i]);
              }
              i++;  
            }
            return result;
        }
    };