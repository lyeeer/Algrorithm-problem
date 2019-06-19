/*#include<stdio.h>
#include<string.h>
typedef struct seqstring
{
    char str[100];
    int length;
}seqstring;

void getnext(seqstring p,int next[])
{
    int i,j;
    next[0]=-1;
    i=0;
    j=-1;
    while(i<p.length)
    {
        if(j==-1||p.str[i]==p.str[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

int kmp(seqstring t,seqstring p,int next[])
{
    int i,j;
    i=0;
    j=0;
    while(i<t.length&&j<p.length)
    {
        if(j==-1||t.str[i]==p.str[j])
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
    {
        return i-p.length;
    }
    else
        return -1;
}


void main()
{
    seqstring t,p;
    int next[50];
    scanf("%s",t.str);
    t.length=strlen(t.str);
    scanf("%s",p.str);
    p.length=strlen(p.str);

    getnext(p,next);
    printf("\n%d\n",kmp(t,p,next));
}*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100001
char a[N],b[N],sum[N];

void bigAdd()
{
    int lena,lenb;
    int i=0,j=0,k=0;
    int c=0;//进位标志
    int temp;
    lena=strlen(a);
    lenb=strlen(b);
    memset(sum,0,N);
    for(i=lena-1,j=lenb-1;i>=0&&j>=0;j--,i--)
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
        if(sum[k]>'9')
        {
            c=1;
            sum[k]-=10;
        }
        i--;
        k++;
    }
    //b>a
    while(j>=0)
    {
        sum[k]=b[j]+c;
        if(sum[k]>'9')
        {
            c=1;
            sum[k]-=10;
        }
        j--;
        k++;
    }
    //进位
    if(c==1)
    {
        sum[k++]='1';
    }
    for(i=0,j=k-1;i<j;i++,j--)
    {
        temp=sum[i];
        sum[i]=sum[j];
        sum[j]=temp;
    }
}

void main()
{
    while(scanf("%s %s",a,b)!=EOF)
    {
        bigAdd();
        puts(sum);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
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
    p1=(char *)realloc(p1,sizeof(char)*i);
    *(p1+i-1)='\0';
    //输入字符串2
    while((a=getchar())!='\n')
    {
        p2=(char *)realloc(p2,sizeof(char)*j);
        *(p2+j-1)=a;
        j++;
    }
    p2=(char *)realloc(p2,sizeof(char)*j);
    *(p2+j-1)='\0';
    //连接
    p1=(char *)realloc(p1,sizeof(char)*(i+j-1));
    for(k=0;k<j;k++,i++)
    {
        *(p1+i-1)=*(p2+k);
    }
    printf("%s\n",p1);
}*/

/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i=1,j=1,k;
    char c;
    char *a=(char *)malloc(sizeof(char));
    char *b=(char *)malloc(sizeof(char));
    while((c=getchar())!='\n')
    {
        a=(char *)realloc(a,sizeof(char)*i);
        *(a+i-1)=c;
        i++;
    }
    a=(char *)realloc(a,sizeof(char)*i);
    *(a+i-1)='\0';

    while((c=getchar())!='\n')
    {
        b=(char *)realloc(b,sizeof(char)*j);
        *(b+j-1)=c;
        j++;
    }
    b=(char *)realloc(b,sizeof(char)*j);
    *(b+j-1)='\0';

    a=realloc(a,sizeof(char)*(i+j-1));
    for(k=0;k<j;k++,i++)
    {
        *(a+i-1)=*(b+k);
    }

    printf("%s\n",a);
}*/

/*#include<stdio.h>
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
}

void main()
{
    int mess[100];
    int N;
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&mess[2*i],&mess[2*i+1]);
    }
    sort(mess,N);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int ten;
    int i=0;
    int eight[100];
    scanf("%d",&ten);
    while(ten>0)
    {
        eight[i]=ten%8;
        ten=ten/8;
        i++;
    }
    i--;
    for(;i>=0;i--)
    {
        printf("%d",eight[i]);
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#include<limits.h>
typedef struct String
{
    char str[100];
    int len;
}String;

void main()
{
    String s[100];
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
        if(s[index].len>MAX)
        {
            MAX=s[index].len;
        }
        else if(s[index].len<MIN)
        {
            MIN=s[index].len;
        }
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
/*
#include<stdio.h>
void create(void);
int safe(int i,int j,int m,int n);
int isLink(int ,int);
void dfs(int);
void out(void);
struct problem
{
    int farmer;
    int wolf;
    int sheep;
    int vegetable;
};

int visit[16];
int max=0;
int pa=0;
struct problem p[16];
int link[16][16];
int path[16];

void main()
{
    int i;
    for(i=0;i<16;i++)
        visit[i]=0;
    create();
    dfs(0);
}

int safe(int i,int j,int m,int n)
{
    if(i!=m&&(j==m||m==n))
    {
        return 0;
    }
    return 1;
}

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
void create()
{
    int i,j,m,n;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(m=0;m<2;m++)
                for(n=0;n<2;n++)
                {
                    if(safe(i,j,m,n))
                    {
                        p[max].farmer=i;
                        p[max].wolf=j;
                        p[max].sheep=m;
                        p[max].vegetable=n;
                        max++;
                    }
                }
    max--;
    for(i=0;i<=max;i++)
    {
        for(j=0;j<=max;j++)
        {
            if(isLink(i,j))
                link[i][j]=1;
            else
                link[i][j]=0;
        }
    }
}
void out()
{
    int i;
    for(i=1;i<pa;i++)
    {
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
}
void dfs(int n)
{
    int i;
    visit[n]=1;
    path[pa++]=n;
    if(n==max)
    {
        out();
        return;
    }
    for(i=0;i<=max;i++)
    {
        if(link[n][i]&&!visit[i])
        {
            dfs(i);
            pa--;
            visit[i]=0;
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define max 8

int sum=0;
int queen[max];

void show()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("(%d %d)",i,queen[i]);
    }
    printf("\n");
    sum++;
}

int check(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
            return 1;
    }
    return 0;
}

void put(int n)
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n]=i;
        if(!check(n))
        {
            if(n==max-1)
                show();
            else
                put(n+1);
        }
    }
}

void main()
{
    put(0);
    printf("%d",sum);
}*/
/*
#include<stdio.h>
void main()
{
    int N;
    int i;
    long long int a[90];
    while(scanf("%d",&N)!=EOF)
    {
        a[1]=1;
        a[2]=1;
        for(i=3;i<N;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        printf("%lld\n",a[N]);
    }
}*/

/*#include<stdio.h>
void main()
{
    int i;
    int N;
    int t[55];
    int a,b;
    scanf("%d",&N);
    t[0]=1;
    t[1]=1;
    for(i=2;i<55;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    while(N--)
    {
        scanf("%d %d",&a,&b);
        printf("%d",t[b-a]);
    }
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#define M 100

void maxAdd(int a[M][M],int b,int c)
{
    int i,j;
    int sum=0;
    int max,temp;
    int imax=0;
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
        a[i][imax]=max;
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
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char str[1001];
    int i,len;
    int flag=0;
    gets(str);
    len=strlen(str);
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("YES!\n");
    }
    else
        printf("NO!\n");
}*/

/*
#include<stdio.h>
#include<string.h>
#define N 1000

struct string
{
    int len;
    char str[N];
};
struct string s[N];

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
            return -1;
    }
    else if(a.len>b.len)
        return 0;
    else if(a.len<b.len)
        return (-1);
}

void main()
{
    int N;
    int i,j;
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
                if(cmp(s[j],s[j+1])==0)
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
            printf("%s\n",s[i].str);
    }
}*/

