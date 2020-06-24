//#include <stdio.h>
//#include <conio.h>
//
//typedef struct node
//{
//	char data;
//	struct node *link;
//}celltype, *List;
//
//
//void insertLast(List *L, char elem);
//void displayInsertLast(List L);
//
//void insertLast(List *L, char elem)
//{
//	List temp, *trav;
//	temp = (List)malloc(sizeof(celltype));
//	if(temp!=NULL){
//		temp->data = elem;
//		temp->link = NULL;
//	}
//		for(trav = L; *trav!=NULL;trav = &(*trav)->link){
//		}
//		*trav = temp;	
//}
//
//void displayInsertLast(List L)
//{
//	List trav;
//	for(trav = L; trav!=NULL;trav = trav->link){
//		printf("%c",trav->data);
//	}
//}
//
//int main()
//{
//	List c = NULL;
//	char elements;
//	
//	insertLast(&c,'a');
//	insertLast(&c,'b');
//	insertLast(&c,'c');
//	insertLast(&c,'d');
//	insertLast(&c,'e');
//	displayInsertLast(c);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int retval(char *str);
int retval (int start, int end);

int main () {
//	char *str = "hello";
//	
//	printf("letter: %c\n",str[1]);
//	int i;
//	char *newStr = (char *)malloc(sizeof(char) * strlen(str));
//	for (i = 0; i < strlen(str); i++) {
//		newStr[i] = str[i];
//	}
//	printf("string: %s",newStr);
//	char str[20] = "12.255.56.1";
	int start = 4, end = 17;
	int ret = retval(start, end);
	
	printf("returned number: %i", ret);
	
	return 0;
}

int roundoff (int num) {
	int dig;
	
	while (num > 0) {
		dig = num % 10;
		num /= 10;
	} 
	
	return dig;
}

int retval (int start, int end) {
	int i, roundNum;
	int count = 0;
	
	for (i = start; i <= end; i++) {
		roundNum = roundoff(i);
		if (!(roundNum == 5) && !(i % 10 == 5)) {
			printf("%d\n",i);
			count++;
		}
		
	}
	return count;
}

//int retval(char *str) {
//	int length = 0, convert,ret = 0, alpha = 0;
//	char *token = strtok(str,".");
//	while (token != NULL){
//			sscanf(token, "%d", &convert);
//			ret = convert > 255 ? 0 : 1;
//			length++;
//			token = strtok(NULL,".");
//			printf("convert: %d\n",convert);
//	} 
//	printf("length: %d\n", length);
//	
//	return length >= 5 ? 0 : ret;
//	
//}
