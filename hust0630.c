/*//奇偶校验
输入一个字符串，然后对每个字符进行奇校验，最后输出校验后的二进制数(如'3’，输出：10110011)。
*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    //int len;
    int s1[10];
    int ans=0;
    int i,j;
    int k=0;
    int temp;
    while(gets(s)!=NULL)
    {
        int len=strlen(s);
        ans=0;
        for(i=0;i<len;i++)
        {
            memset(s1,0,sizeof(s1));//memset(&a, 0, sizeof(struct customer))函数定义在memory.h中，
                                    //用于给指定的内存区域赋值，在该语句中，&a指定待赋值的内存首地址，
                                    //0是要赋的值，而sizeof(struct customer)用于该内存区域待赋值的长度。
            k=0;
            ans=0;
            temp=(int)s[i];//temp为当前字符的ASCII码
            while(temp!=0)
            {
                s1[k++]=(temp&1);//取最后一位
                if(temp&1==1)//代表的意思是a和1做二进制的且运算 即看a的最后边那一位是不是1
                    ans++;
                temp=temp/2;//当前字符右移
            }
            if(ans%2==1)
                s1[7]=0;
            else
                s1[7]=1;
            for(j=7;j>=0;j--)
                printf("%d",s1[j]);
            printf("\n");
        }
    }
}*/

//*********************************************************************************
/*
//strstr(char *str1,char *str2)
//返回str2在str1的指针,若不存在，返回NULL*/
/*
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char *s="Golden Global View";
    char *l="lob";
    char *p;
    system("cls");
    p=strstr(s,l);
    if(p!=NULL)
    {
        printf("%s\n",p);
    }
    else
    {
        printf("NOT FOUND!\n");
    }
    getch();
    return 0;
}*/

/*
//mystrstr()*/
/*
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char *mystrstr(char *s1,char *s2);
int main()
{
    char *s="Golden Global View";
    char *l="ob";
    char *p;
    system("cls");
    p=mystrstr(s,l);
    if(p!=NULL)
    {
        printf("%s\n",p);
    }
    else
    {
        printf("NOT FOUND!\n");
    }
    getch();
    return 0;
}
char *mystrstr(char *s1,char *s2)
{
    int n;
    if(*s2)
    {
        while(*s1)
        {
            for(n=0;*(s1+n)==*(s2+n);n++)
            {
                if(!*(s2+n+1))
                {
                    return (char *)s1;
                }
            }
            s1++;
        }
        return NULL;
    }
    else
    {
        return (char *)s1;
    }
}*/

//*********************************************************************************
/*//从string1 onexxx string2 oneyyy中找yyy*/
/*
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char *s="string1 onexxx string2 oneyyy";
    char *p;
    p=strstr(s,"string2");
    printf("%s\n",p);
    if(p==NULL)
    {
        printf("NOT FOUND\n");
    }
    p=strstr(p,"one");
    printf("%s\n",p);
    if(p==NULL)
    {
        printf("NOT FOUND\n");
    }
    p+=strlen("one");
    printf("%s\n",p);
    getch();
    return 0;
}*/
/*
//观察字符串s，要获取到yyy，one部分相同，找到不同部分开始
#include<stdio.h>
#include<string.h>
void main()
{
    char *s="string1 onexxx string2 oneyyy";
    char *p;
    p=strstr(s,"string2");//从string2部分截取
    printf("%s\n",p);//string2 oneyyy
    p=strstr(p,"one");
    printf("%s\n",p);//oneyyy
    p+=strlen("one");//将*p往后移动one字符串的长度
    printf("%s\n",p);//yyy
}*/
//*********************************************************************************
/*
//统计一个字符串在另个字符串中出现的次数
//朴素匹配算法
//从原字符串开始搜索，若出现不能匹配，则从原搜索位置+1继续。*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100],t[100];
    int m=0;
    int n=0;
    int count=0;
    gets(s);
    gets(t);
    while(m<=strlen(s)&&n<=strlen(t))
    {
        if(s[m]==t[n])
        {
            m++;
            n++;
        }
        else
        {
            m=m-n+1;
            n=0;
        }
        if(n==strlen(t))
        {
            count++;
        }
    }
    if(m==strlen(s)+1)
    {
        printf("count=%d",count);
    }
    return 0;
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 100
void main()
{
    char str1[N];
    char str2[N];
    int m=0,n=0;
    int count=0;
    gets(str1);
    gets(str2);
    while((m<=strlen(str1))&&(n<=strlen(str2)))
    {
        if(str1[m]==str2[n])
        {
            m++;
            n++;
        }
        else
        {
            m=m-n+1;
            n=0;
        }
        if(n==strlen(str2))
        {
            count++;
        }
    }
    printf("%d\n",count);
}
*/

/*//kmp算法 字符串快速匹配*/
/*
#include<stdio.h>
#include<string.h>
typedef struct seqstring{
    char string[100];
    int length;
}seqstring;

void getnext(seqstring p,int next[])
{
    int i,j;
    next[0]=-1;
    i=0;//指向字符串每个字符的指针
    j=-1;
    while(i<p.length)//若还没到达结尾
    {
        if(j==-1||p.string[i]==p.string[j])//第一个字符或者是相同字符
        {
            i++;
            j++;
            //若令next[j]=k,则next[j]表明当模式中第j个字符与主串中相应字符失配时,
            //在模式中需要重新与主串中该字符进行比较的字符的位置
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
    for(i=0;i<p.length;i++)//输出next[]的值
    {
        printf("%d",next[i]);
    }
}

int kmp(seqstring t,seqstring p,int next[])
{
    int i,j;
    i=j=0;
    while(i<t.length&&j<p.length)
    {
        if(j==-1||t.string[i]==p.string[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==p.length)
        return i-p.length;
    else
        return -1;
}

int main()
{
    seqstring t,p;
    int next[50];
    printf("string t:\n");
    scanf("%s",t.string);
    t.length=strlen(t.string);

    printf("string s:\n");
    scanf("%s",p.string);
    p.length=strlen(p.string);

    getnext(p,next);
    printf("\n%d\n",kmp(t,p,next));
    return 0;
}*/
/*
#include<stdio.h>
#include<string.h>
typedef struct seqstring
{
    char string[100];
    int length;
}seqstring;

void getnext(seqstring p,int next[])//p为被比较字串
{
    int i,j;
    next[0]=-1;
    i=0;
    j=-1;
    while(i<p.length)
    {
        if(j==-1||p.string[i]==p.string[j])
        {
            j++;
            i++;
            next[i]=j;
            printf("if--%d %d next[i]=%d\n\n",j,i,next[i]);
        }
        else
            j=next[j];
            printf("else--%d %d next[i]=%d\n\n",j,i,next[i]);
    }
    for(i=0;i<p.length;i++)
    {
        printf("%d ",next[i]);
    }
}

int kmp(seqstring t,seqstring p,int next[])
{
    int i,j;
    i=j=0;
    while(i<t.length&&j<p.length)
    {
        if(j==-1||t.string[i]==p.string[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j==p.length)
        return i-p.length;
    else
        return -1;
}

int main()
{
    seqstring t,p;
    int next[50];
    int i;
    scanf("%s",t.string);
    t.length=strlen(t.string);
    scanf("%s",p.string);
    p.length=strlen(p.string);

    getnext(p,next);//这里传入next数组，相当于传入next地址,所以不用返回值也可以传出数

    for(i=0;i<p.length;i++)
    {
        printf("%d ",next[i]);
    }

    printf("\n%d\n",kmp(t,p,next));
    return 0;
}*/


/*
#include<stdio.h>
void a1(int a)
{
    a=10;
}
void main()
{
    int a;
    a=5;
    a1(a);
    printf("%d\n",a);//5，无返回
}*/
//*********************************************************************************
/*//大数相加*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100001
char a[N],b[N],sum[N];
int bigDataPlus();

int main()
{
    //不能用scanf("%s,%s",a,b)没有结束符 会把,作为a的字符传进去
    while(scanf("%s %s",a,b)!=EOF)
    {
        bigDataPlus();
        puts(sum);
    }
    return 0;
}

int bigDataPlus()
{
    int i,j,k,lena,lenb;
    char temp;
    int c=0;    //进位标识
    lena=strlen(a);
    lenb=strlen(b);
    //初始化数组sum
    memset(sum,0,N);
    //倒序相加
    k=0;
    for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--)
    {
        sum[k]=a[i]+b[j]-'0'+c;
        c=0;
        if(sum[k]>'9')
        {
            c=1;
            sum[k]-=10;
        }
        k++;
    }
    //a>b
    while(i>=0)
    {
        sum[k]=a[i]+c;
        c=0;
        if(sum[k]>'9')
        {
            c=1;
            sum[k]-=10;
        }
        k++;
        i--;
    }
    //b>a
    while(j>=0)
    {
        sum[k]=b[j]+c;
        c=0;
        if(sum[k]>'9')
        {
            c=1;
            sum[k]-=10;
        }
        k++;
        j--;
    }
    //最后的进位
    if(c==1)
    {
        sum[k++]='1';
    }
    //翻转
    for(i=0,j=k-1;i<j;i++,j--)
    {
        temp=sum[i];
        sum[i]=sum[j];
        sum[j]=temp;
    }
    return 0;
}*/

//*********************************************************************************
/*字符串连接
*不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
*无冗余理解为不占用多余的内存空间来存储输入的字符串
*用动态内存分配函数malloc和realloc
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=1,j=1,k;
    char a;
    char *p1=(char *)malloc(sizeof(char));
    char *p2=(char *)malloc(sizeof(char));
    //输入字符串1
    while((a=getchar())!='\n')
    {
        p1=(char *)realloc(p1,sizeof(char)*i);
        *(p1+i-1)=a;
        i++;
    }
    //添加结束字符
    p1=(char *)realloc(p1,sizeof(char)*i);
    *(p1+i-1)='\0';
    //输入字符串2
    while((a=getchar())!='\n')
    {
        p2=(char *)realloc(p2,sizeof(char)*j);
        *(p2+j-1)=a;
        j++;
    }
    //添加结束字符
    p2=(char *)realloc(p2,sizeof(char)*j);
    *(p2+j-1)='\0';

    p1=realloc(p1,sizeof(char)*(i+j-1));
    //将第二个字符串连接在第一个后面
    for(k=0;k<j;k++,i++)
    {
        *(p1+i-1)=*(p2+k);
    }
    printf("%s\n",p1);
    return 0;
}*/

//*********************************************************************************
/*
//成绩排序
//用一维数组存储学号和成绩，然后，按成绩排序输出。*/
/*
#include<stdio.h>
void sort(int *data,int n);
void main()
{
    int N;//学生的个数
    int i;
    int str[100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&str[2*i],&str[2*i+1]);//奇数位为学号 偶数位成绩
    }
    sort(str,N);
}
void sort(int *data,int n)
{
    int i,j;
    int temp;
    for(i=1;i<2*n-1;i+=2)
    {
        for(j=1;j<2*n-1-i;j+=2)
        {
            if(data[j]<data[j+2])
            {
                temp=data[j];
                data[j]=data[j+2];
                data[j+2]=temp;

                temp=data[j-1];
                data[j-1]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",data[2*i],data[2*i+1]);
    }
}*/

