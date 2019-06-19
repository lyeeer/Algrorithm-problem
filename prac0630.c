//湖大2014年829 编程题1
/*#include <stdio.h>
#define N 100
void trans(int m,int k)
{
    int i=0;//位数
    int a[N];
    int len;
    for(i=0;(m/k)!=0;i++)
    {
        a[i]=m%k;
        printf("余数：%d\n",a[i]);
        m=m/k;
    }
    len=i;
    a[len]=m;
    for(i=0;i<=len;i++)
    {
        printf("%d",a[len-i]);
    }
}

main()
{
    int b,n;
    scanf("%d,%d",&n,&b);
    trans(n,b);
}*/
/*
//湖大2014年829 编程题2
#include <conio.h>
#include <stdio.h>
//#define LENGTH(s) (sizeof(s)/sizeof(int))
void fun(int a[],int b[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(a[i]>0&&a[i]<10)
            b[0]++;
        else if(a[i]>=10&&a[i]<20)
            b[1]++;
        else if(a[i]>=20&&a[i]<30)
            b[2]++;
        else if(a[i]>=30&&a[i]<40)
            b[3]++;
        else if(a[i]>=40&&a[i]<50)
            b[4]++;
        else if(a[i]>=50)
            b[5]++;
    }
}

main()
{
    int i,a[100]={9,18,27,38,59,33,14,75,38},b[6]={0,0,0,0,0,0};;
    fun(a,b,9);
    printf("Result:\n");
    for(i=0;i<6;i++)
        printf("%d  ",b[i]);
    printf("\n");
}*/
/*
//湖大2014年829 编程题3
#include<stdio.h>
double fact(int k)
{
    if(k>1)
    {
        return k*fact(k-1);
    }
    else if(k==1)
        return 1;
}
main()
{
    int b;
    scanf("%d",&b);
    printf("%d!=%.0f\n",b,fact(b));
}*/
/*
//湖大2014年829 编程题4
#include <stdio.h>
#include <string.h>
void deletestr(char *s,char *t,char *u)
{
    int i,j,k=0;
    int flag=0;//0代表没出现
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(t);j++)
        {
            if(t[j]==s[i])  flag=1;
        }
        if(flag==0)
        {
            u[k++]=s[i];
        }
            //k++;
        flag=0;
    }
}
main()
{
    char s[100],t[100],u[100];
    printf("String s:\n");
    scanf("%s",s);
    printf("String t:\n");
    scanf("%s",t);
    deletestr(s,t,u);
    printf("%s",u);
}*/



