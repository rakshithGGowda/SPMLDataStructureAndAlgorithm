
/* Implementation of Merge-Sort
Objective : Sort an array in ascending order using Merge-Sort algorithm
Authors : 
*/

#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *A, int N);
void merge_arrays(int *B, int *C, int *A, int Nb, int Nc, int Na);

int main(int argc, char *argv[]) {
      // The main program has two command line 
      // arguements :- filename that contains the 
      // integer numbers, number of values in the file

      // Check for correct number of command line arguements
      if(argc < 4) {
           fprintf(stderr,"Usage is %s <infile> <N> <outfile> \n",argv[0]);
           fprintf(stderr,"\t infile - name of the file that contains the numbers\n");
           fprintf(stderr,"\t      N - number of elements in the file\n");
           fprintf(stderr,"\toutfile - output file that stores sorted numbers\n");
           exit(1);
      }
 
     //Assign Command line arguements
     char *infile = argv[1];
     int N = atoi(argv[2]);
     char *outfile = argv[3];
     
     //Read Input File 
     int *a = NULL ; //Array to store values read from the file
     FILE *fp = fopen(infile,"r"); //Open input file
     if(fp == NULL) {             //check if opening was successful
           fprintf(stderr,"ERROR: Cannot open file <<%s>> \n",infile);
           exit(1);
     }
     //allocating memory to read the values
     a = (int*) malloc(N*sizeof(int));
     
     int i = 0;
     // Reading values to he array
     for (i = 0;i<N && !feof(fp) ; ++i)
         fscanf(fp,"%d",a+i);
 
     //close the file
     fclose (fp);

     if(i<N){
         printf("Only %d values are read from file ", i);
         N = i;
     }

//	printf("Hello Main");

     merge_sort(a,N);
     //check the values : Uncomment only for small files
     /*
     for (i = 0;i<N  ; ++i) {
         printf("a[%d] =%3d\n", i,a[i]);
     }
     */
     
     //Write to the output file
     fp = fopen(outfile,"w"); // open output file
     if(fp == NULL) {         // check if the command was successful
           fprintf(stderr,"ERROR: Cannot open file <<%s>> \n",infile);
           exit(1);
     }
     
     //Write sorted values to output file
     for (i = 0;i<N  ; ++i)
         fprintf(fp,"%d\n",a[i]);
     fclose(fp);

     free(a);
}


//------------------------------------------
// This is the recursive merge sort function
// input is the array "a" and its size N 
//------------------------------------------
void merge_sort(int *A, int N){

//	printf("%d", N);


   if(N<2) return;

   int *B = NULL,*C = NULL;  //Sub arrays for recursive calls
   int i,j,k; //loop variable

   //Split array size into two almost equal halves
   // start - (midpnt-1) in B and 
   // midpnt - last value in C
   int midpnt = N/2; // Remember Integer division :) 
   int Nb = midpnt ; // number of elements in B
   int Nc = N - midpnt; // rest of the elements in C

   //Nb and Nc are same if N is even
   //else they differ by 1
   B = (int *) malloc(Nb*sizeof(int));
   C = (int *) malloc(Nc*sizeof(int));
   
   //TODO Split the array into two equal halves
   //Copy the first Nb elements to B
   //next Nc elements to C

i = 0, j = 0;

while(i < Nb){
B[i] = A[i];
i++;
}

while(k<Nc){
	C[j] =  A[i];
	j++;
}

   //TODO :  recursive sorting on arrays B and C
    


printf("B: --size:%d\n",Nb);
for(int x =0; x<Nb;x++){
printf("%d\n",B[x]);
}

printf("C: --size: %d\n",Nc);

for(int x = 0; x< Nc; x++){
printf("%d\n",C[x]);
}


merge_sort(B,Nb);
merge_sort(C,Nc-1);


   //Merge those sorted arrays to one
   merge_arrays(B, C, A, Nb, Nc, N);

   free(B);
   free(C);
}

// This function merges sorted arrays B and C and store it in array A
// Nb, Nc, Na - Number of elements in B, C, A respectively.
void merge_arrays(int *B, int *C, int *A, int Nb, int Nc, int Na)
{
	//TODO : Complete the function
	//  To access i^th element of arrays you can simply call A[i] B[j] etc.    
	// Please declare required variables i, j, k etc... 
	// Also think when one array elements finish

	int i = 0, j = 0, k = 0;


	while(i < Nb && j < Nc) {

	if(B[i] < C[j]) {
	A[k] = B[i];
	i++;
	}
	else {
	A[k] = C[j];
	j++;
	}
	k++;
	}

	while(i<Nb) {
	A[k++] = B[i++];
	} 

	while(j<Nc){
	A[k++] = C[j++];
	}

}



























