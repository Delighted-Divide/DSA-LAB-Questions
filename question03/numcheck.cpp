#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void armstrong(int num);
void palindrome(int num);
void perfect(int num);


int main(){
    int *choice=(int*)malloc(sizeof(int));
    int *number=(int*)malloc(sizeof(int));
    int *loop=(int*)malloc(sizeof(int));
    *loop=5;
    printf("1: Armstrong\n2: palindrome\n3: perfect\n4: new number\n5: exit\n");
    printf("Enter 5 to exit");
    while (*loop==5){
        printf("Enter your choice: ");
        scanf("%d",&*choice);
        if(*choice==1){
            armstrong(*number);
        }
        else if(*choice==2){
            palindrome(*number);
        }
        else if(*choice==3){
            perfect(*number);
        }
        else if(*choice==4){
            printf("Enter a new number: ");
            scanf("%d",&*number);
        }
        else if(*choice==5){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid input!");
        }

    }
    free(choice);
    free(number);
    free(loop);
    return 1;    


}

//function for checking armstrong number
void armstrong(int num){
    int *num1=(int*)malloc(sizeof(int));
    *num1=num;
    int *size=(int*)malloc(sizeof(int));
    *size=0;
    int *temp=(int*)malloc(sizeof(int));
    *temp=num;
    int *sum=(int*)malloc(sizeof(int));
    *sum=0;
    while(*temp>0){
        (*size)++;
        (*temp)/=10;
    }
    while(*num1>0){
        *sum+=pow(((*num1)%10),(*size));
        (*num1)/=10;
    }
    if(*sum==num){
        printf("%d is an armstrong number",*sum);
    }
    else{
        printf("%d is not an armstrong number",num);
    }
    free(size);
    free(temp);
    free(sum);
    free(num1);
}

//function for checking palindrome number
void palindrome(int num){
    int *temp=(int*)malloc(sizeof(int));
    *temp=num;
    int *sum=(int*)malloc(sizeof(int));
    *sum=0;
    while(*temp>0){
        *sum=(*sum)*10+*temp%10;
        *temp/=10;
    }
    if(*sum==num){
        printf("%d is a palindrome number!",*sum);
    }
    else{
        printf("%d is not a palindrome number",num);
    }
    free(temp);
    free(sum);


}

//function for checking perfect number
void perfect(int num){
    int *num1=(int*)malloc(sizeof(int));
    *num1=num;
    int *i=(int*)malloc(sizeof(int));
    *i=1;
    int *sum=(int*)malloc(sizeof(int));
    *sum=0;
    while(*i<(*num1)){
        if(*num1%(*i)==0){
            *sum+=*i;
        }
        (*i)++;
    }
    if(*sum==*num1){
        printf("%d is a perfect number!",*num1);
    }
    else{
        printf("%d is not a perfect number",*num1);
    }
    free(num1);
    free(i);
    free(sum);
}
