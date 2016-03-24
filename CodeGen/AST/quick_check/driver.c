#include <stdio.h>
#include <stdlib.h>

int f(int a, int b);

int main()
{
   int vs[]={0,-1,+1,-2,+2,78686, -454, 0xFFFF, -0xFFFF  };
   int ns=sizeof(vs)/sizeof(vs[0]);

   for(int i=0;i<ns;i++){
     for(int j=0;j<ns;j++){
       int r=f(vs[i],vs[j]);
       fprintf(stdout, "%d,%d,%d\n", vs[i],vs[j],r);
     }
   }
   return 0;
}
