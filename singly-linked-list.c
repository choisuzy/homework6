#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {  /* struct Node에 타입이 다른 데이터들을 그룹화 */
	int key;           /* key를 int형으로 선언 */
	struct Node* link; /* 구조체 Node포인터 link를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
} listNode;            /* 구조체 호출용 이름 */

typedef struct Head {   /* struct Head에 타입이 다른 데이터들을 그룹화 */
	struct Node* first; /* 구조체 Node포인터 first를 선언 */ /* 위에서 typedef struct로 선언을 해주지 않았기에 struct를 써줘야함 */
}headNode;              /* 구조체 호출용 이름 */


/* 함수 리스트 */
headNode* initialize(headNode* h); /* headNode에 메모리를 할당하여 초기화하는 initialize 함수 선언 */
int freeList(headNode* h); /* 할당된 메모리를 모두 해제하는 freeList 함수 선언 */

int insertFirst(headNode* h, int key); /* list 처음에 key에 대한 노드 하나를 추가하는 insertFirst 함수 선언 */
int insertNode(headNode* h, int key);  /* 리스트를 검색하여 입력받은 key값보다 큰 값이 나오는 노드 바로 앞에 삽입하는 insertNode 함수 선언 */
int insertLast(headNode* h, int key);  /* key에 대한 노드 하나를 추가하는 insertLast 함수 정의 */

int deleteFirst(headNode* h);   /* list의 첫번째 노드를 삭제하는 deleteFirst 함수 선언 */
int deleteNode(headNode* h, int key); /* list에서 key에 대한 노드를 삭제하는 deleteNode 함수 선언 */
int deleteLast(headNode* h); /* list의 마지막 노드를 삭제하는 deleteLast 함수 선언 */
int invertList(headNode* h); /* 리스트의 링크를 역순으로 재 배치하는 invertList 함수 선언 */

void printList(headNode* h); /* list를 print하는 printList 함수 선언 */

int main()
{
    printf("[----- [Choi Suzy]  [2021024135] -----]\n");

	char command;  /* command를 char형으로 선언 */
	int key;       /* key를 int형으로 선언 */
	headNode* headnode=NULL; /* headNode포인터 headnode를 빈공간으로 지정 */

	do{
		printf("----------------------------------------------------------------\n"); /* print */
		printf("                     Singly Linked List                         \n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */
		printf(" Initialize    = z           Print         = p \n"); /* print */
		printf(" Insert Node   = i           Delete Node   = d \n"); /* print */
		printf(" Insert Last   = n           Delete Last   = e\n"); /* print */
		printf(" Insert First  = f           Delete First  = t\n"); /* print */
		printf(" Invert List   = r           Quit          = q\n"); /* print */
		printf("----------------------------------------------------------------\n"); /* print */

		printf("Command = "); /* print */
		scanf(" %c", &command); /* char형 command를 입력자에게 입력받음 */

		switch(command) { /* command가 ~이면 조건문 */ 
		case 'z': case 'Z': /* command가 z나 Z면 */
			headnode = initialize(headnode); /* initialize(headnode)함수 headnode에 넣음 */
			break; /* 조건식을 빠져나옴 */
		case 'p': case 'P': /* command가 p나 P면 */
			printList(headnode); /* printList(headnode)함수 실행 */
			break; /* 조건식을 빠져나옴 */
		case 'i': case 'I': /* command가 i나 I면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertNode(headnode, key); /* insertNode함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'd': case 'D': /* command가 d나 D이면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			deleteNode(headnode, key); /* deleteNode함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'n': case 'N': /* command가 n이나 N이면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertLast(headnode, key); /* insertLast함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'e': case 'E': /* command가 e나 E이면 */
			deleteLast(headnode); /* deleteLast함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'f': case 'F': /* command가 f나 F면 */
			printf("Your Key = "); /* print */
			scanf("%d", &key); /* int형 key를 입력자에게 입력받음 */
			insertFirst(headnode, key); /* insertFirst함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 't': case 'T': /* command가 t나 T면 */
			deleteFirst(headnode); /* deleteFirst함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'r': case 'R': /* command가 r이나 R면 */
			invertList(headnode); /* invertList함수 호출 */
			break; /* 조건식을 빠져나옴 */
		case 'q': case 'Q': /* command가 q나 Q이면 */
			freeList(headnode); /* freeList함수 호출 */
			break; /* 조건식을 빠져나옴 */
		default: /* 위의 알파벳이 다 아니면 */
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); /* print */
			break; /* 조건식을 빠져나옴 */
		}

	}while(command != 'q' && command != 'Q'); /* command가 q가 아니고 Q가 아니라면 do루프 계속 돎 */

	return 1; /* 1을 반환함 */
}