//*********************************************************************************
/*//八进制*/
/*
#include<stdio.h>
#include<stdlib.h>
void main()
{
    long n;
    int eight[6];
    int i=0,j;
    scanf("%ld",&n);
    if(n>=0&&n<=100000)
    {
        while(n>0)
        {
            eight[i]=n%8;
            n=n/8;
            i++;
        }
        for(j=i-1;j>=0;j--)
        {
            printf("%d",eight[j]);
        }
    }
}*/
//*********************************************************************************
/*
//最长/短文本
//输入多行字符串，按照原文本顺序输出最长/短字串
//字符串数组 自己构造一个
//最值的初始化：#include<limit.h> int MAX=INT_MIN,MIN=INT_MAX;最大值是最小，最小值是最大(初始化)
//输入ctrl+Z再输回车，再输一次ctrl+Z再输回车，就可以结束输入*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
typedef struct String{
    int len;
    char str[N];
}String;

String s[100001];
void main()
{
    int index=0;
    int MAX,MIN;
    int i;
    while(scanf("%s",s[index].str)!=EOF)
    {
        s[index].len=strlen(s[index].str);
        if(index==0)
        {
            MAX=s[0].len;
            MIN=s[0].len;
        }
        //获取最大长度
        if(s[index].len>MAX)
            MAX=s[index].len;
        else if(s[index].len<MIN)
            MIN=s[index].len;
        index++;
    }
    for(i=0;i<index;i++)
    {
        if(s[i].len==MIN)
            printf("%s\n",s[i].str);
    }
    for(i=0;i<index;i++)
    {
        if(s[i].len==MAX)
            printf("%s\n",s[i].str);
    }

}*/
//*********************************************************************************
/*农夫过河
*有一个农夫带一只羊、一筐菜和一只狼过河.如果没有农夫看管，则狼要吃羊，羊要吃菜.
*但是船很小，只够农夫带一样东西过河。问农夫该如何解此难题？
*4个变量分别表示人和所带东西的状态，在河对岸则为1，否则为0。
*那么该题的初始状态是(0, 0, 0, 0)，终止状态是(1, 1, 1, 1)。
*BFS，用一个变量的低四位表示状态
*/
//位运算符
/*#include<stdio.h>
#include<string.h>
#define M 16

int beginState;
int endState;
int state[M],v[M];
int best[M],lest;

void init()
{
    beginState=0;
    endState=M-1;
    state[0]=beginState;
    memset(v,0,sizeof(v));
    v[beginState]=1;
    lest=M+1;
}

int bit(int i,int b)
{
    return (i>>b)&1;
}

int move(int count)
{
    int s=state[count-1];
    int i,t;
    int step;
    if(s==endState)
    {
        if(count<lest)
        {
            lest=count;
            for(i=0;i<count;i++)
            {
                best[i]=state[i];
            }
        }
        return count;
    }
    if(count==M)
        return M+1;
    for(i=0;i<M;i++)
    {
        if(v[i])
            continue;
        if(s/8==i/8)
            continue;
        if(s/8==1)
        {
            t=s-8;
            int flag=0;
            if(t==i)
                flag=1;
            if(bit(t,0)&&t-1==i)
                flag=1;
            if(bit(t,1)&&t-2==i)
                flag=1;
            if(bit(t,2)&&t-4==i)
                flag=1;
            if(flag==0)
                continue;
        }
        else
        {
            t=s+8;
            int flag=0;
            if(t==i)
                flag=1;
            if(bit(i,0)&&t+1==i)
                flag=1;
            if(bit(i,1)&&t+2==i)
                flag=1;
            if(bit(i,2)&&t+4==i)
                flag=1;
            if(flag==0)
                continue;
        }
        if(bit(i,3)^bit(i,1))
        {
            if((bit(i,3)^bit(i,0))||(bit(i,3)^bit(i,2)))
                continue;
        }
        state[count]=i;
        v[i]=1;
        step=move(count+1);
        if(step<=M)
            return step;
        v[i]=0;
    }
    return M+1;
}

void printBest()
{
    int s0,s,t;
    int i;
    s0=best[0];
    for(i=1;i<lest;i++)
    {
        s=best[i];
        if(bit(s,3))
        {
            t=s-s0;
            if(t==8)
                printf("nothing_go\n");
            if(bit(t,0))
                printf("vegetable_go\n");
            if(bit(t,1))
                printf("sheep_go\n");
            if(bit(t,2))
                printf("wolf_go\n");
        }
        else
        {
            t=s0-s;
            if(t==8)
                printf("nothing_come\n");
            if(bit(t,0))
                printf("vegetable_come\n");
            if(bit(t,1))
                printf("sheep_come\n");
            if(bit(t,2))
                printf("wolf_come\n");
        }
        s0=s;
    }
    printf("succeed\n\n");
}

int main()
{
    init();
    move(1);
    printBest();
    return 0;
}*/
/*
//进行深度遍历，当某个状态满足结束状态时就输出一组结果
//根据题目要求的合法性判断可以砍掉很多无效的状态safe(),并对重复状态进行"剪枝"isLink()
#include<stdio.h>
void create(void);
int safe(int i,int j,int m,int n);
int isLink(int ,int );
void dfs(int);
void out(void);
//状态定义
//int=0 代表在未过河 int=1代表已经过河在对岸
struct problem{
    int farmer;
    int wolf;
    int sheep;
    int vegetable;
};

int visit[16];//已经遍历的数组
int max=0;
int pa=0;
struct problem p[16];//每个p里记录一个安全的移动状态 安全状态的结点
int link[16][16];//每个结点间的连接状态
int path[16];//记录结果

int main()
{
    int i;
    for(i=0;i<16;i++)
        visit[i]=0;//置0
    create();
    dfs(0);
    return 0;
}
void create()
{
    int i,j,m,n;//只有两种状态 0/1
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(m=0;m<2;m++)
                for(n=0;n<2;n++)
                {
                    if(safe(i,j,m,n))//如果这样的步骤安全 则把状态存入p
                                        //if(n)即若a为真，真包括非0数字和字符
                                    //检查是否符合题目要求
                    {
                        p[max].farmer=i;
                        p[max].wolf=j;
                        p[max].sheep=m;
                        p[max].vegetable=n;
                        max++;
                    }
                }
    max--;//max为共有多少种状态是安全的
    for(i=0;i<=max;i++)//检查新状态是否和路径上已经处理过的状态有重复
        for(j=0;j<=max;j++){//去掉重复结点
            if(isLink(i,j))//isLink不为0  
                link[i][j]=1;
            else
                link[i][j]=0;
        }
}

int safe(int i,int j,int m,int n)//i=farmer;j=wolf;m=sheep;n=vegetable
{
    if(i!=m&&(j==m||m==n))//通过分析，可知 在没有农夫看管的情况下(即羊和农夫状态不一致),
                            //狼=羊则狼羊在同一岸，则不安全，同理羊菜同一岸也不安全
        return 0;
    return 1;
}
//与新状态比较是否有相同状态，如果没有返回1
int isLink(int i,int j)
{
    int k=0;
    if(p[i].wolf!=p[j].wolf)
        k++;
    if(p[i].sheep!=p[j].sheep)
        k++;
    if(p[i].vegetable!=p[j].vegetable)
        k++;
    if(p[i].farmer!=p[j].farmer&&k<=1)
        return 1;
    return 0;
}
//通过递归调用实现对状态树的遍历
//visit[n]为当前搜索的状态路径上的所有状态列表
void dfs(int n)
{
    int i;
    visit[n]=1;//遍历到该位置，置1
    //从当前状态开始
    path[pa++]=n;
    //首先判断这个状态列表的最后一个状态是不是最终状态,
    //如果是，调用out()打印结果
    //return表示终止这个搜索路径的搜索。
    if(n==max)
    {
        out();
        return;
    }
    for(i=0;i<=max;i++)
    {
        //从新的状态继续搜索
        if(link[n][i]&&!visit[i])//如果可以连接并且未被访问过
        {
            dfs(i);
            pa--;
            visit[i]=0;
        }
    }
}

void out()
{
    int i;
    for(i=1;i<pa;i++)
    {
        //如果上一个状态的wolf是0 ，这个状态是1.则代表wolf过河
        if(p[path[i-1]].wolf==0&&p[path[i]].wolf==1)
            printf("wolf_go\n");
        else if(p[path[i-1]].wolf==1&&p[path[i]].wolf==0)
            printf("wolf_come\n");

        else if(p[path[i-1]].sheep==0&&p[path[i]].sheep==1)
            printf("sheep_go\n");
        else if(p[path[i-1]].sheep==1&&p[path[i]].sheep==0)
            printf("sheep_come\n");

        else if(p[path[i-1]].vegetable==0&&p[path[i]].vegetable==1)
            printf("vegetable_go\n");
        else if(p[path[i-1]].vegetable==1&&p[path[i]].vegetable==0)
            printf("vegetable_come\n");

        else if(p[path[i-1]].farmer==0&&p[path[i]].farmer==1)
            printf("nothing_go\n");
        else if(p[path[i-1]].farmer==1&&p[path[i]].farmer==0)
            printf("nothing_come\n");
    }
    printf("succeed\n\n");
}*/
//*********************************************************************************
/*八皇后问题(回溯算法)
*在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
*即任意两个皇后都不能处于同一行、同一列或同一斜线(对角线)上，问有多少种摆法。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#define max 8

int sum=0;
int queen[max];//queen[n]为第n列的皇后的行号

void show()//输出皇后坐标
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("(%d %d)",i,queen[i]);//i为横坐标，queen[i]为相应纵坐标
    }
    printf("\n");
    sum++;
}

int check(int n)//检查当前列是否可以放皇后
                //可以放 返回0
{
    int i;
    for(i=0;i<n;i++)//检查横排和对角线
    {
        if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))//abs()求绝对值
        {
            return 1;
        }
    }
    return 0;
}
void put(int n)//回溯尝试皇后位置 n为横坐标
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n]=i;//将皇后摆在当前位置
        if(!check(n))
        {
            if(n==max-1)//摆放完毕
            {
                show();
            }
            else
            {
                put(n+1);//继续摆放下一个皇后
            }
        }
    }
}

int main()
{
    put(0);//从横坐标为0开始尝试
    printf("%d",sum);
    return 0;
}*/

/********斐波拉数列*************/
/* N阶楼梯上楼问题
*一次可以走两阶或一阶，问有多少种上楼方式。（要求采用非递归）
*首先要理解题目，到达第N层的方式 就是到达第N-1和N-2的方式总和
*斐波拉契数列
*因为89阶的时候已经超过2的32次方，所以用long long int
*/
/*
#include<stdio.h>
int main()
{
    long long int a[90];
    int N;
    int i;
    while(scanf("%d",&N)!=EOF)
    {
        a[1]=1;
        a[2]=2;
        for(i=3;i<90;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        printf("%lld\n",a[N]);
    }
    return 0;
}*/
/*一只小蜜蜂
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。
蜜蜂从蜂房a爬到蜂房b的可能路线数。
*/
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int t[55];
    int a,b;
    int i;//用于循环
    t[0]=1;
    t[1]=1;
    //输入数据的第一行是一个整数N,表示测试实例的个数
    scanf("%d",&n);
    for(i=2;i<55;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    //然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
    while(n--)
    {
        scanf("%d %d",&a,&b);
        printf("%d",t[b-a]);
    }
    return 0;
}
*/
/*********************************************************************************/
/*矩阵最大值
*编写一个程序输入一个mXn的矩阵存储并输出，并且求出每行的最大值和每行的总和。
*要求把每行总和放入每行最大值的位置，如果有多个最大值，取下标值最小的那一个作为最大值。
*最后将结果矩阵输出
*/
/*
#include<stdio.h>
#include<stdlib.h>
#define M 100
void maxAdd(int a[M][M],int b,int c)
{
    int i,j;
    int sum=0;
    int max,temp;
    int imax=0;//一行中最大数的列号
    for(i=0;i<b;i++)
    {
        sum=0;
        max=0;
        for(j=0;j<c;j++)
        {
            sum=sum+a[i][j];
            if(a[i][j]>max)
            {
                imax=j;
                max=a[i][j];
            }
        }
        a[i][imax]=sum;
    }
    for(i=0;i<b;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int m,n;
    int mix[M][M];
    int i,j;
    while((scanf("%d %d",&m,&n))!=EOF)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&mix[i][j]);
            }
        }
        maxAdd(*mix,m,n);
    }
}*/

/*回文字符串
*给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。
*/
/*#include<stdio.h>
#include<string.h>
#define M 1000
int main()
{
    char str[M];
    int i;
    int flag;
    while((scanf("%s",str))!=EOF)
    {
        flag=0;
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]!=str[strlen(str)-i-1])
                flag=1;//不是回文
        }
        if(flag==1)
        {
            printf("NO!\n");
        }
        else if(flag==0)
        {
            printf("YES!\n");
        }
    }
    return 0;
}*/

/*矩阵转置
*输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就地逆置)。
*应该是不得再使用其他数组
*保存的时候就反着保存
*/
/*
#include<stdio.h>
#define M 10
int main()
{
    int N,i,j;
    int matrix[M][M];
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&matrix[i][j]);//反着保存，matrix[j][i]
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ",matrix[j][i]);//就可以正着输出matrix[i][j]
            }
            printf("\n");
        }
    }
    return 0;
}*/


/*大整数排序
*对N个长度最长可达到1000的数进行排序
*构造一个结构体，存储长度
*长度不同，由长度判断大小；长度相同，用strcmp()比较大小
*/
/*
#include<stdio.h>
#include<string.h>
#define M 1000
struct string{
    int len;
    char str[M];
};
struct string s[M];
int cmp(struct string a,struct string b)
{
    int i;
    if(a.len==b.len)
    {
        if(strcmp(a.str,b.str)>0)
        {
            return 0;
        }
        else if(strcmp(a.str,b.str)<0)
        {
            return -1;
        }
    }
    else if(a.len>b.len)
    {
        return 0;//a大于b
    }
    else if(a.len<b.len)
    {
        return (-1);//a小于b
    }
}
int main()
{
    int N,i,j;
    char m[M];
    int tempLen;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%s",s[i].str);
            s[i].len=strlen(s[i].str);
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N-i-1;j++)
            {
                if(cmp(s[j],s[j+1])==0)//返回0 则s[j]>s[j+1]  s[n]，n越大，值越大
                {

                    strcpy(m,s[j].str);
                    strcpy(s[j].str,s[j+1].str);
                    strcpy(s[j+1].str,m);

                    tempLen=s[j].len;
                    s[j].len=s[j+1].len;
                    s[j+1].len=tempLen;

                }
            }
        }
        for(i=0;i<N;i++)
        {
            printf("%s\n",s[i].str);
        }

    }
    return 0;
}*/

/*//给定一个字符串，找出重复字符，并给出位置*/
/*
#include<stdio.h>
#include<string.h>

typedef struct ch_arr
{
    int index[100];//相同字符出现位置
    int p;//相同字符出现次数
    int flag;//相应字符是否输出过
}ch_arr;

int main()
{
    ch_arr temp[130];
    char str[100];
    int k,t;

    while(scanf("%s",str)!=EOF)
    {
        //初始化存储字符串
        for(k=0;k<130;k++)
        {
            temp[k].p=0;
            temp[k].flag=0;//字符从未输出过
        }
        //接受用户输入的字符串
        for(k=0;k<strlen(str);k++)
        {
            //寻找直接用字符,而不是寻找位置
            temp[str[k]].index[temp[str[k]].p]=k;
            temp[str[k]].p++;
        }
        //输出结果
        for(k=0;k<strlen(str);k++)
        {
            if(temp[str[k]].p>1&&0==temp[str[k]].flag)//出现次数大于1(即重复),并且未输出过
            {
                for(t=0;t<temp[str[k]].p-1;t++)
                {
                    printf("%c:%d,",str[k],temp[str[k]].index[t]);
                }
                printf("%c:%d\n",str[k],temp[str[k]].index[t]);
                temp[str[k]].flag=1;
            }
        }
    }

    return 0;
}*/

/*输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。*/
/*
#include<stdio.h>
int main()
{
    int N,i,j;
    int arr[1000];
    int temp;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
        if(N>1)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<N-i-1;j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
            printf("%d\n",arr[N-1]);
            for(i=0;i<N-1;i++)
            {
                printf("%d ",arr[i]);
            }
        }
        else
        {
            printf("%d\n",arr[0]);
            printf("-1\n");
        }

    }
    return 0;
}*/

/*IP地址
*输入一个ip地址串，判断是否合法。
*或者作为字符串输入，判断字符串中点的个数以判断格式，再判断各个数的范围是否在0-255之间
* <256
*/
/*
#include<stdio.h>
struct ip
{
    int address[10];
    int flag;//0代表合法,1代表不合法
}ip;
struct ip p[100];
int main()
{
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d.%d.%d.%d",&p[i].address[0],&p[i].address[1],&p[i].address[2],&p[i].address[3]);
            p[i].flag=0;
            if(p[i].address[0]>256||p[i].address[1]>256||p[i].address[2]>256||p[i].address[3]>256||
               p[i].address[0]<=0||p[i].address[1]<=0||p[i].address[2]<=0||p[i].address[3]<=0)
            {
                p[i].flag=1;
            }
        }
        for(i=0;i<N;i++)
        {
            if(p[i].flag==0)
            {
                printf("YES!\n");
            }
            else
            {
                printf("NO!\n");
            }
        }
    }
    return 0;
}*/

/*华为机试-判断输入字符串是否为有效IP地址
实现以下接口：bool isIPAddressValid(const char* pszIPAddr)
输出：true 有效的IP地址，false，无效的IP地址
约束条件：
输入IP为XXX.XXX.XXX.XXX
字符串两边有空格认为合法
字符串中间有空格认为不合法
IP子段以0开头为不合法
子段为单个0合法
*/
/*
bool isIPAddressValid(const char *pszIPAddr)
{
	char temp[5]="\0";
	int i=0,j;
	int count=0;
	int number;
	if(NULL==pszIPAddr)
        return false;
    while(*pszIPAddr!='\0')
    {
        if(count==0&&i==0&&*pszIPAddr==' ')//字符串两边有空格认为合法 跳过前面的空格
        {
            pszIPAddr++;
            continue;
        }
        if(count<3)//前1，2，3个子段
        {
            if(*pszIPAddr<='9' && *pszIPAddr>='0')
            {
                temp[i++]=*pszIPAddr;
                if(i>3)
                    return false;
            }
            else
            {
                if(*pszIPAddr=='.')//如果是点，就计算大小是否符合要求
                {
                    if(i==0)//如果没有数字，只有.
                        return false;
                    temp[i]='\0';//temp[]记录这个三位数
                    number=0;
                    if(temp[0]=='0'&&i>1)//IP子段以0开头,不合法
                        return false;
                    for(j=0;j<i;j++)
                    {
                        number=10*number+temp[j]-'0';
                    }
                    if(number>255)
                        return false;
                    count++;
                    i=0;
                }
                else
                    return false;
            }
        }
        else
        {
            i=0;
            while(count==3)//第4子段
			{
                if(*pszIPAddr<='9'&& *pszIPAddr>='0')
                {
                    temp[i++]=*pszIPAddr;
                    if(i>3)
                        return false;
                }
                else
                {
                    if(i==0)
                        return false;
                    while(*pszIPAddr!='\0')
                    {
                        if(*pszIPAddr==' ')
                            pszIPAddr++;
                        else
                            return false;
                    }
                    if(temp[0]=='0'&&i>1)//IP子段以0开头,不合法
                        return false;
                    temp[i]='\0';
                    number=0;
                    for(j=0;j<i;j++)
                    {
                        number=10*number+temp[j]-'0';
                    }
                    if(number>255)
                        return false;
                    else
                        return true;
                }
                pszIPAddr++;
            }
        }
        pszIPAddr++;
    }
    return false;
}*/


/*最大的两个数
*输入一个四行五列的矩阵，找出每列最大的两个数。
*/
/*
#include<stdio.h>
int main()
{
    int matrix[10][10];
    int i,j,k;
    int temp;
    while(1)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<5;j++)
            { 
                scanf("%d",&matrix[i][j]);
            }
        }
        printf("\n\n");
        for(j=0;j<5;j++)
        {
            for(i=0;i<4;i++)
            {
                for(k=0;k<4-i-1;k++)
                {
                    if(matrix[k][j]<matrix[k+1][j])
                    {
                        temp=matrix[k][j];
                        matrix[k][j]=matrix[k+1][j];
                        matrix[k+1][j]=temp;
                    }
                }
            }
        }
        for(i=0;i<2;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}*/

