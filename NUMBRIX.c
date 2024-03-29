#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int  Numbrix[1024][1024];
	char *str;
	char *p_str;
    int row = 0, col =0 , N_row = 0, N_col = 0, Max_num = 0;

    // open stdin
    while(!feof(stdin))
    // read from stdin until it's end
	{
		fgets(str,1024,stdin);
		for(p_str = strtok(str," "); p_str; p_str = strtok(NULL," "))
		{
			Numbrix[row][col] = atoi(p_str);
			col++;
		}
		N_col = col;
		row++;
		col = 0;
		}
	N_row = row++;
 	Max_num = N_row * N_col;

   
       // if any error occured, exit with an error message
    if(stdin == NULL)
    {
           fprintf(stderr, "ERROR opening stdin. aborting.\n");
           exit(1);
    }
     
    
    
    

   FILE* fp = fopen("formula","w");

   int i,j;

    fprintf(fp,";Q1\n");
    for(int i=0; i<= N_row+1; i++)
    {	
        for(int j = 0; j<= N_col+1; j++)
        {

               fprintf(fp,"(declare-const p%d%d Int)\n",i,j);

	}
    }
    //pij값을 int로 설정,일단 테두릭까지 array로 설정. -1으로 둘러쌀지 아닐지는 나중에 보고 결정하자. 나중에 모든 pij가 1이상 nm 이하임을 명시해야 함

    fprintf(fp,";Q2\n");
    for(int i = 1; i<=N_row; i++)
    {
	for(int j = 1; j<=N_col; j++)
        {
    	    fprintf(fp,"(assert (and (> p%d%d 0) (<= p%d%d %d)))\n",i,j,i,j,Max_num);
        }
    }
    //여기서 pij의 범위 명시

    fprintf(fp,";Q3\n");
    for(int i=0; i<=N_row+1; i++)
    {
	for(int j=0; j<=N_col+1; j++)
    	{
            if(i == 0 || i == N_row+1 || j == 0 || j == N_col+1)
            {
           	
		 fprintf(fp,"(assert ( = p%d%d 0))\n",i,j);
           
	    } else if(Numbrix[i][j] != 0)
	    {
        	    fprintf(fp,"(assert ( = p%d%d %d))\n",i,j,Numbrix[i-1][j-1]);
            }
	}
    }
    //인풋의 숫자부터 주어진 배열에 할당.pij와 array의 범위는 다르다 pij가 하나 확장된 범위를 표현한다(테두리 포함)

    fprintf(fp,";Q4\n");
    fprintf(fp,"(assert (and ");
    for(int i=1; i<=N_row; i++)
    {
   	 for(int j=1; j<=N_col; j++)
   	 {
	        //printf("(and ");
 		fprintf(fp,"(or ( = p%d%d %d) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1))",i,j,Max_num,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
        	fprintf(fp,"(or ( = p%d%d 1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
		 //printf(")");
   	 }
    }
    fprintf(fp,"))\n");
    //칸 안의 수가 가장 큰 값이거나, 1큰 값이 동서남북에 존재하는 경우 & 가장 작은 값이거나, -1인 값이 동서남북에 존재하는 경우  
    
    fprintf(fp,";Q5\n");
    fprintf(fp,"(assert (distinct ");
    for(int i=1; i<=N_row; i++)
    {
	for(int j=1; j<=N_col; j++)
   	{
        	fprintf(fp,"p%d%d ",i,j);
   	}
    }
    fprintf(fp,"))\n");
    fprintf(fp,"\n");
    //모두 다른 값을 가지는 경우
    
    fprintf(fp,"(check-sat)\n(get-model)\n");    

    fclose(fp);

}
