/************************************************************************/
/* int����ĳ���                                                        */
/************************************************************************/
/*
#include <stdio.h>
int main(){
	//int s[]="hello\nworld\n";
	int ss[]={0,0,0,0};
	//int l=sizeof(s)/sizeof(int);
	int ll=sizeof(ss)/sizeof(int);
	char s[]="hello\nworld\n";
	printf("%d\n",ll);
	printf("%d\n",sizeof(s));
	return 0;
}*/

/************************************************************************/
/* ���һԪ���η�����Ľ�                                               */
/************************************************************************/
/*#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c;
	float x1,x2;
	float realp,imagep;
	scanf("%f,%f,%f",&a,&b,&c);
	float disc=b*b-4*a*c;
	if (a==0)
	{
		printf("����һԪ���η�����");
	} 
	else
	{
		if (disc==0)
		{
			printf("�������ʵ��:%8.4f",-b/(2*a));
		} 
		else if(disc>0)
		{
			x1=(-b+sqrt(disc))/(2*a);
			x1=(-b-sqrt(disc))/(2*a);
			printf("����Ϊ��%8.4f,%8.4f",x1,x2);
		}
		else
		{
			realp=-b/(2*a);
			imagep=sqrt(-disc)/(2*a);
			printf("������Ϊ��%8.4f+%8.4fi,%8.4f-%8.4fi",realp,imagep,realp,imagep);
		}
	}
	return 0;
}
*/
/************************************************************************/
/* �ж�����                                                             */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	int year;
	scanf("%d",&year);
	if ((year%4==0&&year%100!=0)||(year%400==0))
	{
		printf("������");
	} 
	else
	{
		printf("��������");
	}
	return 0;
}
*/
/************************************************************************/
/* switchӦ��                                                           */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	float p,w,f,d;
	int c,s;
	scanf("%f,%f,%d",&p,&w,&s);
	if (s>=3000)
	{
		c=12;
	} 
	else
	{
		c=s/250;
	}
	switch(c)
	{
	case 0:d=0;break;
	case 1:d=2;break;
	case 2:
	case 3:d=5;break;
	case 4:
	case 5:
	case 6:
	case 7:d=8;break;
	case 8:
	case 9:
	case 10:
	case 11:d=10;break;
	case 12:d=15;break;
	}
	f=p*w*s*(1-d/100.0);
	printf("%15.4f",f);
	return 0;
}*/

/************************************************************************/
/* ѭ��                                                                 */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	int sum,i=1;*/
	/*loop:if (i<=100)
	{
		sum+=i;
		i++;
		goto loop;
	}*/

	/*while(i<=100)
	{
		sum+=i;
		i++;
	}*/

	/*do 
	{
		sum+=i;
		i++;
	} while (i<=100);*/



/*	printf("%d",sum);
	return 0;
}*/

/************************************************************************/
/* ����pai                                                              */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	float i=1,j=1;
	float pai=0;
	while((1/i)>1e-6){
		pai=pai+j*(1.0/i);
		i=i+2;
		j=-j;
	}
	printf("%f",pai*4);
	return 0;
}*/
/************************************************************************/
/* Fibonacci����                                                        */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	long i1=1,i2=1;
	int i=1;
	//printf("%ld\n%ld\n",i1,i2);
	while(i<=20){
		printf("%ld\n%ld\n",i1,i2);
		i1=i1+i2;
		i2=i1+i2;
		i++;
	}
	return 0;
}*/
/************************************************************************/
/* �ж�����                                                                     */
/************************************************************************/
/*#include <stdio.h>
#include <math.h>
int main()
{
	int m;
	int n,i;
	scanf("%d",&m);*/
	/*
		sqrtҪ��ʵ����������float����double�ͣ�����ֵҲ����Ӧ��ʵ�����ͣ�
		���Զ������β���Ҫ��������ת����Ȼ�󷵻�ֵҲת��Ϊ���ξ�ok��
	*/
	/*n=(int)sqrt((float)m);
	for (i=2;i<=n;i++)
	{
		if(m%i==0)
			break;
	}
	if (i>n)
	{
		printf("������");
	} 
	else
	{
		printf("��������");
	}
	return 0;
}*/
/************************************************************************/
/* 100-200�ڵ�����                                                      */
/************************************************************************/
/*
#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k;
	for(i=100;i<=200;i++)
	{
		k=(int)sqrt((float)i);
		for (j=2;j<=k;j++)
		{
			if (i%j==0)
			{
				break;
			}
		}
		//���û����Χ������������j=k+1,������
		if (j>k)
		{
			printf("%d  ",i);
		}

	}
	return 0;
}
*/
/************************************************************************/
/* ASCII�� ������                                                       */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	char c='a';
	while((c=getchar())!='\n')
	{
		if ((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{

			if (c<='Z'&&c>='Z'-4||c<='z'&&c>='z'-4)
			{
				c=c-22;
			}
			else
			{
				c=c+4;
			}
		}
		printf("%c",c);
	}
	return 0;
}*/

/************************************************************************/
/* ˮ�ɻ���                                                             */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	int ge,shi,bai;
	for(int i=100;i<=999;i++)
	{
		bai=i/100;
		shi=i%100/10;
		ge=i%100%10;
		if ((bai*bai*bai+shi*shi*shi+ge*ge*ge)==i)
		{
			printf("%d ",i);
		}
	}
	return 0;
}*/

