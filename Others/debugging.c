#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 15

//int main () {
//	int a[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//	int b[SIZE] = {0, 8, 7, 6, 105, 16, 0, 0, 0, 0, 5, 0, 0, 2, 12};
//	int c[SIZE];
//	int i, x,ctr=0,j,sqr,position;
//	
//	for (i = 0; i <= SIZE-1;i++) {
//		printf("[%d]\n",i);
//		sqr = a[i] * a[i];
//		printf("Square root [%d]: %d\n",i,sqr);
//		for (j = 0; j <= SIZE - 1 && sqr != b[j]; j++) {}
//		printf("found at index j[%d]\n",j);
//		if (j <= SIZE - 1 && sqr == b[j]) {
//			position = j;
//			c[ctr++] = b[j];
//			printf("position [%d]\n\n", position);
//			for (x = position ; x < SIZE - 1; x++) {
//				b[x] = b[x+1];
//			}
//		}
//	
//	}
////	printf("%d",x);
////	for (i = 0; i < SIZE - 1; i++) {
////		printf("C[%d] = %d\n",i, c[i]);
////	}
//	
//	if (ctr == SIZE) {
//		printf("true");
//	} else {
//		printf("false");
//	}
////	
//
////	char *digits = "283910";
////	char str[6];
////	int i, j = 0;
////	int length = strlen(digits);
////	
////	for (i = length - 5; i < length; i++, j++) {
//////		printf("[%d] = %c\n", i, digits[i]);
////		str[j] = digits[i];
////	}
////	
////	printf("STRING: %s",str);
////	printf("STRING: %d",i = 0);
//
//	
//	return 0;
//}






/** PLAYING WITH DIGITS **/



//int reverseNumber(int num);
//
//int main () {
//	int n = 46288;
//	int p = 3;
//	int rev, remainder, ret;
//	int sqr, sum = 0;
//	
//	rev = reverseNumber(n);
//
//	while (rev != 0) {
//		remainder = rev % 10;
//		sqr = pow(remainder,p);
//		sum += sqr;
//		rev /= 10;
////		printf("remainder : %d\n",remainder);
////		printf("sqr : [%d] * [%d]\n",remainder,p);
////		printf("sum: %d\n",sum);
////		printf("rev: %d\n\n",rev);
//		p++;
//	}
////	int numdigit = floor(log10(n))+1; //count length of a number
////	printf("sample: %d\n", numdigit);
//	printf("sum: %d\n",sum);
////	printf("res: %d", sum / n);
//	ret = sum / n;
//	if (ret == 0 || sum != n * ret) {
//		printf("-1");
//	} else {
//		printf("ret %d",ret);
//	}
//	
//	return 0;
//}
//
//int reverseNumber(int num) {
//	int remainder, rev = 0;
//	
//	while (num != 0) {
//		remainder = num % 10;
//		rev = rev * 10 + remainder;
//		num /= 10;
//	}
//	
//	return rev;
//}






/** HIGHEST SCORING WORD**/

//int main () {
//	const char *str = "what time are we climbing up the volcano";
//	char *token;
//	char *ret = malloc(sizeof(char)*100);
////	printf("hello wtf?");
//	
//	strcpy(ret, str);
////	printf("string: %d\n", (str[0] - 97) + 1);
//	int sum2,sum = 0,x = 0,temp;
//	unsigned long i,j;
////	
//	token = strtok(ret, " ");
//	printf("first token: %s", token);
//
//	for (i = 0; i <= strlen(token) - 1; i++) {
//		sum += token[i] - 96;
//	}
//	
//	temp = sum;
//	
//	while (token != NULL) {
//		sum2 = 0;
//		for (j = 0; j <= strlen(token) - 1; j++) {
//			sum2 += token[j] - 96;
//		}
//		
//		if (temp < sum2) {
//			temp = sum2;
//			ret = token;
//		}
//		token = strtok(NULL, " ");
//	}
////	while (token != NULL) {
////		sum = 0;
////		printf("[%d]\n",x++);
////		printf("string: %s\n", token);
////		for (i = 0; i <= strlen(token)-1; i++) {
////			sum += token[i] - 96;
////		}
////		temp = sum;
////		printf("sum: %d\n",temp);
////		while (token != NULL) {
////			sum2 = 0;
////			for (j = 0; j <= strlen(token) - 1; j++) {
////				sum2 += token[j] - 96;
////			}
////			
////			if (temp < sum2) {
////				temp = sum2;
////				ret = token;
////			}
////			
////			token = strtok(NULL, " ");
////		}
////		token = strtok(NULL, " ");
////	}
//	
//	printf("final temp: %d\n", temp);
//	printf("final string: %s", ret);
//	
//	return 0;
//}