/*二叉排序树
*输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
*/
/*关于“expected ';', ',' or ')' before '&' token”错误
在C语言里没有C++所谓的“按引用传递” 定义函数时不能用&，要改成地址引用
*/
/*C语言中没有bool
*要使用的话可以自己定义
    #define true 1
    #define false 0
    typedef int bool;
*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct BitNode
{
    int value;
    struct BitNode *lchild,*rchild;
}BiTree;

void insertBST(BiTree **root,int data)
{
    if(*root==NULL)//二叉排序树为空时,被插入结点为新的根节点
    {
        *root=(struct BiTree *)malloc(sizeof(BiTree));
        (*root)->value=data;
        (*root)->lchild=NULL;
        (*root)->rchild=NULL;
    }
    else
    {
        if(data<(*root)->value)//当前值小于根节点，建左子树
        {
            insertBST(&((*root)->lchild),data);
        }
        else if(data>(*root)->value)
        {
            insertBST(&((*root)->rchild),data);
        }
    }
}

void MK(BiTree **r,int a[],int n)//整体的插入
{
    int i;
    for(i=0;i<n;i++)
    {
        insertBST(&(*r),a[i]);//每个数分别插入
    }
}

void PreOrderTraverse(BiTree *root)//先序遍历 根左右
{
    if(root)
    {
        printf("%d ",root->value);
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}

void InOrderTraverse(BiTree *root)//中序遍历 左根右
{
    if(root)
    {
        InOrderTraverse(root->lchild);
        printf("%d ",root->value);
        InOrderTraverse(root->rchild);
    }
}

void PostOrderTraverse(BiTree *root)//后序遍历 左右根
{
    if(root)
    {
        PostOrderTraverse(root->lchild);
        PostOrderTraverse(root->rchild);
        printf("%d ",root->value);
    }
}

int main()
{
    int i,a[100],n;
    BiTree *root;
    while(scanf("%d",&n)!=EOF)
    {
        root=NULL;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        MK(&root,a,n);//将输入的数据生成二叉树 root为生成树
        PreOrderTraverse(root);
        printf("\n");
        InOrderTraverse(root);
        printf("\n");
        PostOrderTraverse(root);
        printf("\n");
    }
    return 0;
}*/

/*打印日期
*给出年份m和一年中的第n天，算出第n天是几月几号。
*/
/*
#include <stdio.h>
int isLeap(int y)//判断是不是闰年
{
    if((y%4==0&&y%100!=0)||y%400==0)
    {
        return 1;//是闰年
    }
    else
    {
        return 0;//不是闰年
    }
}

int main()
{
    int year,day;
    int m=0;
    int i;
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d %d",&year,&day)!=EOF)
    {
        if(isLeap(year)==1)//闰年
        {
            month[1]+=1;
        }
        for(i=0;i<12;i++)
        {
            if(day>month[i])
            {
                day-=month[i];
                m++;
            }
            else
                break;
        }
        printf("%d-%d-%d",year,m+1,day);
        month[1]=28;
    }
}*/

/*3个年龄最小的职工
职工有职工号，姓名，年龄.输入n个职工的信息，找出3个年龄最小的职工打印出来。
*/
/*
#include<stdio.h>
#include<string.h>
struct staff
{
    int id;
    char name[12];
    int age;
}staff;

struct staff s[50];

int main()
{
    int N;
    int i,j;
    int tempi,tempa;
    char tempn[12];
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d %s %d",&s[i].id,s[i].name,&s[i].age);
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N-i-1;j++)
            {
                if(s[j].age>s[j+1].age)//使s[0]位年龄最小值
                {
                    //交换年龄
                    tempa=s[j].age;
                    s[j].age=s[j+1].age;
                    s[j+1].age=tempa;
                    //交换ID
                    tempi=s[j].id;
                    s[j].id=s[j+1].id;
                    s[j+1].id=tempi;
                    //交换姓名
                    strcpy(tempn,s[j].name);
                    strcpy(s[j].name,s[j+1].name);
                    strcpy(s[j+1].name,tempn);
                }
            }
        }
        for(i=0;i<(N>3?3:N);i++)
        {
            printf("%d %s %d\n",s[i].id,s[i].name,s[i].age);
        }

    }
}*/

/*统计单词
*编一个程序，读入用户输入的，以“.”结尾的一行文字，统计一共有多少个单词，并分别输出每个单词含有多少个字符。
*/
/*
#include<stdio.h>
#include<string.h>
char a[10000];//记录每个输入的单词
char b[10000];//记录每个单词的字符数
int main()
{
    int n,i,k,t;
    while(gets(a)!=NULL)
    {
        k=0;
        n=strlen(a);
        t=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=' '&&a[i]!='.')//如果是字符，临时记录的字符长度+1
                t++;
            if((a[i]==' '||a[i]=='.')&&t>0)//如果是空格或者是. 就代表一个单词
            {
                b[k++]=t;
                t=0;
            }
        }
        for(i=0;i<k-1;i++)
            printf("%d ",b[i]);
        printf("%d",b[k-1]);
        printf("\n");
    }
}*/

/*守形数
*守形数是这样一种整数，它的平方的低位部分等于它本身。
*比如25的平方是625，低位部分是25，因此25是一个守形数。
*编一个程序，判断N是否为守形数。
*设a为一整数，如果能使a^2=xxa成立，则称a为“守形数”。
*/
/*
//法1
#include<stdio.h>
#include<math.h>
int isShou(int n)//返回0是守形数
{
    int i=0;
    int m=n*n;
    int hu=1;
    int j;
    while((m/10)!=0)
    {
        i++;
        m/=10;
    }
    for(j=0;j<i;j++)
    {
        hu=10*hu;
    }
    if((n*n)%hu==n)
    {
        return -1;
    }
    else
        return 1;
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        if(N>=2&&N<100)
        {
            if(isShou(N)==-1)
            {
                printf("YES!\n");
            }
            else if(isShou(N)==1)
            {
                printf("NO!\n");
            }
        }
        else
            break;
    }
    return 0;
}*/
/*
//法2
//两数都从最低位开始比较，知道原来数被比较完
//如果有数据不一致，则设置flag，并break出循环
#include<stdio.h>
int main()
{
    int N;
    int m,tmp,num1,num2;
    int flag;
    while(scanf("%d",&N)!=EOF)
    {
        m=N*N;
        tmp=N;
        flag=1;

        while(tmp!=0)
        {
            num1=tmp%10;
            //printf("%d\n",num1);
            num2=m%10;
            //printf("%d\n",num2);
            if(num1!=num2)
            {
                flag=0;
                break;
            }
            tmp/=10;
            m/=10;
        }
        if(flag==1)
        {
            printf("YES!\n");
        }
        else
        {
            printf("NO!\n");
        }
    }
    return 0;
}*/
/*二叉树遍历
*编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
*例如如下的先序遍历字符串：
*ABC##DE#G##F###
*其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BitNode
{
    char value;
    struct BitNode *lchild,*rchild;
}*BiTree;
void chu(BiTree *head)
{
    (*head)=NULL;
}
void xtree(BiTree *head)
{
    char x;
    scanf("%c",&x);
    if(x=='#')
        (*head)=NULL;
    else
    {
        (*head)=(BiTree)malloc(sizeof(struct BitNode));
        (*head)->value=x;
        xtree(&((*head)->lchild));
        xtree(&((*head)->rchild));
    }
}
void ztree(BiTree head)
{
    if(head)
    {
        ztree(head->lchild);
        printf("%c",head->value);
        ztree(head->rchild);
    }
}

int main()
{
    char s[100];
    int n;
    BiTree head;
    chu(&head);
    scanf("%d",&n);
    while(n--)
    {
        xtree(&head);
        ztree(head);
    }
    return 0;
}*/

/*阶乘
*输入n，
*求y1=1!+3!+...m!(m是小于等于n的最大奇数）
*y2=2!+4!+...p!(p是小于等于n的最大偶数)。
*/
/*
#include<stdio.h>
int fac(int x)
{
    int i;
    int f=1;
    for(i=1;i<=x;i++)
    {
        f*=i;
    }
    return f;
}

int main()
{
    int n;
    int y1=0,y2=0;
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2==0)//偶数
        {
            for(i=1;i<=(n-1);i+=2)
            {
                y1+=fac(i);
            }
            for(i=2;i<=n;i+=2)
            {
                y2+=fac(i);
            }
            printf("%d %d\n",y1,y2);
        }
        else//奇数
        {
            for(i=1;i<n;i+=2)
            {
                y1+=fac(i);
            }
            for(i=2;i<=(n-1);i++)
            {
                y2+=fac(i);
            }
            printf("%d %d\n",y1,y2);
        }
    }
}*/


/*对称矩阵
*输入一个N维矩阵，判断是否对称。
*/
/*
#include<stdio.h>
#define M 100
int main()
{
    int N;
    int i,j;
    int matrix[M][M];
    int flag;
    while(scanf("%d",&N)!=EOF)
    {
        flag=0;//对称
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(matrix[i][j]!=matrix[j][i])
                {
                    flag=1;//不对称
                }
            }
        }
        if(flag==1)
        {
            printf("NO!\n");
        }
        else
        {
            printf("YES!\n");
        }

    }
    return 0;
}*/

/*遍历链表
*建立一个升序链表并遍历输出。
*/
/*
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LinkList;

int main()
{
    int N;
    int i;
    while(scanf("%d",&N)!=EOF)
    {
        LinkList *head,*pre,*p,*newNode;
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;
        //输入数据
        for(i=0;i<N;i++)
        {
            //创建节点
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);
            //升序排列
            pre=head;
			//.是一般结构体变量访问结构体成员的操作符;->是结构体指针变量对结构体成员访问的操作符
            p=head->next;
            //找到插入位置
            while(p)
            {
                if(newNode->data<p->data)
                {
                    break;
                }
                pre=p;
                p=p->next;
            }
            //插入新节点
            newNode->next=p;
            pre->next=newNode;
        }
        //输出
        p=head->next;
        printf("%d",p->data);
        while(p->next)
        {
            p=p->next;
            printf(" %d",p->data);
        }
        printf("\n");
    }
    return 0;
}*/

/***********2011*************/
/*
*（1）从键盘输入一个文本（ASC2码文件），并将该文本输出到D盘根目录下的abc0.txt文件中，再关闭该文件，以Ctrl+Z（即eof）结束。
*（2）打开D盘根目录下的abc0.txt文件，将单词之间两个以上的空格都压缩为一个空格，输出处理后的文本，
    同时将处理后的文本输出到D盘根目录下的abc1.txt文件中，并关闭该文件。
*（3）打开D盘根目录下的abc1.txt文件，统计文件中字符的个数，单词的个数，以及句子的个数，并输出统计结果。
*/
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //问题1
    char c;
    char c_before;
    int ccount=0;
    int wcount=0;
    int scount=0;
    FILE *fp=fopen("D:\\abc0.txt","w");
    FILE *fp1=fopen("D:\\abc1.txt","r");
    if(fp==NULL)
    {
        puts("open fail.\n");
        return 0;
    }
    while((c=getchar())!=EOF)
    {
        fputc(c,fp);
    }
    fclose(fp);
    puts("input success!\n");
    puts("Mission 1 complete!\n");
    //问题2
    fp=fopen("D:\\abc0.txt","r");
    if(fp==NULL)
    {
        puts("open fail.\n");
        return 0;
    }
    if(fp1==NULL)
    {
        puts("open fail.\n");
        return 0;
    }
    c_before=NULL;
    c=NULL;
    while((c=fgetc(fp))!=EOF)
    {
        if(c==' ')
        {
            if(c_before==' ')   continue;
            else
                fputc(c,fp1);
        }
        else
            fputc(c,fp1);
        c_before=c;
    }
    fclose(fp);
    fclose(fp1);
    puts("Mission 2 complete!\n");
    //问题3
    fp1=fopen("D:\\abc1.txt","r");
    if(fp1==NULL)
    {
        puts("open fail!\n");
        return 0;
    }
    c=NULL;
    while((c=fgetc(fp1))!=EOF)
    {
        ccount++;
        putchar(c);
        if(c==' ')  wcount++;
        if(c=='.')  scount++;
    }
    wcount++;
    fclose(fp1);
    printf("char:%d;word:%d;sentence:%d\n",ccount,wcount,scount);
    puts("Mission 3 complete!\n");
    return 0;
}*/


