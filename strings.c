#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *randstr ( int l )
{
   char *S;
   int i;

   S = (char *)malloc((l+1) * sizeof(char));
   S[l] = '\0';
   for (i=0; i<l; ++i) S[i] = '0' + (char)(rand() & 1);
   return S;
}

int *KMP ( char *S, char *T, int n, int m )
{
   char *TS;
   int i, j, *match, *F, *G, cnt;


   TS = (char *)malloc((n+m)*sizeof(char));
   for (i=0; i<m; ++i) TS[i] = T[i];
   for (i=0; i<n; ++i) TS[m+i] = S[i];

   F = (int *)malloc((n+m)*sizeof(int));
   F[0] = 0; i = 1; j = 0;
   while (i < m+n) {
      while ((i < m+n) && (TS[i] == TS[j])) F[i++] = ++j;
      if (j == 0) F[i++] = 0; else j = F[j-1];
   }

   G = (int *)malloc((m+n)*sizeof(int));
   for (i=0; i<=m-2; ++i) G[i] = 0;  
   G[m-1] = 1;                       
   cnt = 0;                          
   for (i=m; i<m+n; ++i) {          
      if (F[i] < m) G[i] = 0;        
      else if (F[i] == m) G[i] = 1;  
      else G[i] = G[F[i]-1];         

      if ((i >= 2*m - 1) && (G[i])) ++cnt; 
   }

  
   match = (int *)malloc((cnt+1)*sizeof(int));
   match[0] = cnt; 
   j = 1;         
   for (i=2*m-1; i<m+n; ++i) if (G[i]) match[j++] = i - 2*m + 1;

   free(TS); free(F); free(G);

   
   return match;
}

void strmatch ( int n, int m )
{
   char *S, *T;
   int *match, i;

   S = randstr(n); T = randstr(m);
   printf("S = %s\n", S);
   printf("T = %s\n", T);
   match = KMP(S,T,n,m);
   printf("%d matches found at indices", match[0]);
   for (i=1; i<=match[0]; ++i) printf(" %d", match[i]);
   printf("\n");
   free(S); free(T); free(match);
}


void patmatch ( int n , int m )
{
   char *S, *T1, *T2;
   int m1, m2, *match1, *match2;
   int i, j, k;

   
   S = randstr(n);
   m1 = m - 1; T1 = randstr(m1);
   m2 = m; T2 = randstr(m2);
   printf("S = %s\n", S);
   printf("T = %s*%s\n", T1, T2);

  
   match1 = KMP(S,T1,n,m1);
   match2 = KMP(S,T2,n,m2);

   printf("Pattern matches at index pairs");
   for (i=j=1; i<=match1[0]; ++i) { 
      k = match1[i] + m1;           

      if (k > match2[match2[0]]) break; 

      while ((j <= match2[0]) && (k > match2[j])) ++j;

 
      for (k=j; k<=match2[0]; ++k) printf(" (%d,%d)", match1[i], match2[k]);
   }
   printf("\n");

 
   free(S); free(T1); free(T2); free(match1); free(match2);
}

int main ( int argc, char *argv[] )
{
   int n, m;

   srand((unsigned int)time(NULL));
   if (argc >= 3) {
      n = atoi(argv[1]); m = atoi(argv[2]);
   } else {
      printf("for convinence enter n>50 n  = "); scanf("%d", &n);
      printf("for convinence enter m>5 m  = "); scanf("%d", &m);
   }
   printf("\n*** String matching\n"); strmatch(n,m);
   printf("\n*** Pattern matching\n"); patmatch(n,m);
   exit(0);
}
