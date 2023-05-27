#include <stdio.h>

int f_mv[200001] = {0};
int m_inst[100000] = {0};

int main(){
    int n, m, tmp;
    int e;
    int i=-1;
    scanf("%d %d",&n, &m);
    tmp = m;
    while(tmp--){
        scanf("%d",&e);
        m_inst[tmp] = e;
        f_mv[e] = 1;
    }
    for(i=0;i<m;i++){
        if(f_mv[m_inst[i]] == 1){
            printf("%d\n",m_inst[i]);
            f_mv[m_inst[i]] = -1;
        }else{}
    }
    for(i=1; i<=n;i++){
        if(f_mv[i] == 0){
            printf("%d\n",i);
        }else{}
    }
    
    
    return 0;
}
