#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
char arr[20];
int max_cal = INT_MIN;
void sol(int n, int idx, int cal){  
    int yes, no;
    yes = arr[idx]-'0';
    no = cal;
    if (idx > n - 1)
    {
        max_cal = max(max_cal, cal);
        //printf("%d\n", max_cal);
        return ;
    }
    
    //괄호 O
    if (idx + 2 < n)
    {
        if(arr[idx+1] == '+'){
            yes += (arr[idx+2]-'0');
        }
        else if(arr[idx+1] == '-'){
            yes -= (arr[idx+2]-'0');
        }
        else if(arr[idx+1] == '*'){
            yes *= (arr[idx+2]-'0');
        }
        
        if(idx!=0){
            if(arr[idx-1] == '+'){
                cal += yes;
            }
            else if(arr[idx-1] == '-'){
                cal -= yes;
            }
            else if(arr[idx-1] == '*'){
                cal *= yes;
            }
        }
        else{
            cal = yes;
        }
        sol(n, idx + 4, cal);
    }
    
    if(idx!=0){
        if(arr[idx-1] == '+'){
            no += (arr[idx]-'0');
        }
        else if(arr[idx-1] == '-'){
            no -= (arr[idx]-'0');
        }
        else if(arr[idx-1] == '*'){
            no *= (arr[idx]-'0');
        }
    }
    else
        no = (arr[idx]-'0');
    sol(n, idx + 2, no);
    
}

int main(void){
    int n;

    scanf("%d", &n);
    scanf("%s", arr);
    
    
    sol(n, 0, 0);
    
    printf("%d\n", max_cal);
}