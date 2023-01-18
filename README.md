# DAA-CIA1


## Question

1. The shortest path from source node to all possible nodes with PRIMS, KRISKALS, DIJKSTRA'S algorithms using C/C++/Python/Java. Give a justification for the choice of the programming language.

2. Give a note of comparison regarding the performance of the algorithms. If you feel that any of the algorithms fail to find any of the required paths, give justification for the same.



## Answer

1. I used the C programming language to find the shortest path using PRIMS, KRUSKALS and DIJKSTRAS algorithm as i have experience in doing a few algorithms in C and also have been using C language for some time for all coding.

2. For this specific graph, my code for DIJKSTRAS and KRUSKALS works. The code for PRIMS does not give the complete output.


## Output

  ### Dikstra
    
    Distance 1=5
    Path=1<-4<-5<-0
    
    Distance 2=5
    Path=2<-3<-1<-4<-5<-0
    
    Distance 3=7
    Path=3<-1<-4<-5<-0
    
    Distance 4=9
    Path=4<-5<-0
    
    Distance 5=8
    Path=5<-0
    
   ### Kruskal
   
    Edge 1:(4 1) cost:-4
    Edge 2:(3 2) cost:-2
    Edge 3:(4 3) cost:-1
    Edge 4:(5 4) cost:1
    Edge 5:(0 5) cost:8
    Minimun cost=2
