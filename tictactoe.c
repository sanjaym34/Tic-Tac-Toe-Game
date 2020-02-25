#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

char a[3][3];
int count=0;
int count1=0;
int count2=0;

void input1()
{
	int r,c;
	printf("Enter the position of input");
	scanf("%d %d",&r,&c);
	if((r==1||r==2||r==3)&&(c==1||c==2||c==3))
	{
	if(a[r-1][c-1]==NULL)
	{
    a[r-1][c-1]='X';	
    count1++;
	++count;
	}
    else
    {
    	printf("\nPlease enter a other location\n");
    	input1();
	}
	}
	else
	{
	printf("Enter position between 1 and 3\n");
	input1();
    }
	/*    else
    {
    	printf("\nPlease enter only digits.");
    	input1();
	}*/

}

void input2()
{
	int r,c;
	printf("Enter the position of input");
	scanf("%d %d",&r,&c);
	/*if(isdigit(r)&&isdigit(c))
	{*/
	if((r==1||r==2||r==3)&&(c==1||c==2||c==3))
	{
	if(a[r-1][c-1]==NULL)
	{
    a[r-1][c-1]='O';	
    count2++;
    ++count;
	}
    else
    {
    	printf("\nPlease enter a other location\n");
    	input2();
	}
    }
    else
	{
	printf("Enter position between 1 and 3\n");
	input2();
    }
    /*}
    else
    {
    	printf("\nPlease enter only digits");
    	input2();
	}*/
}

void output()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]=='X'||a[i][j]=='O')
			printf("%c\t",a[i][j]);
			else
			printf("_\t");
		}
		printf("\n");
	}
}

int check_rows()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		if((a[i][0]==a[i][1])&&(a[i][1]==a[i][2]))
		{
		return 1;
	    }
		else
		continue;
	}
}

int check_col()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		if((a[0][i]==a[1][i])&&(a[1][i]==a[2][i]))
		{
		return 1;
	    }
		else
		continue;
	}
}

int check_diag()
{
	int i,j;
		if(((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))||((a[0][2]==a[1][1])&&(a[1][1]==a[2][0])))
		{
		return 1;
	    }
		else
		return 0;
}

int main()
{
	int flag=0;
	int i,j;
	while(1)
	{
			printf("\nPlayer 1 enter the input(X):\n");
		    input1();
		if(count1>=3)
		{
			if(check_rows()==1||check_col()==1||check_diag()==1)
			{
				printf("\nPlayer1(X) wins\n");
				output();
				break;
			}
		}
		output();
		if (count == 9)
		{
			printf("\nDraw...");
			break;
		}
		printf("\nPlayer 2 enter the input(O):\n");
		input2();
		if(count2>=3)
		{
			if(check_rows()==1||check_col()==1||check_diag()==1)
			{
				printf("\nPlayer2(O) wins\n");
				output();
				break;
			}
		}
		output();
	}
}
	