/** BACKWARDS READ PRIMES **/

//typedef long long ll;
//
//struct Data {
//	ll* array;
//	int sz;
//};
//
//typedef struct Data Data;
//
//Data* backwardsPrime(ll start, ll end);
//ll reverseNum(ll num);
//
//int main () {
//	ll start = 7000;
//	ll end = 7100;
//	Data *ret;
//	ret->array = malloc(sizeof(ll)*10);
//	ret->sz = 0;
//	ll revNum;
//	ll i = 0, j, flag;
//	ll rev;
////	ret = backwardsPrime(start,end);
//
////	printf("ret: %lli\n\n", rev);
//	while(start < end) {
//		rev = reverseNum(start);
////		printf("return val: %lli\n",rev);
//		flag = 0;
//		for (j  = 2; j <= start / 2; ++j) {
//			if (start % j == 0 || rev % j == 0) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
////			ret->array[i++] = start;
//			ret->sz++;
////			printf("reverse prime number: %lli\n",rev);
////			printf("prime number: %d\n\n",start);
//		}
//		start++;
//	}
//	printf("array size: %lli", ret->sz);
////	for (i = start; i <= end; i++) {
////		revNum = reverseNum(start);
////		if (start % i != 0 && revNum % i != 0 ) {
////			printf("prime numbers: %lli\n", start);
////		}
////	}
////	for (i = 0; i <= ret->sz; i++) {
////		printf("[%d]: %lli",i, ret->array[i]);
////	}
//
//	return 0;
//}
//
////Data* backwardsPrime(ll start, ll end) {
////	Data ret, temp;
////	ll i, revNum;
////	
////	for (i = 2; i <= sqrt(end); i++, start++) {
////		revNum = reverseNum(start);
////		if (i % start == 0 && i % revNum == 0 ) {
////			printf("prime numbers: %lli", start);
////		}
////	}
////}
//
//ll reverseNum(ll num) {
//	ll remainder, rev = 0;
//	while (num != 0) {
//		remainder = num % 10;
//		rev = rev * 10 + remainder;
//		num /= 10;
//	}
//	
//	return rev;
//}






/** DUPLICATE ENCODER **/

//int main () {
////	char *newString = (char *)malloc(sizeof(char)*50);
//	int i, j, flag = 0;
//	char str[50] = "success";
//	char newstr[7];
//	int length = strlen(str);
//	
//	for (i = length - 1; i >= 0; i++) {
//		
//		for (j = 0; j <= length - 1; j++) {
//			if (str[i] == str[j]) {
//				newstr[j] = ')';
//				printf("index found: %d",j);
//			}
//		}
//	}
//	
//	for (i = 0; i < 7; i++) {
//		printf("[%d]: %c\n",i, newstr[i]);
//	}
//	
//	return 0;
//}





/* Replace With Alphabet Position **/

//int main () {
//	char *str = "The sunset sets at twelve o' clock.";
//	char newstr[50], lower, letter;
//	int i, j = 0, length = strlen(str);
////	char *wew = malloc(sizeof(char)*length);
//	char wew[length], lol[length];
////	char *l = malloc(sizeof(cha r)*length);
//
//	printf("Length: %d\n", sizeof(str));	
//	
//	for (i = 0; i <= length - 1 ; i++) {
//		lower = tolower(str[i]);
//		if (isalpha(lower) != 0) {
//			j += sprintf(&wew[j], "%d ", lower - 96);
//			printf("J: %d \n", j);
//		}
//	}
//	
//	printf("letter: %s", wew);
//	printf("string length : %d", strlen(wew));
//	return 0;
//}





