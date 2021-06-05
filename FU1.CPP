#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>

void dis(int a)
{
if(a<10)
cout<<"   ";
else if(a<100)
cout<<"  ";
else if(a<1000)
cout<<" ";
else
cout<<"";
}

void putlist(int A[4][4])
{char ul=218,um=194,ur=191,ml=195,mc=197,mr=180,dl=192,dm=193,dr=217,h=179,v=196;
cout<<"\t\t\t     "<<ul<<v<<v<<v<<v<<um<<v<<v<<v<<v<<um<<v<<v<<v<<v<<um<<v<<v<<v<<v<<ur<<endl;
for(int i=0;i<4;i++)
{cout<<"\t\t\t     ";
for(int j=0;j<4;j++)
{cout<<h;
if(A[i][j]==0)
cout<<" ";
else
cout<<A[i][j];
dis(A[i][j]);}
cout<<h<<endl;
if (i<3)
cout<<"\t\t\t     "<<ml<<v<<v<<v<<v<<mc<<v<<v<<v<<v<<mc<<v<<v<<v<<v<<mc<<v<<v<<v<<v<<mr<<endl;
}
cout<<"\t\t\t     "<<dl<<v<<v<<v<<v<<dm<<v<<v<<v<<v<<dm<<v<<v<<v<<v<<dm<<v<<v<<v<<v<<dr<<endl;
}

void merge(int A[4],int &points)
{
int la[4],r[4],j=0,k=0,reurn[4];
for(int i=0;i<4;i++)
{if(A[i]!=0)
{la[j]=A[i];
j++;}}

for(i=0;i<j;i++)
{
if(la[i]==la[i+1]&&i!=j-1)
{r[k]=la[i]+la[i+1];
points += r[k] ;
i++;}
else
{r[k]=la[i];}
k++;}
for(i=0;i<4;i++)
{A[i]=r[i];}

for(i=k;i<4;i++)
A[i]=0;
}

void change(int Q[4][4],char al[6],int &points)
{
alll:
int i=0;
while(al[i]!='\0')
{al[i]=toupper(al[i]);
i++;}

if(!strcmp(al,"QUIT"))
exit(4);
if(!strcmp(al,"RIGHT"))
{int ar[4];
for( i=0;i<4;i++)
{for(int j=3;j>=0;j--)
{ar[3-j]=Q[i][j];}
merge(ar, points);
for(j=3;j>=0;j--)
{Q[i][j]=ar[3-j];}}}

else if(!strcmp(al,"LEFT"))
{for(i=0;i<4;i++)
{merge(Q[i], points);}}

else if(!strcmp(al,"UP"))
{int ar[4];
for(i=0;i<4;i++)
{for(int j=0;j<4;j++)
{ar[j]=Q[j][i];}
merge(ar, points);
for(j=0;j<4;j++)
{Q[j][i]=ar[j];}}}

else if(!strcmp(al,"DOWN"))
{int ar[4];
for(i=0;i<4;i++)
{for(int j=3;0<=j;j--)
{ar[3-j]=Q[j][i];}
merge(ar, points);
for(j=3;0<=j;j--)
{Q[j][i]=ar[3-j];}}
}
else
{cout<<"Wrong input.Enter:";
gets(al);
goto alll;
}}




void main()
{clrscr();
cout<<"\t\t\t    Welcome To 2048 Game \n";
cout<<"INSTRUCTION: Enter direction right, left, up and down for moving them.\n\t     Quit for exit.\n";
int A[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},space=1, points=0;
randomize();
A[random(4)][random(4)]=2;
do{
int a,b;
a=random(4);
b=random(4);
while(A[a][b]!=0)
{a=random(4);
b=random(4);}
A[a][b]=2;
cout<<"\n\n\n";
putlist(A);
cout<<"Points :"<<points<<"\n\n\n";

cout<<"Enter direction:";
char Alpha[6];
gets(Alpha);

change(A,Alpha,points);
delay(1000);
clrscr();
cout<<"\t\t\t\t   2048 GAME";
cout<<"\n\n\n";
putlist(A);
cout<<"Points :"<<points<<"\n\n\n";
delay(1000);
int win=0,space=0;


for(int i=0;i<4;i++)
{for(int j=0;j<4;j++)
{if(A[i][j]==2048)
{win=1;}
else if(A[i][j]==0)
{space=1;}
}}

if(win==1)
{cout<<"\t\t\t\tCONGRULATIONS\n\t\t\t\t   YOU WON";break;}
else if(space==0)
{cout<<"\t\t\t\t   You lose ";
break;}

clrscr();
cout<<"\t\t\t\t   2048 GAME";

}while(space);
getch();
}