//BRUTE FORCE

class solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        int i=0;
        while(i<intervals.size()){
            if(intervals[i][j]<newInterval[0]){
                i++;
            }else if(intervals[i][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }else{
                //overlap: merge them and erase the intervals ehich are merged
                newInterval[0]=min(newInterval[0], intervals[i][0]);
                newInterval[1]=max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }         
        }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

//OPTIMAL TC:O(N)
int i=0;
 vector<vector<int>> result;
 int n=intervals.size();
 while(i<n){
    if(intervals[i][1]<newInterval[0]){
        result.push_back(intervals[i]);
    }else if(intervals[i][0]>newInterval[1]){
        break;
    }else{
        //merge kro and aange dekho
        newInterval[0]=min(newInterval[0], intervals[i][0]);//0->stating point of that index
        newInterval[1]=max(newInterval[1], intervals[i][1]);//Here i->current index and 1->end point of that index
    }
    i++;
 }
 result.push_back(newInterval);
 while(i<n){
    result.push_back(intervals[i]);
    i++;
 }
 return result;