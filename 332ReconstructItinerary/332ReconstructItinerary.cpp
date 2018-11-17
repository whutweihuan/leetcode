/***********************************************
#
#      Filename: 332ReconstructItinerary.cpp
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2018-11-17 23:03:12
# Last Modified: 2018-11-17 23:03:12
#          Link: https://leetcode.com/problems/reconstruct-itinerary/
#   Description: ---
#   Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
#   
#   Note:
#   
#   If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
#   All airports are represented by three capital letters (IATA code).
#   You may assume all tickets form at least one valid itinerary.
#   Example 1:
#   
#   Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
#   Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
#   Example 2:
#   
#   Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
#   Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
#   Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
#                But it is larger in lexical order.
***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

using namespace std;

//error code
//note: not every site is unique
//but need visit every route,so you cannot push at first
//class Solution {
//public:
//    vector<string> findItinerary(vector<pair<string, string>> tickets) {
//       map<string, set<string> > m;
//       vector<string> res;  
//       for(auto e : tickets){
//           m[e.first].insert(e.second);
//       }
//       string st = "JFK";
//       res.push_back(st);
//       int len = m.size();
//       while(res.size() < len){
//           string next = st;
//           st = *m[st].begin();
//           res.push_back(st);
//           m[next].erase(m[next].begin());
//       }
//
//       return res;
//    }
//};


class Solution {
public:
    //dfs
    void travel(string& start, unordered_map<string, multiset<string>>& map, vector<string>& result) {
        while (map[start].size() > 0 ) {
            string next = *(map[start].begin());
            map[start].erase(map[start].begin());
            travel(next, map, result);
        }
        result.insert(result.begin(), start);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> map;
        for(auto t : tickets) {
            map[t.first].insert(t.second);
        }
        vector<string> result;
        string start = "JFK";
        travel(start, map, result);
        return result;
    }
};

int main(){
    Solution ss;
    vector<pair<string,string>> tickets;
    //tickets.push_back(make_pair("MUC", "LHR"));
    //tickets.push_back(make_pair("JFK", "MUC"));
    //tickets.push_back(make_pair("SFO", "SJC"));
    //tickets.push_back(make_pair("LHR", "SFO"));
    tickets.push_back(make_pair("JFK","ATL"));
    tickets.push_back(make_pair("ORD","PHL"));
    tickets.push_back(make_pair("JFK","ORD"));
    tickets.push_back(make_pair("PHX","LAX"));
    tickets.push_back(make_pair("LAX","JFK"));
    tickets.push_back(make_pair("PHL","ATL"));
    tickets.push_back(make_pair("ATL","PHX"));

    for(auto e : ss.findItinerary(tickets)){
        cout<<e<<"\t";
    }
    

}
