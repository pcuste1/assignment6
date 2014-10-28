#include <stdio.h>
#include <stdlib.h>

/* DECLARATION OF FUNCTIONS */
int doDifferentEquations(int LHS[], int RHS[], int size);
int checkOps(int LHS[], int RHS[]);

/* FUNCTIONS */
int doDifferentEquations(int LHS[], int RHS[], int LHSsize){
  /* recursive, calls itself till checkOps returns a 1 */
  /* FIRST BASE CASE. */
  if(LHSsize == 1){
    /* when the size of lhs is just one, we still want to go through it         
       but the last thing so return it */
    return 0;
  }
  /* SECOND BASE CASE */
  int z = checkOps(LHS,RHS);
  if(z == 1){
    return 1;
  }else{
    /* now shifting over one value from lhs to rhs */
    /* so one size small */
    int newLHS[LHSsize-1];
    /* one size big */
    int newRHS[LHSsize+1];
    /* making the new LHS, size - 1 to have 1 less size */
    int a,b;
    while( a < LHSsize -1){
        newLHS[a] = LHS[a];
        a++;
    }

    /* only regular size to copy the whole thing */
    while(b < LHSsize){
      newRHS[b] = RHS[b];
      b++;
    }
    /* now the last element from the old LHS is added to the last spot          
       in the new RHS */
    newRHS[LHSsize] = LHS[LHSsize];
    /* we always want to decrement so an infintie loop does not occur */
    LHSsize--;
    /* RECURSION */
    int y = doDifferentEquations(newLHS,newRHS,LHSsize);
  }
}

int checkOps(int LHS[], int RHS[]){
  /* printing the equation happens here, and returning 1 or o */
  if(LHS == RHS){
    printf("They are equal!!\n");
    return 1;
  }
  return 2;
}

/* MAIN */
int main(int argc, char *argv[]){
  /* the length of the list is argc -1 one since we need get rid of the         
     initial filename entered 2*/
  int LHS[argc-1];
  int RHS[argc-1];
  if(argc > 1){
    int x=1;
    int a;
    while(x < argc){
      /* casting the input to an integer to use it */
      a = strtol(argv[x], NULL, 0);
      /* have to use x-1 since arrays are assigned form 0, we staretd  from     
         1 in the loop */
      LHS[x-1] = a;
      RHS[x-1]=a;
      x++;
    }
  }else{
    printf("Enter some arguments to run the program\n");
  }
  /*                                                                            
    FOR NOW IN COMMENTS, MAYBE PRINT THIS MESSAGE IN THE FUNC */
  int z = doDifferentEquations(LHS,RHS,argc-1);
  if(z != 1){
    printf("This equaiton is not possible.\n");
    }
  return 0;
  }