/** REMOVE ANCHOR FROM URL **/

//char *removeSubstring(const char *str);
//
//
//int main () {
//	const char str[] = "www.codewars.comabout?page=1";
//	char *string;
//	
//	string = removeSubstring(str);
//	
//	printf("%s", string);
//	
//	return 0;
//}
//
//char *removeSubstring(const char *str) {
//	char *substring;
//	char *buffer = malloc(sizeof(char)*30);
//	int num;
//	
//	substring = strstr(str, "#");
//	
//	if (substring) {
//		num = strlen(str) - strlen(substring);
//	
//	//	printf("%d", num);
//		strncpy(buffer, str, num);
//		buffer[num] = '\0';
////		printf("%s", buffer);	
//		
//		return buffer;
//	}
//	
////	printf("%s", str);
//	return str;
//}


/** DIRECTION REDUCTION **/

//
//int main () {
//	char *arr[] ={"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
//	char **directions = (char **)malloc(sizeof(char *) * 10);
////	char directions[20][250];
//	int i, j, flag = 0, temp;
//	
//	temp = sizeof(arr) / sizeof(char *);
//	printf("array of string length: %d\n\n", temp);
//	
//	for (i = 0; i < temp; i++) {
//		for (j = i + 1; j < temp; j++) {
//			if (strcmp(arr[i], "NORTH") == 0 && strcmp(arr[j], "SOUTH") == 0) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1) {
//			arr[i] = NULL;
//			arr[j] = NULL;
//		}
//	}
//	
//	for (i = 0; i < temp; i++) {
//	    if (arr[i] != NULL ) {
//	    	printf("[%d]: %s", i, arr[i]);
//	//       strcpy(directions[i],arr[i]);
////	        sprintf(directions[i], "{%s}", arr[i]);
//	    }
//  }
//
//	return 0;
//}


/**SUM OF DIGITS / DIGITAL ROOT**/

//int splitInt(int num);
//
//int main () {
//	int n = 493193;
//	int sum;
//	
//	sum = splitInt(n);
//	
//	printf("First value: %d\n", sum);
//	
////	while (sum > 0 && sum > 10) {
////			sum = splitInt(sum);
////			printf("Final value: %d\n",sum);
////	}
//	
//	
//	return 0;
//}
//
//int splitInt(int num) {
//	int sum = 0;
//	int digit;
//	while (num > 0) {
//		digit = num % 10;
//		sum += digit;
//		num /= 10;
//	}
//	
//	if (sum > 0 && sum > 10) {
//		return splitInt(sum);
//	} else {
//		return sum;	
//	}
//	
//}


/** PERSISTENT BUGGER **/

//int bugger(int n);
//
//int main () {
//	int ret;
//	int num = 999;
//	int choices = 0;
//	int number;
////	
////	while (!choices) {
////		printf("Choices: 1 = get value, 0: exit: \n\n");
////		scanf("%d", &number);
////		switch(number) {
////			case 1:
////				printf("Enter a number: \n");
////				scanf("%d", &number);
////				ret = bugger(number);
////				printf("value: %d\n\n", ret);
////				break;
////			case 0:
////				choices = 1;
////				break;
////			default:
////				printf("enter a valid choice\n\n");
////		}
////	}
//	ret = bugger(num);
//	
//	printf("Return value: %d", ret);
//	
//	return 0;
//}
//
////int bugger(int n) {
////	int sum = 1;
////	int digit;
////	static int j = 0;
////	int total_sum = 0;
////	
////	if (n < 10) {
////		return j;
////	}
////	
////	while (n > 0) {
////		digit = n % 10;
////		sum *= digit;
////		n /= 10;
////	}
////	
////	if (sum >= 10 || sum < 10) {
////		printf("sum: %d\n", sum);
////		j++;
////	}
////	
////	
////	
////	return bugger(sum);
////}
//
////int bugger(int n) {
////	int sum = 1;
////	int digit;
////	
////	if (n < 10) {
////		return 0;
////	}
////	while (n > 0) {
////		sum *= (n % 10);
////		n /= 10;
////	}
////	printf("sum: %d\n", sum)
////	
////	return 1 + bugger(sum);
////}
//
//int bugger(int n) {
//	int m, p = 0;
//    while (n > 9) {
//        ++p;
//        while (n > 0)
//            m *= (n % 10);
//            n /= 10;
//        n = m;
//    }
//    return p;
//}



