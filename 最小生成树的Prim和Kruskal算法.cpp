/*
MST性质，设图N={V,E},V为顶点集合，E为边集合
（u，v）是一条具有最小权值的边，其中u∈U，v∈V-U
则必存在一棵包含（u，v）的最小生成树
/

/*普里姆（Prim）算法
1.N={V,E}，TE是N的最小边集合
2.初始U={U0}，TE={}
3.在u∈U，v∈V-U的边(u,v)∈E中，找一条代价最小的边(u0，v0)
4.将（u0，v0）加入到TE中，同时v0并入U
/

/*克鲁斯卡尔算法(Kruskal)算法
1.设连通网=(V,E),令最小生成树的状态只有n个顶点而无边的非联通图T=(V，{})
，每个顶点都是一个连通分量。
2.在E中选取代价最小的边，若该边依附的顶点落在T中不同的连通分量上，将次边加入T中；
否则舍弃此边，选取下一条边
3.以此类推，直至T中所有顶点都在同一连通分量上(n-1条边)
/

/最小生成树可能不唯一/
*/

void MiniSpanTree_Prim(MGraph G)
{
    int min,i,j,k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    lowcost[0] = 0;
    adjvex=[0] = 0;
    for(i = 1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i];//lowcost[j]代表V0--Vj的距离
        adjvex[i] = 0;
    }
    for(i = 1; i < G.numVertexes; i++)
    {
        min = INFINITY;
        j = 1;k = 0;
        while (j < G.numVertexes;)
        {
            if( lowcost[j]!=0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d, %d),adjvex[k],k");
        lowcost[k] = 0;
        for(j = 1; j < G.numVertexes; j++)
        {
            if(lowcost[j]!=0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }

        }

    }

}

void MinispanningTree_Kruskal(MGraph G)
{
    int i,n,m;
    Edge edges[MAXEDGE];
    int parent[MAXVEX];
    /*此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码*/
    for(i = 0; i < G.numVertexes; i++)
        parent[i] = 0;
    for(i = 0; i < G.numEdges; i++)
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if (n!= m)
        {
            parent[n] = m;
            printf("(%d,%d) %d", edges[i].begin,
                            edges[i].end, edges[i].weight);
        }

    }

}

int Find(int *parent ,int f)
{
    while (parent[f] > 0)
        f = parent[f];
    return f;
}


