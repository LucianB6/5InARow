#include<iostream>
#include<graphics.h>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;
int A[50][50],q;
int matrice,p2,limba,culori1,culori2,cp=0,pvp,player2,muzica;

void sizeM( int &n)
{
 if(matrice==0||matrice==8)
    n=8;
 if(matrice==16)
    n=16;
 if(matrice==6)
    n=6;
}
bool CorrectMove(int A[50][50],int a,int b,int n)
{
  if(A[a][b]==0&&a<n&&b<n)
    return 1;
  return 0;
}
bool P1_win(int A[50][50],int c,int n)
{
  int l,i,j,k,t;
   setlinestyle(0,0,3);
  for(i=0;i<n;i++)
  {
    l=1;
    for(j=0;j<n-1;j++)
       if(A[i][j]==1&&A[i][j+1]==1)
       {
         l++;
         if(l==c)
         {
           if(n==8)
              line(i*36+271,(j-c+2)*36+199,i*36+271,(j+1)*36+199);
           if(n==16)
              line(i*36+120,(j-c+2)*36+32,i*36+120,(j+1)*36+32);
           return 1;
          }
       }
       else
         l=1;
  }
  for(j=0;j<n;j++)
  {
    l=1;
    for(i=0;i<n-1;i++)
    if(A[i][j]==1&&A[i+1][j]==1)
    {
      l++;
      if(l==c)
      {
        if(n==8)
          line((i-c+2)*36+271,j*36+199,(i+1)*36+271,j*36+199);
        if(n==16)
          line((i-c+2)*36+120,j*36+32,(i+1)*36+120,j*36+32);
        return 1;
      }
    }
    else
      l=1;
  }
  for(i=0;i<n;i++)
     { l=1;
       for(j=0;j<n;j++)  //-sub diag princip
        if(i+j<n)
          if(A[i+j][j]==1&&A[i+j+1][j+1]==1)
          {
              l++;
              if(l==c)
              {
                 if(n==8)
                   line((i+j-c+2)*36+271,(j-c+2)*36+199,(i+j+1)*36+271,(j+1)*36+199);
                 if(n==16)
                    line((i+j-c+2)*36+120,(j-c+2)*36+32,(i+j+1)*36+120,(j+1)*36+32);
                 return 1;
              }
           }
            else
               l=1;
      }
  for(i=0;i<n;i++)
      {l=1;
        for(j=0;j<n;j++)  //-partea deasupra diag prin
             if(i+j<n)
                if(A[j][i+j]==1&&A[j+1][i+j+1]==1)
                {
                  l++;
                  if(l==c)
                  {
                     if(n==8)
                        line((j-c+2)*36+271,(i+j-c+2)*36+199,(j+1)*36+271,(i+j+1)*36+199);
                     if(n==16)
                        line((j-c+2)*36+120,(i+j-c+2)*36+32,(j+1)*36+120,(i+j+1)*36+32);
                     return 1;
                  }
                 }
                  else
                      l=1;
      }
      k=n-1;
      for(i=0;i<n;i++)
      {
        l=1;
        for(j=0;j<=k;j++)    //deasupra diag sec
            if(A[j][k-j]==1&&A[j+1][k-j-1]==1)
            {
              l++;
              if(l==c)
              {
                if(n==8)
                  line((j-c+2)*36+271,(k-j+c-2)*36+199,(j+1)*36+271,(k-j-1)*36+199);
                if(n==16)
                  line((j-c+2)*36+120,(k-j+c-2)*36+32,(j+1)*36+120,(k-j-1)*36+32);
                return 1;
              }
             }
             else
              l=1;
         k--;
        }
        for(i=0;i<n;i++)
        {
          t=n-1;
          l=1;
          for(j=i+1;j<n;j++)    //sub diag sec
            if(t>i)
            {
              if(A[j][t]==1&&A[j+1][t-1]==1)
              {
                  l++;
                  if(l==c)
                  {
                     if(n==8)
                        line((j-c+2)*36+271,(t+c-2)*36+199,(j+1)*36+271,(t-1)*36+199);
                     if(n==16)
                        line((j-c+2)*36+120,(t+c-2)*36+32,(j+1)*36+120,(t-1)*36+32);
                     return 1;
                   }
                }
              else
                 l=1;
              t--;
             }
          }
  return 0;
}
bool P2_win(int A[50][50],int c,int n)     //c este nr de elemente in linie(ex: 5 in linie => c=5)
{
  int l,i,j,t,k;
  for(i=0;i<n;i++)
  {
    l=1;
    for(j=0;j<n-1;j++)
       if(A[i][j]==2&&A[i][j+1]==2)
       {
         l++;
         if(l==c)
          {
            if(n==8)
              line(i*36+271,(j-c+2)*36+199,i*36+271,(j+1)*36+199);
            if(n==16)
               line(i*36+120,(j-c+2)*36+32,i*36+120,(j+1)*36+32);
            return 1;
          }
       }
       else
          l=1;
  }
  for(j=0;j<n;j++)
  {
    l=1;
    for(i=0;i<n-1;i++)
    if(A[i][j]==2&&A[i+1][j]==2)
    {
      l++;
      if(l==c)
      {
          if(n==8)
             line((i-c+2)*36+271,j*36+199,(i+1)*36+271,j*36+199);
          if(n==16)
            line((i-c+2)*36+120,j*36+32,(i+1)*36+120,j*36+32);
          return 1;
      }
    }
    else
      l=1;
  }
   for(i=0;i<n;i++)
     {
       l=1;
       for(j=0;j<n;j++)  //-sub diag princip
           if(i+j<n)
           if(A[i+j][j]==2&&A[i+j+1][j+1]==2)
           {
             l++;
             if(l==c)
             {
               if(n==8)
                  line((i+j-c+2)*36+271,(j-c+2)*36+199,(i+j+1)*36+271,(j+1)*36+199);
               if(n==16)
                   line((i+j-c+2)*36+120,(j-c+2)*36+32,(i+j+1)*36+120,(j+1)*36+32);
               return 1;
             }
           }
           else
               l=1;
      }
  for(i=0;i<n;i++)
  {
      l=1;
      for(j=0;j<n;j++)  //-partea deasupra diag prin
          if(i+j<n)
            if(A[j][i+j]==2&&A[j+1][i+j+1]==2)
            {
               l++;
               if(l==c)
               {
                  if(n==8)
                     line((j-c+2)*36+271,(i+j-c+2)*36+199,(j+1)*36+271,(i+j+1)*36+199);
                  if(n==16)
                     line((j-c+2)*36+120,(i+j-c+2)*36+32,(j+1)*36+120,(i+j+1)*36+32);
                  return 1;
                }
            }
            else
                l=1;
    }
    k=n-1;
    for(i=0;i<n;i++)
    {
        l=1;
        for(j=0;j<=k;j++)    //deasupra diag sec
            if(A[j][k-j]==2&&A[j+1][k-j-1]==2)
            {
              l++;
              if(l==c)
              {
                if(n==8)
                  line((j-c+2)*36+271,(k-j+c-2)*36+199,(j+1)*36+271,(k-j-1)*36+199);
                if(n==16)
                   line((j-c+2)*36+120,(k-j+c-2)*36+32,(j+1)*36+120,(k-j-1)*36+32);
                return 1;
              }
             }
             else
              l=1;
        k--;
    }
    for(i=0;i<n;i++)
    {
        t=n-1;
        l=1;
        for(j=i+1;j<n;j++)    //sub diag sec
            if(t>i)
            {
               if(A[j][t]==2&&A[j+1][t-1]==2)
               {
                  l++;
                  if(l==c)
                  {
                     if(n==8)
                        line((j-c+2)*36+271,(t+c-2)*36+199,(j+1)*36+271,(t-1)*36+199);
                     if(n==16)
                        line((j-c+2)*36+120,(t+c-2)*36+32,(j+1)*36+120,(t-1)*36+32);
                     return 1;
                   }
                }
               else
                  l=1;
               t--;
             }
     }
  return 0;
}
void FPC(int A[50][50],int n,int c,int &a,int &b,int p)        //gaseste o formatiune posibil castigatoare
{                                          //p reprezinta jucatorul pentru care se verifica, pentru adversar voi avea 2 altfel 1
  int l,i,j,ok=0,o,m,t,k;
  for(i=0;i<n&&ok==0;i++)
  {
    l=1;
    for(j=0;j<n-1&&ok==0;j++)
       if(A[i][j]==p&&A[i][j+1]==p)
       {
         l++;
         if(l==2&&c==5)
            if(A[i][j+2]==0&&A[i][j+3]==p&&A[i][j+4]==p)
            {
               a=i;
               b=j+2;
               ok=1;
            }
         if(l==c-1)
         {
           if(A[i][j+2]==0&&j+2<n)
           {
              a=i;
              b=j+2;
              ok=1;
           }
         else
           if(A[i][j+2-c]==0&&j+2-c<n)
           {
             a=i;
             b=j+2-c;
             ok=1;
           }
          }
      }
       else
          l=1;
  }
  for(j=0;j<n&&ok==0;j++)
  {
      l=1;
      for(i=0;i<n-1&&ok==0;i++)
       if(A[i][j]==p&&A[i+1][j]==p)
       {
         l++;
         if(l==2&&c==5)
            if(A[i+2][j]==0&&A[i+3][j]==p&&A[i+4][j]==p)
            {
               a=i+2;
               b=j+2;
               ok=1;
            }
         if(l==c-1)
         {
           if(A[i+2][j]==0&&i+2<n)
           {
            a=i+2;
            b=j;
            ok=1;
           }
          else
            if(A[i+2-c][j]==0&&i+2-c<n)
            {
              a=i+2-c;
              b=j;
              ok=1;
            }
         }
       }
      else
         l=1;
  }
  for(i=0;i<n&&ok==0;i++)
     { l=1;
       for(j=0;j<n&&ok==0;j++)  //-sub diag princip
           if(i+j<n)
              if(A[i+j][j]==p&&A[i+j+1][j+1]==p)
              {
                 if(l==1)
                 {
                    m=i+j;
                    o=j;
                 }
                 l++;
                 if(l==2&&c==5)
                 {
                   if(A[i+j+2][j+2]==0&&A[i+j+3][j+3]==p&&A[i+j+4][j+4]==p)
                   {
                      a=i+j+2;
                      b=j+2;
                      ok=1;
                   }
                 }
                if(l==c-1)
                {
                  if(A[i+j+2][j+2]==0&&i+j+2<n&&j+2<n)
                  {
                     a=i+j+2;
                     b=j+2;
                     ok=1;
                  }
                  else
                  if(A[m-1][o-1]==0&&m-1>=0&&o-1>=0)
                  {
                     a=m-1;
                     b=o-1;
                     ok=1;
                  }
                }
             }
            else
               l=1;
      }
  for(i=0;i<n&&ok==0;i++)
  {
      l=1;
      for(j=0;j<n&&ok==0;j++)  //-partea deasupra diag prin
          if(i+j<n)
             if(A[j][i+j]==p&&A[j+1][i+j+1]==p)
             {
                if(l==1)
                {
                   m=j;
                   o=i+j;
                }
                l++;
                if(l==2&&c==5)
                {
                    if(A[j+2][i+j+2]==0&&A[j+3][i+j+3]==p&&A[j+4][i+j+4]==p)
                    {
                        a=j+2;
                        b=i+j+2;
                        ok=1;
                    }
                }
                if(l==c-1)
                {
                  if(A[j+2][i+j+2]==0&&j+2<n&&i+j+2<n)
                  {
                    a=j+2;
                    b=i+j+2;
                    ok=1;
                  }
                  else
                  if(A[m-1][o-1]==0&&m-1>=0&&o-1>=0)
                  {
                      a=m-1;
                      b=o-1;
                      ok=1;
                  }
                }
              }
              else
                l=1;
      }
  k=n-1;
  for(i=0;i<n&&ok==0;i++)
  {
      l=1;
      for(j=0;j<=k&&ok==0;j++)    //deasupra diag sec
          if(A[j][k-j]==p&&A[j+1][k-j-1]==p)
          {  if(l==1)
             {
                 m=j;
                 o=k-j;
             }
             l++;
             if(l==2&&c==5)
             {
               if(A[j+2][k-j-2]==0&&A[j+3][k-j-3]==p&&A[j+4][k-j-4]==p)
               {
                  a=j+2;
                  b=k-j-2;
                  ok=1;
               }
             }
             if(l==c-1)
             {  if(A[j+2][k-j-2]==0&& j+2<n&& k-j-2>=0)
                {
                  a=j+2;
                  b=k-j-2;
                  ok=1;
                }
            else
                if(A[m-1][o+1]==0&&m-1>=0&&o+1<n)
                {
                  a=m-1;
                  b=o+1;
                  ok=1;
                }
             }
            }
             else
              l=1;
         k--;
  }
   for(i=0;i<n&&ok==0;i++)
   {
       t=n-1;
       l=1;
       for(j=i+1;j<n&&ok==0;j++)    //sub diag sec
           if(t>i)
           {
              if(A[j][t]==p&&A[j+1][t-1]==p)
              {
                 if(l==1)
                 {
                    m=j;
                    o=t;
                 }
                 l++;
                 if(l==2&&c==5)
                 {
                     if(A[j+2][t-2]==0&&A[j+3][t-3]==p&&A[j+4][t-4]==p)
                     {
                        a=j+2;
                        b=t-2;
                        ok=1;
                     }
                 }
                 if(l==c-1)
                 {  if(A[j+2][t-2]==0&&j+2<n&&t-2>=0)
                    {
                       a=j+2;
                       b=t-2;
                       ok=1;
                    }
                    else
                    if(A[j-1][o+1]==0&&j-1>=0&&o+1<n)
                    {
                        a=j-1;
                        b=o+1;
                        ok=1;
                    }
                   }
                }
                else
                 l=1;
              t--;
            }
   }
    for(i=0;i<n&&ok==0;i++)
  {
    l=1;
    for(j=0;j<n-1&&ok==0;j++)
       if(A[i][j]==p&&A[i][j+1]==p)
       {
         l++;
         if(l==c-2&&A[i][j+2-c]==p&&A[i][j+3-c]==0)
         {
               a=i;
               b=j+3-c;
               ok=1;
         }
            else
          if(l==c-2&&A[i][j+2]==0&&A[i][j+3-c]==0&&j+2<n&&j+3-c>=0)
          {
              a=i;
              b=j+2;
              ok=1;
          }
         }
       else
        l=1;
    }
    for(j=0;j<n&&ok==0;j++)
  {
      l=1;
      for(i=0;i<n-1&&ok==0;i++)
       if(A[i][j]==p&&A[i+1][j]==p)
       {
         l++;
           if(l==c-2&&A[i+2-c][i]==p&&A[i+3-c][j]==0)
              {
                a=i+3-c;
                b=j;
                ok=1;
              }
           else
            if(l==c-2&&A[i+2][j]==0&&A[i+3-c][j]==0&&i+2<n&&i+3-c>=0)
            {
                a=i+2;
                b=j;
                ok=1;
            }
        }
        else
          l=1;
  }
 for(i=0;i<n&&ok==0;i++)
     { l=1;
       for(j=0;j<n&&ok==0;j++)  //-sub diag princip
           if(i+j<n)
           if(A[i+j][j]==p&&A[i+j+1][j+1]==p)
           {
             if(l==1)
             {
                m=i+j;
                o=j;
             }
             l++;
             if(l==c-2&&A[i+j+2][j+2]==0&&A[i+j+3][j+3]==p)
             {
                a=i+j+2;
                b=j+2;
                ok=1;
             }
             else
             if(l==c-2&&A[m-1][o-1]==0&&A[i+j+2][j+2]==0&&m-1>=0&&o-1>=0&&i+j+2<n&&j+2<n)
             {
                a=m-1;
                b=o-1;
                ok=1;
             }
           }
           else
                l=1;

      }
for(i=0;i<n&&ok==0;i++)
{   l=1;
    for(j=0;j<n&&ok==0;j++)  //-partea deasupra diag prin
        if(i+j<n)
           if(A[j][i+j]==p&&A[j+1][i+j+1]==p)
           {
               if(l==1)
              {
                  m=j;
                  o=i+j;
              }
              l++;
              if(l==c-2&&A[j+3][i+j+3]==p&&A[j+2][i+j+2]==0)
                {
                   a=j+2;
                   b=i+j+2;
                   ok=1;
                }
                else
                 if(l==c-2&&A[m-1][o-1]==0&&A[j+2][i+j+2]==0&&m-1>=0&&o-1>=0&&j+2<n&&i+j+2<n)
                 {
                   a=m-1;
                   b=o-1;
                   ok=1;
                 }
           }
           else
            l=1;
}
k=n-1;
for(i=0;i<n&&ok==0;i++)
{   l=1;
    for(j=0;j<=k&&ok==0;j++)    //deasupra diag sec
        if(A[j][k-j]==p&&A[j+1][k-j-1]==p)
        {
           if(l==1)
           {
              m=j;
              o=k-j;
           }
           l++;
           if(l==c-2&&A[j+3][k-j-3]==p&&A[j+2][k-j-2]==0)
             {
               a=j+2;
               b=k-j-2;
               ok=1;
             }
            else
             if(l==c-2&&A[m-1][o+1]==0&&A[j+2][k-j-2]==0&&m-1>=0&&o+1<n&&j+2<n&&k-j-2>=0)
             {
                a=m-1;
                b=o+1;
                ok=1;
             }
        }
        else
          l=1;
      k--;
}
for(i=0;i<n&&ok==0;i++)
{
    t=n-1;
    l=1;
    for(j=i+1;j<n&&ok==0;j++)    //sub diag sec
        if(t>i)
        {
           if(A[j][t]==p&&A[j+1][t-1]==p)
           {
              if(l==1)
              {
                  m=j;
                  o=t;
              }
              l++;
              if(l==c-2&&A[j+3][t-3]==p&&A[j+2][t-2]==0)
              {
                  a=j+2;
                  b=t-2;
                  ok=1;
              }
              else
              if(l==c-2&&A[m-1][o+1]==0&&A[j+2][t-2]==0&&m-1>=0&&o+1<n&&j+2<n&&t-2>=0)
              {
                  a=m-1;
                  b=o+1;
                  ok=1;
              }
          }
          else
          l=1;
          t--;
       }
    }
 if(ok==0)
 {
   a=n;
   b=n;
 }
}
void SimpleMove(int A[50][50],int n,int &a,int &b)
{
  int i,j,ok=0;
  for(i=0;i<n;i++)
     for(j=0;j<n;j++)
         if(A[i][j]==1&&A[i][j+1]==0&&A[i][j-1]==0&&j+1<n&&j-1>=0)
         {
            a=i;
            b=j+1;
            ok=1;
         }
  if(ok==0)
  {
     a=(n-1)/2;
     b=(n-1)/2;
     while(ok==0)
     {
          while(CorrectMove(A,a,b,n)==0&&a<n)
                 a++;
          if(CorrectMove(A,a,b,n)==0&&b<n)
              b++;
          else
             ok=1;
      }
  }
}
void bot(int A[50][50],int c,int n,int &a,int &b)
{
  FPC(A,n,c,a,b,1);
  A[a][b]=1;
  if(P1_win(A,c,n)==0)
  {
    A[a][b]=0;
    FPC(A,n,c,a,b,2);
     if(a==n)
     {
       FPC(A,n,c,a,b,1);
       if(a==n)
       {
        FPC(A,n,3,a,b,1);
        if(a==n)
           SimpleMove(A,n,a,b);
       }
     }
   }
}
void tab16(int &a,int &b)             //mutare pentru 16x16
{
 int i,j,w,r;
 int choice=0;

 do{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();
         for(i=103; i<=673 && choice==0; i+=36)
              for(j=18; j<=588; j+=36)
                  if(x>=i+5 && x <=673 && y>j && y <= 588 )
                  {
                    w=x-x%36+10;
                    r=y-y%36+32 ;
                    choice = 1;
                  }
    }
   if(choice==1)
   {
      if(cp == 0)
      {
          if(culori1 == 0)
          {
             setlinestyle(0,0,3);
             setfillstyle(SOLID_FILL,YELLOW);
             circle(w,r,10);
             floodfill(w,r,WHITE);
             player2 = 14;
          }
          if(culori1 == 1)
          {
             setlinestyle(0,0,3);
             setfillstyle(SOLID_FILL,BLUE);
             circle(w,r,10);
             floodfill(w,r,WHITE);
             player2 = 1;
          }
          if(culori1 == 2)
          {
             setlinestyle(0,0,3);
             setfillstyle(SOLID_FILL,YELLOW);
             circle(w,r,10);
             floodfill(w,r,WHITE);
             player2 = 14;
          }
          if(culori1 == 3)
          {
             setlinestyle(0,0,3);
             setfillstyle(SOLID_FILL,RED);
             circle(w,r,10);
             floodfill(w,r,WHITE);
             player2 = 4;
          }
          if(culori1 == 4)
          {
             setlinestyle(0,0,3);
             setfillstyle(SOLID_FILL,GREEN);
             circle(w,r,10);
             floodfill(w,r,WHITE);
             player2 == 2;
          }
      }
      if(cp == 1)
      {
          if(pvp == 1)
          {
             if(culori2 == 0)
             {
                 setlinestyle(0,0,3);
                 setfillstyle(SOLID_FILL,BLUE);
                 circle(w,r,10);
                 floodfill(w,r,WHITE);
             }
             if(culori2 == 1)
             {
                setlinestyle(0,0,3);
                setfillstyle(SOLID_FILL,BLUE);
                circle(w,r,10);
                floodfill(w,r,WHITE);
             }
             if(culori2 == 2)
             {
                setlinestyle(0,0,3);
                setfillstyle(SOLID_FILL,YELLOW);
                circle(w,r,10);
                floodfill(w,r,WHITE);
             }
             if(culori2 == 3)
             {
                setlinestyle(0,0,3);
                setfillstyle(SOLID_FILL,RED);
                circle(w,r,10);
                floodfill(w,r,WHITE);
             }
             if(culori2 == 4)
             {
                setlinestyle(0,0,3);
                setfillstyle(SOLID_FILL,GREEN);
                circle(w,r,10);
                floodfill(w,r,WHITE);
             }
           }
           else
            if(pvp == 0)
            {
                setlinestyle(0,0,3);
                setfillstyle(SOLID_FILL, player2);
                circle(w,r,10);
                floodfill(w,r,WHITE);
            }
         }

      a=(w-112)/36;
      b=(r-17)/36;
      if(cp == 0)
         cp = 1;
       else cp = 0;
   }


  }while(!choice);

}
void tab6(int &a,int &b)
{
 int i,j,w,r;
 int choice=0;

 do{

        if(ismouseclick(WM_LBUTTONDOWN))
   {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

         for(i=287; i<=502 && choice==0; i+=36)
              for(j=225; j<=440 ; j+=36)
        if(x>=i && x <= 502 && y>=j && y <= 440 )
        {
             w=x-x%36 + 17;
             r=y-y%36+25;
            choice = 1;
        }
   }
  if(choice==1)
  {
      if(cp == 0)
      {
          if(culori1 == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 14;
          }
          if(culori1 == 1)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 1;
          }
          if(culori1 == 2)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 14;
          }
          if(culori1 == 3)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,RED);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 4;
          }
          if(culori1 == 4)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,GREEN);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 == 2;
          }
      }
      if(cp == 1)
      {
          if(pvp == 1)
          {
          if(culori2 == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 1)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 2)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 3)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,RED);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 4)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,GREEN);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          }
          else if(pvp == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL, player2);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
      }

      a=(w-303)/36;
      b=(r-205)/36;

      if(cp == 0)
        cp = 1;
      else cp = 0;
      // choice=0;
   }

}while(!choice);
//closegraph();
}
void tab8(int &a,int &b)
{
 int i,j,w,r;
 int choice=0;

do{

        if(ismouseclick(WM_LBUTTONDOWN))
   {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();
         for(i=253; i<=253 + 36*8 && choice==0; i+=36)
              for(j=181; j<=181 + 36*8; j+=36)
        if(x>=i && x <=253 + 36*8 && y>=j && y <= 181 + 36*8&&CorrectMove(A,(x-x%36+18-270)/36,(y-y%36+18-198)/36,8)==1)
        {
             w=x-x%36 + 18;
             r=y-y%36 + 18;

            choice = 1;
        }
   }
    if(choice==1)
  {
      if(cp == 0)
      {
          if(culori1 == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 14;
          }
          if(culori1 == 1)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 1;
          }
          if(culori1 == 2)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 14;
          }
          if(culori1 == 3)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,RED);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 = 4;
          }
          if(culori1 == 4)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,GREEN);
      circle(w,r,10);
      floodfill(w,r,WHITE);

      player2 == 2;
          }
      }
      if(cp == 1)
      {
          if(pvp == 1)
          {
          if(culori2 == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 1)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,BLUE);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 2)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 3)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,RED);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          if(culori2 == 4)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL,GREEN);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
          }
          else if(pvp == 0)
          {
      setlinestyle(0,0,3);
      setfillstyle(SOLID_FILL, player2);
      circle(w,r,10);
      floodfill(w,r,WHITE);
          }
      }

      a=(w-270)/36;
      b=(r-198)/36;

      if(cp == 0)
        cp = 1;
      else cp = 0;
      // choice=0;
   }

}while(!choice);

}
void pagina_start()
{

    initwindow(800, 600, "TUTORIAL");

    setbkcolor(WHITE);
    cleardevice();
    readimagefile ("Meniu1.jpg", 0,0,800,600);

    meniu1:

    if(limba == 1 || limba == 0)
    readimagefile ("Meniu1.jpg", 0,0,800,600);

    else if(limba == 2)
    readimagefile ("Meniu1Ro.jpg", 0,0,800,600);

    int choice = 0;
    int setari = 0;
    int alegere = 0;
    int muzica = 0;

    do
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

        if(x >= 327 && x <= 486 && y >= 368 && y < 416 )
        {
            choice = 1;
        }
        if(x >= 243 && x <= 573 && y >= 425 && y < 472 )
        {
            choice = 2;
        }
        if(x >= 331 && x <= 448 && y >= 484 && y < 537)
            choice = 3;
        if(x >= 313.30 && x <= 519.53 && y >= 536.71 && y <= 602.23)
            choice = 4;

        if(x >= 725 && x <= 782 && y >= 533 && y < 590 )
            choice = 5;

        if(x >= 667 && x <= 714 && y >= 533 && y < 590 )
            choice = 6;

        if(choice == 5)                            // buton oprire muzica
        {
            mciSendString("Close audio_fe4d3bcac9.mp3", NULL, 0, NULL);
            goto meniu1;
        }
        if(choice == 6)                             // buton pornire muzica
        {
            mciSendString("play audio_fe4d3bcac9.mp3 repeat", NULL, 0, NULL);
            goto meniu1;
        }

    }


}while(!choice);


