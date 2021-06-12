#include <iostream>
#include <list>
using namespace std;

// constant for indicate
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// class definition
class Node
{
public:
    int puzzle[9];          // puzzle data array
    list<Node*> child_node; // child node of node
    Node* parent;           // parent node

    void set_puzzle(const int arr[]);
    int empty_index();
    bool isGoal(const int arr[]);
    void block_move(int op);
    void clone_puzzle(int* new_puzzle, const int* origin_puzzle);
    void print_puzzle();
    bool equal_check(int arr[]);
};

// function definition
list<Node*>* breadth_first_search(Node* root, int *target);
bool contains (list<Node*>* list, Node *np);
void solution_trace(list<Node*>* solution, Node* np);

int main()
{
    int init1[9] = {1, 3, 2, 0, 7, 8, 5, 6, 4}; // initial case 1
    int init2[9] = {3, 7, 0, 1, 6, 2, 5, 4, 8}; // initial case 2
    int init3[9] = {7, 5, 6, 3, 4, 2, 1, 0, 8}; // initial case 3
    int target[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5}; // target(final) case

    Node* root = new Node;
    root->set_puzzle(init1);

    list<Node*>* solution = breadth_first_search(root, target);
    cout << "step = " << solution->size() << endl;
    solution->reverse();

    if(!solution->empty()) {
        for(Node* node : *solution) {
            node->print_puzzle();
            cout << endl;
        }
    }
    else
        cout << "Failed to find solutions..." << endl;
    return 0;
}

// method definition
void Node:: set_puzzle(const int arr[])
{
    for(int i=0 ; i<9 ; i++)
        puzzle[i] = arr[i];
}

int Node:: empty_index()
{
    for(int i=0 ; i<9 ; i++) {
        if(puzzle[i] == 0)
            return i;
    }
    return -1;
}

bool Node:: isGoal(const int arr[])
{
    int counter = 0;

    for(int i=0 ; i<9 ; i++) {
        if(puzzle[i] != arr[i]) break;
        counter++;
    }
    if(counter < 9) return false;
    else return true;
}

void Node:: clone_puzzle(int *new_puzzle, const int *origin_puzzle)
{
    for(int i=0 ; i<9 ; i++)
        new_puzzle[i] = origin_puzzle[i];
}

void Node:: block_move(int op)
{
    int zero_index = empty_index();
    int tmp_arr[9];
    int tmp;

    if(op == UP && zero_index / 3 != 0) {
        clone_puzzle(tmp_arr, puzzle);
        tmp = tmp_arr[zero_index-3];
        tmp_arr[zero_index-3] = 0;
        tmp_arr[zero_index] = tmp;

        Node* child = new Node;
        child->set_puzzle(tmp_arr);
        child_node.push_back(child);
        child->parent = this;
    }
    else if(op == DOWN && zero_index / 3 != 2) {
        clone_puzzle(tmp_arr, puzzle);

        tmp = tmp_arr[zero_index+3];
        tmp_arr[zero_index+3] = 0;
        tmp_arr[zero_index] = tmp;

        Node* child = new Node;
        child->set_puzzle(tmp_arr);
        child_node.push_back(child);
        child->parent = this;
    }
    else if(op == LEFT && zero_index % 3 != 0) {
        clone_puzzle(tmp_arr, puzzle);

        tmp = tmp_arr[zero_index-1];
        tmp_arr[zero_index-1] = 0;
        tmp_arr[zero_index] = tmp;

        Node* child = new Node;
        child->set_puzzle(tmp_arr);
        child_node.push_back(child);
        child->parent = this;
    }
    else if(op == RIGHT && zero_index % 3 != 2) {
        clone_puzzle(tmp_arr, puzzle);

        tmp = tmp_arr[zero_index+1];
        tmp_arr[zero_index+1] = 0;
        tmp_arr[zero_index] = tmp;

        Node* child = new Node;
        child->set_puzzle(tmp_arr);
        child_node.push_back(child);
        child->parent = this;
    }
}

void Node:: print_puzzle()
{
    for(int i=0 ; i<9 ; i++) {
        if((i+1) % 3 == 0)
            cout << puzzle[i] << endl;
        else
            cout << puzzle[i] << " ";
    }
}

bool Node::equal_check(int arr[])
{
    for(int i=0 ; i<9 ; i++)
        if(puzzle[i] != arr[i])
            return false;
    return true;
}

// function definition
bool contains(list<Node*>* list, Node* np)
{
    bool contains = false;

    for(Node* node : *list) {
        if(node->equal_check(np->puzzle))
            contains = true;
    }
    return contains;
}

list<Node*>* breadth_first_search(Node* root, int* target)
{
    list<Node*>* solution = new list<Node*>;
    list<Node*>* open = new list<Node*>;
    list<Node*>* close = new list<Node*>;

    open->push_back(root);
    bool goalCheck = false;

    while(!open->empty() && !goalCheck) {
        Node* curNode = open->front();
        close->push_back(curNode);
        open->pop_front();

        curNode->block_move(UP);
        curNode->block_move(DOWN);
        curNode->block_move(LEFT);
        curNode->block_move(RIGHT);

        for(Node* node : curNode->child_node)
        {
            if(node->isGoal(target)) {
                cout << "solution was founded..." << endl;
                goalCheck = true;
                solution_trace(solution, node);
            }

            if(!contains(open, node) && !contains(close, node))
                open->push_back(node);
        }
    }
    return solution;
}

void solution_trace(list<Node*>* solution, Node* np)
{
    cout << "Trace Solution" << endl;
    solution->push_back(np);
    while(np->parent != NULL)
    {
        np = np->parent;
        solution->push_back(np);
    }
}