/************************************************************************/
/* ��ӡ����                                                             */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=2*n-1;j++)
		{
			if (j<=n-i||j>=n+i)
			{
				printf(" ");
			} 
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	for (int i=n+1;i<=2*n-1;i++)
	{
		for (int j=1;j<=2*n-1;j++)
		{
			if ((j<=i-n)||j>=3*n-i)
			{
				printf(" ");
			} 
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}*/
/************************************************************************/
/* ð������                                                             */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	int num[10];
	int i,j,temp;
	for (i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("\n");
	for (i=0;i<9;i++)
	{
		for (j=0;j<9-i;j++)
		{
			if (num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	printf("������Ϊ��\n");
	for (i=0;i<10;i++)
	{
		printf("%d  ",num[i]);
	}

	return 0;
}*/

/************************************************************************/
/* ѡ������                                                                     */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	int num[10];
	int i,curmax,j,temp;
	for (i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	}
	for (i=0;i<9;i++)
	{
		curmax=i;
		for (j=i+1;j<10;j++)
		{
			if (num[curmax]<num[j])
			{
				curmax=j;
			}
		}
		if (curmax!=i)
		{
			temp=num[curmax];
			num[curmax]=num[i];
			num[i]=temp;
		}
	}
	for (i=0;i<10;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}*/

/************************************************************************/
/* ���뷨����                                                                     */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	int num[10];
	int i,temp,j;
	for (i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	}
	for (i=1;i<10;i++)
	{
		temp=num[i];
		for (j=i-1;j>=0&&temp>num[j];j--)
		{
			num[j+1]=num[j];//δ�ҵ�����λ�ã���ǰԪ�غ���
		}
		num[j+1]=temp;//�ҵ�����λ�ã���ɲ���
	}
	for (i=0;i<10;i++)
	{
		printf("%d ",num[i]);
	}

	return 0;
}*/


/************************************************************************/
// ѡ������
/************************************************************************/
/*#include <stdio.h>
void main()
{
	void sort(int array[],int n);
	int n[10];
	int i;
	for (i=0;i<10;i++)
	{
		scanf("%d",&n[i]);
	}
	sort(n,10);
	for (i=0;i<10;i++)
	{
		printf("%d  ",n[i]);
	}
}
void sort(int array[],int n)
{
	int i,j,k;
	int temp;
	for (i=0;i<n-1;i++)
	{
		k=i;
		for (j=i+1;j<n;j++)
		{
			if (array[j]<array[k])
			{
				k=j;
			}
		}
		temp=array[k];
		array[k]=array[i];
		array[i]=temp;
	}
}*/

/************************************************************************/
/* ��ά����Ԫ�ؽ���                                                                     */
/************************************************************************/
/*#include <stdio.h>                                                                                                                                                                                                             
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int b[3][2];
	int i,j;
	printf("a����Ϊ��\n");
	for (i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d  ",a[i][j]);
			b[j][i]=a[i][j];
		}
		printf("\n");
	}

	printf("b����Ϊ��\n");
	for (j=0;j<3;j++)
	{
		for (i=0;i<2;i++)
		{
			printf("%d  ",b[j][i]);
		}
		printf("\n");
	}
		return 0;
}*/

/************************************************************************/
/* ����������ֵ                                                                     */
/************************************************************************/
/*
#include <stdio.h>
int main()
{
	int a[3][4];
	int i,j;
	int max;
	int ri,rj;
	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	max=a[0][0];
	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{
			if (max<a[i][j])
			{
				max=a[i][j];
				ri=i;
				rj=j;
			}
		}	
	}	
	printf("\n���ֵΪ:%d,%d��%d��\n",max,ri,rj);
	return 0;
}*/
/************************************************************************/
/* ͳ�Ƶ�����                                                                     */
/************************************************************************/
/*#include <stdio.h>
int main()
{
	char string[81];
	int i,num=0,word=0;
	char c;
	gets(string);
	for (i=0;(c=string[i])!='\0';i++)
	{
		if (c==' ')
		{
			word=0;
		}
		else if (word==0)
		{
			word=1;
			num++;
		}
	}
	printf("%d\n",num);
	return 0;
}*/

/************************************************************************/
/* �ҵ��ַ��������ֵ                                                                     */
/************************************************************************/
/*#include <stdio.h>
#include <string.h>
#define N 10
int main()
{
	char str1[N],str2[N],str3[N];
	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",str3);
	//ʹstr1Ϊ���
	if (strcmp(str1,str2)<=0)
	{
		strcpy(str1,str2);
	}
	if (strcmp(str1,str3)<=0)
	{
		strcpy(str1,str3);
	}
	printf("�������Ϊ:%s",str1);
	return 0;
}*/


/************************************************************************/
/* �ҽط��󷽳̸�                                                                     */
/************************************************************************/
/*#include <stdio.h>
#include <math.h>

float f(float x)
{
	float y;
	y=((x-5.0)*x+16.0)*x-80.0;
	return y;
}
float xpoint(float x1,float x2)
{
	float y;
	y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
	return y;
}
float root(float x1,float x2)
{
	float x,y,y1;
	y1=f(x1);
	do 
	{
		x=xpoint(x1,x2);
		y=f(x);
		if(y*y1>0)
		{
			y1=y;
			x1=x;
		}
		else
			x2=x;
	} while (fabs(y)>=0.0001);
	return x;
}
int main()
{
	float x1,x2,f1,f2,x;
	do 
	{
		scanf("%f,%f",&x1,&x2);
		f1=f(x1);
		f2=f(x2);
	} while (f1*f2>=0);
	x=root(x1,x2);
	printf("%8.4f",x);
	return 0;
}*/

/************************************************************************/
/* ��ŵ������                                                                     */
/************************************************************************/
/*#include <stdio.h>
void main()
{
	void hanoi(int n,char one,char two,char three);
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}

void hanoi(int n,char one,char two,char three)
{
	void move(char x,char y);
	if (n==1)
	{
		move(one,three);
	} 
	else
	{
		hanoi(n-1,one,three,two);
		move(one,three);
		hanoi(n-1,two,one,three);
	}
}


void move(char x,char y)
{
	printf("%c-->%c\n",x,y);
}*/

/************************************************************************/
/* �Ƚ��������ڸ�Ԫ��ֵ                                                                     */
/************************************************************************/
/*#include <stdio.h>
#define N 10
void main(){
	int large(int x,int y);
	int a[N],b[N];
	int i;
	int z=0,x=0,c=0;
	for (i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=0;i<10;i++)
	{
		scanf("%d",&b[i]);
	}
	for (i=0;i<10;i++)
	{
		if (large(a[i],b[i])==-1)
		{
			z++;
		} 
		else if (large(a[i],b[i])==1)
		{
			x++;
		}
		else
		{
			c++;
		}
	}
	printf("a>b:%d;a=b:%d;a<b:%d\n",x,c,z);
	if (x>z)
	{
		printf("a>b");
	} 
	else if(x<z)
	{
		printf("a<b");
	}
	else
	{
		printf("a=b");
	}
}

int large(int x,int y)
{
	int flag;
	if (x>y)
	{
		flag=1;
	} 
	else if(x==y)
	{
		flag=0;
	}
	else
	{
		flag=-1;
	}
	return flag;
}*/

/************************************************************************/
// ����������������
// ��ƽ���ɼ�
/************************************************************************/
/*#include <stdio.h>
void main()
{
	float aver(float array[10]);
	float grade[10];
	for (int n=0;n<10;n++)
	{
		scanf("%f",&grade[n]);
	}
	printf("%.2f\n",aver(grade));
}
float aver(float array[10])
{
	int i;
	float aver;
	float sum=0;
	for (i=0;i<10;i++)
	{
		sum+=array[i];
	}
	aver=sum/10;
	return aver;
}*/


/************************************************************************/
//��ά�����е����ֵ 
/************************************************************************/
/*#include <stdio.h>
void main()
{
	int max_value(int array[][4]);
	int a[3][4]={{1,3,5,7},{2,4,6,8},{15,17,34,12}};
	printf("%d\n",max_value(a));
}
int max_value(int array[][4])
{
	int i,j,max;
	max=array[0][0];
	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{
			if (array[i][j]>max)
			{
				max=array[i][j];
			}
		}
	}
	return max;
}*/

/************************************************************************/
//ȫ�ֱ��������/Сֵ
/************************************************************************/
/*#include <stdio.h>
float MAX,MIN;
float aver(float array[10])
{
	int i;
	float aver;
	float sum=0;
	MAX=array[0];
	MIN=array[0];
	for (i=0;i<10;i++)
	{
		sum+=array[i];
		if (MAX<array[i])
		{
			MAX=array[i];
		}
		if (MIN>array[i])
		{
			MIN=array[i];
		}
	}
	aver=sum/10;
	return aver;
}
void main()
{
	float grade[10];
	int i;
	for (i=0;i<10;i++)
	{
		scanf("%f",&grade[i]);
	}
	printf("MAX=%.1f,MIN=%.1f,aver=%.1f",MAX,MIN,aver(grade));
}*/