if( choice ==4 )            //buton exit
{
    cleardevice();
    closegraph();

}

if( choice == 2 )                   //setari
{

    cleardevice();

    if(limba == 1 || limba == 0)
    readimagefile("Meniu2.jpg", 0, 0, 800, 600);

    else if( limba == 2 )
    readimagefile("Meniu2Ro.jpg", 0, 0, 800, 600);

     do
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

        if(x >= 328 && x <= 446 && y >=349 && y < 418 )
        {
            setari = 1;
        }

        if(x >= 0 && x <= 73 && y >= 538 && y < 599 )

            setari = 2;
        if(x >= 262 && x <= 535 && y >=424 && y < 469 )
        {
            setari = 3;
        }

        if( x >= 218 && x <= 590 && y >= 475 && y <= 541)

            setari = 4;


        if (setari == 2)          //inapoi la meniu
{
    cleardevice();
    goto meniu1;
}


    }
}while(!setari);
if( setari == 3 )               //setari culori
{
    cleardevice();
    if( limba == 2 )
    readimagefile("culoriRo.jpg", 0, 0, 800, 600);
    else if( limba == 1 || limba == 0 )
    readimagefile("culori.jpg", 0, 0, 800, 600);

    int colors = 0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int x = mousex();
            int y = mousey();

            if(x >= 171 && x <= 227 && y >= 219 && y <= 261)
                colors = 1;
            if(x >= 171 && x <= 227 && y >= 303 && y <= 345)
                colors = 2;
            if(x >= 171 && x <= 227 && y >= 382 && y <= 424)
                colors = 3;
            if(x >= 171 && x <= 227 && y >= 461 && y <= 501)
                colors = 4;
            if(x >=  578 && x <= 634 && y >= 219 && y <= 261)
                colors = 5;
            if(x >= 578 && x <= 634 && y >= 303 && y <= 345)
                colors = 6;
            if(x >= 578 && x <= 634 && y >= 382 && y <= 424)
                colors = 7;
            if(x >= 578 && x <= 634 && y >= 461 && y <= 501)
                colors = 8;
            if(x >= 0 && x <= 73 && y >= 538 && y < 599 )
                colors = 9;
            if(colors == 9)
            {
                cleardevice();
                goto meniu1;
            }
            if(colors == 1)
            {
                culori1 = 1;
                colors = 0;
            }
            if(colors == 2)
            {
                culori1 = 2;
                colors = 0;
            }
            if(colors == 3)
            {
                culori1 = 3;
                colors = 0;
            }
            if(colors == 4)
            {
                culori1 = 4;
                colors = 0;
            }
            if(colors == 5)
            {
                culori2 = 1;
                colors = 0;
            }
            if(colors == 6)
            {
                culori2 = 2;
                colors = 0;
            }
            if(colors == 7)
            {
                culori2 = 3;
                colors = 0;
            }
            if(colors == 8)
            {
                culori2 = 4;
                colors = 0;
            }
        }
    }while(!colors);
}