/*
*（1）输入任意n个整数，并将其无冗余的放入数组中（n值不得事先确定，否则0分），然后输出这数组中的n个数。
*（2）对该数组中的n个数进行排序并输出结果。
* 无冗余理解为不占用多余的内存空间来存储输入的字符串
*/
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *num;
    int t;
    int i,j;
    int temp;
    int count;
    //问题1
    count=0;
    num=(int *)malloc(sizeof(int));
    scanf("%d",&t);

    while(t)
    {
        count++;
        num=(int *)realloc(num,count*sizeof(int));
        num[count-1]=t;
        scanf("%d",&t);
    }

    puts("Mission 1 complete!\n");
    //问题2
    for(i=0;i<count;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(num[j]<num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
    fflush(stdin);
    getchar();
    puts("Mission 2 complete!\n");
    return 0;
}*/
/*(1)无冗余接受n个字符串，并无冗余存入字符数组
(2)以单个字符串为数据域，按字典顺序将n个字符串生成一棵二叉搜索树,左子树小于右子树
(3)先序遍历该二叉树
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char *data;
    struct node *lchild,*rchild;
}BNode,*BTree;

void insert(BTree* t,char *data)
{
    if(!(*t))
    {
        (*t)=(BTree)malloc(sizeof(BNode));
        (*t)->data=data;
        (*t)->lchild=NULL;
        (*t)->rchild=NULL;
    }
    else
    {
        if(strcmp(data,((*t)->data))<0)
            insert(&((*t)->lchild),data);
        else
            insert(&((*t)->rchild),data);
    }
}

void PreOrder(BTree t)
{
    if(t)
    {
        printf("%s\n",t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

int main()
{
    int i,n;
    int count;
    char c;
    BTree t=NULL;
    char **a;
    scanf("%d",&n);
    a=(char**)malloc(n*sizeof(char*));
    getchar();
    if(a==NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        count=0;
        a[i]=(char*)malloc(sizeof(char));
        //a[i][count++]=getchar();
        while((c=getchar())!='\n')
        {
            count++;
            a[i]=(char*)realloc(a[i],count*(sizeof(char)));
            a[i][count-1]=c;
        }
        a[i]=(char*)realloc(a[i],(count+1)*sizeof(char));
        a[i][count]='\0';
    }
    for(i=0;i<n;i++)
    {
        insert(&t,a[i]);
    }
    PreOrder(t);
    fflush(stdin);
    return 0;
}*/

/***********2012*************/
/*(1)输入一个无符号长整数，将最高字节与最低字节互换，然后再输出。
*(2)将这个长整数中间两个字节循环左移 n 位(n 要输入)，然后再输出。
*(3)将长整数按照二进制输出，每 8 位输出一个空格
*/
/*
//十进制
#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long num,temp;
    int high,low;
    long mid;
    int count=0;//num的位数
    int i;
    scanf("%ld",&num);
    temp=num;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }
    high=num/((int)(pow(10,count-1)));
    for(i=count;i>1;i--)
    {
        low=num%((int)(pow(10,i-1)));
    }
    mid=num-high*((int)(pow(10,count-1)))-low;
    temp=low*((int)(pow(10,count-1)))+high+mid;
    //printf("%d  %d   %ld",high,low,mid);
    printf("%ld\n",temp);
    printf("Mission 1 completed!\n");
    return 0;
}*/
/*
*int/long/float 有无符号都是4字节
*short 有无符号都是2字节
*char 有无符号都是1字节
*double 8
*int 由编译器决定，16位或者32位
*/
//十六进制
//十六进制的1位是二进制的4位，2进制中的a>>=1，对应十六进制a>>=4
/*#include<stdio.h>
#include<stdlib.h>
int main()
{
    //问题一 (1)输入一个无符号长整数，将最高字节与最低字节互换，然后再输出。
    unsigned long int ulln,ulHigh=0,ulLow=0,rolBit;
    int n,bit;
    //输入十六进制数
	//无符号长整型占4个字节
    scanf("%x",&ulln);
    ulHigh=ulln>>24;//取到最高4位在最前面
    ulLow=ulln<<24;//左移1位，最高位就在这里舍弃，最低位补0
					//则取到了最低4位在最前面
	//计算时，按位计算，分析0x00ffffff的二进制为32位，最高4位和最低4位为0，其余为1
	//按与运算，只有两个均为1时，结果才对应为1，则可知结果的最高4位和最低4位为0，剩余24位与左边操作数一样
    ulln=ulln&0x00ffff00;//取ulln的中间24位，即中间2字节的值。
    ulln=ulln|ulHigh;//把高四位加进去
    ulln=ulln|ulLow;//把低四位加进去
    printf("%x\n",ulln);
    printf("Mission 1 completed!\n");

    //问题2 将这个长整数中间两个字节循环左移 n 位(n要输入)，然后再输出。
	*/
/*
		//循环左移
//因为是一个环，所以左移n位就是右移(长度-n)位，所以|上相反的位移操作32-j位
unsigned char crol(unsigned char c,unsigned b)
{
    unsigned char left=c<<b;
    unsigned char right=c>>(sizeof(unsigned char)-b);
    unsigned char temp=left|right;
    return temp;
}

unsigned char cror(unsigned char c,unsigned b)
{
    unsigned char right=c>>b;
    unsigned char left=c<<(sizeof(unsigned char)-b);
    unsigned char temp=left|right;
    return temp;
}		
	*/
	/*
    scanf("%d",&n);
    n=n%16;
    rolBit=rolBit>>8;
    rolBit=rolBit<<n;
    ulHigh=0;
    ulHigh=(rolBit&0xffff0000)>>16;//取前2字节 右移16位，把前2字节的数放到最后面
    rolBit=(rolBit&0x0000ffff)|ulHigh;
    rolBit=rolBit<<8;
    ulln=(ulln&0xff0000ff)|rolBit;
    printf("%x\n",ulln);
    printf("Mission 2 completed!\n");

    //问题3 将长整数按照二进制输出，每 8 位输出一个空格
    ulHigh=1;
    for(bit=0;bit<=31;bit++)
    {
        if(bit%8==0)
            putchar(' ');
        ulLow=ulln&(ulHigh<<(31-bit));
        printf("%d",ulLow>>(31-bit));
    }
    putchar('\n');
    printf("Mission 3 completed!\n");
    return 0;
}*/
/*
#include"stdio.h"
void main()
{
    unsigned long u,ah,am,al,x,y;
    int n,i,j;
    x=y=ah=am=al=0;
    printf("请输入一个16进制数u:");
    scanf("%x",&u);

    ah=(u&0xff000000)>>24;
    ah=ah&0x000000ff;
    am=(u&0x00ffff00)>>8;
    am=am&0x0000ffff;
    al=u&0x000000ff;
    u=(al<<24)|(am<<8)|ah;
    printf("(1)u=%x\n",u);

    printf("请输入一个十进制数n:");
    scanf("%d",&n);
    n=n%16;
    x=am;
    x=x<<n;
    y=x>>16;
    x=(x|y)&0xffff;
    u=(al<<24)|(x<<8)|ah;
    printf("(2)u=%x\n",u);

    printf("(3)");
    for(i=31,j=0;i>=0;i--,j++){
        if(j!=0&&j%8==0)printf(" ");
        if(u&(1<<i))printf("1");
        else printf("0");
    }
	printf(" ");
}*/

/*
*(1)输入 n 个字符串，字符串只能是纯字母或者纯数字，不能事先指定字符串个数，最后 将输入字符串倒序输出
*(2)将纯字母的字符串按照字典顺序排序，纯数字的字符串按照数值大小排序，最后输出
*/
/*
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//检查字符串合法性,字母串返回1，数字串返回2，非法返回0
int check(char *s)
{
    int flag=0,len=0,i;
    if(isalpha(s[0]))
        flag=1;
    else if(isdigit(s[0]))
        flag=2;
    else
        return 0;
    len=strlen(s);
    for(i=1;i<=len-1;i++)
    {
        if(isalpha(s[i])&&flag==2)
            return 0;
        if(isdigit(s[i])&&flag==1)
            return 0;
    }
    if(flag==1)
        return 1;
    if(flag==2)
        return 2;
}

int main()
{
    char **str;
    int i,j,k,count;
    char ch='!';
    char t[100];
    str=(char **)malloc(sizeof(char *));
	printf("输入字符串，空格为间隔，回车结束：\n");
	fflush(stdin);
    for(i=0;ch!='\n';i++)
    {
        str=(char **)realloc(str,(i+1)*sizeof(char *));
        count=0;
        str[i]=(char *)malloc(sizeof(char));
        while((ch=getchar())!=' '&&ch!='\n')
        {
            if(ch=='\n')
                break;
            count++;
            str[i]=(char *)realloc(str[i],count*sizeof(char));
            str[i][count-1]=ch;
        }
        str[i]=(char *)realloc(str[i],(count+1)*sizeof(char));
        str[i][count]='\0';
        if(check(str[i])==0)
        {
            printf("input error!\n");
            exit(-1);
        }
    }
    i--;
    for(j=0;j<i;j++)
    {
        for(k=0;k<i-j;k++)
        {
            if(strcmp(str[k],str[k+1])>0)
            {
                strcpy(t,str[k]);
                strcpy(str[k],str[k+1]);
                strcpy(str[k+1],t);
            }
        }
    }
    for(j=0;j<=i;j++)
        printf("%s ",str[j]);
    printf("\n");
    return 0;
}*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x,y;
    int distance;
    struct node *next;
}node;

void exchange(struct node *n1,struct node *n2)
{
    int n;
    n=n1->x;
    n1->x=n2->x;
    n2->x=n;

    n=n1->y;
    n1->y=n2->y;
    n2->y=n;

    n=n1->distance;
    n1->distance=n2->distance;
    n2->distance=n;
}

int lookfor(int *s,int count,int i)
{
    int j;
    for(j=0;j<count;j++)
    {
        if(s[j]==i)
            return 1;
    }
    return 0;
}

void main()
{
    int n,i,j,x,len=0;
    int **map;
    node *head,*p,*q;
    node *tree,*tail;
    int *s;
    int count=0;

    printf("输入图节点数:\n");
    scanf("%d",&n);
    map=(int **)malloc(n*sizeof(int *));
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;

    printf("请输入各边长的权值:\n");
    for(i=0;i<n;i++)
    {
        map[i]=(int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]&&i<j)
            {
                p=(struct node *)malloc(sizeof(struct node));
                p->next=head->next;
                head->next=p;
                p->x=i+1;
                p->y=j+1;
                p->distance=map[i][j];
            }
        }
    }
    for(i=0,p=head->next;i<len-1;i++,p=p->next)
    {
        for(j=i+1,q=p->next;j<len;j++,q=q->next)
        {
            if(p->distance>q->distance)
                exchange(p,q);
        }
    }
    p=head->next;
    printf("排序格式:权值(节点1，节点2):\n");
    while(p)
    {
        printf("%d(%d,%d) ",p->distance,p->x,p->y);
        p=p->next;
    }
    s=(int *)malloc(n*sizeof(int));
    tree=(struct node *)malloc(sizeof(struct node));
    tree->next=NULL;
    p=head->next;

    s[count++]=p->x;
    s[count++]=p->y;
    q=(struct node *)malloc(sizeof(struct node));
    q->x=p->x;
    q->y=p->y;
    p->distance=q->distance;
    tree->next=q;
    q->next=NULL;
    tail=q;

    p=p->next;
    while(count<n)
    {
        if(lookfor(s,count,p->x)==0&&lookfor(s,count,p->y)==1)
        {
            s[count++]=p->x;
        }
        else if(lookfor(s,count,p->x)==1&&lookfor(s,count,p->y)==0)
        {
            s[count++]=p->y;
        }
        else
        {
            p=p->next;
            continue;
        }
        q=(struct node *)malloc(sizeof(struct node));
        q->x=p->x;
        q->y=p->y;
        q->distance=p->distance;
        tail->next=q;
        q->next=NULL;
        tail=q;
        p=head->next->next;
    }
    p=tree->next;
    printf("\n最小二叉树格式:权值(节点1，节点2):\n");
    while(p)
    {
        printf("%d(%d,%d) ",p->distance,p->x,p->y);
        p=p->next;
    }
    printf("\n");
}
*/

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct Edge
{
    int start;
    int end;
    int pri;
}Edge;

int mtrOut[5][5];
int testCyl(int start,int end);
int ordNum=1,trNum=1,i,j;
Edge *eOrd,*eTree,xch;
int *visited;

int mtrIn[5][5]={{0,1,0,2,2},
    {1,0,2,0,0},{0,2,0,3,4},
    {2,0,3,0,0},{2,0,4,0,0}};

void main()
{
    //边排序
    eOrd=(Edge *)malloc(ordNum*sizeof(Edge));
    ordNum--;
    for(i=0;i<=3;i++)
    {
        for(j=i+1;j<=4;j++)
        {
            if(mtrIn[j]!=0)
            {
                ordNum++;
                realloc(eOrd,ordNum*sizeof(Edge));
                eOrd[ordNum-1].start=i;
                eOrd[ordNum-1].end=j;
                eOrd[ordNum-1].pri=mtrIn[j];
            }
        }
    }
    for(i=ordNum-1;i>=1;i--)
    {
        for(j=0;j<i;j++)
        {
            if(eOrd[j].pri>eOrd[j+1].pri)
            {
                xch=eOrd[j];
                eOrd[j]=eOrd[j+1];
                eOrd[j+1]=xch;
            }
        }
    }
    printf("对边进行排序:\n");
    for(i=0;i<ordNum;i++)
        printf("边:%d<-->%d 权值:%d\n",eOrd.start+1,eOrd.end+1,eOrd.pri);

    //最小生成树
    visited=(int *)malloc(ordNum*sizeof(int));
    eTree=(Edge *)malloc(trNum*sizeof(Edge));
    eTree[trNum-1]=eOrd[trNum-1];

    for(i=1;i<ordNum;i++)
    {
        //初始化访问标记数组
        for(j=0;j<ordNum;j++)
            visited[j]=0;
        if(testCyl(eOrd.start,eOrd.end)==0)
        {
            realloc(eTree,(++trNum)*sizeof(Edge));
            eTree[trNum-1]=eOrd;
        }
    }
    printf("\n最小生成树的边：\n");
    for(i=0;i<trNum;i++)
        printf("边:%d<-->%d 权值:%d\n",eOrd.start+1,eOrd.end+1,eOrd.pri);
}

int testCyl(int start,int end)
{
    int x;
    int cnt=0;
    for(x=0;x<trNum;x++)
    {
        if(visited[x]==0)
        {
            if(start==eTree[x].start)
            {
                //开始端点匹配则访问
                visited[x]=1;
                if(eTree[x].end==end)
                    return 1;
                else
                    if(testCyl(eTree[x].end,end)==1)
                        return 1;
            }
            if(start==eTree[x].end)
            {
                //结束端点匹配则访问
                visited[x]=1;
                if(eTree[x].start==end)
                    return 1;
                else
                    if(testCyl(eTree[x].start,end)==1)
                        return 1;
            }
        }
    }
}*/


/********2013**********/
/*孪生素数
如果 n 和 n+2 都是素数，则称它们是孪生素数。
输入 m，输出 2 个均不超过 m 的最大孪生 素数。5<=m<=1000。
例如 m=20 时候，答案为 17、19 */
/*
#include<stdio.h>

int isPrime(int n)//判断是不是素数
{
    int i;
    int flag=0;//1就是素数
    for(i=2;i<n;i++)
    {
        if(n%i==0)
            flag=1;//是素数
    }
    return flag;
}

int main()
{
    int m;
    int p[1000];
    int i,count=0;
    scanf("%d",&m);
    for(i=2;i<=m;i++)
    {
        if(isPrime(i)==0)
        {
            p[count]=i;
            count++;
        }
    }
    for(i=count-2;i<=count-1;i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}*/

/*顺转方针
输入一个数字 n，输出一个 n 阶顺转方针
将1-n^2从左上角开始，由外层至中心按顺时针螺旋排序
(i,i)    ……(i,n-1-i)
'              '
'              '
'              '
(n-1-i,i)……(n-1-i,n-1-i)
*/
/*
#include<stdio.h>
#define M 100
int main()
{
    int n;
    int a[M][M];
    int i,j;
    int num=1;
    int count=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i;j++)//上层
            if(a[i][j]==0)
                a[i][j]=num++;
        for(j=i;j<n-i;j++)//右层
            if(a[j][n-i-1]==0)
                a[j][n-i-1]=num++;
        for(j=n-i-1;j>i;j--)//下层
            if(a[n-i-1][j]==0)
                a[n-i-1][j]=num++;
        for(j=n-i-1;j>i;j--)//左层
            if(a[j][i]==0)
                a[j][i]=num++;
        if(n%2==1)
            a[n/2][n/2]=num;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

/*输入一个字符串，求出其中最长的回文子串。
子串的含义是：在原串连续出现的字符串片段。
 回文的含义是：正着看和倒着看是相同的，如 abba 和 abbebba。
 在判断是要求忽略所有的 标点和空格，且忽略大小写，但输出时按原样输出（首尾不要输出多余的字符串）。
 输入字符串长度大于等于1小于等于5000
*/
/*首先把符号和标点忽略，只记录字母，然后把大写换成小写存储*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5010

int main()
{
    int t,len,st,end;
    int i,j,max,k;
    char s[MAX];//输入
    char s1[MAX];//记录buf中字母 并进行处理
    int pos[MAX];//记录res中字母在buf中位置
                //由于输出时要表示大小写，所以记录位置
    scanf("%d",&t);
    getchar();//吸收输入t时的输入残余
    while(t--)
    {
        gets(s);//不能用scanf()，因为可能有空格
        len=strlen(s);
        k=st=max=end=0;
        for(i=0;i<len;++i)
        {
            if(isalpha(s[i]))//判断是不是字母
            {
                pos[k]=i;//记录res中字母在buf的位置
                //可以用s1[k++]=toupper(s[i]);
                if(s[i]<97)//大写转化成小写
                    s1[k++]=s[i]+32;
                else
                    s1[k++]=s[i];
            }
        }
		 //k为新字串的长度
        for(i=0;i<k;++i)//不判断奇偶，先奇后偶,max自动更新
        {
            for(j=0;j<=i&&i+j<k;++j)//最长回文字符数位奇数
            {
                if(s1[i-j]!=s1[i+j])
                    break;//向两边扩展，不相等跳出

                if(j*2+1>max)
                {
                    max=2*j+1;//记录最长回文串长度
                    st=pos[i-j];//记录最长回文字串起点
                    end=pos[i+j];//记录最长回文字串终点
                }
            }
            for(j=0;j<=i&&i+j+1<k;++j)//回文字符数位偶数
            {
                if(s1[i-j]!=s1[i+j+1])
                    break;
                if(j*2+2>max)
                {
                    max=2*j+2;
                    st=pos[i-j];
                    end=pos[i+j+1];
                }
            }
        }
        for(i=st;i<=end;++i)//st为起点，end为终点
            printf("%c",s[i]);
        printf("\n");

    }
    return 0;
}*/

/**********排序**********/
/************************************************************************/
/* 冒泡排序                                                                    */
/* 对待排序记录两两(相邻)进行排序码比较，如果不满足顺序，则交换                */
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
	printf("排序后的为：\n");
	for (i=0;i<10;i++)
	{
		printf("%d  ",num[i]);
	}

	return 0;
}*/

/************************************************************************/
/* 选择法排序                                                                  */
/* 每次从待排序的文件中选择出排序最小/大的记录，将该记录放在已排序的最后一个位置,
直到已排序个数等于总个数  */
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
		curmax=i;//默认为剩余的第一个
		for (j=i+1;j<10;j++)//选出剩余中最大的值
		{
			if (num[curmax]<num[j])
			{
				curmax=j;
			}
		}
		if (curmax!=i)//如果不是剩余的第一个位置，就交换
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
/* 插入法排序                                                                  */
/* 将待排序记录 按初始顺序插入到当前已经排好序的记录中，始终保持新文件有序     */
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
	//默认第一个记录已经排好序，所以从i=1开始
	for (i=1;i<10;i++)
	{
		temp=num[i];
		for (j=i-1;j>=0&&temp>num[j];j--)
		{
			num[j+1]=num[j];//未找到插入位置，当前元素后移
		}
		num[j+1]=temp;//找到插入位置，完成插入
	}
	for (i=0;i<10;i++)
	{
		printf("%d ",num[i]);
	}
	return 0;
}*/