/*
#include<stdio.h>
#include<string.h>

#define M 130

struct ch
{
    int index[M];
    int p;
    int flag;
};

void main()
{
    struct ch temp[M];
    char str[M];
    int k,t;

    while(scanf("%s",str)!=EOF)
    {
        for(k=0;k<M;k++)
        {
            temp[k].p=0;
            temp[k].flag=0;
        }

        for(k=0;k<strlen(str);k++)
        {
            temp[str[k]].index[temp[str[k]].p]=k;
            temp[str[k]].p++;
        }

        for(k=0;k<strlen(str);k++)
        {
            if(temp[str[k]].p>1&&temp[str[k]].flag==0)
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
}*/
/*
bool isIPAddressValid(const char *pszIPAddr)
{
    char temp[5]="\0";
    int i=0,j;
    int count=0;
    int number;
    if(pszIPAddr==NULL)
        return false;
    while(*pszIPAddr!='\0')
    {
        if(count==0&&i=0&& *pszIPAddr==' ')
        {
            pszIPAddr++;
            continue;
        }
        if(count<3)
        {
            if(*pszIPAddr<='9' && *pszIPAddr>='0')
            {
                temp[i++]=*pszIPAddr;
                if(i>3)
                    return false;
            }
            else
            {
                if(*pszIPAddr=='.')
                {
                    if(i==0)
                        return false;
                    temp[i]='\0';
                    number=0;
                    if(temp[0]=='0'&&i>1)
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
            while(count==3)
            {
                if(*pszIPAddr<='9'&&*pszIPAddr>='0')
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
                    if(temp[0]=='0'&&i>1)
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

/*#include<stdio.h>
#include<stdlib.h>

typedef struct BitNode
{
    int value;
    struct BitNode *lchild,*rchild;
}BiTree;

void insertBST(BiTree **root,int data)
{
    if(*root==NULL)
    {
        *root=(BiTree *)malloc(sizeof(BiTree));
        (*root)->value=data;
        (*root)->lchild=NULL;
        (*root)->rchild=NULL;
    }
    else
    {
        if(data<(*root)->value)
        {
            insertBST(&((*root)->lchild),data);
        }
        else if(data>(*root)->value)
        {
            insertBST(&((*root)->rchild),data);
        }
    }
}

void MK(BiTree **r,int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        insertBST(&(*r),a[i]);
    }
}

void PreOrderTraverse(BiTree *root)
{
    if(root)
    {
        printf("%d ",root->value);
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}

void InOrderTraverse(BiTree *root)
{
    if(root)
    {
        InOrderTraverse(root->lchild);
        printf("%d ",root->value);
        InOrderTraverse(root->rchild);
    }
}

void PostOrderTraverse(BiTree *root)
{
    if(root)
    {
        PostOrderTraverse(root->lchild);
        PostOrderTraverse(root->rchild);
        printf("%d ",root->value);
    }
}

void main()
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
        MK(&root,a,n);
        PreOrderTraverse(root);
        printf("\n");
        InOrderTraverse(root);
        printf("\n");
        PostOrderTraverse(root);
    }
}*/

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
    if(*root==NULL)
    {
        *root=(struct BiTree *)malloc(sizeof(BiTree));
        (*root)->value=data;
        (*root)->lchild=NULL;
        (*root)->rchild=NULL;
    }
    else
    {
        if(data<(*root)->value)
        {
            insertBST(&((*root)->lchild),data);
        }
        else if(data>(*root)->value)
        {
            insertBST(&((*root)->rchild),data);
        }
    }
}


void MK(BiTree **root,int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        insertBST(&(*root),a[i]);
}

void PreOrderTraverse(BiTree **r)
{
    if(r)
    {
        printf("%d ",r->value);
        PreOrderTraverse(r->lchild);
        PreOrderTraverse(r->rchild);
    }
}

void InOrderTraverse(BiTree **r)
{
    if(r)
    {
        InOrderTraverse(r->lchild);
        printf("%d ",r->value);
        InOrderTraverse(r->rchild);
    }
}

void PostOrderTraverse(BiTree **r)
{
    if(r)
    {
        PostOrderTraverse(r->lchild);
        PostOrderTraverse(r->rchild);
        printf("%d ",r->value);
    }
}

void main()
{
    int n,i;
    int a[100];
    BiTree *root;
    while(scanf("%d",&n)!=EOF)
    {
        root=NULL;
        for(i=0;i<n;i++)
        {
            scanf("%d",a[i]);
        }
        MK(&root,a,n);
        PreOrderTraverse(root);
        printf("\n");
        InOrderTraverse(root);
        printf("\n");
        PostOrderTraverse(root);
    }
}*/
/*
#include<stdio.h>
int isLeap(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return 1;
    else
        return 0;
}

void main()
{
    int year,day;
    int i;
    int m=0;
    int month={31,28,31,30,31,30,31,31,30,31,30,31};
    while(scanf("%d %d",&year,&day)!=EOF)
    {
        if(isLeap(year)==1)
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

void main()
{
    int n;
    int i;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
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
    }
}*/
/*
#include<stdio.h>
#include<string.h>

char a[10000];
char b[10000];

void main()
{
    int n,i,k,t;
    while(gets(a)!=NULL)
    {
        k=0;
        n=strlen(a);
        t=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=' '&&a[i]!='.')
                t++;
            if((a[i]==' '||a[i]=='.')&&t>0)
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
/*
#include<stdio.h>
void main()
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
            num2=m%10;
            if(num1!=num2)
            {
                flag=0;
                break;
            }
            tmp/=10;
            m/=10;
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}*/

/*#include<stdio.h>
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
        printf("%d ",head->value);
        ztree(head->rchild);
    }
}

void main()
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
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    char c;
    scanf("%c",&c);
    if(c!='#')
       (*head)=NULL;
    else
    {
        (*head)=(BiTree)malloc(sizeof(struct BitNode));
        (*head)->value=c;
        xtree(&((*head)->lchild));
        xtree(&((*head)->rchild));
    }
}

void ztree(BiTree head)
{
    if(head)
    {
        ztree(head->lchild);
        printf("%d ",head->value);
        ztree(head->rchild);
    }
}

void main()
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
}*/
/*
#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LinkList;

void main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        LinkList *head,*pre,*p,*newNode;
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;

        for(i=0;i<N;i++)
        {
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);

            pre=head;
            p=head->next;

            while(p)
            {
                if(newNode->data<p->data)
                    break;
                pre=p;
                p=p->next;
            }

            newNode->next=p;
            pre->next=newNode;
        }

        p=head->next;
        printf("%d",p->data);
        while(p->next)
        {
            p=p->next;
            printf(" %d",p->data);
        }
        printf("\n");
    }
}*/
/*
#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
}LinkList;

void main()
{
    int N;
    int i,a;
    while(scanf("%d",&N)!=EOF)
    {
        LinkList *head,*pre,*p,*newNode;
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;

        for(i=0;i<N;i++)
        {
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);

            pre=head;
            p=head->next;

            while(p)
            {
                if(newNode->data<p->data)
                    break;
                pre=p;
                p=p->next;
            }
            newNode->next=p;
            pre->next=newNode;
        }

        p=head->next;
        printf("%d",p->data);
        while(p->next)
        {
            p=p->next;
            printf(" %d",p->data);
        }
        printf("\n");
    }
}*/

/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    char c;
    char cb;
    int ccount=0;
    int wcount=0;
    int scount=0;
    FILE *fp=fopen("D:\\abc0.txt","w");
    FILE *fp1=fopen("D:\\abc1.txt","r");
    if(fp==NULL)
    {
        puts("open fail\n");
        return 0;
    }
    while((c==getchar())!=EOF)
        fputc(c,fp);
    fclose(fp);
    puts("Mission 1-------\n\n");

    fp=fopen("D:\\abc0.txt","r");
    if(fp==NULL)
    {
        puts("open fail\n");
        return 0;
    }
    if(fp1==NULL)
    {
        puts("open fail\n");
        return 0;
    }
    cb=NULL;
    c=NULL;
    while((c=fgetc(fp))!=EOF)
    {
        if(c==' ')
        {
            if(cb==' ') continue;
            else
                fputc(c,fp1);
        }
        else
            fputc(c,fp1);
        cb=c;
    }
    fclose(fp);
    fclose(fp1);
    puts("Mission2-------\n\n");

    fp1=fopen("D:\\abc1.txt","r");
    if(fp1==NULL)
    {
        puts("open fail\n");
        return 0;
    }
    c=NULL;
    while((c=getc(fp1))!=EOF)
    {
        ccount++;
        putchar(c);
        if(c==' ') wcount++;
        if(c=='.') scount++;
    }
    wcount++;
    fclose(fp1);
}*/

/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int count;
    int *num;
    int t;
    int i,j;
    int temp;
    //-------------
    count=0;
    num=(int *)malloc(sizeof(int));
    scanf("%d",&t);

    while(t)
    {
        count++;
        num=(int *)malloc(num,count*sizeof(int));
        num[count-1]=t;
        scanf("%d",&t);
    }
    for(i=0;i<count;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n------------\n");

    for(i=0;i<count;i++)
    {
        for(j=0;j<count-1-i;j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n------------\n");
    fflush(stdin);
    getchar();
}*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *num;
    int t;
    int count;

    count=0;
    num=(int *)malloc(sizeof(int));
    scanf("%d",&t);

    while(t)
    {
        count++;
        num=(int *)malloc(sizeof(int));
        num[count-1]=t;
        scanf("%d",&t);
    }

}*/

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char *data;
    struct node *lchild,*rchild;
}BNode,*BTree;

