#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int rank, size;

  MPI_Init(NULL, NULL);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if(rank ==0) {
    // tis master node
    int x = 2;
    MPI_Send(&x, 1, MPI_INT, 1, 3, MPI_COMM_WORLD);
    printf("Master node sending a signal: %d to the node 1\n", x);
  } else if(rank == 1) {
    // tis slave node
    int x, number_amount;
    MPI_Status status;
    MPI_Recv(&x, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
    printf("Slave node recieving a signal from master node 0: %d\n", x);

    // getting the count - should be 1
    MPI_Get_count(&status, MPI_INT, &number_amount);
    printf("Amount of signals recieved is: %d\n", number_amount);
  }

  MPI_Finalize();
  return 0;
}