/***********2014年************/
/*超级素数
*找出所有的4位超级素数 每行6个数
*1个n位超级素数指一个n位正整数,其前1.2..n位均为素数
*/
/*
#include<stdio.h>
int isPrime(int n)
{
    int i;
    int flag=1;//不是素数
    for(i=2;i<n/2;i++)
    {
        if(n%i==0)
            flag=0;//是素数
    }
    return flag;
}

int isSuper(int n)
{
    int flag=1;//不是超级素数

    if((isPrime(n)==1)&&(isPrime(n/1000)==1)&&(isPrime(n/100)==1)&&(isPrime(n/10)==1))
    {
        flag=0;
    }
    return flag;//是
}

int main()
{
    int m;
    int count=0;
    for(m=1000;m<=9999;m++)
    {
        if(isSuper(m)==0)
        {
            printf("%d ",m);
            count++;
            if(count%6==0)
            {
                printf("\n");
            }
        }
    }
}*/

/*计算二进制
*以二进制方式输入两个正整数,然后输入四则运算符
*按short型计算，结果按二进制输出
*二进制不好处理，转化成十进制计算，再转回二进制
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int BtoD(char a[])
{
    int sum=0;
    int len=strlen(a)-1;
    int i;
    for(i=0;len>=0;i++,len--)
    {
        if(a[i]=='1')
            sum+=pow(2,len);
    }
    return sum;
}

char* DtoB(int x,char str[])
{
    int i=0;
    do{
        str=(char *)realloc(str,(i+1)*sizeof(char));
        str[i++]=x%2+'0';
        x=x/2;
    }while(x>0);
    str[i]='\0';
    return str;
}

int main()
{
    short m,n;
    short result;
    char op;
    int i;
    char *rs=NULL;
    char ms[20],ns[20];
    scanf("%s %s",ms,ns);
    do{
        op=getchar();
    }while(op==' ');
    m=BtoD(ms);
    n=BtoD(ns);
    switch(op)
    {
    case '+':
        result=m+n;
        break;
    case '-':
        result=m-n;
        break;
    case '*':
        result=m*n;
        break;
    case '/':
        result=m/n;
        break;
    }
    rs=DtoB(result,rs);
    for(i=strlen(rs)-1;i>=0;i--)//倒序输出
    {
        printf("%c",rs[i]);
    }
    printf("\n");
    return 0;
}*/

/*编写一个程序，判断规定的字符串是否是合法的C整型常量，是，输出Yes，不是，输出No。
要求程序能循环接受用户的输入，每行输入一个字符串，给出判定结果，再输入一个字符串，
给出判定结果.直到输入Ctrl+Z结束。
*/
/*
#include<stdio.h>

int IsOct(char str[])//判断数据是否为八进制数
{
    int i,flag;
    for(i=0;str[i]!=0;i++)
    {
        if(str[i]>='0'&&str[i]<='7')
            flag=1;
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int IsDec(char str[])//判断数据是否为十进制数
{
    int i,flag;
    for(i=0;str[i]!=0;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            flag=1;
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int IsHex(char str[])//判断数据是否为十六进制数
{
    int i,flag;
    for(i=0;str[i]!=0;i++)
    {
        if(str[i]>='0'&&str[i]<='9'||str[i]>='a'&&str[i]<='f'||str[i]>='A'&&str[i]<='F')
            flag=1;
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    char str[20];
    int flag;
    while(scanf("%s",str)!=EOF)
    {
        switch(str[0])
        {
        case '0':
            if(str[1]=='x'||str[1]=='X')//十六进制
            {
                 if(IsHex(str+2))
                    flag=1;
                 else
                    flag=0;
            }
            else//八进制
            {
                if(IsOct(str+1))
                    flag=1;
                else
                    flag=0;
            }
            break;
        default://十进制
            if(IsDec(str))
                flag=1;
            else
                flag=0;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}*/

/**********2015年***********/
/*
输入一串字符，并验证其是否为正确的电话号码。
长度必须为 11 位
第一位必须为 1，第二位为 3、5、6、8 中得一个，其余位必须为 0-9 中的一个数。
*/
/*
#include<stdio.h>
#include<string.h>

int main()
{
    char str[13];
    int len;
    int i;
    int flag;
    while(scanf("%s",str)!=EOF)
    {
        flag=0;
        len=strlen(str);
        if(len!=11)
        {
            flag=1;//不为正确电话号码
        }
        else
        {
            switch(str[0])
            {
            case '1':
                if(str[1]=='3'||str[1]=='5'||str[1]=='6'||str[1]=='8')
                {
                    for(i=2;i<len-1;i++)
                    {
                        if(str[i]>'9'||str[i]<'0')
                        {
                            flag=1;
                        }
                    }
                }
                else
                {
                    flag=1;
                }
                break;
            default:
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("NO!\n");
        }
        else
        {
            printf("YES!\n");
        }
    }
    return 0;
}*/

/*
无冗余的输入两个字符串，并对其进行拼接，
1）输出拼接后的字符串。例如，string buff    stringbuff
2）对于拼接后的字符串，输出奇数下标组成的子串和偶数下标组成的子串。  例如，srnbf tiguf
3）对于奇数下标组成的子串以及偶数下标组成的子串进行排序。例如 bfnrs fgitu
*/
/*
(1) malloc 分配指定字节数的存储区。此存储区中的初始值不确定
(2) calloc 为指定长度的对象，分配能容纳其指定个数的存储空间。该空间中的每一位(bit)都初始化为0
(3) realloc 更改以前分配区的长度(增加或减少)。当增加长度时，可能需将以前分配区的内容移到另一个足够大的区域，而新增区域内的初始值则不确定
都在stdlib.h中
void* malloc(unsigned size);//需要内存的长度
void* realloc(void* ptr, unsigned newsize);//重新申请的地址长度
void* calloc(size_t numElements, size_t sizeOfElement);
*/
/*
#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
    //问题一
    char *a=(char *)malloc(sizeof(char));
    char *b=(char *)malloc(sizeof(char));
    int counta=1,countb=1;
    int k,len;
    int leno,lenj;
    char c;
    char aj[20]={},ao[20]={};
    while((c=getchar())!=' ')//接收第一个字符串
    {
        a=(char*)realloc(a,counta*sizeof(char));
        *(a+counta-1)=c;
        counta++;
    }
    a=(char*)realloc(a,counta*sizeof(char));
    *(a+counta-1)='\0';

    while((c=getchar())!='\n')//接收第二个字符串
    {
        b=(char *)realloc(b,countb*sizeof(char));
        *(b+countb-1)=c;
        countb++;
    }
    b=(char *)realloc(b,countb*sizeof(char));
    *(b+countb-1)='\0';

    a=(char *)realloc(a,sizeof(char)*(counta+countb-1));
    for(k=0;k<countb;k++,counta++)
    {
        *(a+counta-1)=*(b+k);
    }
    printf("%s\n",a);
    printf("Missions 1 completed!\n");

    //问题2
    len=strlen(a);//获取长度
    counta=0;
    countb=0;
    for(k=0;k<len;k++)
    {
        if(k%2==0)//偶数下标
        {
            *(ao+counta)=*(a+k);
            counta++;
        }
        else
        {
            *(aj+countb)=*(a+k);
            countb++;
        }

    }
    *(ao+counta)='\0';
    *(aj+countb)='\0';
    printf("%s %s\n",ao,aj);
    printf("Missions 2 completed!\n");

    //问题3
    leno=strlen(ao);
    lenj=strlen(aj);
    //对于偶列排序
    for(counta=0;counta<leno;counta++)
    {
        for(countb=0;countb<leno-counta-1;countb++)
        {
            if(*(ao+countb)>*(ao+countb+1))
            {
                c=*(ao+countb);
                *(ao+countb)=*(ao+countb+1);
                *(ao+countb+1)=c;
            }
        }
    }
    //对于奇列排序
    for(counta=0;counta<lenj;counta++)
    {
        for(countb=0;countb<lenj-counta-1;countb++)
        {
            if(*(aj+countb)>*(aj+countb+1))
            {
                c=*(aj+countb);
                *(aj+countb)=*(aj+countb+1);
                *(aj+countb+1)=c;
            }
        }
    }
    printf("%s %s\n",ao,aj);
    printf("Missions 3 completed!\n");
    return 0;
}*/

/*无冗余的输入一个字符串
1）输出该字符串
2）对于不是首次出现的字符，对其进行过滤，例如 abcdacdef,过滤后为 abcdef
3）对于字符 0-9，A-F，a-f,将其对应的 ASCII 码的低 4 位进行对调
例如将 1011,转换为1101,并将对应的 ACSII 码对应的字符输出，若为字母，转换为大写。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int isRepeat(char str[],char c,int m)
{
    int len=strlen(str);
    int i;
    int flag=0;//未出现
    for(i=0;i<m;i++)
    {
        if(str[i]==c)
            flag=1;
    }
    return flag;
}

int isRight(char a)//判断字符是否在范围,返回1在范围内
{
    int flag=0;
    if((a>='0'&&a<='9')||(a>='a'&&a<='f')||(a>='A'&&a<='F'))
    {
        flag=1;
    }
    return flag;
}

int main()
{
    //问题一
    char c;
    int len,i;
    char *p=(char *)malloc(sizeof(char));
    char rp[20];
    int count=1;
    while((c=getchar())!='\n')
    {
        p=(char *)realloc(p,count*sizeof(char));
        *(p+count-1)=c;
        count++;
    }
    p=(char *)realloc(p,count*sizeof(char));
    *(p+count-1)='\0';
    printf("%s\n",p);
    printf("Mission 1 completed!\n\n");

    //问题二
    len=strlen(p);
    count=0;
    for(i=0;i<len;i++)
    {
        if(isRepeat(p,p[i],i)==0)
        {
            rp[count]=p[i];
            count++;
        }
    }
    rp[count]='\0';
    printf("%s\n",rp);
    printf("Mission 2 completed!\n\n");

    //问题3
    count=0;
    //15的二进制为00001111,用一个二进制数异或，表示对后四位取反
    //0^1=1,0^0=0,1^1=0,1^0=1
    for(i=0;i<len;i++)
    {
        if(isRight(p[i])==1)
        {
            p[i]^=15;
        }
    }
    for(i=0;i<len;i++)
    {
        if(islower(p[i]))
        {
            p[i]-=32;
        }
    }
    printf("%s\n",p);
    printf("Mission 3 completed!\n\n");

    return 0;
}*/


//将其对应的 ASCII 码的低 4 位进行对调
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char c='a';
    //printf("%d\n",(c>>3)&7);
    char a[10],a2[10];
    int len,i;
    int count=0;
    char strh[5]={};//高位
    char strl[5]={};//低位
    int convertN;
    itoa(97,a,2);
    len=strlen(a);
    //取低四位 并取反存储到strl中
    for(i=len-1;i>=len-4;i--)
    {
        strl[count]=a[i];
        count++;
    }
    count=0;
    //取高四位 并存储到strh中
    for(i=0;i<=len-5;i++)
    {
        strh[count]=a[i];
        count++;
    }
    printf("\n%s\n",strl);
    printf("\n%s\n",strh);
    printf("\n%s\n",a);
    //convertN=atoi(strcat(strh,strl));
    //printf("\n%s\n",strcat(strh,strl));
    //printf("\n%d\n",convertN);
    printf("\n%c\n",strtol(strcat(strh,strl),NULL,2));
    //strtol(strcat(strh,strl),NULL,2);
    return 0;
}*/


/*提取连续位
如提取a的第四至六位
(a>>3)&7
右移(n-1)位，然后与上m个二进制1
11110000
00011110
00000111*/
/*
先交换每相邻两位上的数，以后把交换过来的数都看成一个整体，继续进行单位的交换操作，之后以4为单位，以此类推
*/
/*
void VLBinSwap(unsigned char *s)//二进制逆序
{
    unsigned char temp1,temp2,temp3;
    temp1=((*s)&0x55)<<1;
    temp2=((*s)&0xAA)>>1;
    temp3=(temp1|temp2);
    temp1=(temp3&0x33)<<2;
    temp2=(temp3&0xCC)>>2;
    temp3=(temp1|temp2);
    temp1=(temp3&0x0F)<<4;
    temp2=(temp3&0xF0)>>4;
    (*s)=(temp1|temp2);
}*/

/************2016年************/
/*输入字符串，共三问，去除前面的空格，中间多个空格只保留一个空格，数字字母中间加上_*/
/*
#include<stdio.h>
#include<string.h>
void RemoveExtraSpace(char *str)
{
    int keep_space=0;//0代表否
    int new_str_end=0;
    int i;
    for(i=0;str[i];++i)
    {
        if(str[i]!=' ')
        {
            str[new_str_end++]=str[i];
            keep_space=1;
        }
        else if(keep_space==1)
        {
            str[new_str_end++]=str[i];
            keep_space=0;
        }
    }
    if(new_str_end>0&&str[new_str_end-1]==' ')
    {
        str[new_str_end-1]='\0';
    }
    else
    {
        str[new_str_end]='\0';
    }
}
int main()
{
    char a[100];
    gets(a);
    RemoveExtraSpace(a);
    printf("%s",a);
    return 0;
}*/

/*********树的遍历***********/
/**树的孩子表示法(指针方式)**/
/*
#include<stdio.h>
#define m 3
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *child[m];//指向子女的指针数组
}node,*tree;
tree root;

//前序遍历--根左右
//按照各自规定的顺序，访问根结点的时候就输出根结点的值，访问子树时便进行递归调用即可
void preorder(tree p)//p为指向树根结点的指针
{
    int i;
    if(p!=NULL)//树不为空
    {
        printf("%c",p->data);//输出根结点的值
        for(i=0;i<m;++i)//递归实现各子树的前序遍历
        {
            preorder(p->child[i]);
        }
    }
}

//后序遍历--左右根
void postorder(tree p)
{
    int i;
    if(p!=NULL)
    {
        for(i=0;i<m;++i)//m为tree的度数
        {
            postorder(p->child[i]);
        }
        printf("%c",p->data);
    }
}

//层次遍历--从根开始，之后每层从左到右
//层次遍历首先访问根结点，因此初始队列仅包含根结点。只要队列不为空，则还有结点未被访问,遍历可以继续
//每次需访问一个结点时只需取队头元素，访问完成后，若其子女非空，则将其所有子女按顺序依次进队
//不断重复以上，直到队列为空
void levelorder(tree t)//t为指向树根结点的指针
{
    tree queue[100];//存放等待访问的结点队列
    int f,r,i;//f为队头指针，r为队尾指针
    tree p;
    f=0;
    r=1;
    queue[0]=t;
    while(f<r)//队列不为空
    {
        p=queue[f];
        f++;
        printf("%c",p->data);//访问队头元素
        for(i=0;i<m;++i)//将刚被访问的元素的所有子女结点一次进队
        {
            if(p->child[i])
            {
                queue[r]=p->child[i];
                ++r;
            }
        }
    }

}*/

/*********二叉树的遍历**********/
#include<stdio.h>
#include<stdlib.h>

//链式存储下二叉树结点数据结构的定义
typedef char datatype;//结点属性类型
typedef struct node
{
    datatype data;
    struct node *lchild,*rchild;
}bintnode;
typedef bintnode *bintree;
bintree root;//指向二叉树树根结点的指针

/*******递归实现*******/
//二叉树的遍历是递归定义的，只要按照遍历规定的次序，访问根结点就输出根结点的值，访问左/右子树时进行递归调用
//前序遍历--根左右
/*void preorder(bintree t)//指针变量t表示指向二叉树根结点的指针
{
    if(t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

//中序遍历--左根右
void inorder(bintree t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

//后序遍历--左右根
void postorder(bintree t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}*/

/******二叉树的创建******/
//根据二叉树前序遍历结果建立一棵给定二叉树
//由于一棵非空二叉树的前序遍历序列中，第一个结点一定是该二叉树的根结点
//接下来应该是该二叉树左子树所有结点前序遍历的结果(若左子树存在)
//然后是该二叉树左右子树所有结点前序遍历的结果(若右子树存在)

