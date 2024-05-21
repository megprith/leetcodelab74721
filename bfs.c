#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

int arr[5], front = -1, rear = 0;
void enque(int val)
{
    if (front == -1)
        front = 0;

    arr[rear] = val;
    rear++;
}
void deque()
{
    front++;
}
int top()
{
    return arr[front];
}
bool isEmpty()
{
    if (front == rear)
        return 1;
    return 0;
}
void graph(int a[5][5])
{
    int i, j;
    for (int i = 0; i < 5; i++)
    {
        printf("%d -> ", i);
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}

void bfs(int a[5][5], int visited[5])
{
    int i = 0, j = 0;
    printf("enter the start point \n");
    int start;

    scanf("%d", &start);
    enque(start);
    while (!isEmpty())
    {
        int current = top();
        deque();
        printf("%d ", current);
        visited[current] = 1;
        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == 0 && a[current][i] == 1)
            {
                enque(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i = 0;
    int j = 0;
    int visited[5] = {0, 0, 0, 0, 0};
    int list[5][5] = {
        0, 1, 1, 1, 0,
        1, 0, 0, 1, 0,
        1, 0, 0, 1, 0,
        1, 1, 1, 0, 1,
        0, 0, 0, 1, 0};
    graph(list);
    printf("the bfs of the graph is: \n");
    bfs(list, visited);

    return 0;
}