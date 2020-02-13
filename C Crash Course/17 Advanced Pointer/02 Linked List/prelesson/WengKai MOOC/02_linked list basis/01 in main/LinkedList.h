#ifndef _LINK_LIST_
#define _LINK_LIST_

typedef struct _node {

	char Name[20];
	char Gender[5];
	int Age;
	long long ID;
	struct _node* next;
}node;

#endif