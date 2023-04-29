#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int good=0;
    int bad=0;
    int time=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]==1)good++;
            else if(grid[i][j]==2)bad++;
        }
    }
    if(!good)return 0;
    if(!bad) return -1;
    int goods=good;
    while(goods){
        time++;
        for(int i=0;i<gridSize;i++){
            for(int j=0;j<gridColSize[0];j++){
                if(grid[i][j]==2){
                    if(i != gridSize - 1&&grid[i+1][j]==1){
                        grid[i+1][j]=3;
                        goods--; 
                    }
                    if(i&&grid[i-1][j]==1){
                        grid[i-1][j]=3;
                        goods--;
                    }
                    if(j != gridColSize[0] - 1 &&grid[i][j+1]==1){
                        grid[i][j+1]=3;
                        goods--;
                    }
                    if(j&&grid[i][j-1]==1){
                        grid[i][j-1]=3;
                        goods--;
                    }
                }
            }
        }
        for(int i=0;i<gridSize;i++)
            for(int j=0;j<gridColSize[0];j++)
                if(grid[i][j]==3)grid[i][j]=2;
        if(goods == good) return -1;
        good = goods;
    }
    return time;
}
int main(){
	int gridSize=3;
	int** grid;
	grid=(int**)malloc(3*sizeof(int*));
	for(int i=0;i<3;i++)grid[i]=(int*)malloc(3*sizeof(int));
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>grid[i][j];
	int* gridColSize=grid[0];
	cout<<orangesRotting(grid,gridSize,gridColSize)<<endl;
}
