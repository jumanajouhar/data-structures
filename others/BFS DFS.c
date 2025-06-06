#include<stdio.h>

#include<stdlib.h>
#define MAX 5
void BFS(int adj[][MAX],int visited[],int start){
    int queue[MAX], i,k,rear=-1,front=-1;
    for(k=0;k<MAX;k++){
        visited[k]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;
    while(rear>=front){
        start=queue[front++];
        printf("%c-",start+65);
        for(i=0;i<MAX;i++){
        if(adj[start][i]&&visited[i]==0){
            queue[++rear]=i;
            visited[i]=1;
        }
    }
    }
}
void DFS(int adj[][MAX],int visited[],int start){
    int stack[MAX],top=-1,i,k;
    for(k=0;k<MAX;k++){
        visited[k]=0;
    }
    stack[++top]=start;
  
    visited[start]=1;
    while(top!=-1){
        start=stack[top--];
        printf("%c-",start+65);
        for(i=0;i<MAX;i++){
        if(adj[start][i]&&visited[i]==0){
            stack[++top]=i;
            visited[i]=1;
            break;
        }
        }
}
}
int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j;
    int choice,size;
    while(1){
        printf("enter choice 1:enter values of graph,2:BFS,3:DFS,4:exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the adjacemcey matrix");
            for(i=0;i<MAX;i++){
                for(j=0;j<MAX;j++){
                    scanf("%d",&adj[i][j]);
                    
                    
                }
            }
            break;
            case 2:
            printf("BFS traversal is");
            BFS(adj,visited,0);
            break;
            case 3:
            printf("DFS traversal is");
            DFS(adj,visited,0);
            break;
            case 4:
            exit(0);
            default:
            printf("invalid ");
        }
    }
}