typedef struct queue Queue;

Queue* create_queue();
void delete_queue();

int queue_size(Queue* li);
int full_queue(Queue* li);
int empty_queue(Queue* li);

int enqueue(Queue* li);
int dequeue(Queue* li);

int front_queue(Queue* li, int *value);