void insert(BTree *t,char *data)
{
    if(!(*t))
    {
        (*t)=(BTree)malloc(sizeof(BNode))
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

void main()
{
    char **a;
    int count;
    int i,n;
    char c;

    scanf("%d",&n);
    a=(char **)malloc(sizeof(char *));
    getchar();

    if(a==NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        count=0;
        a[i]=(char *)malloc(sizeof(char));
        while((c=getchar())!='\n')
        {
            count++;
            a[i]=(char *)realloc(a[i],count*(sizeof(char)));
            a[i][count-1]=c;
        }
        a[i]=(char *)realloc(a[i],(count+1)*sizeof(char));
        a[i][count]='\0';
    }
    for(i=0;i<n;i++)
    {
        insert(&t,a[i]);
    }
    PreOrder(t);
    fflush(stdin);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char *data;
    struct node *lchild,*rchild;
}BNode,*BTree;

void insert(BTree *t,char *data)
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

void main()
{
    int i,n;
    int count;
    char c;
    char **a;
    scanf("%d",&n);
    a=(char **)malloc(n*sizeof(char));
    getchar();
    if(a==NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        count=0;
        a[i]=(char *)malloc(sizeof(char));
        while((c=getchar())!='\n')
        {
            count++;
            a[i]=(char *)realloc(a[i],count*sizeof(char));
            a[i][count-1]=c;
        }
        a[i]=(char *)realloc(a[i],(count+1)*sizeof(char));
        a[i][count]='\0';
    }
    for(i=0;i<n;i++)
    {
        insert(&t,a[i]);
    }
    PreOrder(t);
    fflush(stdin);
}*/

/*
#include<stdio.h>
#include<stdlib.h>
void main()
{
    unsigned long int ulln,ulHigh=0,ulLow=0,rolBit;
    int n,bit;

    scanf("%x",&ulln);
    ulHigh=ulln>>24;
    ulLow=ulln<<24;
    ulln=ulln&0x00ffff00;
    ulln=ulln|ulHigh;
    ulln=ulln|ulLow;
    printf("%x\n",ulln);
    printf("Mission1----------\n\n");

    scanf("%d",&n);
    n=n%16;
    rolBit=rolBit>>8;
    rolBit=rolBit<<n;
    ulHigh=0;
    ulHigh=(rolBit&0xffff0000)>>16;
    rolBit=(rolBit&0x0000ffff)|ulHigh;
    rolBit=rolBit<<8;
    ulln=(ulln&0xff0000ff)|rolBit;
    printf("%x\n",ulln);
    printf("Mission2----------\n\n");

    ulHigh=1;
    for(bit=0;bit<=31;bit++)
    {
        if(bit%8==0)
            putchar(' ');
        ulLow=ulln&(ulHigh<<(31-bit));
        printf("%d",ulLow>>(31-bit));
    }
    putchar('\n');
    printf("Mission3----------\n\n");
}*/
/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>

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

void main()
{
    int i,j,k,count;
    char **str;
    char ch;
    str=(char **)malloc(sizeof(char *));
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
            printf("input error\n");
            exit(-1);
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void main()
{
    char **str;
    int i,j,k,count;
    char ch;
    char t[100];
    str=(char **)malloc(sizeof(char *));
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
            printf("input error\n");
            exit(-1);
        }
    }
}*/
/*
void main()
{
    char **str;
    int i,j,k,count;
    char ch;
    char t[100];
    str=(char **)malloc(sizeof(char *));

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
    }
}*/
/*
void main()
{
    char t[100];
    char **str;
    int i,count;
    char ch='!';
    str=(char **)malloc(sizeof(char *));
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
    }

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

    scanf("%d",&n);
    map=(char **)malloc(n*sizeof(int *));
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;

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
            if(p->distance>p->distance)
                exchange(p,q);
        }
    }
}*/
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
/*
#include<stdio.h>
#define M 100
void main()
{
    int n;
    int i,j;
    int num=1;
    int a[M][M];
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
        for(j=i;j<n-i;j++)
            if(a[i][j]==0)
                a[i][j]=num++;
        for(j=i;j<n-i;j++)
            if(a[j][n-i-1]==0)
                a[j][n-i-1]=num++;
        for(j=n-i-1;j>i;j--)
            if(a[n-i-1][j]==0)
                a[n-i-1][j]=num++;
        for(j=n-i-1;j<i;j--)
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

}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5010

void main()
{
    int t,len,st,end;
    int i,j,max,k;
    char s[MAX];
    char s1[MAX];
    int pos[MAX];

    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        len=strlen(s);
        k=st=max=end=0;
        for(i=0;i<len;++i)
        {
            if(isalpha(s[i]))
            {
                pos[k]=i;
                if(s[i]<97)
                    s1[k++]=s[i]+32;
                else
                    s1[k++]=s[i];
            }
        }
        for(i=0;i<k;++i)
        {
            for(j=0;j<=i&&i+j<k;++j)
            {
                if(s1[i-j]!=s1[i+j])
                    break;
                if(j*2+1>max)
                {
                    max=2*j+1;
                    st=pos[i-j];
                    end=pos[i+j];
                }
            }
            for(j=0;j<=i&&i+j+1<k;++j)
            {
                if(s1[i-j]!=s1[i+j+1])
                    break;
                ig(j*2+2>max)
                {
                    max=2*j+2;
                    st=pos[i-j];
                    end=pos[i+j+1];
                }
            }
        }
        for(i=st;i<=end;++i)
            printf("%c",s[i]);
        printf("\n");
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 5010

void main()
{
    int t,len,st,max;
    int i,j,max,k;
    char s[MAX];
    char s1[MAX];
    int pos[MAX];

    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        len=strlen(s);
        k=st=max=end=0;
        for(i=0;i<len;i++)
        {
            if(isalpha(s[i]))
            {
                pos[k]=i;
                if(s[i]<97)
                    s1[k++]=s[i]+32;
                else
                    s1[k++]=s[i];
            }
        }
        for(i=0;i<k;++i)
        {
            for(j=0;j<=i&&i+j<k;++j)
            {
                if(s1[i-j]!=s1[i+j])
                    break;
                if(j*2+1>max)
                {
                    max=2*j+1;
                    st=pos[i-j];
                    end=pos[i+j];
                }
            }
        }
        for(j=0;j<=i&&i+j+1<k;++j)
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
    for(i=st;i<=end;++i)
        printf("%c",s[i]);
    printf("\n");
}*/
/*
for(i=0;i<9;i++)
{
    curmax=i;
    for(j=i+1;j<10;j++)
    {
        if(num[curmax]<num[j])
        {
            curmax=j;
        }
    }
    if(curmax!=i)
    {
        temp=num[curmax];
        num[curmax]=num[i];
        num[i]=temp;
    }
}*/
/*
for(i=1;i<10;i++)
{
    temp=num[i];
    for(j=i-1;j>=0&&temp>num[j];j--)
    {
        num[j+1]=num[j];
    }
    num[j+1]=temp;
}*/

/*#include<stdio.h>
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

char *DtoB(int x,char str[])
{
    int i=0;
    do
    {
        str=(char *)realloc(str,(i+1)*sizeof(char));
        str[i++]=x%2+'0';
        x=x/2;
    }while(x>0);
    str[i]='\0';
    return str;
}*/
/*
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
char *DtoB(int x,char str[])
{
    int i=0;
    do
    {
        str=(char *)realloc(str,(i+1)*sizeof(char));
        str[i++]=x%2+'0';
        x=x/2;
    }while(x>0);
}*/

/*
#include<stdio.h>

int isOct(char str[])
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

int isDec(char str[])
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

int isHex(char str[])
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

void main()
{
    char str[20];
    int flag;
    while(scanf("%s",str)!=EOF)
    {
        switch(str[0])
        {

        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
void main()
{
    //问题一
    char *a=(char *)malloc(sizeof(char));
    char *b=(char *)malloc(sizeof(char));
    char c;
    int counta=1,countb=1;
    int k,len;
    int leno,lenj;
    char aj[20]={},ao[20]={};

    while((c=getchar())!=' ')
    {
        a=(char *)realloc(a,counta*sizeof(char));
        *(a+counta-1)=c;
        counta++;
    }
    a=(char *)realloc(a,counta*sizeof(char));
    *(a+counta-1)='\0';

    while((c=getchar())!='\n')
    {
        b=(char *)realloc(b,countb*sizeof(char));
        *(b+countb-1)=ch;
        countb++;
    }
    b=(char *)realloc(b,countb*sizeof(char));
    *(b+countb-1)='\0';

    a=(char *)realloc(a,sizeof(char)*(counta+countb-1));
    for(k=0;k<countb;k++,counta++)
    {
        *(a+counta-1)=*(b+k);
    }
    printf("%s\n\n",a);

    //问题2
    len=strlen(a);
    counta=0;
    countb=0;
    for(k=0;k<len;k++)
    {
        if(k%2==0)
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

    //问题3
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isRepeat(char str[],char c,int m)
{
    int len=strlen(str);
    int i;
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(str[i]==c)
            flag=1;
    }
    return flag;
}


void main()
{
    char *p=(char *)malloc(sizeof(char));
    char ch;
    int count=1;
    char rp[20];
    int len,i;

    while((c=getchar())!='\n')
    {
        p=(char *)realloc(p,sizeof(char)*count);
        *(p+count-1)=ch;
        count++;
    }
    p=(char *)realloc(p,sizeof(char)*count);
    *(p+count-1)='\0';
    printf("%s\n",p);

    //问题2
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
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char c='a';
    char a[10],a2[10];
    int len,i;
    int count=0;
    char strh[5]={};
    char strl[5]={};
    int convertN;
    itoa(97,a,2);

    for(i=len-1;i>=len-4;i--)
    {
        strl[count]=a[i];
        count++;
    }
    count=0;

    for(i=0;i<=len-5;i++)
    {
        strh[count]=a[i];
        count++;
    }
}*/

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
/*
void RemoveExtraSpace(char *str)
{
    int keep_space=0;
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
        str[new_str_end-1]='\0';
    else
        str[new_str_end]='\0';
}*/
/*
#include<stdio.h>
#define m 3
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *child[m];
}node,*tree;

tree root;

void preorder(tree p)
{
    int i;
    if(p!=NULL)
    {
        printf("%c",p->data);
        for(i=0;i<m;++i)
        {
            preorder(p->child[i]);
        }
    }
}

void postorder(tree p)
{
    int i;
    if(p!=NULL)
    {
        for(i=0;i<m;++i)
        {
            postorder(p->child[i]);
        }
        printf("%c",p->data);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild,*rchild;
}bintnode;
typedef bintnode *bintree;

bintree root;

void preorder(bintree t)
{
    if(t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bintree t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

void postorder(bintree t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

bintree create()
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
        t->lchild=create();
        t->rchild=create();
    }
    return t;
}*/
/*
struct bintnode
{
    char data;
    bintnode *lchild,*rchild;
};
typedef bintnode *bintree;

typedef struct stack
{
    bintree data[100];
    int tag[100];
    int top;
}seqstack;

void push(seqstack *s,bintree t)
{
    s->data[s->top]=t;
    s->top++;
}

bintree pop(seqstack *s)
{
    if(s->top!=0)
    {
        s->top--;
        return (s->data[s->top]);
    }
    else
        return NULL;
}

void preorder1(bintree t)
{
    seqstack s;
    s.top=0;
    while((t)||(s.top!=0))
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
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    int len;
    char a[100];
    int n1,n2,n3;
    int i=0,j;
    while(scanf("%s",a)!=EOF)
    {
        len=strlen(a);
        n1=n3=(len+2)/3;
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
}*/
/*
#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
    char str1[15],str2[15];
    int len1,len2;
    long long int s1=0,s2=0;
    int i,j;

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
        if(str2[i]=='-')
            s2=-s2;
        printf("%lld\n",s1+s2);
    }
}*/
/*
#include<stdio.h>
#include<string.h>

void main()
{
    char str[20];
    int count1,count2,count3;
    int len;
    int i,j;
    int flag=0,cnt=0;
    while(scanf("%s",str)!=EOF)
    {
        count1=count2=count3=0;
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
}*/
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
    int sKind;
    int BestRank;
    int Rank;
}country;

