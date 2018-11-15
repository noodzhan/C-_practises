#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
vector <int> E[100];
bool vis[110];
void DFS(int u)
{
	int len;
	vis[u]=1;
	printf("%d ",u);
	len=E[u].size();
	for(int i=0;i<len;++i)
		if(vis[E[u][i]]==0)
			DFS(E[u][i]);
}
void E_init()
{
	E[1].push_back(2);
	E[1].push_back(3);
	E[2].push_back(3);
	E[2].push_back(4);
	E[3].push_back(6);
	E[3].push_back(7);
	E[4].push_back(5);
	
}
int main()
{
	E_init();
	DFS(1);
	return 0;
		
}


















