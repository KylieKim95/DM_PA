#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
		char Numbrix[100][100];
		int row = 0, col = 0, N_row = 0, N_col = 0, Max_num = 0;
		int i = 0, j = 0;
		char store;
		char* temp; //인풋을 받아 자를 문자열

		while (fgets(str, 1024, stdin)) {
				for (p_str = strtok(str, ' '); p_str; p_str = strtok(NULL, ' ')) {
						num[row][col] = atoi(p_str);
						col++;
				}
				row++;
		}

		while((store =  fgetc(stdin) != EOF)
						{
						fgets(temp,1024,stdin);
						printf("Temp : %s",temp);
						}







						/*  while( (end = fgetc(stdin)) != EOF ){
							fgets(temp,101,stdin);
							str = strtok(temp," ");
							while( str == strtok(NULL, " "))
							{
							printf("%s\n",str);
							}
							}	    
						 */
		/*if( (temp = fge != ' ') && (store != '\n')){
		  Numbrix[row][col] = store - '0';
		  printf("col : %d\n", N_col);
		  col++;
		  }
		  else if(temp == '\n')
		  {
		  N_col = col;
		  row++;
		  col = 0;

		  } else { }
		  }

		  N_row = row++;
		  Max_num = N_row * N_col;

		  printf("R : %d, C : %d",N_row,N_col);
		 */
}



