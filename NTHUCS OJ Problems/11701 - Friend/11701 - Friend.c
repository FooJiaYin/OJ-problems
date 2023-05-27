#include<stdio.h>
#include<stdbool.h>
#define MAXN 2005

bool f[MAXN][MAXN];
int n;

void init(){
      int i=0,j;
      for(;i<n;++i){
            for(j=0;j<n;++j){
                  f[i][j]=false;
            }
            f[i][i]=true;
      }
}

bool is_friend(int a,int b){
      //if f[a][b]=true, person a and person b are friends.
      return f[a][b];
}

int ga[MAXN],gb[MAXN];
int len_ga,len_gb;

void get_ga(int a){
      //Array ga saves all the friends of person a.
      //For example, if all the friends of person a are 1, 4, 5 and 10,
      //ga[]={1,4,5,10}, len_ga=4.
      //Please think how to get Array ga according to 2D Array f.
      int i, j;
      for(i=0, j=0; i<n; i++)
        if(f[a][i]) ga[j++] = i;
      len_ga = j;
}

void get_gb(int b){
      //Array gb saves all the friends of person b.
      //Similar to get_ga().
      int i, j;
      for(i=0, j=0; i<n; i++)
        if(f[b][i]) gb[j++] = i;
      len_gb = j;
}

void set_friend_ab(){
      //Now you have Array ga and gb.
      //Because person a and b will be friends,
      //how to use Array ga and gb for updating 2D Array f?
      int i, j;
      for(i=0; i<len_ga; i++)
        for(j=0; j<len_gb; j++)
        {
            f[ga[i]][gb[j]] = true;
            f[gb[j]][ga[i]] = true;
        }
}

void merge_friend(int a,int b){
      if(is_friend(a,b)) return;
      get_ga(a);
      get_gb(b);
      set_friend_ab();
}

int main(){
      int t,q;
      scanf("%d",&t);
      while(t--){
            scanf("%d%d",&n,&q);
            init();
            while(q--){
                  int op,a,b;
                  scanf("%d%d%d",&op,&a,&b);
                  if(op==1) puts(is_friend(a,b) ? "they are friends!" : "they are not friends!");
                  else merge_friend(a,b);
            }
      }
      return 0;
}