/** ENCRYPT THIS **/

//char *reverseChar(char *str);
//
//int main () {
//	char str[50] = "A";
//	char *token, temp;
//	int length = strlen(str);
////	char *string = (char *)malloc(sizeof(char)*strlen(str));
//	char string[50];
//	int i;
//	
//	
//	token = reverseChar(str);
////	printf("final string: %s\n", token);
////	token = strtok(str, " ");
//	
////	while (token != NULL) {
////    	snprintf(string, length, "%s",reverseChar(str));
////    	printf( "final string: %s\n", string);
////      	token = strtok(NULL, " ");
////	}
//	
//	return 0;
//}
//
//char *reverseChar(char *str) {
//	int length = strlen(str);
//    char *string = (char *)malloc(sizeof(char) * length);
//    char *reverseString = (char *)malloc(sizeof(char) * length);
//    int a;
//	char temp;
//	char *token;
//	
//    if(!*str) {
//		printf("str not found");
//	} else {
//		 strcpy(string,str);
//    
//	    a = string[0];
//	  	temp = string[1];
//	  	string[1] = string[length-1];
//	  	string[length-1] = temp;
//	  	memmove(&string[0], &string[0 + 1], length - 0);
//	  	
//	  	snprintf(reverseString,sizeof(str),"%d%s",a,string);
//	  	
//	  	printf("string: %s", reverseString);
//		
//		return reverseString;	
//	}
//}


/**MOVES IN SQUARED STRINGS **/
//char *vert_mirror(char *str);
//char *hor_mirror(char *str);
//
//int main () {
//	char string[100] = "abcd\nefgh\nijkl\nmnop";
//	char *vertString;
//	char *horString;
//	vertString = vert_mirror(string);
////	
//	printf("vertical string result: \n%s", vertString);
//	
////	horString = hor_mirror(string);
////	printf("horizontal string result: \n%s", strrev(string));
//	return 0;
//	
//}
//
//char *vert_mirror(char *str) {
//	char *token;
//	int length = strlen(str);
//	printf("string length: %d\n", sizeof(str));
//	char *sample = calloc(length, sizeof(char));
//	int j;
//	const char deli[2] = "\n";
//	token = strtok(str,deli);
//	
//	while (token != NULL) {
//		strrev(token);
//		j += snprintf(&sample[j], sizeof(token), "%s ", token);
//		token = strtok(NULL, deli);
//	}
//	
//	return sample;
//}
//
//char *hor_mirror(char *str) {
//	char *token;
//	int length = strlen(str);
////	printf("horizontal token: %s", str);
//	char reverstring[50];
//	int i = 0, j = 0, k, n = 0;
//	char *horstring = calloc(length, sizeof(char));
//	char *ret;
//	token = strtok(str,"\n");
//	
//	while(token !=NULL) {
//		i += snprintf(&horstring[i], sizeof(token),"%s\n", token);
//		j++;
//		token = strtok(NULL,"\n");
//	}
//	
//	for (k = j; k >= 0; k--) {
//		strcpy(reverstring[n++],horstring[k]);
//	}
//
//	printf("horizontal string: %s", reverstring);
//	
//}