headNode* initialize(headNode* h) { /* headNode에 메모리를 할당하여 초기화하는 initialize 함수 정의 */

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL) /* headNode가 NULL이 아니면 */
		freeList(h); /* freeList 함수 호출 */

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode)); /* headNode크기만큼을 동적할당한 headNode포인터를 headNode포인터 temp에 넣음 */
	temp->first = NULL; /* temp의 first부분을 NULL로 만듦 */
	return temp; /* temp를 반환함 */
}

int freeList(headNode* h){ /* 할당된 메모리를 모두 해제하는 freeList 함수 정의 */
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first; /* h의 first부분을 listNode포인터 p에 넣음 */

	listNode* prev = NULL; /* listNode포인터 prev를 NULL로 만듦 */
	while(p != NULL) { /* headNode가 NULL이 아니면 */
		prev = p; /* p를 prev에 넣음 */
		p = p->link; /* p의 link부분을 p에 넣음 */
		free(prev); /* prev를 free시킴 */
	}
	free(h); /* h를 free시킴 */
	return 0; /* 0을 반환함 */
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) { /* 리스트를 검색하여 입력받은 key값보다 큰 값이 나오는 노드 바로 앞에 삽입하는 insertNode 함수 정의 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key; /* 입력받은 key 값을 node의 key부분에 넣음 */
	node->link = NULL; /* node의 link부분을 NULL로 만듦 */

	if (h->first == NULL) /* h의 first부분이 NULL이면 */
	{
		h->first = node; /* h의 first부분에 node를 넣음 */
		return 0; /* 0을 반환함 */
	}

	listNode* n = h->first; /* listNode포인터 n에 h의 first부분을 넣음 */
	listNode* trail = h->first; /* listNode포인터 trail부분에 h의 first부분을 넣음 */

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) { /* n이 NULL이 아니면 while문 계속 돎 */
		if(n->key >= key) { /* n의 key부분이 입력받은 key의 값과 같거나 크면 */
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) { /* n이 h의 first부분이면 */
				h->first = node; /* h의 first부분에 h의 first부분을 넣음 */
				node->link = n; /* node의 link부분에 n을 넣음 */
			} else { /* 중간이거나 마지막인 경우 */
				node->link = n; /* node의 link부분에 n을 넣음 */
				trail->link = node; /* trail의 link부분에 node를 넣음 */
			}
			return 0; /* 0을 반환함 */
		}

		trail = n; /* trail에 n을 넣음 */
		n = n->link; /* n의 link부분에 n을 넣음 */
	}

	/* 마지막 노드까지 찾지 못한 경우 , 마지막에 삽입 */
	trail->link = node; /* trail의 link부분에 node을 넣음 */
	return 0; /* 0을 반환함 */
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) { /* key에 대한 노드 하나를 추가하는 insertLast 함수 정의 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key;  /* node의 key부분에 key값을 넣음 */
	node->link = NULL; /* node의 link부분을 빈공간으로 만듦 */

	if (h->first == NULL) /* h의 first부분이 빈공간이라면 */
	{
		h->first = node; /* h의 first부분에 node을 넣음 */
		return 0; /* 0을 반환함 */
	}

	listNode* n = h->first; /* listNode포인터n에 h의 first부분을 넣음 */
	while(n->link != NULL) { /* n의 link부분이 빈공간이 아니라면 */
		n = n->link; /* n에 n의 link부분을 넣음 */
	}
	n->link = node; /* n의 link부분에 node를 넣음 */
	return 0; /* 0을 반환함 */
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) { /* list 처음에 key에 대한 노드 하나를 추가하는 insertFirst 함수 정의 */

	listNode* node = (listNode*)malloc(sizeof(listNode)); /* listNode크기만큼을 동적할당한 listNode포인터를 listNode포인터 node에 넣음 */
	node->key = key; /* node의 key부분에 key값을 넣음 */

	node->link = h->first; /* node의 link부분에 h의 first부분을 넣음 */
	h->first = node; /* h의 first부분에 h의 first부분을 넣음 */

	return 0; /* 0을 반환함 */
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) { /* list에서 key에 대한 노드를 삭제하는 deleteNode 함수 정의 */

	if (h->first == NULL) /* h의 first부분이 빈공간이라면 */ 
	{
		printf("nothing to delete.\n"); /* print */
		return 0; /* 0을 반환함 */
	} 

	listNode* n = h->first; /* h의 first부분을 listNode포인터 n에 넣음 */
	listNode* trail = NULL; /* node의 link부분에 h의 first부분을 넣음 */

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) { /* node의 link부분에 h의 first부분을 넣음 */
		if(n->key == key) {
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) { /* n이 h의 first부분과 같다면 */
				h->first = n->link; /* h의 first부분에 n의 link부분을 넣음 */
			} else { /* 중간인 경우거나 마지막인 경우 */
				trail->link = n->link; /* trail의 link부분에 n의 link부분을 넣음 */
			}
			free(n); /* n을 free시킴 */
			return 0; /* 0을 반환함 */
		} 

		trail = n; /* trail에 n을 넣음 */
		n = n->link; /* n에 n의 link부분을 넣음 */
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key); /* print */
	return 0; /* 0을 반환함 */

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) { /* list의 마지막 노드를 삭제하는 deleteLast 함수 정의 */

	if (h->first == NULL) /* h의 first부분이 빈공간이라면 */
	{
		printf("nothing to delete.\n"); /* print */
		return 0; /* 0을 반환함 */
	}

	listNode* n = h->first; /* listNode포인터 n에 h의 first부분을 넣음 */
	listNode* trail = NULL; /* listNode포인터 trail을 빈공간으로 만듦 */

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) { /* n의 link부분이 빈공간이라면 */
		h->first = NULL; /* h의 first부분을 빈공간으로 만듦 */
		free(n); /* n을 free시킴 */
		return 0; /* 0을 반환함 */
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) { /* n의 link부분이 빈공간이라면 */
		trail = n; /* trail에 n을 넣음 */
		n = n->link; /* n에 n의 link부분을 넣음 */
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL; /* trail의 link부분을 빈공간으로 만듦 */
	free(n); /* n을 free시킴 */

	return 0; /* 0을 반환함 */
}
/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {  /* list의 첫번째 노드를 삭제하는 deleteFirst 함수 정의 */

	if (h->first == NULL) /* h의 first부분이 빈공간이라면 */
	{
		printf("nothing to delete.\n"); /* print */
		return 0; /* 0을 반환함 */
	}
	listNode* n = h->first; /* listNode포인터 n에 h의 first부분을 넣음 */

	h->first = n->link; /* h의 first부분에 n의 link부분을 넣음 */
	free(n); /* n을 free시킴 */

	return 0; /* 0을 반환함 */
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) { /* 리스트의 링크를 역순으로 재 배치하는 invertList 함수 정의 */


	if(h->first == NULL) { /* h의 first부분이 빈공간이라면 */
		printf("nothing to invert...\n"); /* print */
		return 0; /* 0을 반환함 */
	}
	listNode *n = h->first; /* listNode포인터n에 h의 first부분을 넣음 */
	listNode *trail = NULL; /* listNode포인터trail을 빈공간으로 만듦 */
	listNode *middle = NULL; /* listNode포인터middle을 빈공간으로 만듦 */

	while(n != NULL){ /* n이 빈공간이 아니라면 */
		trail = middle; /* trail에 middle을 넣음 */
		middle = n; /* middle에 n을 넣음 */
		n = n->link; /* n에 n의 link부분을 넣음 */
		middle->link = trail; /* middle의 link부분에 trail을 넣음 */
	}

	h->first = middle; /* h의 first부분에 middle을 넣음 */

	return 0; /* 0을 반환함 */
}


void printList(headNode* h) { /* list를 print하는 printList 함수 정의 */
	int i = 0; /* int형 i를 0으로 초기화 */
	listNode* p; /* listNode포인터 p 선언 */

	printf("\n---PRINT\n"); /* print */

	if(h == NULL) { /* h가 빈공간이라면 */
		printf("Nothing to print....\n"); /* print */
		return; /* 반환함 */
	}

	p = h->first; /* h의 first부분에 p를 넣음 */

	while(p != NULL) { /* p가 빈공간이 아니라면 */
		printf("[ [%d]=%d ] ", i, p->key); /* i와 p의 key값을 차례대로 넣어 print */
		p = p->link; /* p에 p의 link부분을 넣음 */
		i++; /* 하나씩 증가시킴 */
	}

	printf("  items = %d\n", i); /* print */
}