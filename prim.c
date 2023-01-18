#include <stdio.h>
#include <stdlib.h>

int v_no;

void print_arr (int arr[v_no][v_no] )
{
    for(int i = 0 ; i < v_no ; i++)
    {
        for(int j = 0 ; j < v_no;j++)
        if(arr[i][j] == 9999)printf("- ");
        else printf("%d ",arr[i][j]);
        printf("\n\n");
    }
}

int main(){

    printf("Enter number of vertices : ");
    scanf("%d",&v_no);

    printf("\t\t\n%d\n\n",v_no);


    int vertices[v_no], visited[v_no];
    int matrix[v_no][v_no];
    int choice = 0, count = 0, cost = 0, tcost = 0, a = 0, b = 0;

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
            matrix[b][a] = cost;
        }
    }

    visited[0] = 1;

    while(count<v_no){

        cost = 9999;
        for(int i = 0; i<v_no; i++){
            for(int j = 0; j<v_no; j++){
                if(matrix[i][j] < cost && visited[i] != 0){
                    cost = matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if(visited[a] == 0 || visited[b] == 0){
            printf("\n Edge %d:(%d %d) cost:%d",count++,a,b,cost);
			tcost+=cost;
			visited[b]=1;
        }

        matrix[a][b] = 9999;
        matrix[b][a] = 9999;

        //print_arr(matrix);

    }

    printf("\n Minimun cost=%d",tcost);

    return 0;
}