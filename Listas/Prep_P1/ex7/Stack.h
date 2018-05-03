/* Dynamic (linked) Stack */

struct element {
  int data;
  struct element *prev;
};

struct stack {
  int count;
  struct element *top;
};

typedef struct stack Stack;

// Stack creation and deletion functions:
Stack* create_stack();
void delete_stack(Stack* stk);

// Stack inspection functions:
int stack_size(Stack* stk);
int full_stack(Stack* stk);
int empty_stack(Stack* stk);

// Stack standard functions:
int push(Stack* stk, int value);
int pop(Stack* stk, int *value);
int top(Stack* stk, int *value);
