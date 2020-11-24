//深度遍历
void DFS(AMGGraph G,int v){ //G为邻接矩阵，v为起始定点
    cout<<v; visited[v]=true; //当前定点被访问
    for(w = 0，w< G.vexnum;w++ )
       if((G.arcs[v][w]!=0)&&(!visited[w]))
            DFS(G,j)
}

//广度遍历
void BFS(Graph g,int v){
  count<<v,visited[v]=true;
  InitQueue(Q);
  EnQueue(Q,v)
  while(!QueueEmpty(Q)){
      DeQueue(Q,u);
      for(w=FirstAdjVex(G,u);w>0;w=NextAdjVex(G,u,w)) //找邻接点，从每条弧依次寻找
      if(!visited[w]){//如果没有访问过，节点入队
          cout<<w;visited[w]=true;Enqueue(Q,w);
      }
  }
}