if( setari == 4 )                  //setari limba
{
    cleardevice();

    if(limba == 0)
    readimagefile("Limbi.jpg", 0, 0, 800, 600);

    else if(limba == 2)
    readimagefile("LimbiRo.jpg", 0, 0, 800, 600);

    int language = 0;

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);

            int x = mousex();
            int y = mousey();

            if( x >= 250 && x <= 550 && y >= 489 && y <= 555 )
                language = 1;

            if( x >= 250 && x <= 557 && y >= 398 && y <= 463 )
                language = 2;

            if(x >= 0 && x <= 73 && y >= 538 && y < 599 )
                language = 3;

            if(language == 3)
            {
                cleardevice();
                goto meniu1;
            }

            if(language == 1)
            {
                limba = 1;
                language = 0;


            }
            if(language == 2)
            {
                limba = 2;
                language = 0;

            }
            if(limba == 1 || limba == 0)
            {
    readimagefile("Limbi.jpg", 0, 0, 800, 600);
            limba = 0;
            }

    else if(limba == 2)

    readimagefile("LimbiRo.jpg", 0, 0, 800, 600);



        }
    }while(!language);

}
if( setari == 1 )               //setari dimensiune matrice
        {
    cleardevice();

    if(limba == 1 || limba == 0)
    readimagefile("Meniu3.jpg", 0, 0, 800, 600);

    else if( limba == 2 )
    readimagefile("Meniu3Ro.jpg", 0, 0, 800, 600);

    int coordonata = 0;

do
    {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

        if(x >= 0 && x <= 73 && y >= 538 && y < 599 )

            coordonata = 4;

        if(x >= 324 && x <= 446 && y >= 366 && y <= 415 )

            coordonata = 1;

        if(x >= 323 && x <= 446 && y >= 421 && y <= 467 )

            coordonata = 2;

        if(x >= 299 && x <= 473 && y >= 476 && y <= 525 )

            coordonata = 3;

if (coordonata == 4)
{
    cleardevice();
    goto meniu1;
}
if ( coordonata == 1)
{
    matrice = 6;
    coordonata = 0;
}
if ( coordonata == 2)
{
    matrice = 8;
    coordonata = 0;
}
if( coordonata == 3)
{
    matrice = 16;
    coordonata = 0;
}
    }
}while(!coordonata);


    }
}
if (choice == 3)     //INFO
{
    cleardevice();
    int info = 0;
    if(limba == 1 || limba == 0)
        readimagefile("info.jpg", 0, 0, 800, 600);
    else if(limba == 2)
        readimagefile("infoRo.jpg", 0, 0, 800, 600);

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);

            int x = mousex();
            int y = mousey();

            if(x >= 0 && x <= 73 && y >= 538 && y < 599 )
                info = 1;

        }
    }while(!info);

    if(info == 1)
    {
        cleardevice();
        goto meniu1;
    }


}
if(choice==1)                //PLAY
        {
    initwindow(800, 600, "PROIECT");

    if(limba == 1 || limba == 0)
    readimagefile("PVP.jpg", 0, 0, 800, 600);

    else if( limba == 2 )
    readimagefile("PVPRo.jpg", 0, 0, 800, 600);


    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);

        int x = mousex();
        int y = mousey();

        if( x >= 58 && x <= 736 && y >= 375 && y <= 426 )
            alegere = 1;
        if( x >= 18 && x <= 791 && y >= 439 && y <= 488 )
            alegere = 2;
        if(x >= 0 && x <= 73 && y >= 538 && y < 599 )
            alegere = 3;

        }
    }while(!alegere);
    if ( alegere == 1)                  //p vs p
    {
        p2 = 1;
        cleardevice();

        if(matrice == 8 || matrice == 0)
        readimagefile("tabel8x8.jpg", 0, 0, 800, 600);

        if(matrice == 6 )
        readimagefile("tabel6x6.jpg", 0, 0, 800, 600);

        if(matrice == 16 )
        readimagefile("tabel16x16.jpg", 0, 0, 800, 600);

        pvp = 1;

    }
   if ( alegere == 2)                   //p vs calculator
    {
        p2 = 0;

        cleardevice();
        mciSendString("Close muzicafundal.mp3 repeat", NULL, 0, NULL);
        if(matrice == 8 || matrice == 0)
        readimagefile("tabel8x8.jpg", 0, 0, 800, 600);

        if(matrice == 6 )
        readimagefile("tabel6x6.jpg", 0, 0, 800, 600);

        if(matrice == 16 )
        readimagefile("tabel16x16.jpg", 0, 0, 800, 600);

        pvp = 0;
    }
    if(alegere == 3)          //inapoi
    {
        cleardevice();
        goto meniu1;
    }
        }
    }
