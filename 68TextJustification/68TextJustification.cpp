/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-1-29 
# Last Modified: 2019-1-29
#          Link: https://leetcode.com/problems/text-justification/
#         title: 68	Text Justification
#   Description: ---

***********************************************/
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <string> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"\n";
	}
	cout << endl;
}

// My wrong code, it need work more hard
// class Solution {
// public:
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//     	int n = words.size();
//     	vector<int> len(n,0);
//     	vector<string> res;
//     	for(int i=0;i<n;i++){
//     		len[i] = words[i].size();
//     		cout << words[i] <<"\t"<<len[i] <<endl;
//     	}
//     	cout <<endl;
//     	int idx = 0;
//     	while(idx < n){
//     		int oldIdx = idx;
//     		int sum = 0;
//     		while(idx < n){   			
//     			if(sum + len[idx] + idx -oldIdx > maxWidth){
//     				break;
//     			}
//     			sum += len[idx] ;
//     			idx++;
//     		}

//   			int blankSize = (maxWidth-sum) / (idx -oldIdx-1);
//   			int moreSize = (maxWidth-sum) % (idx -oldIdx-1);

//     		cout <<"sum\t" << sum <<endl; 
//     		cout << "idx\t" << idx <<endl;;
//     		// system("pause");
//     		string s = "";
//     		if(idx == n-1){
//     			for(int i=oldIdx;i<idx;i++){
//     				s += words[i];
//     				if(i != idx-1){
//     					s += ' ';   					
//     				}
//     				res.push_back(s);
//     			}
//     		}
//     		else{
//     			for(int i=oldIdx;i<idx;i++){
//     			    s += words[i];
//     			    if(i != idx-1){
//     				    s += string(blankSize+1,' ');
//     				    if(i-oldIdx+1 <= moreSize){ s+=' ';}
//     			    }
//     		    }   
//     		    res.push_back(s);
//     		}
    		
//     	}

//         return res;
//     }
// };

#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    
    int len=0;
    int start = 0;
    int end = 0;
    double space =0;
    bool lastLine = false;
    for (int i=0; i<words.size(); i++){
        len += words[i].size();
        if (len + i - start > L || i == words.size()-1) {
            //remove the last one
            if (len + i - start > L) {  
                len -= words[i].size();
                end = i-1;
                lastLine = false;
            }else{
                end = i;
                lastLine = true;
            }
            //calculate the space number
            space = L - len;
            int mspace;
            int extra;
            if (lastLine){
                mspace = 1;
                extra = 0;
            } else {
                mspace = floor(space/(end-start));
                extra = space - mspace * (end-start);
            }

            string line = words[start];
            for (int j=start+1; j<=end; j++) {
                for(int k=0; k<mspace && space>0; k++, space--) {
                    line += " ";
                }   
                if (j-start-1 < extra){
                    line += " ";
                    space--;
                } 
                line += words[j];
            }
            //add the rest space
            if (space>0){
                for(; space>0; space--) {
                    line += " ";
                }
            }
            result.push_back(line);
            start = i;
            i = end;
            len = 0;
        } 
    }

    return result;
}

int main(){
	vector<string>  words{"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> words2{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> res = fullJustify(words,maxWidth);
    printVector(res);
}