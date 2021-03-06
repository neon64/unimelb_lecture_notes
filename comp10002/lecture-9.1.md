# Lecture 9.1 - linked lists

Example program:

```c
int main(int argc, char *argv[]) {
    list_t *list;
    int i;
    list = make_empty_list();
    while (scanf("%d", &i) == 1) {
        list = insert_at_head(list, i);
        list = insert_at_head(list, i+1);
        list = insert_at_foot(list, i+2);
    }
    while(!is_empty_list(list)) {
        i = get_head(list);
        printf("%d ", i);
        list = get_tail(list);
    }
    printf("\n");
    free_list(list);
    list = NULL;
    return 0;
}
```

How to implement the list:

```
typedef struct node node_t;

struct node {
    data_t data;
    node_t *next;
}

typedef struct {
    node_t *head;
    node_t *foot;
} list_t;

list_t *make_empty_list(void) {
    list_t *list;
    list = (list_t *) malloc(sizeof(*list));
    assert(list != NULL);
    list->head = list->foot = NULL;
    return list;
}

int is_empty_list(list_t *list) {
    assert(list != NULL);
    return list->head == NULL:
}

void free_list(list_t *list) {
    node_t *curr, *prev;
    assert(list != NULL);
    curr = //
}

list_t *insert_at_head(list_t *list, data_t value) {
    node_t *new;
    new = (node_t *) malloc(sizeof(*new));
    assert(list != NULL && new != NULL);
    new->data = value;
    new->next = list->head; // new head points where old head pointed
    list->head = new; // pointing at new head,
    if(list->foot == NULL) {
        list->foot = new;
    }
    return list;
}

list_t *insert_at_foot(list_t *list, data_t value) {
    node_t *new;
    new = (node_t *) malloc(sizeof(*new));
    assert(list != NULL && new != NULL);
    new->data = value;
    new->next = NULL;
    if(list->foot == NULL) {
        list->head = list->foot = new;
    } else {
        list->foot->next = new;
        list->foot = new;
    }
    return list;
}
```

(code attribution to Alistair Moffat)





## Types of linked-lists

Singly-linked list:
   - has only a next pointer
- uses less space
   - can be less efficient in some cases

Doubly-linked-list:
    - has a next and prev pointer
    - requires more space
    - more flexible, can iterate in both directions



