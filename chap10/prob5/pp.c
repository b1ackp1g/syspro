#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
void addq(struct node *head, struct node *tail, int data);
int delete(struct node *head, struct node *tail);
int main(){
	int input;
	struct node *p = NULL, *tail = NULL;
	while(scanf("%d", &input)==1){
		if(p==NULL){
			p = (struct node*)malloc(sizeof(struct node));
			p->data = input;
			p->next = NULL;
			tail = p;
		}
		else{
			addq(p, tail, input);
			tail=tail->next;
		}
	}
	printf("Print queue\n");
	delete(p, p->next);
	return 0;
}
void addq(struct node *head, struct node *tail, int data){
	tail->next = (struct node*)malloc(sizeof(struct node));
	tail->next->data = data;
	tail->next->next = NULL;
}
int delete(struct node *head, struct node *tail){
	printf("%d\n", head->data);
	if(tail != NULL) delete(tail, tail->next);
	free(head);
	return 0;
}
