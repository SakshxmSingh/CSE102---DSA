#include <stdio.h> 
// unsigned int Fact(int n);
// long long int ThreeXPlusOne(long long int n);

// int main(void){
//     // float z = 10/5;
//     // printf("%f",z);
//     long long int n;
//     printf("Enter number: ");
//     scanf("%lld",&n);
//     ThreeXPlusOne(n);
//     printf("\n");

//     return 0;

// }

// unsigned int Fact(int n){
//     if (n<=1){
//         return 1;
//     }
//     else{
//     return n*Fact(n-1);
//     }
// }

// long long int ThreeXPlusOne(long long int n){
//     printf("%lld ",n);
//     if(n==1){
//         return 0;
//     }
//     else if(n%2==0){
//         return ThreeXPlusOne(n/2);
//     }
//     else if(n%2!=0){
//         return ThreeXPlusOne(3*n +1);
//     }
//     else{
//         return 0;
//     }
// }

struct Record{
    int A;
    int B;
    int nums[20];
    int nummss[20];
    char tree[4];
    char trees[5];
    float yo;
    float yoyo;
    float yooo[20];
} example1;

int main(){
    printf("%lu/n",sizeof(example1));
    return 0;
}