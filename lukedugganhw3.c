#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {



int size, rank, a, b;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

srand(rank);
int num = ((rand() % (9)+1));
if (num%2==0)
  num+=1;


MPI_Scan(&num, &b, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
printf("Process %d is asking for %d and will recieve the array portion between index %d-%d\n", rank, num, b-num+1, b);


MPI_Finalize();
return 0;
}
