
/***********************************************
#
#        Author: weihuan -whutweihuan@163.com
#        Create: 2019-2-28 
# Last Modified: 2019-2-28
#          Link: 
#         title: n 皇后
#   Description: ---

***********************************************/
#include<iostream>
#include<string.h>

using namespace std;

int n;

int vis[3][1000];
int board[1000][1000];
int cnt = 0;

void dfs(int cur){
	if(cur==n){
		cnt ++;
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		board[i][j]==1?putchar('x'):putchar('o');		
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	else{
		for(int i=0;i<n;i++){
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
				vis[0][i] = 1;vis[1][cur+i] = 1;vis[2][cur-i+n] = 1;
				board[cur][i] = 1;
				dfs(cur+1);vis[0][i] = 0;vis[1][i+cur] = 0;vis[2][cur-i+n] = 0;
				board[cur][i] = 0;
			}
		}

	}

}


int main(){
	while(scanf("%d",&n)==1 && n){
		memset(vis,0,sizeof(vis));
		memset(board,0,sizeof(board));
		cnt = 0;
		dfs(0);
		cout<<cnt<<endl;
	}
	return 0;
}