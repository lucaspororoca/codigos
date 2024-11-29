//PILHA
struct Node {
    int data;
    struct Node* next;
};

void initialize(struct Node** top_ref) {
    *top_ref = NULL;
}

void push(struct Node** top_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("erro ao alocar memória\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *top_ref;

    *top_ref = new_node;
}

void pop(struct Node** top_ref)
{
    if(top_ref == NULL)
    {
        printf("pilha vazia\n");
        return -1;
    }

    struct Node* temp = *top_ref;
    int poped_data = temp->data;

    *top_ref = temp->next;

    free(temp);

    return poped_data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void printStack(struct Node* top) {
    if (top == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reinitialize(struct Node** top_ref) {
    struct Node* current = *top_ref;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *top_ref = NULL;
}

//FILA
struct Queue {
    struct Node *front, *rear;
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Erro: Memória insuficiente.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    printf("Elemento %d inserido na fila.\n", new_data);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Erro: Fila vazia.\n");
        return -1;  
    }

    struct Node* temp = q->front;
    int dequeued_data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    printf("Elemento %d removido da fila.\n", dequeued_data);
    return dequeued_data;
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Fila: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reinitializeQueue(struct Queue* q) {
    struct Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    printf("A fila foi reinicializada e está vazia.\n");
}

//LISTA
struct Node {
    int data;
    struct Node* next;
};

void initialize(struct Node** head_ref) {
    *head_ref = NULL;
}

int length(struct Node* head){
    struct Node* current = *head;
    int count = 0;

    while(current != NULL){
        current = current->next;
        count++;
    }

    return count;
}

void insert(struct Node** head_ref, int position, int value) {
    // Criar um novo nó
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return;
    }

    // Atribuir o valor ao novo nó
    new_node->data = value;
    new_node->next = NULL;

    // Inserir no início da lista
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // Encontrar a posição correta
    struct Node* current = *head_ref;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Verificar se a posição é válida
    if (current == NULL) {
        printf("Posição fora de alcance.\n");
        free(new_node); // Liberar memória, já que o nó não será usado
        return;
    }

    // Inserir o nó na posição correta
    new_node->next = current->next;
    current->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

//ARVORE
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para inicializar a árvore (retorna NULL, pois a árvore começa vazia)
struct Node* init() {
    return NULL;
}

// Função para criar um novo nó
struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { printf("Erro ao alocar memória.\n"); return NULL; }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Função para buscar uma chave na árvore
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

// Função para contar o número de elementos na árvore
int count(struct Node* root) {
    if (root == NULL) return 0;
    return count(root->left) + 1 + count(root->right);
}

// Função para imprimir a árvore em ordem (ordem crescente)
void print(struct Node* root) {
    if (root == NULL) return;
    print(root->left);
    printf("(");
    print(root->right);
    printf(")");
    printf("%d", root->data);
}

//MAIN
int main() {
    //PILHA
    struct Node* top = NULL;
    initialize(&top);

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printStack(top);

    int poppedElement = pop(&top);
    printf("Elemento removido: %d\n", poppedElement);

    printStack(top);

    reinitialize(&top);
    printStack(top);

    //FILA
     struct Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);

    displayQueue(&q);
    
    reinitializeQueue(&q);

    displayQueue(&q);

    //LISTA
    struct Node* head = NULL;
    initialize(&head);

    insert(&head, 0, 10); 
    insert(&head, 1, 20); 
    insert(&head, 1, 15); 

    printList(head);

    //ARVORE
     struct Node* root = init();

    // Inserindo nós
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Árvore em ordem: ");
    print(root);
    printf("\n");

    // Buscando um nó
    int key = 40;
    struct Node* found = search(root, key);
    if (found) printf("Chave %d encontrada na árvore.\n", key);
    else printf("Chave %d não encontrada na árvore.\n", key);

    // Contando os elementos
    int total = count(root);
    printf("Número de elementos na árvore: %d\n", total);
    
    return 0;
}
