#include<stdio.h>
void DFS(int i,int matrix[10][10],int visited[10])
{
	printf("%c ==> ",(i%26)+65);
	visited[i]=1;
	for(int j=0;j<10;j++)
		if(!visited[j]&&matrix[i][j]==1)
			DFS(j,matrix,visited);
}
int main()
{
	int matrix[10][10]={{0,1,1,1,0,0,0,0,0,0},{1,0,0,1,0,1,1,1,0,0},{1,0,0,1,1,1,1,0,0,0},{1,1,1,0,0,0,0,1,0,0},{0,0,1,0,0,0,0,0,0,1},{0,1,1,0,0,0,0,0,1,0},{0,1,1,0,0,0,0,1,1,0},{0,1,0,1,0,0,1,0,0,0},{0,0,0,0,0,1,1,0,0,0},{0,0,0,0,1,0,0,0,0,0}};
	int visited[10];
	for(int i=0;i<10;i++)
		visited[i]=0;
	DFS(0,matrix,visited);
	printf("\n");
	return 0;
}