int main()
{
 int gdriver = DETECT,gmode;
 initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

 initwindow(800,600, "Proiect");
 play:

 pagina_start();

  int a,b,n=8,c=5,i,j, restart = 0;

  sizeM(n);

  for( i = 0; i < n; i++)          //pentru a putea da restart
    for( j = 0; j < n; j++)
        A[i][j] = 0;

  q++;

  while(P1_win(A,c,n)==0&&P2_win(A,c,n)==0)
  {
        if(q%2==1)             //pentru a putea incepe fiecare jucator pe rand
        {
           if(p2!=0)           //p vs p si incepe primul jucator
           {
              a=0;b=0;
              if(n==8)
                 tab8(a,b);
              if(n==16)
                 tab16(a,b);
              if(n==6)
                 tab6(a,b);
              A[a][b]=1;
              if(P1_win(A,c,n)==0)
              {
                 if(n==8)
                    tab8(a,b);
                 if(n==16)
                    tab16(a,b);
                 if(n==6)
                    tab6(a,b);
                  A[a][b]=2;
              }
           }
           else
           {                               //p vs calculator si incepe calculatorul
             bot(A,c,n,a,b);
             A[a][b]=1;
             setfillstyle(SOLID_FILL,6);
             if(n==8)
             {
                circle(a*36+271,b*36+199,10);
                floodfill(a*36+271,b*36+199,WHITE);
             }
             if(n==16)
             {
                circle(a*36+117,b*36+32,10);
                floodfill(a*36+117,b*36+32,WHITE);
             }
             if(n==6)
             {
                circle(a*36+304,b*36+206,10);
                floodfill(a*36+304,b*36+206,WHITE);
             }
              a=0; b=0;
             if(P1_win(A,c,n)==0)
             {
                if(n==8)
                   tab8(a,b);
                if(n==16)
                   tab16(a,b);
                if(n==6)
                   tab6(a,b);
                A[a][b]=2;
              }
            }
        }
      else
       {
        if(p2!=0)
        {                 //p vs p, incepe al doilea jucator
           if(n==8)
              tab8(a,b);
           if(n==16)
              tab16(a,b);
           if(n==6)
              tab6(a,b);
           A[a][b]=2;
           a=0;b=0;
           if(P2_win(A,c,n)==0)
           {
              if(n==8)
                 tab8(a,b);
              if(n==16)
                 tab16(a,b);
              if(n==6)
                 tab6(a,b);
              A[a][b]=1;
           }
        }
       else
        {                    // p vs calculator, incepe calculatorul
          a=0; b=0;
          if(n==8)
             tab8(a,b);
          if(n==16)
             tab16(a,b);
          if(n==6)
             tab6(a,b);
          A[a][b]=2;
          if(P2_win(A,c,n)==0)
          {
             bot(A,c,n,a,b);
             A[a][b]=1;
             setfillstyle(SOLID_FILL,6);
             if(n==8)
             {
                circle(a*36+271,b*36+199,10);
                floodfill(a*36+271,b*36+199,WHITE);
             }
             if(n==16)
             {
                circle(a*36+117,b*36+32,10);
                floodfill(a*36+117,b*36+32,WHITE);
             }
             if(n==6)
             {
                circle(a*36+304,b*36+206,10);
                floodfill(a*36+304,b*36+206,WHITE);
             }
          }
        }
       }
  }
  if(P1_win(A,c,n)==1)           //mesaj castigator p vs c
  {
     delay(1000);
     cleardevice();
     if(p2 == 0)
     {
        if(limba == 1 || limba == 0)
           readimagefile("computer.jpg", 0, 0, 800, 600);
        else
          if(limba == 2)
             readimagefile("computerRo.jpg", 0, 0, 800, 600);
     }
     else
      if(p2 == 1)
      {
         if( limba == 1 || limba == 0 )
            readimagefile("player2.jpg", 0, 0, 800, 600);
         else
          if( limba == 2 )
             readimagefile("player2Ro.jpg", 0, 0, 800, 600);
      }
  do
  {
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

        if(x >= 265 && x <= 555 && y >= 400 && y <= 460 )

            restart = 1;

        if(x >= 308 && x <= 515 && y >= 468 && y <= 534 )

            restart = 2;

    }
  }while(!restart);

  if (restart == 1)             //restart
  {
    cleardevice();
    goto play;
    restart = 0;
  }
  if( restart == 2 )           //exit
  {
    cleardevice();
    closegraph();
    return 0;
  }
 }
  else
  {
        delay(1000);
        cleardevice();

        if(limba == 1 || limba == 0)
        readimagefile("player1.jpg", 0, 0, 800, 600);
        else if( limba == 2 )
        readimagefile("player1Ro.jpg", 0, 0, 800, 600);

    do
    {
     if(ismouseclick(WM_LBUTTONDOWN))
     {
        clearmouseclick(WM_LBUTTONDOWN);
        int x = mousex();
        int y = mousey();

        if(x >= 265 && x <= 555 && y >= 400 && y <= 460 )

            restart = 1;

        if(x >= 308 && x <= 515 && y >= 468 && y <= 534 )

            restart = 2;

     }
    }while(!restart);
  if (restart == 1)
  {
    cleardevice();
    goto play;
    restart = 0;
  }
  if (restart == 2)
  {
    cleardevice();
    closegraph();
    return 0;
  }
 }
getch();
closegraph();

return 0;
}