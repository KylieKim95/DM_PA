#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int i, j=0;
    int ct = 0;
    int background[1000][1000] = { 0 };
    while(;;)
    {
	gets(background[][j]);
	j++;
    }(
	
    
    //Q1
    for(int i=0; i<=4; i++)
    {	
        for(int j = 0; j<=4; j++)
        {

                printf("(declare-const p%d% Int)\n",i,j);

	}
    }
    //pij값을 int로 설정,일단 테두릭까지 array로 설정. -1으로 둘러쌀지 아닐지는 나중에 보고 결정하자. 나중에 모든 pij가 1이상 nm 이하임을 명시해야 함

    //Q2
    for(int i = 1; i<=3; i++)
    {
	for(int j = 1; j<=3; j++)
        {
    	    printf("(assert (and (>= p%d%d 0) (<= p%d%d 9)))\n",i,j,i,j);
        }
    }
    //여기서 pij의 범위 명시

    //Q3
    for(int i=0; i<=4; i++)
    for(int j=0; j<=4; j++)
    {
        if(i==0 || i==4 || j==0 || j==4)
        {
            printf("(assert ( = p%d%d 0))\n",i,j);
        }
        else if(array[i-1][j-1]!=0)
        {
            printf("(assert ( = p%d%d %d))\n",i,j,array[i-1][j-1]);
        }
    }
    //인풋의 숫자부터 주어진 배열에 할당.pij와 array의 범위는 다르다 pij가 하나 확장된 범위를 표현한다(테두리 포함)

    //Q4
    printf("(assert (and ");
    for(int i=1; i<=3; i++)
    {
   	 for(int j=1; j<=3; j++)
   	 {
	        //printf("(and ");
 		printf("(or ( = p%d%d 9) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1) (= (- p%d%d p%d%d) 1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
        	printf("(or ( = p%d%d 1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1) (= (- p%d%d p%d%d) -1))",i,j,i,j+1,i,j,i,j-1,i,j,i+1,j,i,j,i-1,j,i,j);
        	printf(")");
   	 }
    }
    printf("))\n");
    //칸 안의 수가 가장 큰 값이거나, 1큰 값이 동서남북에 존재하는 경우 & 가장 작은 값이거나, -1인 값이 동서남북에 존재하는 경우  
    //Q4
    printf("(assert (distinct ");
    for(int i=1; i<=3; i++)
    {
	for(int j=1; j<=3; j++)
   	{
        	printf("p%d%d ",i,j);
   	}
    }
    printf("))\n");
    //모두 다른 값을 가지는 경우
    
    
}
