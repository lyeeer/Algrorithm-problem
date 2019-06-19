

/************************************************************************/
/* pat1003                                                              */
/************************************************************************/
/*#include <stdio.h>
#include <string.h>
#define N 10000
char iStr[N];
int strLen;
bool checkA(int begin,int end)
{
	for(int i=begin;i<end;i++)
		if ('A'!=iStr[i])
			return false;
	return true;
}

bool check(){
	int posP,posT;
	for (int i=0;i<strLen;i++)
	{
		if('P'==iStr[i])
			posP=i;
		if('T'==iStr[i])
			posT=i;
	}
	if (checkA(0,posP)&&checkA(posP+1,posT)&&checkA(posT+1,strLen)
		&&posT-posP>1&&(posT-posP-1)*(posP)==strLen-posT-1)
		return true;
	return false;
}

bool checkOne(){
	for (int i=0;i<strLen;i++)
		if (!('P'==iStr[i]||'A'==iStr[i]||'T'==iStr[i]))
			return false;
	return true;
}

int main()
{
	int nCase;
	scanf("%d",&nCase);
	while(nCase--)
	{
		scanf("%s",iStr);
		strLen=strlen(iStr);
		printf("%s\n",(checkOne()&&check())?"YES":"NO");
	}
	return 0;
}*/

/************************************************************************/
/* p1004                                                                */
/************************************************************************/
/*#include <stdio.h>
struct student{
	char name[11];
	char num[11];
	int score;
};

int main(){
	int n;
	int i,j;
	struct student stuMax,stuMin,temp;
	stuMax.score=-1;
	stuMin.score=101;

	scanf("%d",&n);//学生个数
	getchar();

	for (i=0;i<n;i++)
	{
		scanf("%s %s %d",temp.name,temp.num,&temp.score);
		getchar();
		if (stuMax.score<temp.score)
		{
			for(j=0;j<11;j++){
				stuMax.name[j]=temp.name[j];
				stuMax.num[j]=temp.num[j];
			}
			stuMax.score=temp.score;
		}
		if (stuMin.score>temp.score)
		{
			for (j=0;j<11;j++)
			{
				stuMin.name[j]=temp.name[j];
				stuMin.num[j]=temp.num[j];
			}
			stuMin.score=temp.score;
		}
	}
	printf("%s %s\n",stuMax.name,stuMax.num);
	printf("%s %s\n",stuMin.name,stuMin.num);

	return 0;
}*/

/************************************************************************/
/*R序列循环左移P个位置                                                  */
/************************************************************************/
/*#include <stdio.h>
#define N 50
void Reverse(int R[],int l,int r)
{
	int i,j;
	int temp;
	for(i=1,j=r;i<j;i++,j--)
	{
		temp=R[i];
		R[i]=R[j];
		R[j]=temp;
	}
}

void RCR(int R[],int n,int p)
{
	if (p<=0||p>=n)
	{
		printf("ERROR!\n");
	} 
	else
	{
		Reverse(R,0,p-1);
		Reverse(R,p,n-1);
		Reverse(R,0,n-1);
	}
}
int main(){
	int L,i;
	int R[N],n;
	scanf("%d",&L);
	scanf("%d",&n);
	for (i=0;i<=n-1;i++)
	{
		scanf("%d",&R[i]);
	}
	RCR(R,n,L);
	for (i=0;i<=n-1;i++)
	{
		printf("%d ",R[i]);
	}
	return 0;
}*/

/************************************************************************/
/*p1005                                                                  */
/************************************************************************/
#include <stdio.h>
int main()
{
	int k,i,n,length;
	int num[101];
	for (i=0;i<101;i++)
	{
		num[i]=-1;
	}
	scanf("%d",&k);
	for (i=0;i<k;i++)
	{
		scanf("%d",&n);
		num[n]=0;
	}
	for (i=0;i<101;i++)
	{
		if (num[i]!=0)
		{
			continue;
		}
		n=i;
		while (n!=1)
		{
			if (n%2==0)
			{
				n=n/2;
				if (n<=100)
				{
					num[n]=1;
				} 
			}
			else
			{
				n=3*n+1;
				n=n/2;
				if (n<=100)
				{
					num[n]=1;
				}
			}
		}
	}
	for (i=0,length=0;i<101;i++)
	{
		if (num[i]==0)
		{
			length++;
		}
	}
	for (i=100;i>1;i--)
	{
		if (num[i]==0)
		{
			length--;
			if (length!=0)
			{
				printf("%d ",i);
			}
			else
			{
				printf("%d",i);
				break;
			}
		} 
	}

	return 0;
}