country c[1000];

void main()
{
    int N,M;
    int i,j;
    int ID;
    country cSort[1000];
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d %d %d",&c[i].goldNum,&c[i].mediaNum,&c[i].population);
            c[i].goldRatio=(c[i].goldNum*1.0)/c[i].population;
            c[i].mediaRatio=(c[i].mediaNum*1.0)/c[i].population;
        }
        for(i=0;i<M;i++)
        {
            scanf("%d",&ID);
            cSort[i]=c[ID];
        }
        for(i=0;i<M;i++)
        {
            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].goldNum<cSort[j].goldNum)
                    cSort[i].Rank++;
            }
            cSort[i].BestRank=cSort.Rank;
            cSort[i].sKind=1;

            cSort[i].Rank=1;
            for(j=0;j<M;j++)
            {
                if(cSort[i].goldNum<cSort[j].goldNum)
                    cSort[i].Rank++;
            }
            if(cSort[i].Rank<cSort[i].BestRank)
            {
                cSort[i].BestRank=cSort[i].Rank;
                cSort[i].sKind=2;
            }
        }
    }
}*/

/*#include<stdio.h>
#include<string.h>
#define MAX 100000
#define N 1005
int map[N][N];
int value[N][N];
int dis[N];
int val[N];
int vis[N];

void dijkstra(int start,int n)
{
    int i,j,k,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[start][i];
        val[i]=value[start][i];
    }
    dis[start]=0;
    for(i=1;i<=n-1;i++)
    {
        min=MAX;
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
            return 0;
        for(j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
                val[j]+val[k]+value[k][j];

            }
            else if((dis[j]==dis[k]+map[k][j])&&(val[j]>val[k]+value[k][j]))
             {
                val[j]+val[k]+value[k][j];
             }
        }
    }

}


void main()
{
    int n,m;
    int a,b,d,p;
    int i;
    int s,t;

    while(scanf("%d %d",&n,&m)&&(n+m))
    {
        memset(vis,0,sizeof(vis));
        memset(map,MAX,sizeof(map));
        memset(value,MAX,sizeof(value));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(map[a][b]>d)
            {
                map[a][b]=d;
                map[b][a]=d;
                value[a][b]=p;
                value[b][a]=p;
            }
        }
        scanf("%d %d",&s,&t);
        dijkstra(s,n);
    }
    printf("%d %d\n",dis[t],val[t]);
}*/
/*
#include<stdio.h>
#include<string.h>
#define MAX 10000
#define N 1005

int map[N][N];
int value[N][N];
int dis[N];
int val[N];
int vis[N];

void dijkstra(int start,int n)
{
    int i,j,k,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[start][i];
        val[i]=value[start][i];
    }
    dis[start]=0;
    for(i=1;i<=n-1;i++)
    {
        min=MAX;
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
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
                val[j]=val[k]+value[k][j];
            }
            else if((dis[j]==dis[k]+map[k][j])&&(val[j]>val[k]+value[k][j]))
            {
                val[j]=val[k]+value[k][j];
            }
        }
    }
}

void main()
{
    int n,m;
    int a,b,d,p;
    int i;
    int s,t;
    while(scanf("%d %d",&n,&m)&&(n+m))
    {
        memset(vis,0,sizeof(vis));
        memset(map,MAX,sizeof(map));
        memset(value,MAX,sizeof(value));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(map[a][b]>d)
            {
                map[a][b]=d;
                map[b][a]=d;
                value[a][b]=p;
                value[b][a]=p;
            }
        }
        scanf("%d %d",&s,&t);
        dijkstra(s,n);
    }
    printf("%d %d\n",dis[t],val[t]);
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100005
#define N 1050

int dis[N];
int map[N][N];
int vis[N];
int armycity[N];

void dijkstra(int query,int v)
{
    int i,j,k;
    int min=0;
    for(i=1;i<=v;i++)
    {
        dis[i]=map[query][i];
    }
    dis[query]=0;

    for(i=1;i<v-1;i++)
    {
        min=MAX;
        k=0;
        for(j=1;j<=v;j++)
        {
            if((!vis[j])&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)
            return;
        vis[k]=1;
        for(j=1;j<=v;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
                dis[j]=dis[k]+map[k][j];
        }
    }
}

void main()
{
    int n,m,p,q;
    int t;
    int i;
    int a,b,c;
    int ans=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&p,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&armycity[i]);
        }
        memset(map,MAX,sizeof(map));
        memset(vis,0,sizeof(vis));

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
        ans=MAX;
        for(i=0;i<n;i++)
        {
            if(ans>dis[armycity[i])
            {
                ans=dis[armycity[i]];
            }
        }
        printf("%d\n",ans);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 10000
#define N 1050

int dis[N];
int map[N][N];
int vis[N];
int armycity[N];

void dijkstra(int query,int v)
{
    int i,j,k;
    int min;
    for(i=1;i<=v;i++)
    {
        dis[i]=map[query][i];
    }
    dis[query]=0;

    for(i=1;i<=v-1;i++)
    {
        min=M;
        k=0;
        for(j=1;j<=v;j++)
        {
            if((!vis[j])&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)
            return;
        vis[k]=1;
        for(j=1;j<=v;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
                dis[j]=dis[k]+map[k][j];
        }
    }
}

void main()
{
    int n,m,p,q;
    int t;
    int i;
    int a,b,c;
    int ans=0;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&p,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&armycity[i]);
        }
        memset(map,M,sizeof(map));
        memset(vis,0,sizeof(vis));
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
        ans=M;
        for(i=0;i<n;i++)
        {
            if(ans>dis[armycity[i])
                ans=dis[armycity[i]];
        }
        printf("%d\n",ans);
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

char s[N];
int t1[N];
int t2[N];

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]<c)
            pos=2*pos+1;
        else
            pos=2*pos;
    }
    t[pos]=c;
}

void build(char *str,int *t)
{
    int i;
    t[1]=str[0]-'0';
    for(i=1;s[i];i++)
    {
        insert(s[i],t);
    }
}

void main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
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
                printf("YES\n\n");
            else
                printf("NO\n\n");
        }
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

char s[N];
int t1[N];
int t2[N];

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]<c)
            pos=2*pos+1；
        else
            pos=2*pos;
    }
    t[pos]=c;
}

void build(char *str,int *t)
{
    int i;
    t[1]=str[0]-'0';
    for(i=1;s[i];i++)
        insert(s[i],t);
}

void main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
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
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 1000

char s[N];
int t1[N];
int t2[N];

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]<c)
            pos=pos*2+1;
        else
            pos=2*pos;
    }
}

void build(char *str,int *t)
{
    int i;
    t[1]=str[0]-'0';
    for(i=1;s[i];i++)
        insert(s[i],t);
}

void main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(t1,-1,sizeof(t1));
        scanf("%s",s);
        build(t1,s);
        while(n--)
        {
            memset(t2,-1,sizeof(t2));
            scanf("%s",s);
            bulid(t2,s);
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
}*/
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

