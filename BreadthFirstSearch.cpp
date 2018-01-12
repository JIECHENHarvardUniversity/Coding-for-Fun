//this program is developed to solve the maze navigation problem//

//a matrix with M rows and N columns is defined to simulate the maze//
//"0" is used to represent the obstacles//
//"1" is used to represent the path//
//set the start point and end point of the matrix//
//in each entry of the maze, the agent can move up, down, left, and right//
//the program is required to search for the shortest path from the start point to the end point//

//the "Breadth First Search (BFS)" has been deployed//
//the BFS will startfrom the start point and end once the end point has been reached//
//BFS returns the shortest path from the start point to the end point//
//up, down, left, and right are represented by U, D, L, and R, respectively//

//include the head files
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

//set the limit of iterations for the searching algorithm
#define path_limit 60000

//set the limit of the size of the maze
#define maze_limit 250

using namespace std;

int maze[maze_limit][maze_limit]; //define the matrix representing the maze
int M, N; //define the numbers of rows and columns in the matrix 
int start_x, start_y, terminate_x, terminate_y; //define the start point and end point in the matrix
int next_x, next_y; //define the coordinate of the next step
int HEAD = 0, TAIL = 1;
int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int last[path_limit], A[path_limit], B[path_limit];
//define the path to store the searched path by the BFS algorithm
char path[path_limit], direction[4] = {'U','D','L','R'};
bool label[maze_limit][maze_limit];

void search(int loc);
bool verify(int loc_x, int loc_y);
void BFS();

int main()
{
    int i, j;
    printf("请输入矩阵的行数M和列数N，用空格隔开：\n");
    scanf("%d%d",&M,&N); //input the numbers of rows and columns of the matrix
    
    printf("请按行输入%d行数据，用空格隔开，值只能取0或1：\n",M);
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            scanf("%d",&maze[i][j]);
    printf("请输入入口位置的X[1,%d]和Y[1,%d]坐标，用空格隔开：\n",M,N);
    scanf("%d%d",&start_x,&start_y);
    printf("请输入出口位置的X[1,%d]和Y[1,%d]坐标，用空格隔开：\n",M,N);
    scanf("%d%d",&terminate_x,&terminate_y);
    BFS(); //the BFS algorithm is called
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
