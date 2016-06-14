#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * create a data structure of linked character list	
 */
struct char_list { 
  char num;
  struct char_list* next;
};
typedef struct char_list list_t; 
typedef list_t* list_ptr; 
typedef list_ptr* bigint_t; 

/**
 * allocate memory to a biginteger initially 
 * returns a null value
 */
bigint_t allocateBigInt(void);

/**
 * print a big integer using recursion
 */
void printBigInt(list_ptr tmp);

/**
 * Create a new bigint
 * the new integer should store the given int value
 * assume that given value is within the range of int
 */
bigint_t new_bigint(int);

/**
 * free all the memory used by the given bigint
 */
void free_bigint(bigint_t); 

/**
 * add bigints a and b and store the results in sum
 * Assums: all 3 bigints are allocated before calling
 * return 0 if addition was successful 
 */
int add(bigint_t sum, bigint_t a, bigint_t b); 

/** 
 * Display the value of the given bigint
 */
void show_bigint(bigint_t); 




