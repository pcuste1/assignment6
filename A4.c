/*                                                                              
  AUTHORS:                                                                      
     Neh Patel                                                                  
     Patrick Custer                                                             
     Tommy Tran                                                                
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*========================================================================*/
/* DECLARATION OF FUNCTIONS */
int doDifferentEquations(int LHS[], int RHS[], int size);
int checkOps(int LHS[], int RHS[]);
/*=========================================================================*/


/* FUNCTIONS */
/* The whole concept is to have the original list chooped into two different    
   lists called Right-hand side and Left-hand side. And call the checkOPs       
   function and pass these two lists into it, sum up both lists                 
   with different combinations. Then if two side end up being equal             
   the equations is printed out and both functions return positive values       
   meaning that an actual equation would exist out of the numbers entered */
/*=========================================================================*/
int doDifferentEquations(int LHS[], int RHS[], int LHSsize)
{
  /* FIRST BASE CASE. */
  if(LHSsize == 1){
    /* when the size of lhs is just one, we still want to go through it         
       but the last thing so return after that */
    return 0;
  }
 /* SECOND BASE CASE */
  int z = checkOps(LHS,RHS);
  /* if z is 1, means we've found out equation and now we need to get out of    
     this recursive loop */
  if(z == 1){
    return 1;
  }else{
    /* now shifting over one value from lhs to rhs */
    /* so one size small */
    int newLHS[LHSsize-1];
    /* one size big */
    int newRHS[LHSsize+1];
    /* making the new LHS, size - 1 to have 1 less size */
    int a = 0,b = 0;
    while( a < LHSsize - 1){
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
    /* same goes for the y here. It just exists because this function           
       returns an int which is used in the main as the boolean.                 
       So the next line is pointless, but is there to avoid the                 
       warning prompt */
    y = 0;
  }
   /* we dont really need another return, but since there is a warning           
     error, we will just return a 0 here to avoid it.                           
     There will be no effect of this line in this function but to avoid         
     a warning */
  return 0;
}

/*=========================================================================*/
/*  CHECK OPS  woudld now have the list of left side and right side.            
    Now it will make random combinations of equations for both sides            
    and then compute it. After doing that for both sides, it will               
    compare the sums, and if they match it will return 1, if                    
    not then it may return any other number.                                    
*/
int checkOps(int LHS[], int RHS[])
{
  /* printing the equation happens here, and returning 1 or o */
  if(LHS == RHS){
    printf("They are equal!!\n");
    return 1;
  }
  return 2;
}


/*=========================================================================*/
/* MAIN */
int main(int argc, char *argv[])
{
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
      /* only initializing this list, Rhs is created later                      
         as we need to split the list first */
      LHS[x-1] = a;
      x++;
    }
  }else{
    printf("Enter some arguments to run the program\n");
  }

  int t = 0;
  int size = argc - 1;
  if((size % 2) == 0){
    /* if even number of numbers are given to us */
    /* loop through until half the size is done */
    while(t < ((argc-1) / 2)){
        LHS[size-1] = RHS[t];
        LHS[size-1] = 0;
        size--;
        t++;
    }
  }else{
    /* if odd number of numbers are given to us */
    while(t < ((argc-1) / 2)){
      /* take the last number in the LHS and push it                            
         into the RHS */
      LHS[size-1] = RHS[t];
      LHS[size-1] = 0;
      size--;
      t++;
    }
  /* trying to have one less number in the left hand side                     
       so replace one more time */
    LHS[size-1] = RHS[t];
    LHS[size-1] = 0;
    /* this is broken because zero is still accounted in here                   
       and we do not want that */
  }

  int z = doDifferentEquations(LHS,RHS,argc-1);
  /* the integer returned from the doDifferentEquations function                
     is used in a conditional like a boolean to print the message               
     that we were unable to come up with an equation.                           
     Which will be the case here everytime */
  if(z != 1){
    printf("No equation found.\n");
    }
  return 0;
}