void main()
{
    int x,n;
    double y;
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        y=fun(x,n);
        printf("%6f\n",y);
    }
}*/
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

void main()
{
    int x,n;
    double y;
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        y=fun(x,n);
        printf("%6f\n",y);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 1000

typedef struct NUM
{
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
            if(a[j].data>a[j+1].data)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void main()
{
    int num;
    int i;
    int order[N];
    struct NUM temp;
    int cnt;
    int pre;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&array[i].data);
            array[i].order=i;
            order[i]=0;
        }
        selectSort(array,num);
        cnt=1;
        pre=-999999;
        for(i=0;i<num;i++)
        {
            if(i&&pre==array[i].data)
                order[array[i].order]=cnt;
            else if(i&&pre!=array[i].data)
                order[array[i].order=++cnt;
            else if(!i)
                order[array[i].order]=cnt;
            pre=array[i].data;
        }
        for(i=0;i<num;i++)
        {
            if(i!=num-1)
                printf("%d ",order[i]);
            else
                printf("%d\n",order[i]);
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000

char str[N],string[N][N],string2[N][N];

void main()
{
    int index=0;
    int i,j,k;

    gets(str);

    while(gets(string[index]))
    {
        if(strcmp(string[index],"}")==0)
            break;
        index++;
    }
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]+32;
    }
    for(i=0;i<=index;i++)
    {
        for(j=0;j<strlen(string[i]);j++)
        {
            string2[i][j]=string[i][j];
            if(string[i][j]>='A'&&string[i][j]<='Z')
            {
                string[i][j]=string[i][j]+32;
            }
        }
        for(j=0,k=0;j<strlen(string[i]);)
        {
            if(string[i][j+k]==str[k])
            {
                k++;
                if(k==strlen(str))
                {
                    j=j+k;
                }
            }
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

}*/
/*
#include<stdio.h>
void main()
{
    int k,i;
    double sn=0.0;
    scanf("%d",&k);
    for(i=1;sn<=k;i++)
        sn=sn+1.0/i;
    printf("%d",i-1);
}*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int T;
    double p,fp;
    double sum,index;
    int i;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&p);
        fp=1.0-p;
        sum=0.0;
        i=2;
        while(1)
        {
            index=pow(p,i-1)*fp+pow(fp,i-1)*p;
            if(index*i<0.001)
                break;
            sum+=i*index;
            i++;
        }
        sum=floor(sum+0.5);
        printf("%d\n",(int)sum);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 100

int num[N];
int len;

int toOther(int x,int n)
{
    int temp=x;
    int i=0;
    while(temp!=0)
    {
        num[++i]=temp%n;
        temp=temp/n;
    }
    return i;
}

int isHui()
{
    int i;
    int flag=0;
    for(i=0;i<len/2;i++)
    {
        if(num[i]!=num[len-i-1])
            flag=1;
    }
    return flag;
}

void main()
{
    int t,n,s;
    int count;
    int i;

    scanf("%d",&t);
    while(t--)
    {
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
}*/
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

void main()
{
    int t;
    int w,h;
    double pi=acos(-1);
    double v,r;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&w,&h);
        r=min(w/2.0,h/(2.0+2.0*pi));
        v=pi*r*r*w;
        r=min(h/3.0,w/(2.0*pi));
        v=max(v,pi*r*r*(h-2*r));
        printf("\n%.3f\n",v);
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

int max(int a,int b)
{
    return a>b?a:b;
}

void main()
{
    int t;
    int i,j;
    int n,V;
    int value[N],weight[N];
    int dp[N];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&V);
        for(i=0;i<n;i++)
        {
            scanf("%d",&value[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&weight[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=V;j>=0;j--)
            {
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
        printf("%d\n",dp[V]);
    }
}*/
/*
#include<stdio.h>
#define N 10000
void main()
{
    int t,i,n;
    long sum;
    long mi[N];
    int tag;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        tag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&mi[i]);
            sum=sum+mi[i];
        }
        for(i=0;i<n;i++)
        {
            if(mi[i]>(sum-m[i]-1))
            {
                tag=1;
            }
        }
        if(!tag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}*/
/*
#include<stdio.h>
#include<string.h>

struct poin
{
    char a[15];
    char b[16];
}p[1005];
char c[15];

void main()
{
    int n,m;
    int i;

    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%s %s",p[i].a,p[i].b);
    }
    while(n--)
    {
        scanf("%s",c);
        for(i=0;i<m;i++)
        {
            if(strcmp(c,p[i].a)==0||strcmp(c,p[i].b)==0)
            {
                if(strlen(p[i].a)>strlen(p[i].b))
                    printf("%s",p[i].b);
                else
                    printf("%s",p[i].a);
                if(n!=0)
                {
                    printf(" ");
                }
            }
        }
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    char *p1=(char *)malloc(sizeof(char));
    char *p2=(char *)malloc(sizeof(char));
    char a;
    int i=1,j=1,k;
    while((a=getchar())!='\n')
    {
        p1=(char *)realloc(p1,sizeof(char)*i);
        *(p1+i-1)=a;
        i++;
    }
    p1=(char *)realloc(p1,sizeof(char)*i);
    *(p1+i-1)='\0';

    while((a=getchar())!='\n')
    {
        p2=(char *)realloc(p2,sizeof(char)*i);
        *(p2+j-1)=a;
        j++;
    }
    p2=(char *)realloc(p2,sizeof(char)*i);
    *(p2+i-1)='\0';

    p1=(char *)realloc(p1,sizeof(char)*(i+j-1));
    for(k=0;k<j;k++,i++)
    {
        *(p1+i-1)=*(p2+k);
    }
    printf("%s\n",p1);
}*/

/*
memset(s1,0,sizeof(s1));
temp=(int)s[i];
while(temp!=0)
{
    s1[k++]=(temp&1);
    if(temp&1==1)
        ans++;
    temp=temp/2;
}
if(ans%2==1)
    s1[7]=0;
else
    s1[7]=1;
*/
/*
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
    char s[100],t[100];
    int m=0,n=0;
    int count=0;
    gets(s);
    gets(t);
    while(m<=strlen(s)&&n<=strlen(t))
    {
        if(s[m]==t[n])
            m++;
            n++;
        else
            m=m-n+1;
            n=0;
        if(n==strlen(t))
            count++;
    }
    if(m==strlen(s)+1)
        printf("count=%d",count);
}*/
/*
#include<string.h>
memset(s1,0,sizeof(s1));
temp=(int)s[i];
while(temp!=0)
{
    s1[k++]=(temp&1);
    if(temp&1==1)
        ans++;
    temp=temp/2;
}
if(ans%2==1)
    s1[7]=0;
else
    s1[7]=1;
*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct seqstring
{
    char string[100];
    int len;
}seqstring;

void getnext(seqstring p,int next[])
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<p.len)
    {
        if(j==-1||p.string[i]==p.string[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int kmp(seqstring t,seqstring p,int next[])
{
    int i=0,j=0;
    while(i<t.len&&j<t.len)
    {
        if(j==-1||t.string[i]==p.string[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==p.len)
        return i-p.len;
    else
        return -1;
}

void main()
{
    seqstring t,p;
    int next[50];
    scanf("%s",t.string);
    t.len=strlen(t);

    scanf("%s",p.string);
    p.len=strlen(p);

    getnext(p,next);
    printf("\n%d\n",kmp(t,p,next));
}*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct seqstring
{
    char string[100];
    int len;
}seqstring;

void getnext(seqstring p,int next[])
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<p.len)
    {
        if(j==-1||p.string[i]==p.string[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

void kmp(seqstring t,seqstring p,int next[])
{
    int i=0,j=0;
    while(i<t.len&&j<p.len)
    {
        if(j==-1||t.string[i]==p.string[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==p.len)
        return i-p.len;
    else
        return -1;
}

void main()
{
    seqstring t,p;
    int next[100];

    scanf("%s",t.string);
    t.len=strlen(t.string);

    scanf("%s",p.string);
    p.len=strlen(p.string);

    getnext(p,next);
    printf("\n%d\n",kmp(t,p,next));
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100001

char a[N],b[N],sum[N];

int bigDataPlus()
{
    int i,j,k=0;
    int lena,lenb;
    int c=0;
    int temp;
    lena=strlen(a);
    lenb=strlen(b);
    memset(sum,0,sizeof(sum));

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
    if(c==1)
    {
        sum[k++]='1';
    }
    for(i=0,j=k-1;i<j;i++,j--)
    {
        temp=sum[i];
        sum[i]=sum[j];
        sum[j]=temp;
    }
}*/
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
/*
int na=a*10+c,nb=b*10+d;
if(a*1.0/b*c*1.0/d>=na*1.0/nb*1.0-0.0000001&&
   a*1.0/b*c*1.0/d<=na*1.0/nb*1.0+0.0000001)
*/

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
                dp[j]=max(dp[j],1-(1-dp[j-a[i]])*(1-b[i]));
            }
        }
        printf("%.1f%%\n",dp[n]*100);
    }
}*/

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
/*
#include<stdio.h>
void create(void);
int safe(int i,int j,int m,int n);
int isLink(int ,int );
void dfs(int);
void out(void);

struct problem
{
    int farmer;
    int wolf;
    int sheep;
    int vegetable;
};

int visit[16];
int max=0;
int pa=0;
struct problem p[16];
int link[16][16];
int path[16];

void main()
{
    int i;
    for(i=0;i<16;i++)
        visit[i]=0;
    create();
    dfs(0);
}

int safe(int i,int j,int m,int n)
{
    if(i!=m&&(j==m||m==n))
        return 0;
    return 1;
}

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
}

void dfs(int n)
{
    int i;
    visit[n]=1;
    path[pa++]=n;
    if(n==max)
    {
        out();
        return;
    }
    for(i=0;i<=max;i++)
    {
        if(link[n][i]&&!visit[i])
        {
            dfs(i);
            pa--;
            visit[i]=0;
        }
    }
}

void create()
{
    int i,j,m,n;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(m=0;m<2;m++)
            {
                for(n=0;n<2;n++)
                {
                    if(safe(i,j,m,n))
                    {
                        p[max].farmer=i;
                        p[max].wolf=j;
                        p[max].sheep=m;
                        p[max].vegetable=n;
                        max++;
                    }
                }
            }
        }
    }
    max--;
    for(i=0;i<=max;i++)
        for(j=0;j<=max;j++)
            if(isLink(i,j))
                link[i][j]=1;
            else
                link[i][j]=0;
}*/
/*
#include<stdio.h>
void main()
{
    int n=0;
    if(!n)
    {
        printf("---\n");
    }
}*/
/*
void dfs(int n)
{
    int i;
    visit[n]=1;
    path[pa++]=n;
    if(n==max)
    {
        out();
        return;
    }
    for(i=0;i<=max;i++)
    {
        if(link[n][i]&&!visit[i])
        {
            dfs(i);
            pa--;
            visit[i]=0;
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define max 8

int sum=0;
int queen[max];

void show()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("(%d %d)",i,queen[i]);
    }
    printf("\n");
    sum++;
}

int check(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
            return 1;
    }
    return 0;
}

void put(int n)
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n]=i;
        if(!check(n))
        {
            if(n==max-1)
                show();
            else
                put(n+1);
        }
    }
}

void main()
{
    put(0);
    printf("%d\n",sum);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define max 8

int sum=0;
int queen[max];

void show()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("(%d %d)",i,queen[i]);
    }
    printf("\n");
    sum++;
}

int check(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
        {
            return 1;
        }
    }
    return 0;
}

void put(int n)
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n]=i;
        if(!check(n))
        {
            if(n==max-1)
            {
                show();
            }
            else
                put(n+1);
        }
    }
}

void main()
{
    put(0);
    printf("%d",sum);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define max 8

int sum=0;
int queen[max];

void show()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("(%d %d)",i,queen[i]);
    }
    printf("\n");
    sum++;
}

void check(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
        {
            return 1;
        }
    }
    return 0;
}

void put(int n)
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n]=i;
        if(!check(n))
        {
            if(n==max-1)
                show();
            else
                put(n+1);
        }
    }
}

void main()
{
    put(0);
    printf("%d\n",sum);
}*/
/*
#include<stdio.h>
#include<string.h>

typedef struct ch_arr
{
    int index[100];
    int flag;
    int p;
}ch_arr;

void main()
{
    ch_arr temp[130];
    char str[100];
    int k,t;

    while(scanf("%s",str)!=EOF)
    {
        for(k=0;k<130;k++)
        {
            temp[k].p=0;
            temp[k].flag=0;
        }

        for(k=0;k<strlen(str);k++)
        {
            temp[str[k]].index[temp[str[k]].p]=k;
            temp[str[k]].p++;
        }
        for(k=0;k<strlen(str);k++)
        {
            if(temp[str[k]].p>1&&temp[str[k]].flag==0)
            {
                for(t=0;t<temp[str[k]].p-1;t++)
                {
                    printf("%c:%d,",str[k],temp[str[k]].index[t]);
                }
                printf("%c:%d,",str[k],temp[str[k]].index[t]);
                temp[str[k]].flag=1;
            }
        }
    }
}*/
/*
bool isIPAddressValid(const char *pszIPAddr)
{
    char temp[5]='\0';
    int i=0,j;
    int count=0;
    int number;

    if(pszIPAddr==NULL)
        return false;
    while(*pszIPAddr!='\0')
    {
        if(count==0&&i==0&&*pszIPAddr=' ')
        {
            pszIPAddr++;
            continue;
        }
        if(count<3)
        {
            if(*pszIPAddr<='9'&&*pszIPAddr>='0')
            {
                temp[i++]=*pszIPAddr;
                if(i>3)
                    return false;
            }
            else
            {
                if(*pszIPAddr=='.')
                {
                    if(i==0)
                        return false;
                    temp[i]='\0';
                    number=0;
                    if(temp[0]='0'&&i>1)
                        return false;
                    for(j=0;j<i;j++)
                    {
                        number=number*10+temp[j]-'0';
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
            while(count==3)
            {
                if(*pszIPAddr<='9'&&*pszIPAddr>='0')
                {
                    temp[i++]=*pszIPAddr;
                    if(i>3)
                        return false;
                }
                else
                {
                    if(i==0)
                        return false;
                }
            }
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct BitNode
{
    int value;
    struct BitNode *lchild,*rchild;
}BiTree;

void inserBST(BiTree **root,int data)
{
    if(*root==NULL)
    {
        *root=(struct BiTree *)malloc(sizeof(BiTree));
        (*root)->value=data;
        (*root)->lchild=NULL;
        (*root)->rchild=NULL;
    }
    else
    {
        if(data<(*root)->value)
            inserBST(&((*root)->lchild),data);
        else if(data>(*root)->value)
            inserBST(&((*root)->rchild),data);
    }
}

void MK(BiTree **r,int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        inserBST(&(*r),a[i]);
}

void PreOrderTraverse(BiTree *root)
{
    if(root)
    {
        printf("%d ",root->value);
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}

void main()
{
    int n,i;
    int a[100];
    BiTree *root;
    while(scanf("%d",&n)!=EOF)
    {
        root=NULL;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        MK(&root,a,n);
        PreOrderTraverse(root);
        printf("\n");
        InOrderTraverse(root);
        printf("\n");
        PostOrderTraverse(root);
        printf("\n");
    }
}*/
/*
while(scanf("%d",&N)!=EOF)
{
    m=N*N;
    temp=N;
    flag=1;
    while(temp!=0)
    {
        num1=temp%10;
        num2=m%10;
        if(num1!=num2)
        {
            flag=0;
            break;
        }
        temp/=10;
        m/=10;
    }
}*/
/*
#include<stdio.h>
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
void main()
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
}*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LinkList;

void main()
{
    int i,N;
    while(scanf("%d",&N)!=EOF)
    {
        LinkList *head,*pre,*p,*newNode;
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;

        for(i=0;i<N;i++)
        {
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);

            pre=head;
            p=head->next;
            while(p)
            {
                if(newNode->data<p->data)
                    break;
                pre=p;
                p=p->next;
            }
            newNode->next=p;
            pre->next=newNode;
        }
        p=head->next;
        printf("%d",p->data);
        while(p->next)
        {
            p=p->next;
            printf(" %d",p->data);
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}LinkList;

void main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        LinkList *head,*pre,*p,*newNode;
        head=(LinkList *)malloc(sizeof(LinkList));
        head->next=NULL;

        for(i=0;i<n;i++)
        {
            newNode=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&newNode->data);

            pre=head;
            p=head->next;
            while(p)
            {
                if(newNode->data<p->data)
                    break;
                pre=p;
                p=p->next;
            }
            newNode->next=p;
            head->next=newNode;
        }
        p=head->next;
        printf("%d",p->data);
        while(p->next)
        {
            p=p->next;
            printf(" %d",p->data);
        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    char c,cb;
    int ccount=0,wcount=0,scount=0;
    FILE *fp=fopen("D:\\abc0.txt","w");
    FILE *fp1=fopen("D:\\abc1.txt","r");
    if(fp==NULL)
        return 0;
    while((c=getchar())!=EOF)
    {
        fputc(c,fp);
    }
    fclose(fp);
    //-------------------------
    fp=fopen("D:\\abc0.txt","r");
    if(fp==NULL)
        return 0;
    if(fp1==NULL)
        return 0;
    cb=NULL;
    while((c=fgetc(fp))!=EOF)
    {
        if(c==' ')
        {
            if(cb==' ')
                continue;
            else
                fputc(c,fp);
        }
        else
            fputc(c,fp);
        cb=c;
    }
    fclose(fp);
    fclose(fp1);
    //--------------------------
    fp1=fopen("D:\\abc1.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        ccount++;
        putchar(c);
        if(c==' ')
            wcount++;
        if(c=='.')
            scount++;
    }
    wcount++;
    fclose(fp1);
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *num;
    int i,j;
    int t,count=0;

    num=(int *)malloc(sizeof(int));
    scanf("%d",&t);

    while(t)
    {
        count++;
        num=(int *)realloc(num,count*sizeof(int));
        num[count-1]=t;
        scanf("%d",&t);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *num;
    int i,j;
    int t;
    int temp;
    int count;

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
}*/
/*
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *num;
    int i;
    int count=0;

    num=(int *)malloc(sizeof(int));
    scanf("%d",&t);
    while(t)
    {
        count++;
        num=(int *)realloc(num,count*sizeof(int));
        num[count-1]=t;
        scanf("%d",&t);
    }
}
*/
/*
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char *data;
    struct node *lchild,*rchild;
}BNode,*BTree;

void insert(BTree *t,char *data)
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

void main()
{
    int i,n;
    int count;
    char **a;
    char c;
    scanf("%d",&n);
    a=(char **)malloc(sizeof(char *)*n);
    getchar();
    if(a==NULL)
    {
        return 0;
    }
    for(i=0;i<n;i++)
    {
        count=0;
        a[i]=(char *)malloc(sizeof(char));
        while((c=getchar())!='\n')
        {
            count++;
            a[i]=(char *)realloc(a[i],count*sizeof(char));
            a[i][count-1]=c;
        }
        a[i]=(char *)realloc(a[i],(count+1)*sizeof(char));
        a[i][count]='\0';
    }
    for(i=0;i<n;i++)
    {
        insert(&t,a[i]);
    }
    PreOrder(t);
    fflush(stdin);
}*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char *data;
    struct node *lchild,*rchild;
}BNode,*BTree;

void insert(BTree *t,char *data)
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

void main()
{
    char **a;
    int n,i;
    char c;
    int count;
    scanf("%d",&n);
    a=(char **)malloc(sizeof(char *));
    getchar();
    if(a==NULL)
    {
        return 0;
    }
    for(i=0;i<n;i++)
    {
        count=0;
        a[i]=(char *)malloc(sizeof(char));
        while((c=getchar())!=EOF)
        {
            count++;
            a[i]=(char *)realloc(num,count*sizeof(char));
            a[i][count-1]=c;
        }
        a[i]=(char *)realloc(num,(count+1)*sizeof(char));
        a[i][count]='\0';
    }
    for((i=0;i<n;i++)
    {
        insert(&t,a[i]);
    }
    PreOrder(t);
    fflush(stdin);
}*/
/*
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
}*/
/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>

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
    for(i=1;i<len;i++)
    {
        if(flag==2&&isalpha(s[i]))
            return 0;
        if(flag==1&&isdigit(s[i]))
            return 0;
    }
}

