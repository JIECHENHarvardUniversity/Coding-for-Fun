//基本解题思路//

//将此问题等效成走迷宫的问题//
//利用M行N列的矩阵模拟该迷宫//
//将矩阵中每个传感器能探测到的范围设为“0”//
//将矩阵中所有传感器都不能探测到的范围设为“1”//
//设置矩阵中的入口和出口位置//
//在矩阵中的每一个entry，盗贼可以向上下左右四个相邻的entry移动//
//要求从矩阵的入口到出口搜索出一条最短路径，且使盗贼能避开所有的传感器//

//本算法使用宽度优先搜索算法，“Breadth First Search (BFS)”//
//每次搜索，BFS都从矩阵的入口开始，在矩阵的出口终止//
//BFS算法返回从入口到出口的最短路径上每一步的移动方向//
//其中上下左右分别用U, D, L, R表示//

//引用预编译头文件
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

//设置搜索到的路径所包含的步数的上限
#define path_limit 60000

//设置迷宫尺寸的上限
#define maze_limit 250

using namespace std;

int maze[maze_limit][maze_limit]; //利用maze矩阵表示该迷宫
int M, N; //定义矩阵的行数和列数 
int start_x, start_y, terminate_x, terminate_y; //设置矩阵的入口和出口位置
int next_x, next_y; //设置下一步的位置
int HEAD = 0, TAIL = 1;
int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int last[path_limit], A[path_limit], B[path_limit];
//设置path储存搜索到的路径，direction表示可以使用的方向
char path[path_limit], direction[4] = {'U','D','L','R'};
bool label[maze_limit][maze_limit];

void search(int loc);
bool verify(int loc_x, int loc_y);
void BFS();

int main()
{
    int i, j;
    printf("请输入矩阵的行数M和列数N，用空格隔开：\n");
    scanf("%d%d",&M,&N); //输入矩阵的行数和列数
    
    printf("请按行输入%d行数据，用空格隔开，值只能取0或1：\n",M);
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            scanf("%d",&maze[i][j]);
    printf("请输入入口位置的X[1,%d]和Y[1,%d]坐标，用空格隔开：\n",M,N);
    scanf("%d%d",&start_x,&start_y);
    printf("请输入出口位置的X[1,%d]和Y[1,%d]坐标，用空格隔开：\n",M,N);
    scanf("%d%d",&terminate_x,&terminate_y);
    BFS(); //调用宽度优先搜索算法
    printf("End");
}

void search(int loc)
{
    if(last[loc]!=0)
    {
        search(last[loc]);
        printf("%c-->",path[loc]);
    }
}

bool verify(int loc_x, int loc_y)
{
    if(loc_x<=M && loc_x>0 && loc_y<=N && loc_y>0)
        return(1);
    else
        return(0);
}

void BFS()
{
    int i;
    A[1] = start_x;
    B[1] = start_y;
    label[start_x][start_y] = 1;
    while(HEAD!=TAIL)
    {
        HEAD++;
        for(i=0; i<4; i++)
        {
            next_x = A[HEAD]+x[i];
            next_y = B[HEAD]+y[i];
            if(verify(next_x, next_y) && maze[next_x][next_y]==1 && label[next_x][next_y]==0)
            {
                TAIL++;
                A[TAIL] = next_x;
                B[TAIL] = next_y;
                last[TAIL] = HEAD;
                path[TAIL] = direction[i];
                label[next_x][next_y] = 1;
                if(A[TAIL]==terminate_x && B[TAIL]==terminate_y)
                {
                    search(TAIL);
                    printf("\n");
                    exit(0);
                }
            }
        }
    }
}
