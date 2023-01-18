#include <stdio.h>
#include <stdlib.h>

int v_no;

int main(){

    printf("Enter number of vertices : ");
    scanf("%d",&v_no);

    printf("\t\t\n%d\n\n",v_no);


    int vertices[v_no], visited[v_no], pre[v_no], distance[v_no];
    int matrix[v_no][v_no];
    int choice = 0, count = 0, cost = 0, a = 0, b = 0;

    printf("The vertices are :");
    for(int i = 0; i<v_no; i++){
        vertices[i] = i;
        visited[i] = 0;
        printf("%d\t",i);
    }
    printf("\n");

    for(int i = 0; i<v_no; i++)
        for(int j = 0; j<v_no; j++)
            matrix[i][j] = 9999;

    while(choice != -1){
        printf("Enter -1 to exit else enter 0 : ");
        scanf("%d", &choice);
        if(choice == -1){
            break;
        }
        else{
            printf("Enter the two vertices : ");
            scanf("%d %d", &a, &b);
            printf("Enter the cost : ");
            scanf("%d", &cost);
            matrix[a][b] = cost;
        }
    }

    for(int i=0; i<v_no; i++){
		distance[i]=matrix[0][i];
		pre[i]=0;
		visited[i]=0;
	}

    visited[0] = 1;

    while(count<v_no){

        cost = 9999;
        for(int i = 0; i<v_no; i++){
            if(distance[i]<cost && !visited[i]){
				cost = distance[i];
				a = i;
			}      
        }

        visited[a] = 1;
		for(int i = 0; i < v_no; i++){
			if(!visited[i]){
				if(cost+matrix[a][i] < distance[i]){
					distance[i] = cost+matrix[a][i];
					pre[i] = a;
				}
            }
        }

        count++;

    }

    for(int i = 0; i<v_no; i++)
		if(i!=0)
		{
			printf("\nDistance %d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			b = i;
			do
			{
				b = pre[b];
				printf("<-%d",b);
			}while(b != 0);
	}

    return 0;
}