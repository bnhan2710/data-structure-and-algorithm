#include <stdio.h>
#include <stdlib.h>
struct ElementType {
	unsigned long ID;
	char *name;
};

struct Node {
	struct ElementType value;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;

List createList() {
	List headerNode = malloc(sizeof(struct Node));
	headerNode->next = NULL;
	return headerNode;
}

Position insert(struct ElementType e, Position p){	
	Position newItem;
	newItem = malloc(sizeof(struct Node));
	newItem->value = e;
	
	newItem->next = p->next;
	newItem->prev = p;
	p->next = newItem;
	if (newItem->next!=NULL)
		newItem->next->prev = newItem;
	
	return newItem;
}

void display(List pL)
{
	int count = 1;
	pL = pL->next;
	while (pL!=NULL)
	{
		printf("*** %d | %ld       | %s\n",count,pL->value.ID, pL->value.name);
		pL = pL->next;
		count++;
	}
}

Position find(List pL, unsigned long ID) {
	pL=pL->next;
	while (pL!=NULL && pL->value.ID!=ID)
		pL = pL->next;
	return pL;
}

void Delete(Position p) {
	p->prev->next = p->next;
	if (p->next!=NULL)
		p->next->prev = p->prev;
	free(p);
}



int main()
{
	List pL = createList();
	struct ElementType e1,e2,e3;
	
	e1.ID = 123; e1.name = "Nguyen Van A";
	e2.ID = 124; e2.name = "Dang Thi B";
	e3.ID = 125; e3.name = "Do Van C";
	
	Position p = NULL;
	
	p = insert(e1,pL);
	p = insert(e2,p);
	p = insert(e3,p);
	
	display(pL);
		
	p = find(pL,124);
	
	if (p!=NULL) 
		printf("Found!!!  ID: %ld         Name:%s\n",p->value.ID,p->value.name);
	else
		printf("Not Found!!!");
	Delete(p);
	printf("After deleted!!!\n");
	display(pL);
	return 0;
}