//因此,建立时，应该将第一个输入的结点作为二叉树的根结点
//后序输入的结点序列是二叉树左子树前序遍历的结果，以生成二叉树左子树
//接着输入的结点序列是二叉树右子树前序遍历的结果，以生成二叉树右子树
//与整棵树生成过程相同，只是处理的对象范围不同，用递归实现
/*bintree createbintree()
{
    char ch;
    bintree t;
    if((ch=getchar())=='#')
    {
        t=NULL;
    }
    else
    {
        t=(bintnode *)malloc(sizeof(bintnode));
        t->data=ch;
        t->lchild=createbintree();
        t->rchild=createbintree();
    }
    return t;
}*/

/*******非递归实现*******/
//非递归方式实现二叉树遍历必须使用一个栈记录回溯点，以便回溯
//给出一个顺序栈的定义
/*
typedef struct stack//栈结构定义
{
    bintree data[100];
    int tag[100];//为栈中每个元素设置的标记
    int top;//栈顶指针
}seqstack;

void push(seqstack *s,bintree t)//进栈
{
    s->data[s->top]=t;
    s->top++;
}

bintree pop(seqstack *s)//出栈
{
    if(s->top!=0)
    {
        s->top--;
        return (s->data[s->top]);
    }
    else
        return NULL;
}
//前序遍历
//对于一棵树(子树)t,如果t非空，访问完t的根结点值后，应该进入t的左子树，但是此时应该先将t保存起来
//以便访问完其左子树后，进入其右子树的访问，即应该在t处设置一个回溯点，并将回溯点进栈保存
//栈顶即将出栈时，意味着其根结点和左子树已访问完成，出栈后应该进入右子树进行访问
void preorder1(bintree t)
{
    seqstack s;
    s.top=0;
    while((t)||(s.top!=0))//当前处理的子树不为空
    {
        if(t)
        {
            printf("%c ",t->data);
            push(&s,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&s);
            t=t->rchild;
        }
    }
}

//中序遍历
//当栈中元素位于栈顶即将出栈时，意味着其左子树已访问完成，出栈后立即访问其根结点，再进入右子树进行访问
void inorder1(bintree t)
{
    seqstack s;
    s.top=0;
    while((t!=NULL)||(s.top!=0))
    {
        if(t)
        {
            push(&s,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&s);
            printf("%c ",t->data);
            t=t->rchild;
        }
    }
}

//后序遍历
//当一个元素刚进栈时，其对应的tag值置0；当它第一次位于栈顶即将被处理时，tag为0，意味着应该访问其右子树
void postorder1(bintree t)
{
    seqstack s;
    s.top=0;
    while((t)||(s.top!=0))
    {
        if(t)
        {
            s.data[s.top]=t;
            s.tag[s.top]=0;
            s.top++;
            t=t->lchild;
        }
        else
        {
            if(s.tag[s.top-1]==1)
            {
                s.top--;
                t=s.data[s.top];
                printf("%c ",t->data);
                t=NULL;
            }
            else
            {
                t=s.data[s.top-1];
                s.tag[s.top-1]=1;
                t=t->rchild;
            }
        }
    }
}*/


/***********浙大************/
//Hello world for U
/*#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int len;
    int n1,n3;//左右两边
    int n2;//下边
    int i=0;//输出第i个字符
    int j;//中间的空格
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);//记录字符串长度
        n1=(len+2)/3;
        n3=(len+2)/3;
        n2=len-2*n1+2;
        while(n1>1)
        {
            printf("%c",a[i]);
            for(j=0;j<n2-2;j++)
            {
                printf(" ");
            }
            printf("%c",a[len-1-i]);
            printf("\n");
            i++;
            n1--;
        }
        for(;i<n3+n2-1;i++)
        {
            printf("%c",a[i]);
        }
    }
    return 0;
}*/

/*A+B
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。*/
//字符要进行运算 -'0'
/*#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str1[15],str2[15];
    long long int s1=0,s2=0;
    int i,j;//用于循环
    int len1,len2;
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        len1=strlen(str1);
        len2=strlen(str2);
        s1=0;
        s2=0;
        for(i=0;i<len1;i++)
        {
            if(str1[i]>='0'&&str1[i]<='9')
            {
                s1=s1*10+str1[i]-'0';
            }
        }
        if(str1[0]=='-')
        {
            s1=-s1;
        }
        for(i=0;i<len2;i++)
        {
            if(str2[i]>='0'&&str2[i]<='9')
            {
                s2=s2*10+str2[i]-'0';
            }
        }
        if(str2[0]=='-')
        {
            s2=-s2;
        }
        printf("%lld\n",s1+s2);
    }
    return 0;
}*/

/*ZOJ问题
对给定的字符串(只包含'z','o','j'三种字符),判断他是否能AC。
是否AC的规则如下：
1. zoj能AC；
2. 若字符串形式为xzojx，则也能AC，其中x可以是N个'o' 或者为空；
3. 若azbjc 能AC，则azbojac也能AC，其中a,b,c为N个'o'或者为空；
zj 将原字符串，分成三个部分a,b,c，并且有a*b==c满足条件就AC，不满足条件就会WA。
----------
AC情况:
a个o+z+b个o+j+c个o
c=a*b,且b>=1
(o^a)z(o^b)j(o^c)c=a*b,且b>=1
*/
//法1
/*#include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    int count1,count2,count3;
    int len;
    int i,j;
    int flag=0,cnt=0;
    while(scanf("%s",str)!=EOF)
    {
        count1=0;
        count2=0;
        count3=0;
        flag=0;
        cnt=0;
        len=strlen(str);
        for(i=0;i<len;++i)
        {
            if(flag==0)
            {
                if(str[i]=='o')
                {
                    count1++;
                    continue;
                }
                else if(str[i]=='z')
                {
                    flag++;
                    continue;
                }
                else if(str[i]=='j')
                {
                    cnt=1;
                    break;
                }
            }
            if(flag==1)
            {
                if(str[i]=='o')
                {
                    count2++;
                    continue;
                }
                else if(str[i]=='j')
                {
                    flag++;
                    continue;
                }
                else if(str[i]=='z')
                {
                    cnt=1;
                    break;
                }
            }
            if(flag==2)
            {
                if(str[i]=='o')
                {
                    count3++;
                    continue;
                }
                else if(str[i]!='o')
                {
                    cnt=1;
                    break;
                }
            }
        }
        if(!cnt)
        {
            if(strcmp(str,"zj")==0)
            {
                printf("Accepted\n");
            }
            else if(flag==2&&count1*count2==count3&&count2)
                printf("Accepted\n");
            else
                printf("Wrong Answer\n");
        }
    }

    return 0;
}*/
/*
//法2
#include<string.h>
#include<stdio.h>
int main()
{
    char s[1005];
    int i,j;
    int count1,count2,count3;
    int len;
    while(scanf("%s",s)!=EOF)
    {
        count1=0;
        count2=0;
        count3=0;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='z')
                count1++;
            else if(s[i]=='j')
                count2++;
            else
                count3++;
        }
        if(count1!=1||count2!=1||count3==0)
        {
            printf("Wrong Answer\n");
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(s[i]=='z')
                break;
        }
        for(j=len-1;j>=0;j--)
        {
            if(s[j]=='j')
                break;
        }
        if(i*(j-i-1)==len-j-1)
            printf("Accepted\n");
        else
            printf("Wrong Answer\n");
    }

    return 0;
}*/

/*奥运排序问题
输入：
有多组数据。
第一行给出国家数N，要求排名的国家数M，国家号从0到N-1。
第二行开始的N行给定国家或地区的奥运金牌数，奖牌数，人口数（百万）。
接下来一行给出M个国家号。
输出：
排序有4种方式: 金牌总数 奖牌总数 金牌人口比例 奖牌人口比例
对每个国家给出最佳排名排名方式和最终排名
格式为: 排名:排名方式
如果有相同的最终排名，则输出排名方式最小的那种排名，对于排名方式，金牌总数<奖牌总数<金牌人口比例<奖牌人口比例
如果有并列排名的情况，即如果出现金牌总数为 100,90,90,80.则排名为1,2,2,4.
每组数据后加一个空行。
*/
/*
#include<stdio.h>
#include<string.h>

typedef struct country
{
    int goldNum;
    int mediaNum;
    int population;
    double goldRatio;
    double mediaRatio;
    int sKind;//最佳排名排名方式
    int BestRank;//最终排名
    int Rank;//当前排名
}country;

country c[1000];

int main()
{
    int M,N;
    int i,j;//用于循环
    int ID;
    country cSort[1000];
    while(scanf("%d %d",&M,&N)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d %d %d",&c[i].goldNum,&c[i].mediaNum,&c[i].population);
            c[i].goldRatio=(c[i].goldNum*1.0)/c[i].population;
            c[i].mediaRatio=(c[i].mediaNum*1.0)/c[i].population;
        }
        //给出要排序国家的ID
        for(i=0;i<M;i++)
        {
            scanf("%d",&ID);
            cSort[i]=c[ID];
        }
        for(i=0;i<M;i++)
        {
            //金牌总数
            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].goldNum<cSort[j].goldNum)
                {
                    cSort[i].Rank++;
                }
            }
            cSort[i].BestRank=cSort[i].Rank;
            cSort[i].sKind=1;
            //奖牌总数
            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].goldNum<cSort[j].goldNum)
                {
                    cSort[i].Rank++;
                }
            }
            if(cSort[i].Rank<cSort[i].BestRank)
            {
                cSort[i].BestRank=cSort[i].Rank;
                cSort[i].sKind=2;
            }
            //金牌人口比例
            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].goldRatio<cSort[j].goldRatio)
                {
                    cSort[i].Rank++;
                }
            }
            if(cSort[i].Rank<cSort[i].BestRank)
            {
                cSort[i].BestRank=cSort[i].Rank;
                cSort[i].sKind=3;
            }
            //奖牌人口比例
            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].mediaRatio<cSort[j].mediaRatio)
                {
                    cSort[i].Rank++;
                }
            }
            if(cSort[i].Rank<cSort[i].BestRank)
            {
                cSort[i].BestRank=cSort[i].Rank;
                cSort[i].sKind=4;
            }
            printf("%d:%d\n",cSort[i].BestRank,cSort[i].sKind);
        }
        printf("\n");
    }
    return 0;
}*/



/****************Dijkstra问题******************/
/*最短路径问题
给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，
要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
*/
/*
#include<stdio.h>
#include<string.h>
#define MAX 1000000
#define N 1005
int map[N][N];//记录距离
int value[N][N];//记录花费 与map一一对应
int dis[N];//存放每次的临时最短路径
int val[N];//存放目前最短路径的对应价格
int vis[N];
////此处和最小生成树有一点不一样 最小生成树 是一步步再到从该节点出发的最短路径
void dijkstra(int start,int n)//start为要查询的节点，n为节点数
{
    int i,j,k,min;
    for(i=1;i<=n;i++)//初始化
    {
        dis[i]=map[start][i];
        val[i]=value[start][i];
    }
    dis[start]=0;
    for(i=1;i<=n-1;i++)
    {
        min=MAX;//对于特定节点，此处处理的最短路径
        k=0;
        for(j=1;j<=n;j++)
        {
            if((!vis[j])&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        if(k==0)
            return;
        for(j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])////若目前的dis[j]大于目前要比较的加上现在这一段的值 
            {
                dis[j]=dis[k]+map[k][j];
                val[j]=val[k]+value[k][j];
            }
			//如果当前最短路径相同，去价格小的路径 
            else if((dis[j]==dis[k]+map[k][j])&&(val[j]>val[k]+value[k][j]))
            {
                val[j]=val[k]+value[k][j];
            }
        }
    }
}

int main()
{
    int n,m;
    int a,b,d,p;
    int i;//用于循环
    int s,t;
    while(scanf("%d %d",&n,&m)&&(n+m))//n和m为0时输入结束。
    {
        memset(vis,0,sizeof(vis));
        memset(map,MAX,sizeof(map));
        memset(value,MAX,sizeof(value));
        for(i=0;i<m;i++)
        {
            //每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(map[a][b]>d)//去重
            {
                map[a][b]=d;
                map[b][a]=d;
                value[a][b]=p;
                value[b][a]=p;
            }
        }
        //后一行是两个数 s,t;起点s，终点。
        scanf("%d %d",&s,&t);
        dijkstra(s,n);
    }
    printf("%d %d\n",dis[t],val[t]);
}*/


/*城市平乱
南将军统领着N个部队，这N个部队分别驻扎在N个不同的城市。
他在用这N个部队维护着M个城市的治安，这M个城市分别编号从1到M。
现在，小工军师告诉南将军，第K号城市发生了暴乱，南将军从各个部队都派遣了一个分队沿最近路去往暴乱城市平乱。
现在已知在任意两个城市之间的路行军所需的时间，你作为南将军麾下最厉害的程序员，请你编写一个程序来告诉南将军第一个分队到达叛乱城市所需的时间。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 1000005
#define N 1050

int dis[N];
int map[N][N];//路径之间的用时
int vis[N];
int armycity[N];//部队所在城市的编号

void dijkstra(int query,int v)//要查询的城市，节点数
{
    int i,j,k;
    int min=0;
    for(i=1;i<=v;i++)
    {
        dis[i]=map[query][i];//初始化
    }
    dis[query]=0;

    for(i=1;i<=v-1;i++)//遍历其它点到源点的最短路径
    {
        min=Max;
        k=0;
        for(j=1;j<=v;j++)//在集合U中选取一个到源点距离最小的点
        {
            if((!vis[j])&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)//没有可扩展点
            return;
        vis[k]=1;
        for(j=1;j<=v;j++)//更新
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
            }
        }
    }
}

int main()
{
    int n,m,p,q;//N表示部队数，M表示城市数，P表示城市之间的路的条数,Q表示发生暴乱的城市编号。
    int t;//测试数据的组数
    int i;//用于循环
    int a,b,c;
    int ans=0;
    scanf("%d",&t);
    while(t--)
    {
        //每组测试数据的第一行是四个整数N,M,P,Q
        scanf("%d %d %d %d",&n,&m,&p,&q);
        //随后的一行是N个整数，表示部队所在城市的编号。
        for(i=0;i<n;i++)
        {
            scanf("%d",&armycity[i]);
        }
        //void *memset(void *str, int c, size_t n)
        //str-填充的内存块的指针
        //c-这是要设置的值。作为一个int值传递，但使用这个值的无符号字符型转换函数填充的内存块。
        //n-要设置的值的字节数
        //返回一个指向内存区域str的指针
        memset(map,Max,sizeof(map));
        memset(vis,0,sizeof(vis));
        //再之后的P行，每行有三个正整数，a,b,t(1<=a,b<=M,1<=t<=100)，表示a,b之间的路如果行军需要用时为t
        for(i=0;i<p;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(map[a][b]>c)
            {
                map[a][b]=c;
                map[b][a]=c;
            }
        }
        dijkstra(q,m);
        ans=Max;
        for(i=0;i<n;i++)
        {
            if(ans>dis[armycity[i]])
            {
                ans=dis[armycity[i]];
            }
        }
        //输出第一支部队到达叛乱城市时的时间
        printf("%d\n",ans);
    }
    return 0;
}*/

/*二叉搜索树
判断两序列是否为同一 二叉搜索树序列
*/
/*
本题大意是先输入样例个数，第二行给出标准二叉搜索树，接下来n行输入，每次判断输入与标准二叉搜索树是否吻合。
  所谓二叉搜索树，就是左孩子<根节点<右孩子的一棵树。
insert函数，初始化t1,t2后，如果t[pos]!=-1,则会判断t[pos]和c（即s[i]所对应的数字）的大小
如果t[pos]<c,则搜索右孩子，即pos=pos*2+1,反之，搜索左孩子,pos=pos*2。
总之，先把标准二叉搜索树建起来，接下来每次输入也建起树来，循环遍历比较，如果一模一样，则输出YES，否则输出NO。
*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

char s[N];//s存每次输入的字符串
int t1[N];//t1存标准输入的搜索树
int t2[N];//t2存样例输入的树

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]<c)//搜索右孩子
            pos=2*pos+1;
        else//搜索左孩子
            pos=2*pos;
    }
    t[pos]=c;
}

void build(char *str,int *t)
{
    int i;
    t[1]=str[0]-'0';
    for(i=1;str[i];i++)
    {
        insert(str[i],t);
    }
}

int main()
{
    int n;
    int i;//用于循环
    //开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(t1,-1,sizeof(t1));
        scanf("%s",s);
        build(s,t1);
        while(n--)
        {
            memset(t2,-1,sizeof(t2));
            scanf("%s",s);
            build(s,t2);
            for(i=0;i<=5000;i++)
            {
                if(t1[i]!=t2[i])
                    break;
            }
            if(i==5000)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}*/

