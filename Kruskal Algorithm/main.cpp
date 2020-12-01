#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class Edge{
public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int findParent(int v,int *parent)
{
    if(parent[v]==v)
    return v;
    else findParent(parent[v],parent);
}
void kruskal(Edge *input,int n,int E)
{
    sort(input,input+n,compare);
    Edge  *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0,i=0,mst=0;
    while(count != n-1)
    {
        Edge currentEdge=input[i];
        ///union find Algorithm
        ///check of we can add the edge in MST or NOT
        ///cycle finding with checking the currrentEdge parent
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent!=destParent)
        {
            output[count]=currentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    cout<<"The Shortest Path is: "<<endl;
        for(int i=0;i<n-1;i++)
        {
            if(output[i].source<output[i].dest)
            {
                cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
            }
            else
            {
              cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            }
             mst+=output[i].weight;
        }

    cout<<"Minimum Cost Spanning Tree is : "<<mst<<endl;
}

int main()
{
    cout << "Enter Number of Nodes & Edges"  << endl;
    int n,E;
    cin>>n>>E;
    Edge *input=new Edge[E];
    cout<<"Enter The Matrix: "<<endl;
    for(int i=0;i<E;i++)
    {
       int s,d,w;
       cin>>s>>d>>w;
       input[i].source=s;
       input[i].dest=d;
       input[i].weight=w;
    }
    kruskal(input,n,E);
    return 0;
}
