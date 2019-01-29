/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/sqrtx/
#         title: 69	Sqrt(x)
#   Description: ---
# 	  Implement int sqrt(int x).
# 	  
# 	  Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
# 	  
# 	  Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
# 	  
# 	  Example 1:
# 	  
# 	  Input: 4
# 	  Output: 2
# 	  Example 2:
# 	  
# 	  Input: 8
# 	  Output: 2
# 	  Explanation: The square root of 8 is 2.82842..., and since 
# 	               the decimal part is truncated, 2 is returned.
# 	  
***********************************************/
#include <iostream>

using namespace std;
// int sqrt(int x) {
//     if (x <=0 ) return 0; 
//     //the sqrt is not greater than x/2+1
//     int e = x/2+1;
//     int s = 0;
//     // binary search
//     while ( s <= e ) {
//         int mid = s + (e-s)/2;
//         long long sq = (long long)mid*(long long)mid;
//         if (sq == x ) return mid;
//         if (sq < x) {
//             s = mid + 1;
//         }else {
//             e = mid - 1;
//         }
//     }
//     return e; 
// }

// // http://en.wikipedia.org/wiki/Newton%27s_method
// // https://www.matongxue.com/madocs/205.html
// xn+1 = xn - f(x)/f'(x)
// 对于 x^0.5 
// xn+1 = xn - 2x; 不收敛

// f(x) = x^0.5 - 8 //求8的平方根
// int sqrt_nt(int x) {
//     if (x == 0) return 0;
//     double last = 0;
//     double res = 1;
//     while (res != last)
//     {
//         last = res;
//         res = (res + x / res) / 2;
//     }
//     return int(res);
// }

class Solution {
public:
    int mySqrt(int x) {
        if(!x){return 0;}
    	long long low = 1,high = x;
        for(int i=0;i<100;i++){
        	long long mid = low + (high-low)/2;
        	if(mid <= x/mid){  //mid*mid <= x 可能会溢出
        		low = mid;
        	}else{
        		high = mid;
        	}
        }
        return low;
    }
};

int main(){
	Solution ss;
	cout << ss.mySqrt(10000)<<endl;
}