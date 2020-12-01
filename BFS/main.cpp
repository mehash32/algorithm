#include<bits/stdc++.h>

using namespace std;

int visited[10];
int vertex[10][10];

void BFS();

int main()
{
    int edge;
    cout<<"Enter no of Edges :\n";
    cin>>edge;
    cout<<"enter nodes:"
        int index,j;
    for(int i=0; i<edge; i++)
    {
        cin>>index>>j;
        vertex[index][j] = 1;
        vertex[j][index] = 1;
    }

}
void BFS()
{
    queue<int> que;
    que.push(0);
    visited[0] = 1;
    while(! que.empty())
    {
        int v = que.front();
        for(int i=0; i<10; i++)
        {
            if(vertex[v][i] == 1)
                if(visited[i] == 0)
                {
                    visited[i] = 1;
                    que.push(i);
                }
        }
        cout<<v<<" ";
        que.pop();
    }
}
