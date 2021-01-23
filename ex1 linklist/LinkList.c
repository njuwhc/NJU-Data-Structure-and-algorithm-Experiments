#include "LinkList.h"

/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/
_Bool CreateEmptyList(Node** head)
{
	(*head) =malloc(sizeof(Node));
	(*head)->next = NULL;
	return true;
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an array.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head)
{
	DataType i = 0;
	Node* p,*p1;
	(*head) = malloc(sizeof(Node));
	(*head)->next = NULL;
	p1 = (*head);
	for (; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = addr[i];
		p->next = NULL;
		p1->next = p;
		p1= p;

	}
	return true;
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head)
{
	Node* p1;
	while (head != NULL)
	{
		p1 = head;
		head = head->next;
		free(p1);
	}
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
Returns:
* True or false.
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 0, 6), the linked
* list will be "head->6->3->5->2".
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e)
{
	Node* p1,* p;
	DataType i = 0;
	p1 = head;
	while (p1 && i < index)
	{
		p1 = p1->next;
		i++;
	}
	p = (Node*)malloc(sizeof(Node));
	p->data = e;
	if (p1->next != NULL)
		p->next = p1->next, p1->next = p;
	else
		p->next = NULL, p1->next = p;


	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e)
{
	Node* p;
	Node* p1=head;
	DataType i = 0;
	while (p1&& i < index)
	{
		p1 = p1->next;
		i++;
	}
	p = p1->next;
	*e = p->data;
	if (p->next == NULL)
	{
		p1->next = NULL;
			free(p);
	}
	else
	{
		p1->next = p->next;
		free(p);
	}
	return true;
}
