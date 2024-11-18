#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int data;
	struct node *next;
};
void push(struct node *top, int data);
int pop(struct node *top);
int main(){
	float num;
	struct node *p, *head = NULL;
	while(1){
		scanf("%f", &num);
		p=(struct node *)malloc(sizeof(struct node));
		p->next=head;
		head=p;
		push(head, (int)num);
		if(num-(int)num!=0){
			printf("Print stack\n");
			pop(head);
			break;
		}
	}
}
void push(struct node *top, int data){
	top->data=data;
}
int pop(struct node *top){
	printf("%d\n", top->data);
	if(top->next==NULL)
		return 0;
	pop(top->next);
}
