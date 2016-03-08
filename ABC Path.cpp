#include<iostream>
#include<climits>
#include<queue>
#include<cstdio>
using namespace std;
char grid[51][51];
int m1[] = {-1,0,1,1,1,0,-1,-1};
int m2[] = {-1,-1,-1,0,1,1,1,0};
int h,w;
int bfs(int i,int j){
	int len[h][w]={0};
	int visited[h][w] ={0};
	len[i][j] = 1;
	int maxlen = 0;
	queue<pair<int,int>>q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();
		int x = p.first;int y = p.second;
		visited[x][y] = 1;
		for(int i=0;i<8;i++){
			int newx = x + m1[i];int newy = y + m2[i];
			if(newx>=0 && newx<h && newy>=0 && newy<w && grid[newx][newy] == grid[x][y] + 1  && !visited[newx][newy]){
				q.push(make_pair(newx,newy));
				len[newx][newy] = len[x][y] + 1;
				if(len[newx][newy]>maxlen)
					maxlen = len[newx][newy];
			}
		}	
	}
	return maxlen;
}
int main(){
	int count=0;
	while(1){
		count++;
		int ans,max_ans=0;
		scanf("%d%d",&h,&w);
		if(h==0 && w==0) break;
		for(int j=0;j<h;j++)
			scanf("%s",&grid[j]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(grid[i][j]=='A'){
					ans = bfs(i,j);
					if(ans>max_ans) max_ans = ans;
				}
		printf("Case %d: %d\n",count,max_ans);
	}
	return 0;
}
