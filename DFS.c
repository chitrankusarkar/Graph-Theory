void DFS(int u) {
    status[u]=1;
    cout << u+1 << endl;
    for(int i=0; i<size; i++) {
        if(status[i] == 0 && ajc[i][u])
            DFS(i);
    }
}
