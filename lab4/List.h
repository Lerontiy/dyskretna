typedef int datatype; 

struct Node
{
    datatype key;
    Node* next;
    Node* previous; //у випадку двозв’язного списку
};

void pushstack(datatype item);
void popstack();
void showstack();

void clear();
void add_begin(datatype item);
void add_end(datatype item);
void del_begin();
void del_end();
Node* search(datatype item);
void add_mid(datatype find, datatype item);
void del_mid(datatype find);
void showqueue();





