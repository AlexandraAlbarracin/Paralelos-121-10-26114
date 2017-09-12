#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int rank, size,state;
	int pelota = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	state = rank;
	while(pelota < 9){
		if(state == 1){
			pelota+=1;
			printf("Soy proceso %d y la pelota %d\n",rank, pelota);
			MPI_Send(&pelota,1,MPI_INT,(rank+1)%2,0,MPI_COMM_WORLD);
			
			state = 0;
		}
		else{
			if(pelota < 10){
				MPI_Recv(&pelota,1,MPI_INT,(rank+1)%2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				state = 1;
			}
		}
	}
	MPI_Finalize();
	return 0;
}