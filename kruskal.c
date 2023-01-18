#include <stdio.h>
#include <stdlib.h>

int v_no;

int find(int arr[], int x){
    while(arr[x]){
        x = arr[x];
    }
    return x;
}

int cycle_checker(int arr[], int x, int y){
    x = find(arr, x);
    y = find(arr, y);
    if(x != y){
        arr[y] = x;
        return 1;
    }
    return 0;
}

int main(){

    printf("Enter number of vertices : ");
    scanf("%d",&v_no);

    printf("\t\t\n%d\n\n",v_no);


    int vertices[v_no], parent[v_no];
    int matrix[v_no][v_no];
    int choice = 0, count = 1, cost = 0, tcost = 0, a = 0, b = 0;

    printf("The vertices are :");
    for(int i = 0; i<v_no; i++){
        vertices[i] = i;
        parent[i] = 0;
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

    while(count<v_no){

        cost = 9999;
        for(int i = 0; i<v_no; i++){
            for(int j = 0; j<v_no; j++){
                if(matrix[i][j] < cost){
                    cost = matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if(cycle_checker(parent, a, b)){
            printf("\n Edge %d:(%d %d) cost:%d",count++,a,b,cost);
			tcost+=cost;
        }

        matrix[a][b] = 9999;
        matrix[b][a] = 9999;

    }

    printf("\n Minimun cost=%d",tcost);

    return 0;
}