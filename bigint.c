#include <bigint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bigint_t allocateBigInt(void) {					/*allocate memory to a biginteger by allocating memory to a char list*/
	bigint_t bigInt = malloc(sizeof(list_ptr));
	*bigInt = NULL;

	return bigInt;
}
bigint_t new_bigint(int a) {					/*create biginteger using integer as the argument*/
	char str[20] = {};
	sprintf(str, "%d", a); // convert integer to a char array (string)

	bigint_t bigInt = allocateBigInt(); // allocate memory to a biginteger

	char c = '0'; int flag = 0, i = 0;
	while (1) {
		list_ptr tmp = malloc(sizeof(list_t));
		if (!tmp) return NULL;

		c = str[i];
		if (flag == 0 && c == '-') flag = 1;
		if (c == '\0') break;

		if (isdigit(c)) { // insert converted chars to linked LIFO char list
			tmp -> num = c;
			tmp -> next = *bigInt;
			*bigInt = tmp;
		}
		i++;

		return bigInt;
	}
	if (flag == 1) { // insert minus sign to list as last character
		list_ptr tmpf = malloc(sizeof(list_t));
		if (!tmpf) return NULL;
		tmpf -> num = '-';
		tmpf -> next = *bigInt;
		*bigInt = tmpf;
	}

	return bigInt;
}
int add(bigint_t s, bigint_t a, bigint_t b) {	/*add two bigintegers and give the summation to a biginteger which getting as a argument*/
	list_ptr tmp1 = *a;
	list_ptr tmp2 = *b;

	int add, flag = 0, carry = 0, f1 = 0, f2 = 0;
	char c1, c2;
	while (1) {
		if (f1 == 1 && f2 == 1 && carry == 0) break;

		if ((f1 == 1 && carry == 1) || (f1 == 1 && carry == 0)) c1 = '\0'; else c1 = tmp1 -> num; // check whether all nodes are investigated
		if ((f2 == 1 && carry == 1) || (f2 == 1 && carry == 0)) c2 = '\0'; else c2 = tmp2 -> num;
		
		if ((c1 != '-' && c2 != '-') || flag == 1) {
			char s1[2] = {c1, '\0'}, s2[2] = "";
			char r1[2] = {c2, '\0'}, r2[2] = "";
	    	strcpy(s2, s1); // convert chars to strings
	    	strcpy(r2, r1);
	    	add = atoi(s2) + atoi(r2); // convert strings to integers and add

	    	list_ptr tmpSum = malloc(sizeof(list_t));
	    	if (!tmpSum) return 1;
	    	list_ptr curr = *s;

			if (add + carry > 9) { // check addition is lager than 9 or not
				if (carry == 1) add += 1;
				int rem = add % 10;
				tmpSum -> num = rem + '0'; // convert integers to chars and inserting to each node
				tmpSum -> next = NULL;
				if (!curr) *s = tmpSum;
				else {
					while (curr -> next) curr = curr -> next;
					curr -> next = tmpSum;
				}
				carry = 1;
			}
			else {
				if (carry == 1) add += 1;
				tmpSum -> num = add + '0';
				tmpSum -> next = NULL;
				if (!curr) *s = tmpSum;
				else {
					while (curr -> next) curr = curr -> next;
					curr -> next = tmpSum;
				}
				carry = 0;
			}
			if (tmp1 -> next) tmp1 = tmp1 -> next; else f1 = 1;
			if (tmp2 -> next) tmp2 = tmp2 -> next; else f2 = 1;
			flag = 1;
		}
	}

	return 0; // if all correct
}
void free_bigint(bigint_t bigInt) {				/*delete the whole biginteger*/
	if (*bigInt) {
		free_bigint(&((*bigInt) -> next));
		*bigInt = NULL;
		free(*bigInt); // free allocated memory
	}
}
void printBigInt(list_ptr tmp) {				/*printing a biginteger*/
	if (tmp) {
		printBigInt(tmp -> next);
		printf("%c", tmp -> num);		
	}
}
void show_bigint(bigint_t v) {					/*calling printbigInt function and add a new line to biginteger*/
	printBigInt(*v);
	printf("\n");
}