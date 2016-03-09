#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int m1[] ={1,-1,0,1,0,-1,-1,1};
int m2[] ={0,-1,1,1,-1,0,1,-1};
char mat[101][101];
int r,c;
bool valid(int newx,int newy,int x,int y){
	if(newx<0 || newy<0)
		return false;
	if(newx>=r || newy >=c)
		return false;
	return true;
}
bool bfs(int x,int y){
	char str[] ={'A','L','L','I','Z','Z','W','E','L','L'};
	int visited[r][c];
	memset(visited,0,sizeof(visited));
	int len[r][c];
	memset(len,0,sizeof(len));
	queue<pair<int,int>>q;
	len[x][y] = 1;
	visited[x][y] = 1;
	q.push(make_pair(x,y));
	while(!q.empty()){
		pair<int,int>p = q.front();
		q.pop();
		visited[p.first][p.second] = 1;
		for(int i=0;i<8;i++){
			int xx = p.first + m1[i]; int yy = p.second + m2[i];
			int l = len[p.first][p.second];
			bool res = valid(xx,yy,p.first,p.second);
			if( res && (str[l]==mat[xx][yy])&& !visited[xx][yy]){
				q.push(make_pair(xx,yy));
				len[xx][yy] = len[p.first][p.second] + 1;
				if(len[xx][yy]==10){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",&mat[i]);
		bool ans = false;
		int flag=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j]=='A'){
					ans = ans | bfs(i,j);
					if(ans){
						flag=1;
						break;
					}
				}
			}
			if(flag) break;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