/** WHICH ARE IN? **/
//char** inArray(char* array[], int sz1, char* array2[], int sz2, int* lg);
//int sortarray(const void * a, const void * b);
//int main () {
//	char* arr1[7] = { "cod", "code", "wars", "ewar", "pillow", "bed", "phht" };
//    char* arr2[8] = { "lively", "alive", "harp", "sharp", "armstrong", "codewars", "cod", "code" };
//	size_t array1size = sizeof(arr1) / sizeof(arr1[0]);
//    size_t array2size = sizeof(arr2) / sizeof(arr2[0]);
//    size_t newStringsize;
//    int i, length;
//    
//    char **newString;
//    
//    newString = inArray(arr1,array1size,arr2,array2size,0);
//    
////    printf("size of newString: %d\n", sizeof(*newString) / sizeof(*newString[0]));
////    length = sizeof(*newString) / sizeof(*newString[0]);
////    
////    for (i = 0; i < length && newString[i]; i++) {
////    	printf("string: %s\n", newString[i]);
////	}
//
//	return 0;
//}
//
//int sortarray(const void * a, const void * b) {
//	const char *pa = *(const char**)a;
//    const char *pb = *(const char**)b;
//
//    return strcmp(pa,pb);
//}
//
//char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg) {
//  char **newString = (char **)malloc(sizeof(char *) * sz1);
////  char *newString[sz1];
//  int i, j, x = 0;
//  char *duplicate;
//  size_t length;
//  
//  
//  for (i = 0; i < sz1; i++) {
//    for (j = 0; j < sz2; j++) {
//      duplicate = strstr(array2[j], array1[i]);
//      if (duplicate){
//      	length = strlen(array1[i]);
//      	newString[x] = (char*)malloc(length);
//      	memset(newString[x], 0,sizeof(char*));
//      	strncpy(newString[x++],array1[i],length);
////        newString[x] = (char*)malloc(strlen(array1[i]));
////        strcpy(newString[x++],array1[i]);
//        lg++;
//		break;
//      }
//    }
//  }
//  printf("size: %d\n", x);
//
////  printf("string: %s", *newString);
//  qsort(newString, x, sizeof(char*), sortarray);
//  
//  	for (i = 0; i < x && newString[i]; i++) {
//    	printf("string: %s\n", newString[i]);
//	}
//  return newString;
//}




/** BIT COUNTING **/

//int main () {
//	int num = 10;
//	size_t sum = 0;
//	
//	
//	unsigned int mask, size;
//	
//	size = sizeof(char)*8;
//	
//	for (mask = 1<<size-1; mask != 0; mask >>=1) {
//		if((num&mask) != 0) {
//			printf("1");
//		}else {
//			printf("0");
//		}
//	}
//	
//	return 0;
//}


/** VALID PHONE NUMBER **/

//bool valid_phone_number(const char* number);
//
//int main () {
//	bool res;
//	char *num = "abc(123) 456-7890";
//	res = valid_phone_number(num);
//	if (res) {
//		printf("true");
//	} else {
//		printf("false");
//	}
//	return 0;
//}
//
//bool valid_phone_number(const char* number) {
//	char *newStr;
//	strcpy(newStr,number);
//	static int count = 0;
//	int chr = 0;
//	char *token = strtok(newStr," ");
//	
//	while (token != NULL) {
//		printf("token: %s\n", token);
//		printf("size: %d\n", strlen(token));
//		if ((strlen(token) == 5 || strlen(token) == 8) && !is) {
//			count += 1;	
//		}
//		token = strtok(NULL," ");
//	}
//	printf("count: %d\n",count);
//	return count == 2 ? true : false;
//}


/** TRBONACCI SEQUENCE **/

long long *tribonacci(const long long signature[3], size_t n);

int main() {
	long long signature[3] = {3,2,1};
	long long *retVal;
	size_t n = 10, length;
	
	retVal = tribonacci(signature, n);
	
	length = sizeof(*retVal) / sizeof(retVal[0]);
	
	printf("length: %lli\n\n", retVal);
	return 0;
}

long long *tribonacci(const long long signature[3], size_t n) {
	
	long long *ret = malloc(sizeof(long long) * n);
	long long sum = 0,t1 = 1,t2 = 2,t3 = 3;
	int i,j;
	
	if (n == 0) return NULL;
	
	if (n == 1) return (long long *)signature;
	
	 for (i = 0; i < 3; i++) {
        ret[i] = signature[i]; // copy the three value
        sum += signature[i];
    }
    ret[i] = sum;
    
    
    for (j = i+1; j < n; ++j) {
    	ret[j] = ret[t1++] + ret[t2++] + ret[t3++];
	}
    
    for (i = 0; i < n; ++i) {
    	printf("value: %lli\n", ret[i]);
	}
    
    return ret;
}
