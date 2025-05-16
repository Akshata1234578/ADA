#include<stdio.h>
int main(){
int i,j,k,n,source;
int w[50][50];
int visited[20] ={0};
int minwt,total_cost=0,ev=0,sv=0;
printf("Enter the number of vertices\n");
scanf("%d",&n);
printf("Entr the weight/cost matrix: \n");
for(i=0;i<n;i++){
         for(j=0;j<n;j++){
                scanf("%d",&w[i][j]);
         }
}
printf("Enter the source vertex\n");
scanf("%d",&source);
visited[source]=1;
printf("Minimum weight/cost edge selected for spanning tree are\n");
for(i=1;i<n;i++){
     minwt=999;
        for(j=0;j<n;j++){
               if(visited[j] == 1){
                       for(k=0;k<n;k++){
                               if(visited[k]!=1 && w[j][k] != 0 && w[j][k]<minwt){
                                    sv=j;
                                    ev=k;
                                    minwt=w[j][k];
                                }
                            }
                        }
                    }
             if (minwt == 999) {
                 printf("Graph is not connected. MST not possible.\n");
                return 1;
            }
                total_cost+=minwt;
                visited[ev]=1;
                printf("%d--->%d,cost: %d\n",sv,ev,minwt);
            }
printf("Total cost of minimum spanning tree %d\n",total_cost);
return 0;
}