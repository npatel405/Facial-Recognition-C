/*  This program finds George in a crowd.

 <October 4, 2017>                               <Niket Patel>
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int	             CrowdInts[1024];
   int	             NumInts, TopLeft, BottomRight;
   int               Load_Mem(char *, int *);

   if (argc != 2) {
     printf("usage: ./P1-1 valuefile\n");
     exit(1);
   }
   NumInts = Load_Mem(argv[1], CrowdInts);
   if (NumInts != 1024) {
      printf("valuefiles must contain 1024 entries\n");
      exit(1);
   }

    char * p;
    p = (char *)CrowdInts;
    for (int i=0; i<4096; i++) //Sort through every pixel
    {
        for (int scaler = 1; scaler <6; scaler++) // Scaler for 1,2,3,4,5
        {
            if (*(p+i)== 2) //if a red pixel of the hat is found
            {
                TopLeft = (i-(4*scaler)); //find top left pixel of picture
                BottomRight = TopLeft+(780*scaler)-65; //find bottom right pixel picture
                if (*(p+i+(65*scaler))==1) //if white dot on hat is found
                {
                    if ((*(p+i+(191*scaler)))&&(*(p+i+(195*scaler)))==1) //if white stripe of hat is found
                    {
                        if ((*(p+i+(320*scaler)))&&(*(p+i+(322*scaler)))==3) // if eyes are blue
                        {
                            if ((*(p+i+(512*scaler)))&&(*(p+i+(447*scaler)))==8) //if left side of smile is present
                            {
                                if ((*(p+i+(514*scaler)))&&(*(p+i+(451*scaler)))==8) // if right side of smile is present
                                {
                                    if ((*(p+i+(703*scaler)))&&(*(p+i+(707*scaler)))==7) // if green shirt is present
                                    {
                                        if ((*(p+i+(319*scaler)))&&(*(p+i+(321*scaler)))==5) // if there is yellow next to eyes
                                        {
                                            i=5000; //change i to end pixel finder loop
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
   printf("George is located at: top left pixel %4d, bottom right pixel %4d.\n", TopLeft, BottomRight);
   exit(0);
}

/* This routine loads in up to 1024 newline delimited integers from
a named file in the local directory. The values are placed in the
passed integer array. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int IntArray[]) {
   int	N, Addr, Value, NumVals;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
      printf("%s could not be opened; check the filename\n", InputFileName);
      return 0;
   } else {
      for (N=0; N < 1024; N++) {
         NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
         if (NumVals == 2)
            IntArray[N] = Value;
         else
            break;
      }
      fclose(FP);
      return N;
   }
}