/**********2009北航*************/
/*迭代求立方根
立方根的逼近迭代方程是 y(n+1) = y(n)*2/3 + x/(3*y(n)*y(n)),其中y0=x.求给定的x经过n次迭代后立方根的值。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double fun(double x,int n)
{
    double sum=0;
    int i=0;
    double x1;
    x1=x;
    while(i<n)
    {
        sum=x*2/3+x1/(3*x*x);
        x=sum;
        i++;
    }
    return sum;
}

int main()
{
    int x,n;
    double y;
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        y=fun(x,n);
        printf("%6f\n",y);
    }
    return 0;
}*/

/*数组排序*/
/*输入一个数组的值,求出各个值从小到大排序后的次序。*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 1000

typedef struct NUM{
    int data;
    int order;
};

struct NUM array[N];

void selectSort(struct NUM *a,int size)
{
    int i,j;
    struct NUM t;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j].data>a[j+1].data)//a[0]最大
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main()
{
    int num;
    int i;//用于循环
    int order[N];
    struct NUM temp;
    int cnt;
    int pre;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&array[i].data);
            array[i].order=i;//数字的输入次序
            order[i]=0;//初始化排序数组
        }
        selectSort(array,num);
        cnt=1;
        pre=-999999;
        for(i=0;i<num;i++)
        {
            //处理相同大小的数
            if(i&&pre==array[i].data)
            {
                order[array[i].order]=cnt;
            }
            else if(i&&pre!=array[i].data)
            {
                order[array[i].order]=++cnt;
            }
            else if(!i)
            {
                order[array[i].order]=cnt;
            }
            pre=array[i].data;//记录前一个数据的data
        }
        for(i=0;i<num;i++)
        {
            if(i!=num-1)
            {
                printf("%d ",order[i]);
            }
            else
                printf("%d\n",order[i]);
        }
    }
    return 0;
}
*/

/*字符串的查找删除
给定一个短字符串（不含空格），再给定若干字符串，在这些字符串中删除所含有的短字符串。
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000

char str[N],string[N][N],string2[N][N];
//str为删除部分短字符,string为原来输入的字符串,string2存储处理后的字符串

int main()
{
    int index=0;//第几个字符串
    int i,j,k;//用于循环
    //输入一个短字符串
    gets(str);
    //输入若干字符串直到文件结束为止
    while(gets(string[index]))
    {
        //判断输入结束,内容存储在string[][]里
        if(strcmp(string[index],"}")==0)
        {
            break;
        }
        index++;
    }
    //转换大小写
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
    }
    for(i=0;i<=index;i++)
    {
        //一行行处理
        for(j=0;j<strlen(string[i]);j++)
        {
            //string复制到string2
            string2[i][j]=string[i][j];
            //大小写转换
            if(string[i][j]>='A'&&string[i][j]<='Z')
            {
                string[i][j]=string[i][j]+32;
            }
        }
        //匹配处理
        for(j=0,k=0;j<strlen(string[i]);)
        {
            //继续比较后一字符
            if(string[i][j+k]==str[k])
            {
                k++;
                //匹配成功
                if(k==strlen(str))
                {
                    j=j+k;
                }
            }
            //开始新一轮的匹配
            else
            {
                if(string[i][j]!=' ')
                {
                    printf("%c",string2[i][j]);
                }
                j++;
                k=0;
            }
        }
        printf("\n");
    }
    return 0;
}*/

/* Sn = 1 + 1/2 + 1/3 + ... + 1 / n. Clearly, for any integer K, when n is large enough, Sn is larger than K.
Now given an integer K (1 <= K <= 15),output the smallest n that satisfies Sn > K.*/
/*#include<stdio.h>

int main()
{
    double sn=0.0;
    int n,k;
    int i;
    while((scanf("%d",&k)!=EOF)&&k>=1&&k<=15)
    {
        sn=0;
        for(i=1;sn<=k;i++)
        {
            sn=sn+1.0/i;
        }
        printf("%d\n",i-1);
    }
}*/
/*#include<stdio.h>
int main()
{
    int k,i;
    double sn=0.0;
    scanf("%d",&k);
    for(i=1;sn<=k;i++)
    {
        sn=sn+1.0/i;
    }
    printf("%d",i-1);
    return 0;
}*/

/*掷硬币
有一枚特殊硬币，这枚硬币掷出正面的概率为p，反面的概率为1-p。
现在开始掷硬币，直到正反两面均出现过时停下。问掷硬币的期望次数。
输入数据第一行包含一个整数T<=20，表示测试组数
期望次数 = ∑掷硬币次数 * 该次数出现的概率（掷硬币次数>=2）
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int T;
    double p,fp;
    double sum,index;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        //每行测试数据包含一个精确到千分位的实数p
        scanf("%lf",&p);
        fp=1.0-p;
        sum=0.0;
        i=2;//i为掷硬币次数
        while(1)
        {
            index=pow(p,i-1)*fp+pow(fp,i-1)*p;
            if(index*i<0.001)
                break;
            sum+=i*index;
            i++;
            //printf("sum==%lf\n",sum);
        }
        //其功能是“向下取整”，或者说“向下舍入”，即取不大于x的最大整数;ceil()向上取整
        //表示期望次数四舍五入到整数的值。
        sum=floor(sum+0.5);
        printf("%d\n",(int)sum);
    }
    return 0;
}*/

/*回文回文数
如果一个数从左往右读和从右往左读都是一样，那么这个数就叫做 “回文数”。
事实上，有一些数（如 21），在十进制时不是回文数，但在其它进制（如二进制时为 10101）时就是回文数。
现在，你需要找出来，前 N 个满足大于 S 且在两种或两种以上进制（二进制至十进制）上是回文数的十进制数。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 100
int num[N];
int len;
//转化为n进制
int toOther(int x,int n)//原数为x,转换为n进制
{
    int temp=x,pos=0;
    while(temp!=0)
    {
        num[++pos]=temp%n;
//        printf("%d\n",u[i]);
        temp=temp/n;
    }
    return pos;
}

//判断是否为回文
int isHui()
{
    int i;
    int flag=0;//0为回文
    for(i=0;i<len/2;i++)
    {
        if(num[i]!=num[len-i-1])
        {
            flag=1;//1为非回文
        }
    }
    return flag;
}


int main()
{
    int t;
    int n,s;
    int count;
    int i;
    //toOther(9,2);
    //第一行是数据组数 T(T ≤10)
    scanf("%d",&t);
    while(t--)
    {
        //对于每组数据，包含两个数N(N≤15)，S(0<S≤10000)
        scanf("%d %d",&n,&s);
        while(n)
        {
            s++;
            count=0;
            for(i=2;i<=10;i++)
            {
                len=toOther(s,i);
                if(isHui())
                    count++;
                if(count>=2)
                    break;
            }
            if(count>=2)
            {
                n--;
                printf("%d\n",s);
            }
        }
    }
    return 0;
}*/

/********第三届H-star**********/
/*剪纸片
1.将一张纸剪成两片(平行于短边剪开)
2.将其中一片剪成一个圆,作为圆柱的底面
3.纸的另一边沿着圆围起来，直到围成一圈，形成一个无盖的圆柱体
求一张纸片按上述方式所组成的圆柱的最大体积
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double max(double a,double b)
{
    return a>b?a:b;
}
double min(double a,double b)
{
    return a>b?b:a;
}
int main()
{
    int t;
    int w,h;
    double pi=acos(-1);
    double v,r;//输出纸片能构成的最大圆柱体的体积
    //代表接下来有t组数据
    scanf("%d",&t);
    while(t--)
    {
        //分别代表纸片的宽和高
        scanf("%d %d",&w,&h);
        //以w为高
        r=min(w/2.0,h/(2.0+2.0*pi));
        v=pi*r*r*w;
        //以h-2*r为高
        r=min(h/3.0,w/(2.0*pi));
        //取两个体积更小的一个
        v=max(v,pi*r*r*(h-2*r));
        printf("-----\n");
        printf("%.3f\n",v);
    }
    return 0;
}*/

/*废品收集记
在河海有n个垃圾桶，每个垃圾桶里面都有价值为m，体积为b的废品。但是你的背包体积只有V，
为了赚更多钱，为了身边的Ta更幸福，你每一次捡破烂，都希望自己体积为V的背包里装的废品价值尽量多。
所以你又想起你曾经敲过的代码，你决定写一个程序解决这个问题。
*/
/*背包问题
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），
那么就可以转化为一个只牵扯前i-1件物品的问题。如果不放第i件物品，
那么问题就转化为“前i-1件物品放入容量为v的背包中”，价值为f[i-1][v]；
如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，
此时能获得的最大价值就是f[i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。
*/
/*伪代码
for i=1..N
    for v=V..0
        f[v]=max{f[v],f[v-c[i]]+w[i]};
*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    int n,V;
    int m[N],b[N];
    int dp[N];
    int i,j;//用于循环
    //t组数据
    scanf("%d",&t);
    while(t--)
    {
        //n表示垃圾桶的数量，V表示背包的容量
        scanf("%d %d",&n,&V);
        //输入包括n个数字，代表每个垃圾桶中废品的价值m
        for(i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
        }
        //输入包括n个数字，代表每个垃圾桶中废品需要占用的背包的容量b
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        //初始化
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=V;j>0;j--)
            {
                //if(j>=m[i])
                //{
				//即从原来的重量j中，即用重量为b[i],价值为m[i]的物品替代原来 重量为b[i]的部分，进行比较，取较大值
                    dp[j]=max(dp[j],dp[j-b[i]]+m[i]);
                //}
            }
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}*/
/*
Speakless很早就想出国，现在他已经考完了所有需要的考试，准备了所有要准备的材料，
于是，便需要去申请学校了。要申请国外的任何大学，你都要交纳一定的申请费用，这可是很惊人的。
Speakless没有多少钱，总共只攒了n万美元。他将在m个学校中选择若干的（当然要在他的经济承受范围内）。
每个学校都有不同的申请费用a（万美元），并且Speakless估计了他得到这个学校offer的可能性b。
不同学校之间是否得到offer不会互相影响。“I NEED A OFFER”，他大叫一声。
帮帮这个可怜的人吧，帮助他计算一下，他可以收到至少一份offer的最大概率。
（如果Speakless选择了多个学校，得到任意一个学校的offer都可以）。
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double max(double a,double b)
{
    return a>b?a:b;
}

void main()
{
    int n,m;
    int a[100];//申请费用
    double b[100];//可能性
    int i,j;
    double *dp;

    while(scanf("%d %d",&n,&m)&&(n+m)!=0)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d %ld",&a[i],&b[i]);
        }
        dp=(double *)malloc(sizeof(double)*(n+1));
        memset(dp,0,(n+1)*sizeof(double));
        for(i=1;i<=m;i++)
        {
            for(j=n;j>=a[i];j--)
            {
				// 1-都不接收=可以收到offer
                dp[j]=max(dp[j],1-(1-dp[j-a[i]])*(1-b[i]));
            }
        }
        printf("%.1f%%\n",dp[n]*100);
    }
}*/
/*Northcott游戏
游戏在一个n行m列（1 ≤ n ≤ 1000且2 ≤ m ≤ 100）的棋盘上进行，
每行有一个黑子（黑方）和一个白子（白方）。
执黑的一方先行，每次玩家可以移动己方的任何一枚棋子到同一行的任何一个空格上，
当然 这过程中不许越过该行的敌方棋子。双方轮流移动，直到某一方无法行动为止，移动最后一步的玩家获胜。
alpha总是先下（黑方）。图1是某个初始局面，图二是 alpha移动一个棋子后的局面（第一行的黑子左移两步）。
*/
/*
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,m;
    int x,y;
    int i;//用于循环
    int sg;//两个棋子的距离的绝对值减1,当两个棋子相邻时，已经是必败态
    //每组数据第一行为两个整数n和m，由空格分开。
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        sg=0;
        //接下来有n行，每行两个数x，y (1 ≤ x,y ≤ m)分别表示Tom和Jerry在该行棋子所处的列数。
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            //^=异或 相同为0;不同为1
            sg^=abs(x-y)-1;
        }
        if(sg==0)//当两个棋子相邻时，已经是必败态
            printf("BAD LUCK!\n");
        else
            printf("I WIN!\n");
    }
    return 0;
}*.

/*
小明有一个癖好，吃糖果的时候，不喜欢连着吃同一种糖果，喜欢先吃一种，下一次吃另一种（小明一次只吃一颗糖果）；
可是小明不知道是否存在一种吃糖果的顺序使得他能把所有糖果都吃完。
*/
//对于一种的n个糖果必须有其他种类的糖果的总和>=n-1来分开，总和会超过int。
/*#include<stdio.h>
#define N 10000
int main()
{
    int t,n;
    long mi[N];
    int i;//用于循环
    long sum;
    int tag;
    //t组数据
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        //第一行是一个整数N（0<N<=1000000)
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&mi[i]);
            sum+=mi[i];
        }
        tag=0;
        for(i=0;i<n;i++)
        {
            if(mi[i]>sum-mi[i]+1)
            {
                tag=1;
                break;
            }
        }
        if(!tag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}*/

/*Lecture
coco可以卸下老师讲的每一个单词，不管是第一种语言还是第二种语言。
当然，在上课期间coco写下的每一个单词都是这两种语言中最短的那个。如果单词长度一样，coco会倾向于写第一种语言。
现在给你一段老师讲课的文本，找出这节课coco会在笔记本上记录的内容。
*/
/*
#include<stdio.h>
#include<string.h>

struct poin
{
    char a[15];
    char b[16];
}p[1005];
char c[15];

int main()
{
    int n,m;
    int i;//用于循环
    //第一行包含两个整数,n和m(1<= n,m<= 3000),老师堂内容的单词数和这些语言中的单词数
    scanf("%d %d",&n,&m);
    //接下来的 m 行包含了这些单词.第 i 行包含两个串 ai, bi。ai 是第一门语言的单词,
    //bi是第二门语言的单词,这两个单词拥有相同的意思.输入保证没有相同的单词出现在两种语言中,而且每个单词在一中语言中只出现一次.
    for(i=0;i<m;i++)
    {
        scanf("%s %s",p[i].a,p[i].b);
    }
    while(n--)
    {
        //接下来的一行有 n 个空格隔开的串 c1,c2,...,cn---讲课的内容.保证每一个 Ci 串都会在集合{a1,a2,...am}中.
        scanf("%s",c);
        for(i=0;i<m;i++)
        {
            if(strcmp(c,p[i].a)==0||strcmp(c,p[i].b)==0)
            {
                if(strlen(p[i].a)>strlen(p[i].b))
                {
                    printf("%s",p[i].b);
                }
                else
                {
                    printf("%s",p[i].a);
                }
                if(n!=0)
                {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}*/

