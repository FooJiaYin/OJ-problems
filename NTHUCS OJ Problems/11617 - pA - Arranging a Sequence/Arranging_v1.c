# include <stdio.h>

int seq[200000] = {0};

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    int i;
    for(i=1; i<=n; i++){
        seq[i] = i;
    }
    int input;
    while(m--){
        scanf("%d",&input);
        int pos=0;
        for(i=1; i<=n;i++){
            if(seq[i]==input){
                pos = i;
            }
        }
        seq[0] = seq[pos];
        for(i=pos-1; i>=0;i--){
            seq[i+1] = seq[i];
        }
    }
    for(i=1; i<=n;i++){
        printf("%d\n",seq[i]);
    }
    
    
    return 0;
}
