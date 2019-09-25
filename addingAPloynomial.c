#include <stdio.h>
#include <stdlib.h>

struct node {
	int coefficient ;
	int power ;
	struct node* next ;
};

void insert(struct node** head_reference , int coefficient , int power)
{
	struct node* new_node  = (struct node*)malloc(sizeof(struct node));
	new_node->coefficient = coefficient ;
	new_node->power = power ;
	if((*head_reference) == NULL){
		*head_reference = new_node ;
		new_node->next = NULL ;	
		return ;	
	}
	
	new_node->next = *head_reference ;
	*head_reference = new_node ;
}

void display(struct node* head){
	struct node* traversal = head ;
	if(head != NULL){
		while(traversal != NULL){
			printf("(%d\t,%d)" , traversal->coefficient ,traversal->power);
			traversal = traversal->next ;	
		}
		printf("\n");	
	}
}


void addPolynomial(struct node* poly1 , struct node* poly2){
	struct node* afterAdd = (struct node*)malloc(sizeof(struct node)) ;
	struct node* first = afterAdd ;
	while(poly1 && poly2){
		if(poly1->power == poly2->power){
			afterAdd->power = poly1->power;
			afterAdd->coefficient = poly1->coefficient + poly2->coefficient ;
			poly1 = poly1->next ;
			poly2 = poly2->next ;
			afterAdd->next = (struct node*)malloc(sizeof(struct node));
			afterAdd =  afterAdd->next ;
		}
		else if (poly1->power > poly2->power){
			afterAdd->power = poly1->power ;
			afterAdd->coefficient = poly1->coefficient ;
			poly1 = poly1->next ;
			afterAdd->next = (struct node*)malloc(sizeof(struct node));
			afterAdd =  afterAdd->next ;
		}
		else if (poly1->power < poly2->power){
			afterAdd->power = poly2->power ;
			afterAdd->coefficient = poly2->coefficient ;
			poly2 = poly2->next ;
			afterAdd->next = (struct node*)malloc(sizeof(struct node));
			afterAdd =  afterAdd->next ;
		}
	}
	afterAdd->next = NULL ;
	display(first);
}

int main (void){
	struct node* polynomial1 = NULL ;
	struct node* polynomial2 = NULL ;
insert(&polynomial1 , 0 ,1);
insert(&polynomial1 , 30 ,2);
	insert(&polynomial1 , 13 ,3);
	
	
	display(polynomial1);
insert(&polynomial2 , 30 ,1);
	insert(&polynomial2 , 30 ,2);
	insert(&polynomial2 , 17 ,3);

	
display(polynomial2);
	addPolynomial(polynomial1,polynomial2);
	return 0 ;
}