/*摆放餐具(计算几何)
现给出桌子的大小R和盘子的大小r，试问BG家是否能够招待n个客人。
*/
/*
1、对于有N个小圆的情况，我们肯定是要将小圆紧密的排列在一起才能贪心出最小半径。
那么所以我们将N个小圆排列成一个以每个圆圆心连线是一个正N边形的方式排列。
2、接下来分类讨论：
①n==1的时候不会组成正N边形，那么直接判断小圆和大圆的半径大小即可。
②n==2的时候也不会组成正N边形，那么我们肯定是对接排列的方式最优。那么直接判断小圆二倍半径和大圆的半径大小即可。
③n>=3的时候就会组成正N边形，那么我们就按照上述排列方式进行排列好之后，目的是为了求出排列这N个小圆的最小半径.
其实问题并不难，其实这个最小半径就是求这个正N边形的外切圆半径+r.
*/
/*#include<stdio.h>
#define eps 1e-7

double pi=acos(-1);
int main()
{
    int n;
    double R,r;
    double rr;
    while(scanf("%d %lf %lf",&n,&R,&r)!=EOF)
    {
        if(n==1)
        {
            if(r<=R+eps)
                printf("YES\n");
            else
                printf("NO\n");
            continue;
        }
        if(n==2)
        {
            if(2*r<=R+eps)
                printf("YES\n");
            else
                printf("NO\n");
            continue;
        }
        else
        {
            rr=2*r*sin(pi/2-pi/n)/sin(2*pi/n);
            if(R+eps>=rr+r)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}*/

/************************暴力枚举*/
/*
Ａ、Ｂ、Ｃ、Ｄ、Ｅ五名学生有可能参加计算机竞赛，根据下列条件判断哪些
  人参加了竞赛：
   （１）Ａ参加时，Ｂ也参加；
   （２）Ｂ和Ｃ只有一个人参加；
   （３）Ｃ和Ｄ或者都参加，或者都不参加；
   （４）Ｄ和Ｅ中至少有一个人参加；
   （５）如果Ｅ参加，那么Ａ和Ｄ也都参加。
*/
/*
#include<stdio.h>
void main()
{
    int a,b,c,d,e;
    for(a=0;a<2;a++)
    {
        for(b=0;b<2;b++)
        {
            for(c=0;c<2;c++)
            {
                for(d=0;d<2;d++)
                {
                    for(e=0;e<2;e++)
                    {
                        if(a&&!b)   continue;
                        if(b&&c||!b&&!c)    continue;
                        if(c&&!d||!c&&d)    continue;
                        if(!d&&!e)  continue;
                        if(e&&(!a||!d)) continue;
                    }
                }
            }
        }
    }
}
*/

/*
某侦察队接到一项紧急任务，要求在A、B、C、D、E、F六个队员中尽可能多地挑若干人，但有以下限制条件：
1)A和B两人中至少去一人； 
2)A和D不能一起去；           
3)A、E和F三人中要派两人去； 
4)B和C都去或都不去；
5)C和D两人中去一个； 
6)若D不去，则E也不去。 
试编写一个程序，输出问应当让哪几个人去？
*/
/*
#include<stdio.h>
void main()
{
    int a,b,c,d,e,f;//1去
    for(a=0;a<2;a++)
    {
        for(b=0;b<2;b++)
        {
            for(c=0;c<2;c++)
            {
                for(d=0;d<2;d++)
                {
                    for(e=0;e<2;e++)
                    {
                        for(f=0;f<2;f++)
                        {
                            if((a+b>=1)&&(a+d<=1)&&(a+e+f==2)&&(b+c!=1)&&(c+d==1)&&(d+e==0||d==1))
                                printf("%d %d %d %d %d",a,b,c,d,e);
                        }
                    }
                }
            }
        }
    }
}*/

//暴力枚举中,例如4人中只有1人说假话
//则判断条件加一条，使每个人说话的表达式相加为3
//C语言中 1为真 0为假

/********************约瑟夫问题***********/
/*一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，从某位置起顺序编号为1~N号。
从第1号开始报数，每轮从1报到3，凡报到3的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数。
如此不断循环，最后剩下的一只猴子就选为猴王。请问是原来第几号猴子当选猴王？
*/
/*
#include<stdio.h>
#define MAX 1005

void main()
{
    int monkey[MAX]={0};
    int n,temp=0;
    int monkeyOut=0;
    int count=0;
    int i;
    scanf("%d",&n);
    do
    {
        temp++;//逐个枚举圈中的所有位置
        if(temp>n)
            temp=1;//数组模拟环状
        if(!monkey[temp])
            count++;//第t个位置上有人则报数
        else
            continue;
        if(count==3)
        {
            count=0;
            monkey[temp]=1;
            monkeyOut++;
        }
    }while((monkeyOut+1)!=n);
    for(i=1;i<=n;++i)
    {
        if(!monkey[i])
        {
            printf("%d\n",i);
            break;
        }
    }
}*/

//农场灌溉(深度遍历)  
/*  
1.农场类型初始化 定义结构体 包含每个农场的 上 下 左  右 
2.11类型农场出口不一样  初始化 结构体{上下左右}(有出口 则为1，否则为0)  且用switch 语句 对应每种农田类型和返回值
3.总共有几种形式可以构成连通(函数boolOk),如果两者关系属于可以连通的关系，返回true，否则，返回false。 
4.具体搜索时，不断调用判断函数 dfs算法 
*/ 
/*#include<iostream>
#include<memory.h>
using namespace std;
int m,n;
struct Bone{
	char ch;//农场类型 
	bool visited;//访问标记 
	bool up,down,left,right;
} bone[100][100];
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};//分别代表上下左右四个方向
				//这是给出图给定的行走路线
//x,y 表示当前位置 nx ny为走到的位置  判断两个龙田可否走通  相当于from—>to  
bool place(int x,int y,int nx,int ny ){
	//如果未越界且未被访问过 
    if(nx>0 && nx<=m && ny>0 && ny<=n && !bone[nx][ny].visited)  
    {  
        //向左  
        if(nx==x && ny==y-1 && bone[x][y].left && bone[nx][ny].right)  
            return true;  
        //向下  
        if(nx==x+1 && ny==y && bone[x][y].down && bone[nx][ny].up)  
            return true;  
        //向右  
        if(nx==x && ny==y+1 && bone[x][y].right && bone[nx][ny].left)  
            return true;  
        //向上  
        if(nx==x-1 && ny==y && bone[x][y].up && bone[nx][ny].down)  
            return true;  
    }  
    return 0;  

} 
void dfs(int x,int y){
	bone[x][y].visited=1;//访问当前节点，将访问标志置为1 
	for(int i=0;i<4;i++){//有四个方向 i分别代表上下左右 
		int nx=x+dir[i][0];//走的x轴坐标  横向行动
		int ny=y+dir[i][1];//y坐标	纵向行动
		if(place(x,y,nx,ny)) {//如果可以走通
			dfs(nx,ny);//则以nx，ny出发，继续向前走 
		}
	}
}
int main(){

	
	while(cin>>m>>n&&(m!=-1)&&(n!=-1)){
		int cnt=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				
				cin>>bone[i][j].ch;
			//	memset(bone,0,sizeof(bone));//初始化
				bone[i][j].visited = 0;  
                bone[i][j].down = 0;  
                bone[i][j].up = 0;  
                bone[i][j].right = 0;  
                bone[i][j].left = 0;  
				switch(bone[i][j].ch) {
					case 'A':   bone[i][j].left=1;
                                bone[i][j].up=1;
					            break;
					 case'B':   bone[i][j].right=1;  
                                bone[i][j].up=1;  
                                break;  
                    case'C':    bone[i][j].left=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'D':    bone[i][j].right=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'E':    bone[i][j].up=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'F':    bone[i][j].left=1;  
                                bone[i][j].right=1;  
                                break;  
                    case'G':    bone[i][j].left=1;  
                                bone[i][j].right=1;  
                                bone[i][j].up=1;  
                                break;  
                    case'H':    bone[i][j].left=1;  
                                bone[i][j].up=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'I':    bone[i][j].left=1;  
                                bone[i][j].right=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'J':    bone[i][j].right=1;  
                                bone[i][j].up=1;  
                                bone[i][j].down=1;  
                                break;  
                    case'K':    bone[i][j].left=1;  
                                bone[i][j].right=1;  
                                bone[i][j].up=1;  
                                bone[i][j].down=1;  
                                break;      
				}
				
			}
		}
	    for(int i=1;i<=m;i++){
	    	for(int j=1;j<=n;j++){
	    		if(bone[i][j].visited==0){
	    			dfs(i,j);
	    			cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	} 
	return 0;
} */


/*
所谓贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的仅是在某种意义上的局部最优解。
贪心算法不是对所有问题都能得到整体最优解，但对范围相当广泛的许多问题他能产生整体最优解或者是整体最优解的近似解。贪心算法的基本思路如下：
1.建立数学模型来描述问题。
2.把求解的问题分成若干个子问题。
3.对每一子问题求解，得到子问题的局部最优解。
4.把子问题的解局部最优解合成原来解问题的一个解。
*/
/*
又到毕业季，很多大公司来学校招聘，招聘会分散在不同时间段，小明想知道自己最多能完整的参加多少个招聘会(参加一个招聘会的时候不能中断或离开).
活动选择问题
概述
这个问题是对几个相互竞争的招聘会活动进行调度，它们都要求以独占的方式使用某一公共资源（小明）。
调度的目标是找出一个最大的相互兼容的活动集合。
这里是有一个需要使用某一资源（小明）的n个活动组成的集合S={a1,a2,...,an}.该资源一次只能被一个活动占用。
每个活动ai有开始时间si和结束时间fi，且0<=si<fi<无穷。一旦被选择后，活动ai就占据了区间[si,fi].
如果区间[si,fi]和[sj,fj]互不重叠，称活动ai和aj是兼容的。
活动选择问题就是要选择出一个由互相兼容的问题组成的最大子集合。

定理
对于任意非空子问题Sij，设am是Sij中具有最早结束时间的活动：
fm=min{fk:ak属于Sij}
那么，
1）活动am在Sij的某最大兼容活动子集中被使用
2）子问题Sim为空，所以选择am将使子问题Smj为唯一可能非空的子问题
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct join
{
    int begin;
    int end;
};

int compare(const void *a,const void *b);

int main()
{
    int i,n,k;
    struct join joins[1001],temp[1001];
    // 第一行n，有n个招聘会，n <= 1000
    while(scanf("%d",&n)!=EOF)
    {
        //接下来n行每行两个整数表示起止时间，由从招聘会第一天0点开始的小时数表示。
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&joins[i].begin,&joins[i].end);
        }
        //qsort包含在<stdlib.h>头文件中，此函数根据你给的比较条件进行快速排序，通过指针移动实现排序。
        //排序之后的结果仍然放在原数组中。使用qsort函数必须自己写一个比较函数。 int compare()
        //其中第一个参数是参与排序的数组名（或者也可以理解成开始排序的地址，因为可以写&s[i]）；
        //第二个参数是参与排序的元素个数；
        // 第三个参数是单个元素的大小（推荐使用sizeof(s[0])这样的表达式,特别是对结构体，往往自己定义2*sizeof(int)这样的会出问题，用sizeof(s[0])既方便又保险）；
        //第四个参数就是比较函数
        qsort(joins,n,sizeof(joins[0]),compare);

        k=0;
        temp[k]=joins[0];
        for(i=1;i<n;i++)
        {
			//如果下一个的开始时间 > 当前的结束事件，则可以参加
            if(joins[i].begin>=temp[k].end)
                temp[++k]=joins[i];
        }
        //最多参加的招聘会个数
        printf("%d\n",k+1);
    }
    return 0;
}
//返回值必须是int，两个参数的类型必须都是const void *，那个a,b是我随便写的两个参数
//假设是对int排序的话，如果是升序，那么就是如果a比b大返回一个正值,小则负值,相等返回0
int compare(const void *a,const void *b)
{
    const struct join *p=a;
    const struct join *q=b;
    return p->end - q->end;
}
*/


/*均分纸牌
均分纸牌问题：有 N 堆纸牌，编号分别为 1，2，…, N。每堆上有若干张，但纸牌总数必为 N 的倍数。可以在任一堆上取若于张纸牌，然后移动。
移牌规则为：在编号为 1 堆上取的纸牌，只能移到编号为 2 的堆上；
在编号为 N 的堆上取的纸牌，只能移到编号为 N-1 的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。
在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

可以看到最核心的那个循环的思想是这样的：
从第一堆牌开始处理，如果第一堆牌整好是avg那么就放在一边不管了。
如果第一堆牌不是avg，那么就要把第二堆牌（合法的移动只有从2移到1，这也是这个算法的精髓之处）移动几张到第一堆，
恰好使第一堆等于avg，从而只考虑第二堆开始到第N堆为止这些堆如何搞的子问题。然后依次递归下去。
这里的一个小技巧是认为牌数可以为负数，这样才能继续下去。综上，这个步骤是合理的。
但是看不出来是最优的。可见，贪心法确实是比较容易实现，因为比较符合人类直觉，但是不好证明。
再反过来看一下前面提到的几点，可行性满足，不可取消，每一次操作都是直接赋值，局部最优，
当前情况下，只能从右往左移动，且贪心地想尽快让第一堆满足约束。
*/
/*
int main(){
    int N;
    int pokers[MAX];
    cin>>N;
    int total = 0;
    for (int i=0; i<N; i++) {
        cin>>pokers[i];
        total+=pokers[i];
    }
    int avg = total/N,times=0;
    for(int i=0;i<N;i++){
        if(pokers[i]!=avg){
            pokers[i+1] -= avg - pokers[i];
            times++;
        }
    }
    cout<<times<<endl; 
}*/

/*找零钱
买东西找零钱是日常生活中很普遍的事情,那么顾客付钱之后,需要找钱的最少张数是多少,
假设最小为1元.比如顾客消费76元,顾客给100元,售货员找给的最少张数是3张(1张20,2张2元).
现行人民币有100,50,20,10,5,2,1元券。
*/
/*
#include<stdio.h>
int least_num_cash(int _money)
{
 
    int ret=0;
    while(_money!=0)
    {
        if(_money>=100)
        {
               _money-=100;
        }
        else if(_money>=50)
         {
               _money-=50;
          }  
        else if(_money>=20)
       {
               _money-=20;
         }
       else if(_money>=10)
            {
               _money-=10;
            }          
       else if(_money>=5)
        {
                _money-=5;
            }  
       else if(_money>=2)
       {
                _money-=2;
            }  
       else if(_money>=1)
            {
                _money-=1;
             }
        ret++;
   }
   return ret;
}

int main()
{
   int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d\n",least_num_cash(m-n));
   }
    return 0;
}
*/
/*
http://blog.csdn.net/wang704987562/article/details/70991590
贪心算法的3个相当经典的程序
1.线段覆盖（linescover）

题目大意：在一维空间中告诉你N条线段的起始坐标与终止坐标，要求求出这些线段一共占了多大的长度。

解题思路：将线段按其实坐标进行排序,使之依次递增。然后定义一个变量last记录考虑到当前线段之时被线段覆盖的最大的坐标值。
因为已经排过序所以当前线段的效应长度为(x为起始坐标，y为终止坐标)：

length:=0 (y<=last)

y-last (x<=last & y>last)

y-x (x>last & y>last)

并且注意同时更新last的值。最后统计每条线段的效应长度就为我们所需要的答案。

2.最优数对（bestpair）

题目大意：按递增的顺序告诉你N个正整数和一个实数P，要求求出求出该数列中的比例最接近P的两个数（保证绝对没有两个数使得其比值为P）。

解题思路：定义两个指针i和j，然后进行如下操作：当code[j]/code[i]>p时inc（j），当code[j]/code[i]<p时inc（i），然后记录其中产生的最优值即可。

3.连续数之和最大值（maxsum）

题目大意：给你N个数，要求求出其中的连续数之和的最大值。（也可以加入a和b来限制连续数的长度不小于a且不大于b）。

解题思路：定义一个统计变量tot，然后用循环进行如下操作：inc（tot，item） 其中如果出现tot<0的情况，则将tot赋值为0。
在循环过程之中tot出现的最大值即为答案。如果加入了限制条件的话，问题就变得难一些了（这句真的不是废话）。
为此我们需要定义：数组sum[i]来表示code[1]到code[i]之和（这样的话code[a]~code[b]的和我们就可以用sum[b]-sum[a-1]来表示了。），
数组hash[i]来表示满足条件的sum[a-1]所对应的下标（并使之按sum[i]的递增顺序排列，一定要处理好sum[i]进出hash的过程）。
这样的话对于终止坐标为i的连续数列其最大和必定为sum[i]-sum[hash[1]],求出其最大值即可。
*/



