#include <stdio.h>
#include <malloc.h>

struct Node;

typedef struct Node* Tree;

struct Node {
  int val;
  Tree left, right;
};

static void printAll(Tree t) {
    if (t != NULL) {
        printAll(t->left);
        printf("%d\n", t->val);
        printAll(t->right);
    }
}

void removeALL(Tree t) {
    if (t != NULL) {
        removeALL(t->left);
        removeALL(t->right);
        free(t);
    }

}

void insert(Tree *treePtr, int x) {
    Tree t = *treePtr;
    if (t == NULL) {
        t = malloc(sizeof(struct Node));
        t->val = x;
        t->right = t->left = NULL;
        *treePtr = t;
    }
    else if (x > t->val) {
        insert(&(t->right), x);
    }
    else if (x < t->val) {
        insert(&(t->left), x);
    }
}

int helpRemoveMin(Tree *treePointer, Tree previous) {
    Tree t = *treePointer;
    if (t != NULL) {
        int x = t->val;
        if (!t->left && !previous) {
            Tree help = t->right;
            free(t);
            *treePointer = help;
            return x;
        }
        else if (!t->left) {
            previous->left = t->right;
            return x;
        }
        return helpRemoveMin(&(t -> left), t);
    }
    return -1;
}

int removeMin(Tree *treePtr) {
    return helpRemoveMin(treePtr, NULL);
}

void helpRemove(Tree *treePtr, Tree previous, int x) {
    Tree t = *treePtr;
    if (t != NULL) {
        if (t->val == x && !t->right && previous) {
            if(previous->right == t) {
                previous->right = t->left;
            }
            else{
                previous->left = t->left;
            }
        }
        else if (t->val == x && !t->right && !previous) {
            Tree help = t->left;
            free(t);
            *treePtr = help;
        }
        else if (t->val == x && t->right) {
            t->val = removeMin(&(t->right));
        }
        else if (x > t->val) {
            helpRemove(&(t->right), t, x);
        }
        else {
            helpRemove(&(t->left), t, x);
        }
    }
}

void removeValue(Tree *treePtr, int x) {
    helpRemove(treePtr, NULL, x);
}

int main() {
    Tree root = NULL;
    int x;
    while (scanf("%d", &x) == 1) {
        if (x > 0) {
            insert(&root, x);
        }
        else if (x < 0) {
            removeValue(&root, -x);
        }
    }
    printAll(root);

    removeALL(root);
}