void main()
{
    char **str;
    char ch='!';
    int i,j,k,count;
    char t[100];
    str=(char **)malloc(sizeof(char *));
    fflush(stdin);
    for(i=0;ch!='\n';i++)
    {
        count=0;
        str=(char **)realloc(str,(i+1)*sizeof(char *));
        str[i]=(char *)malloc(sizeof(char));
        while((ch=getchar())!=' '&&ch!='\n')
        {
            if(ch=='\n')
                break;
            count++;
            str[i]=(char *)realloc(str,count*sizeof(char));
            str[i][count-1]=ch;
        }
        str[i]=(char *)realloc(str[i],(count+1)*sizeof(char));
        str[i][count]='\0';
        if(check(str[i])==0)
        {
            printf("error!\n");
            exit(-1);
        }
    }

}
*/
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

    scanf("%d",&n);
    map=(int **)malloc(n*sizeof(int *));
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;

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
    while(p)
    {
        printf("%d(%d,%d)",p->distance,p->x,p->y);
        p=p->next;
    }
    s=(int *)malloc(n*sizeof(int));
    tree=(struct node *)malloc(sizeof(struct node));

}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5010

void main()
{
    char s[MAX];
    char s1[MAX];
    int t,len,st,end;
    int i,j,max,k;
    int pos[MAX];

    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        len=strlen(s);
        for(i=0;i<len;++i)
        {
            if(isalpha(s[i]))
            {
                pos[k]=i;
                if(s[i]<97)
                    s1[k++]=s[i]+32;
                else
                    s1[k++]=s[i];
            }
        }
        //k为新字串的长度
        for(i=0;i<k;++i)
        {
            for(j=0;j<=i&&i+j<k;++j)
            {
                if(s1[i-j]!=s1[i+j])
                    break;
                if(j*2+1>max)
                {
                    max=2*j+1;
                    st=pos[i-j];
                    end=pos[i+j];
                }
            }

            for(j=0;j<=i&&i+j+1<k;++j)
            {
                if(s1[i-j]!=s1[i+j+1])
                    break;
                if(j*2+2>max)
                {
                    max=j*2+2;
                    st=pos[i-j];
                    end=pos[i+j+1];
                }
            }
        }
        for(i=st;i<=end;++i)
            printf("%c",s[i]);
        printf("\n");
    }
}*/
/*
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
}

char *DtoB(int x,char str[])
{
    int i=0;
    do
    {
        str=(char *)realloc(str,sizeof(char));
        str[i++]=x%2+'0';
        x=x/2;
    }while(x>0);
    str[i]='\0';
    return str;
}*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char *a=(char *)malloc(sizeof(char));
    char *b=(char *)malloc(sizeof(char));
    int counta=1,countb=1;
    int i,len;
    char ch;
    int leno,lenj;
    char aj[20]={},ao[20]={};

    while((ch=getchar())!=' ')
    {
        a=(char *)realloc(a,counta*sizeof(char));
        *(a+counta-1)=ch;
        counta++;
    }
    a=(char *)realloc(a,counta*sizeof(char));
    *(a+counta-1)='\0';

    while((ch=getchar())!='\n')
    {
        b=(char *)realloc(b,countb*sizeof(char));
        *(b+countb-1)=ch;
        countb++;
    }
    b=(char *)realloc(b,countb*sizeof(char));
    *(b+countb-1)='\0';

    a=(char *)realloc(a,(counta+countb-1)*sizeof(char));
    for(k=0;k<countb;k++,counta++)
    {
        *(a+counta-1)=*(b+k);
    }
    printf("%s\n",a);

    len=strlen(a);
    counta=0;
    countb=0;
    for(k=0;k<len;k++)
    {
        if(k%2==0)//偶数
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
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isRepeat(char str[],char c,int m)
{
    int len=strlen(str);
    int i;
    int flag=0;
    for(i=0;i<m;i++)
    {
        if(str[i]==c)
            flag=1;
    }
    return flag;
}


void main()
{
    char *p=(char *)malloc(sizeof(char));
    char ch;
    int count,len;

    while((ch=getchar())!='\n')
    {
        p=(char *)realloc(p,count*sizeof(char));
        *(p+count-1)=ch;
        count++;
    }
    p=(char *)realloc(p,count*sizeof(char));
    *(p+count-1)='\0';
    printf("%s\n",p);

    len=strlen(p);
    count=0;
    for(i=0;i<len;i++)
    {
        if(isRepeat(p,p[i],i)==0)
        {

        }
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char a[10];
    int i,len;
    char strh[5]={},strl[5]={};
    itoa(97,a,2);
    len=strlen(a);
    for(i=len-1;i>=len-4;i--)
    {
        strl[count]=a[i];
        count++;
    }
}*/

