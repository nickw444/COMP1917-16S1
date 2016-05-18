
typedef struct _linkedList * LinkedList;


LinkedList newLinkedList(void);
void addNode(LinkedList l, int newValue);
int getNumNodes(LinkedList l);
int getSmallest(LinkedList l);