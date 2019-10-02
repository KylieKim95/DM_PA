#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
  /* FILE *instream;
    
    int i = 0, j = 0 , k = 0;

    // open stdin for reading
    instream = fopen("/dev/stdin","r");

    if(instream!=NULL)
    {
    // read from stdin until it's end
i
        char temp;
        while( (temp = fgetc(instream)) != EOF ){
            if((temp != ' ') && (temp != '\n'))
            {
                puzzle_list[i][j] = temp-'0';
                j++;
            }
            else if(temp == '\n')
            {
                k = j;
                i++;
                j=0;
            }
        }

    */
    int array[3][16] =
    {
        {0,0,0,4,5,0,7,0,0,0,0,0,0,0,15,16},
        {0,0,0,0,0,27,26,25,0,0,0,0,0,19,18,17},
        {33,34,35,36,0,38,0,0,0,0,0,0,0,0,0,0}
        //0을 ?로 생각하세요
    };
    
    //Q1
    for(int i=0; i<=4; i++)
    {	
        for(int j = 0; j<=17; j++)
        {

                printf("(declare-const p%d%d Int)\n",i,j);

	}
    }
    //pij값을 int로 설정,일단 테두릭까지 array로 설정. -1으로 둘러쌀지 아닐지는 나중에 보고 결정하자. 나중에 모든 pij가 1이상 nm 이하임을 명시해야 함

    //Q2
    for(int i = 1; i<=3; i++)
    {
	for(int j = 1; j<=7; j++)
        {
    	    printf("(assert (and (>= p%d%d 0) (<= p%d%d 48)))\n",i,j,i,j);
        }
    }
    //여기서 pij의 범위 명시

    //Q3
    for(int i=0; i<=4; i++)
    {
	for(int j=0; j<=17; j++)
    	{
            if(i==0 || i==4 || j==0 || j==17)
            {
           	
		 printf("(assert ( = p%d%d 0))\n",i,j);
           
	    } else if(array[i-1][j-1]!=0)
	    {
        	    printf("(assert ( = p%d%d %d))\n",i,j,array[i-1][j-1]);
            }
	}
    }
    //인풋의 숫자부터 주어진 배열에 할당.pij와 array의 범위는 다르다 pij가 하나 확장된 범위를 표현한다(테두리 포함)

    //Q4
    printf("(assert (and ");
    for(int i=1; i<=3; i++)
    {
   	 for(int j=1; j<=16; j++)
   	 {
	        //printf("(and ");
 		printf("(or ( = p%d%d 48) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
        	printf("(or ( = p%d%d 1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
		 //printf(")");
   	 }
    }
    printf("))\n");
    //칸 안의 수가 가장 큰 값이거나, 1큰 값이 동서남북에 존재하는 경우 & 가장 작은 값이거나, -1인 값이 동서남북에 존재하는 경우  
    
    //Q5
    printf("(assert (distinct ");
    for(int i=1; i<=3; i++)
    {
	for(int j=1; j<=16; j++)
   	{
        	printf("p%d%d ",i,j);
   	}
    }
    printf("))\n");
    //모두 다른 값을 가지는 경우
    
    printf("(check-sat)\n(get-model)\n");    
}
