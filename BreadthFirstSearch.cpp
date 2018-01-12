//��������˼·//

//���������Ч�����Թ�������//
//����M��N�еľ���ģ����Թ�//
//��������ÿ����������̽�⵽�ķ�Χ��Ϊ��0��//
//�����������д�����������̽�⵽�ķ�Χ��Ϊ��1��//
//���þ����е���ںͳ���λ��//
//�ھ����е�ÿһ��entry���������������������ĸ����ڵ�entry�ƶ�//
//Ҫ��Ӿ������ڵ�����������һ�����·������ʹ�����ܱܿ����еĴ�����//

//���㷨ʹ�ÿ�����������㷨����Breadth First Search (BFS)��//
//ÿ��������BFS���Ӿ������ڿ�ʼ���ھ���ĳ�����ֹ//
//BFS�㷨���ش���ڵ����ڵ����·����ÿһ�����ƶ�����//
//�����������ҷֱ���U, D, L, R��ʾ//

//����Ԥ����ͷ�ļ�
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

//������������·���������Ĳ���������
#define path_limit 60000

//�����Թ��ߴ������
#define maze_limit 250

using namespace std;

int maze[maze_limit][maze_limit]; //����maze�����ʾ���Թ�
int M, N; //������������������ 
int start_x, start_y, terminate_x, terminate_y; //���þ������ںͳ���λ��
int next_x, next_y; //������һ����λ��
int HEAD = 0, TAIL = 1;
int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int last[path_limit], A[path_limit], B[path_limit];
//����path������������·����direction��ʾ����ʹ�õķ���
char path[path_limit], direction[4] = {'U','D','L','R'};
bool label[maze_limit][maze_limit];

void search(int loc);
bool verify(int loc_x, int loc_y);
void BFS();

int main()
{
    int i, j;
    printf("��������������M������N���ÿո������\n");
    scanf("%d%d",&M,&N); //������������������
    
    printf("�밴������%d�����ݣ��ÿո������ֵֻ��ȡ0��1��\n",M);
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            scanf("%d",&maze[i][j]);
    printf("���������λ�õ�X[1,%d]��Y[1,%d]���꣬�ÿո������\n",M,N);
    scanf("%d%d",&start_x,&start_y);
    printf("���������λ�õ�X[1,%d]��Y[1,%d]���꣬�ÿո������\n",M,N);
    scanf("%d%d",&terminate_x,&terminate_y);
    BFS(); //���ÿ�����������㷨
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
