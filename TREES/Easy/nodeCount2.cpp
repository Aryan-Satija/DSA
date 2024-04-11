// CODING NINJAS -> Number Of Nodes
int powOf2(int N){
    return (1 << N);
}
int numberOfNodes(int N){
    return (powOf2(N-1));
}