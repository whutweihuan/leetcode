/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-21 
# Last Modified: 2019-1-21
#          Link: https://leetcode.com/problems/trapping-rain-water/
#         title: 42	Trapping Rain Water
#   Description: ---
#	  
#	  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
#	  *     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1       
#	  
#	  The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
#	  
#	  Example:
#	  
#	  Input: [0,1,0,2,1,0,1,3,2,1,2,1]
#	  Output: 6

***********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdio>

using namespace std;

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if(height.size()<=2){return 0;}
//         vector <int> moutain;
//         int ans = 0;
//         int addflag = 1;// 0代表当前为递减，1代表当前为递增
//         int start = height.size()-1;
//         for(int i=1;i<height.size();i++){
//         	if(height[i] < height[i-1]){
//         		start = i-1 ;
//         		break;
//         	}
//         }
       
//         // moutain.push_back(start);
//         start = std::max(1,start);
//         cout << "start   "<< start <<endl;
//         // system("pause");
//         for(int i=start;i<height.size();i++){
//         	if(addflag == 1 && height[i] < height[i-1]){
//         		// cout <<"峰值下标为  "<< i -1 <<endl;
//         		moutain.push_back(i-1);
//         		addflag = 0;
//         	}
//         	else if(addflag == 0 && height[i] > height[i-1]){
//         		addflag = 1;
//         		if(i==height.size()-1){
//         			moutain.push_back(i);
//         		}
//         	}

//         }
//         cout<<moutain.size()<<endl;

//         if(moutain.size() <2){ return 0 ;}

//         cout <<"峰值下标为  ";
//         for(int i=0;i<moutain.size();i++){
//         	cout << moutain[i] <<"\t";
//         }
//         cout<<endl;



//         int left = 0;
//         int right = moutain.size()-1;
//         while(left<right){
//         	int temp = ans;
//         	int minHeight = 0;
//         	int i ;
//         	if(moutain[left] > moutain[right]){
//         		minHeight = moutain[right];
//         		i = right -1;
//         		right = right -1;
        		
//         	}
//         	else{
//         		minHeight = moutain[left];
//         		i = left;
//         		left = left+1;
//         	}

//         	for(int j = moutain[i]+1;j<moutain[i+1];j++){
//         		if(minHeight > height[j] ){
//         			ans += abs(minHeight-height[j]);
//         		}    		
//         	}
//         	printf("第%d个和第%d个得到的结果为%d,minHeight为%d\n",i,i+1,ans -temp,minHeight );
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
    	int ans = 0;

    	// Find the max height and index
    	int maxIdx=0;
    	int maxHeight = 0;
    	for(int i=0;i<height.size();i++){
    		if( maxHeight < height [i]){
    			maxHeight = height[i];
    			maxIdx = i;
    		}
    	}

    	// Go through from left to the highest bar
    	int preHeight = 0;
    	for(int i=0;i<maxIdx;i++){
    		if(height[i]>preHeight){
    			preHeight = height[i];
    		}
    		ans += preHeight-height[i];
    	}

    	 // Go through from right to the highest bar
    	preHeight = 0;
    	for(int i=height.size()-1;i > maxIdx;i--){
    		if(height[i]>preHeight){
    			preHeight = height[i];
    		}
    		ans += preHeight-height[i];
    	}

    	return ans;
    }
};

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        /*
//        if(height.size()<3){
//            return 0;
//        }
//        vector<int> l(height.size(), 0);
//        vector<int> r(height.size(), 0);
//        for(int i=1; i<height.size()-1; ++i){
//            l[i]=max(l[i-1], height[i-1]);
//        }
//        for(int i=height.size()-2; i>0; --i){
//            r[i]=max(r[i+1], height[i+1]);
//        }
//        int res=0;
//        for(int i=1; i<height.size()-1; ++i){
//            res+=min(l[i], r[i])>height[i] ? min(l[i], r[i])-height[i] : 0;
//        }
//        return res;
//        */


//        int res=0;
//        int lmax=0, rmax=height.size()-1;
//        int l=1, r=height.size()-2;
//        while(l<=r){
//            if(height[lmax]<height[rmax]){
//                height[lmax]>height[l] ? res+=height[lmax]-height[l] : lmax=l;
//                l++;
//            }
//            else{
//                height[rmax]>height[r] ? res+=height[rmax]-height[r] : rmax=r;
//                r--;
//            }
//        }
//        return res;
//    }
//};


int main(){
	Solution ss;
	// vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> height {5,2,1,2,1,5	 };
	cout << ss.trap(height) << endl;
}