/*void RemoveExtraSpace(char *str)
{
    int keep_space=0;
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
}*/
/*
void RemoveExtraSpace(char *str)
{
    int keep_space=0;
    int new_str_end=0;
    int i;
    for(i=0;str[i];++i)
    {
        //不为空格，则记录
        if(str[i]!=' ')
        {
            keep_space=1;
            str[new_str_end++]=str[i];
        }
        //为空格，且前一项不为空格
        else if(keep_space==1)
        {
            str[new_str_end++]=str[i];
            keep_space=0;
        }
        //否则 是为空格，且前一项为空格，不进行处理
    }
}*/
/*
#include<stdio.h>
#define m 3
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *child[m];
}node,*tree;
tree root;

void preorder(tree p)
{
    int i;
    if(p!=NULL)
    {
        printf("%c",p->data);
        for(i=0;i<m;++i)
        {
            preorder(p->child[i]);
        }
    }
}

void postorder(tree p)
{
    int i;
    if(p!=NULL)
    {
        for(i=0;i<m;++i)
        {
            postorder(p->child[i]);
        }
        printf("%c",p->data);
    }
}*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild,*rchild;
}bitnode;
typedef bitnode *bintree;

bintree root;

void preorder(bintree t)
{
    if(t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bintree t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

void postorder(bintree t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

bintree createbintree()
{
    char ch;
    bintree t;
    if((ch=getchar())=='#')
    {
        t=NULL;
    }
    else
    {
        t=(bintree *)malloc(sizeof(struct bitnode));
        t->data=ch;
        t->lchild=createbintree();
        t->rchild=createbintree();
    }
    return t;
}*/
/*
#include<stdio.h>
#include<string.h>

void main()
{
    char s[1005];
    int i,j;
    int count1,count2,count3;
    int len;
    while(scanf("%s",s)!=EOF)
    {
        count1=count2=count3=0;
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
        if(count1!=1||count2!=1||count3!=1)
        {
            printf("WA\n");
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
            printf("AC\n");
        else
            printf("WA\n");
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define M 100000
#define N 1005

int map[N][N];
int value[N][N];
int dis[N];
int va[N];
int vis[N];

void dijkstra(int start,int n)
{
    int i,j,k,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[start][i];
        va[i]=value[start][i];
    }
    dis[start]=0;

    for(i=1;i<=n-1;i++)
    {
        min=M;
        k=0;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        if(k==1)
            return;
        for(j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
                va[j]=va[k]+value[k][j];
            }
            else if((dis[j]==dis[k]+map[k][j])&&(va[j]>va[k]+value[k][j]))
            {
                va[j]=va[k]+value[k][j];
            }
        }
    }
}

void main()
{
    int n,m;
    int a,b,d,p;
    int s,t;

    while(scanf("%d %d",&n,&m)&&(n+m))
    {
        memset(vis,0,sizeof(vis));
        memset(map,M,sizeof(map));
        memset(value,M,sizeof(value));

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(map[a][b]>p)
            {
                map[a][b]=d;
                map[b][a]=d;
                value[a][b]=p;
                value[b][a]=p;
            }
        }
        scanf("%d %d",&s,&t);
        dijkstra(s,n);
    }
    printf("%d %d\n",dis[t],va[t]);
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000005
#define N 1050

int dis[N];
int map[N][N];
int vis[N];
int armycity[N];

void dijkstra(int query,int v)
{
    int i,j,k;
    int min=0;
    for(i=1;i<=v;i++)
    {
        dis[i]=map[query][i];
    }
    dis[query]=0;

    for(i=1;i<=v-1;i++)
    {
        min=MAX;
        k=0;
        for(j=1;j<=v;j++)
        {
            if((!vis[j])&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)
            return;
        vis[k]=1;
        for(j=1;j<=v;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
            }
        }
    }

}

void main()
{
    int n,m,p,q;
    int t;
    int a,b,c;
    int i;
    int ans=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&p,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&armycity[i]);
        }
        memset(map,MAX,sizeof(map));
        memset(vis,0,sizeof(vis));
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
        ans=MAX;
        for(i=0;i<n;i++)
        {
            if(ans>dis[armycity[i])
            {
                ans=dis[armycity[i]];
            }
        }
        printf("%d\n",ans);
    }
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10005
#define N 1050

int dis[N];
int map[N][N];
int vis[N];
int armycity[N];

void dijkstra(int query,int n)
{
    int i,j,k;
    int min=0;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[query][i];
    }
    dis[query]=0;
    for(i=1;i<=n-1;i++)
    {
        min=MAX;
        k=0;
        for(j=1;j<=n;j++)
        {
            if((!vis[j])&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)
            return;
        vis[k]=1;
        for(j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
            }
        }
    }
}

void dijkstra(int query,int n)
{
    int i,k,j;
    int min;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[query][i];
    }
    dis[query]=0;

    for(i=1;i<=n-1;i++)
    {
        min=MAX;
        k=0;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&(min>dis[j]))
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==0)
            return;
        vis[k]=1;
        for(j=1;j<=n;j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
            }
        }
    }

}


void main()
{
    int n,m,q,p;
    int t,i;
    int a,b,c;
    int ans=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&q,&p);
        for(i=0;i<n;i++)
        {
            scanf("%d",&armycity[i]);
        }
        memset(map,MAX,sizeof(map));
        memset(vis,0,sizeof(vis));
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
        ans=MAX;
        for(i=0;i<n;i++)
        {
            if(ans>dis[armycity[i]])
                ans=dis[armycity[i]];
        }
    }
    printf("%d\n",ans);
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

char s[N];
int t1[N];
int t2[N];

void build(char *str,int *t)
{
    int i;
    t[1]=str[0]-'0';
    for(i=1;s[i];i++)
    {
        insert(s[i],t);
    }
}

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]<c)
        {
            pos=2*pos+1;
        }
        else
            pos=2*pos;
    }
    t[pos]=c;
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

char s[N];
int t1[N];
int t2[N];

void insert(char w,int *t)
{
    int pos=1;
    int c=w-'0';
    while(t[pos]!=-1)
    {
        if(t[pos]>c)
            pos=2*pos;
        else
            pos=2*pos+1;
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
}*/
/*
double fun(double x,double n)
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
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 1000

typedef struct NUM
{
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
        for(j=0;j<size-i-1;j++)
        {
            if(a[j].data>a[j+1].data)
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void main()
{
    int num;
    int i;
    int order[N];
    struct NUM temp;
    int cnt;
    int pre;

    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            scanf("%d",&array[i].data);
            array[i].order=i;
            order[i]=0;
        }
        selectSort(array,num);
        cnt=1;
        pre=-999999;
        for(i=0;i<num;i++)
        {
            if(i&&pre=array[i].data)
                order[array[i].order]=cnt;
            else if(i&&pre!=array[i].data)
                order[array[i].order]=++cnt;
            else if(!i)
                order[array[i].order]=cnt;
            pre=array[i].data;
        }
        for(i=0;i<num;i++)
        {
            if(i!=num-1)
                printf("%d ",order[i]);
            else
                printf("%d\n",order[i]);
        }
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000

char str[N],string[N][N],string2[N][N];

void main()
{
    int index=0;
    int i,j,k;
    gets(str);
    while(gets(string[index]))
    {
        if(strcmp(string[index],"}")==0)
            break;
        index++;
    }
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]+32;
    }
    for(i=0;i<index;i++)
    {
        for(j=0;j<strlen(string[i]);j++)
        {
            string2[i][j]=string[i][j];
            if(string[i][j]>='A'&&string[i][j]<='Z')
                string[i][j]=string[i][j]+32;
        }
        for(j=0,k=0;j<strlen(string[i]);)
        {
            if(string[i][j+k]==str[k])
            {
                k++;
                if(k==strlen(str))
                {
                    j=j+k;
                }
            }
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
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 1000

int max(int a,int b)
{
    return a>b?a:b;
}

void main()
{
    int m[N],b[N],dp[N];
    int i,j,t;
    int n,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&V);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=v;j>0;j--)
            {
                dp[j]=max(dp[j],dp[j-b[i]]+m[i]);
            }
        }
        printf("%d\n",dp[v]);
    }
}*/
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
    int a[100];
    double b[100];
    int i,j;
    double *dp;
    int n,m;

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d %ld",&a[i],&b[i]);
        }
        dp=(double *)malloc(sizeof(double)*(n+1));
        memset(dp,0,sizeof(double)*(n+1));

        for(i=1;i<=m;i++)
        {
            for(j=n;j>=a[i];j--)
            {
                dp[j]=max(dp[j],1-(1-dp[j-a[i]])*(1-b[i]));
            }
        }
        printf("%.1f%%\n",dp[n]*100);
    }
}*/

/*
#include<stdio.h>
#define MAX 1005

void main()
{
    int monkey[MAX]={0};
    int n,temp=0;
    int count=0,monkeyOut=0;
    int i;
    scanf("%d",&n);
    do
    {
        temp++;
        if(temp>n)
            temp=1;
        if(!monkey[temp])
        {
            count++;
        }
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
/*
#include<stdio.h>
#define MAX 1005

void main()
{
    int monkey[MAX]={0};
    int n,temp=0;
    int i;
    int monkeyOut=0;

    scanf("%d",&n);
    do
    {
        temp++;
        if(temp>n)
            temp=1;
        if(!monkey[temp])
            count++;
        else
            continue;
        if(count==3)
        {
            count=0;
            monkeyOut++;
            monkey[temp]=1;
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
/*
void dfs(int x,int y)
{
    bone[x][y].visited=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(place(x,y,nx,ny))
            dfs(nx,ny);
    }
}*/

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


















