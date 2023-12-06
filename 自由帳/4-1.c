#include <stdio.h>

int main(){
    /*3辺の長さを受け取る変数*/
    int a,b,c;
    /*入力*/
    printf("3辺の長さを整数で入力してください\n");
    printf("1辺目: ");
    scanf("%d",&a);
    printf("2辺目: ");
    scanf("%d",&b);
    printf("3辺目: ");
    scanf("%d",&c);
    /*3辺の長さを大きい順にソートしたものを保存する変数*/
    int x,y,z;
    if(a>b){
        if(c>a){
            x=c;y=a;z=b;
        }
        else if(b>c){
            x=a;y=b;z=c;
        }
        else{
            x=a;y=c;z=b;
        }
    }
    else{
        if(c>b){
            x=c;y=b;z=a;
        }
        else if(a>c){
            x=b;y=a;z=c;
        }
        else{
            x=b;y=c;z=a;
        }
    }
    /*判定*/
    /*三角形をつくるかどうか*/
    if(x>=y+z){
        printf("3辺 %d, %d, %d は三角形をつくりません\n",x,y,z);
    }
    else{
        /*鈍角、直角、鋭角三角形の判定*/
        if(x*x>y*y+z*z){
            printf("3辺 %d, %d, %d は鈍角三角形です\n",x,y,z);
        }
        else if(x*x==y*y+z*z){
            printf("3辺 %d, %d, %d は直角三角形です\n",x,y,z);
        }
        else{
            printf("3辺 %d, %d, %d は鋭角三角形です\n",x,y,z);
        }
        /*二等辺三角形、正三角形の判定*/
        if(x==z){
            printf("さらに正三角形です\n");
        }
        else if(x==y||y==z){
            printf("さらに二等辺三角形です\n");
        }
    }
    return 0;
}