// WAP to implement Kruskal's algorithm for finding MST.
#include<iostream>
using namespace std;

int parent[20];

int find(int x)
{
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

void unionSet(int x,int y)
{
    int px=find(x);
    int py=find(y);
    parent[px]=py;
}

int main()
{
    int n,e,i,j;
    int u[50],v[50],w[50];
    int mstu[50],mstv[50],mstw[50];
    int mstEdges=0,totalWeight=0;
    int temp;

    cout<<"Enter Number of Vertices:";
    cin>>n;
    cout<<"Enter Number of Edges:";
    cin>>e;

    for(i=0;i<e;i++)
    {
        cout<<"\nEnter edge "<<i+1<<" (u v): ";
        cin>>u[i]>>v[i];
        cout<<"Enter weight of edge "<<u[i]<<" - "<<v[i]<<": ";
        cin>>w[i];
    }
    // Sort edges by weight (bubble sort)
    for(i=0;i<e-1;i++)
        for(j=0;j<e-i-1;j++)
            if(w[j]>w[j+1])
            {
                temp=w[j]; w[j]=w[j+1]; w[j+1]=temp;
                temp=u[j]; u[j]=u[j+1]; u[j+1]=temp;
                temp=v[j]; v[j]=v[j+1]; v[j+1]=temp;
            }

    // Initialize parent
    for(i=0;i<n;i++)
        parent[i]=i;

    cout<<"\nKruskal's MST Process:"<<endl;
    cout<<"\nEdges considered in order:"<<endl;

    for(i=0;i<e;i++)
    {
        int pu=find(u[i]);
        int pv=find(v[i]);

        if(pu!=pv)
        {
            mstu[mstEdges]=u[i];
            mstv[mstEdges]=v[i];
            mstw[mstEdges]=w[i];
            mstEdges++;
            totalWeight+=w[i];
            unionSet(u[i],v[i]);
            cout<<"Edge ("<<u[i]<<" - "<<v[i]<<") Weight:"<<w[i]<<" -> Added"<<endl;
        }
        else
            cout<<"Edge ("<<u[i]<<" - "<<v[i]<<") Weight:"<<w[i]<<" -> Rejected (forms cycle)"<<endl;

        if(mstEdges==n-1)
            break;
    }

    cout<<"\nMinimum Spanning Tree:"<<endl;
    cout<<"\nEdge\tWeight"<<endl;
    for(i=0;i<mstEdges;i++)
        cout<<mstu[i]<<" - "<<mstv[i]<<"\t"<<mstw[i]<<endl;
    cout<<"\nTotal MST Weight:"<<totalWeight<<endl;

    return 0;
}