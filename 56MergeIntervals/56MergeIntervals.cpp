/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-28 
# Last Modified: 2019-1-28
#          Link: https://leetcode.com/problems/merge-intervals/
#         title: 56	Merge Intervals
#   Description: ---
#	  Given a collection of intervals, merge all overlapping intervals.
#
#	  Example 1:
#
#	  Input: [[1,3],[2,6],[8,10],[15,18]]
#	  Output: [[1,6],[8,10],[15,18]]
#	  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
#	  Example 2:
#
#	  Input: [[1,4],[4,5]]
#	  Output: [[1,5]]
#	  Explanation: Intervals [1,4] and [4,5] are considered overlapping.

***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


 //Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };




class Solution {
public:
  static bool cmp(const Interval & a,const Interval & b){
 	return a.start < b.start; // a.start - b.start will wrong
 }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> result;
        int idx = 0;

        while(idx < intervals.size()){
        	int start = intervals[idx].start;
            int end = intervals[idx].end;
            idx++;
        	while(idx < intervals.size() && end >= intervals[idx].start ){
        		end = std::max(end,intervals[idx++].end);
        	}
        	result.push_back(Interval(start,end));
        	
        }
        return result;
    }
};

int main(){
	Solution ss;
	vector<Interval> intervals;
	intervals.push_back(Interval(2,3));
	intervals.push_back(Interval(1,4));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));

	vector<Interval> res = ss.merge(intervals);
	for(int i=0;i<res.size();i++){
		cout<<res[i].start<<","<<res[i].end<<"\t";
	}

}