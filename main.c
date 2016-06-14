#include <bigint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
    int i, f;

    for (f = 1; f < 101; f++) { 
        bigint_t a = new_bigint(0);      //create new bigintegers 0 and 1
        bigint_t b = new_bigint(1);
        bigint_t fib = new_bigint(1);

        for (i = 1; i < f; i++) { 
            fib = allocateBigInt();     //need to allocate memory for a new biginteger otherwise string will be concatenate to previous char
            if(add(fib, a, b)) break;
            a = b;                      //equalling address of b to a
            b = fib;                    //equalling address of fib to b
        }
        printf("%3d the Fib is ", f);
        show_bigint(fib);               //displaying biginteger
        free_bigint(a);                 //freeing bigintegers
        free_bigint(b);
        free_bigint(fib);
    }   

    return 0;
}
  
  
