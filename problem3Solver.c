#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{

		int Numbrix[1024][1024];
		int sol[100][100];
		int i = 0, j = 0, N_row = 0, N_col = 0, Max_num = 0;


		// open stdin
		if(stdin != NULL)
		{
				// read from stdin until it's end
				char temp[1024];
				int offset;
				int num;
				char temp2[20];
				FILE *instream;
				instream = fopen("/dev/stdin","r");
				while(fgets(temp, 1024, stdin) != NULL)
				{
						char * data = temp;
						while (sscanf(data," %s%n",temp2,&offset) == 1) {
								if(!strcmp(temp2,"?"))
								{
										num = 0;
								}
								else{
										num = atoi(temp2);
								}
								Numbrix[i][j] = num;
								j++;
								data += offset;
								N_col = j;
						}
						i++;
						j=0;
				}
				N_row = i;
				printf("row : %d\n",N_row);
				printf("col : %d\n",N_col);

				for(int i = 0; i<N_row; i++)
				{
						for(int j = 0; j<N_col; j++)
						{
								printf("%d ",Numbrix[i][j]);
						}
						printf("\n");
				}

		}

		Max_num = N_col * N_row;

		FILE* fp = fopen("formula","w");

		fprintf(fp,";Q1\n");
		for(int i=0; i<= N_row+1; i++)
		{
				for(int j = 0; j<= N_col+1; j++)
				{

						fprintf(fp,"(declare-const p%d_%d Int)\n",i,j);

				}
		}
		//pij값을 int로 설정,일단 테두릭까지 array로 설정. -1으로 둘러쌀지 아닐지는 나중에 보고 결정

		fprintf(fp,";Q2\n");
		for(int i = 1; i<=N_row; i++)
		{
				for(int j = 1; j<=N_col; j++)
				{
						fprintf(fp,"(assert (and (> p%d_%d 0) (<= p%d_%d %d)))\n",i,j,i,j,Max_num);
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

								fprintf(fp,"(assert ( = p%d_%d 0))\n",i,j);

						} else if(Numbrix[i-1][j-1] != 0)
						{
								fprintf(fp,"(assert ( = p%d_%d %d))\n",i,j,Numbrix[i-1][j-1]);
						}
				}
		}
		//인풋의 숫자부터 주어진 배열에 할당.pij와 array의 범위는 다르다 pij가 하나 확장된 범위를 표

		fprintf(fp,";Q4\n");
		fprintf(fp,"(assert (and ");
		for(int i=1; i<=N_row; i++)
		{
				for(int j=1; j<=N_col; j++)
				{
						fprintf(fp,"(or ( = p%d_%d %d) (= (- p%d_%d p%d_%d) 1) (= (- p%d_%d p%d_%d) 1) (= (- p%d_%d p%d_%d) 1) (= (- p%d_%d p%d_%d) 1))",i,j,Max_num,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
						fprintf(fp,"(or ( = p%d_%d 1) (= (- p%d_%d p%d_%d) -1) (= (- p%d_%d p%d_%d) -1) (= (- p%d_%d p%d_%d) -1) (= (- p%d_%d p%d_%d) -1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
						//printf(")");
				}

		}
		fprintf(fp,"))\n");
		//칸 안의 수가 가장 큰 값이거나, 1큰 값이 동서남북에 존재하는 경우 & 가장 작은 값이거나, -1>인 값이 동서남북에 존재하는 경우

		fprintf(fp,";Q5\n");
		fprintf(fp,"(assert (distinct ");
		for(int i=1; i<=N_row; i++)
		{
				for(int j=1; j<=N_col; j++)
				{
						fprintf(fp,"p%d_%d ",i,j);
				}
		}
		fprintf(fp,"))\n");
		fprintf(fp,"\n");
		//모두 다른 값을 가지는 경우

		fprintf(fp,"(check-sat)\n(get-model)\n");

		fclose(fp);

		int m, n;
		int num;
		char buf[256] ;
		char locate[256];

		FILE * form = popen("z3 formula", "r");
		fscanf(form, "%s", buf);

		if(!strcmp(buf,"unsat"))
		{
				printf("No solution!");
		}else{
			
		fscanf(form, "%s", buf);

		while(!feof(form))
		{
				fscanf(form, "%*s");
				fscanf(form, "%s", locate); //
				fscanf(form, "%*s"); // ()
				fscanf(form, "%*s"); // Int
				fscanf(form, "%d", &num); // num
				fscanf(form, "%*s");
				sscanf(locate, "%*1s %d_%d",&m,&n);
				sol[m][n] = num;
		}

		printf("solution\n\n");

		for(i = 1; i< N_row+1 ; i++){
				for(j = 1; j < N_col+1 ; j++){
						printf("%5d ", sol[i][j]);
				}
				printf("\n");
		}
		}

		pclose(form);
		printf("\n");
}
