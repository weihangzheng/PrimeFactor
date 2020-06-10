#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    int num = 0;
	printf("Enter a positive integer >= 2 to prime factorize: ");
    scanf("%d", &num);
    
    //count the number of prime factors
    int count = 0;
    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            bool flag = true;
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }
    }
    //create array to store potential prime factors
    int *array = malloc(2*count*sizeof(int));
    for(int i = 0; i < 2*count; i++)
        array[i] = 0;
    
    int index1 = 0;
    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            bool flag = true;
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                array[index1++] = i;
        }
    }
    
    //prime factorize
    int index2 = 0;
    while(num > 1){
        if(num % array[index2] == 0){
            num /= array[index2];
            array[index2 + count]++;
        }
        else
            index2++;
    }
    
    //print prime factorization
    for(int i = 0; i < count-1; i++)
        printf("%d^%d x ", array[i], array[i + count]);
    printf("%d^%d\n\n", array[count-1], array[2*count - 1]);
    free(array);
    main(argc, argv);
}
