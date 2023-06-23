// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Node
// {
//     struct Node *lchild;
//     int data;
//     int height;
//     struct Node *rchild;
// } *root = NULL;

// int NodeHeight(struct Node *p)
// {
//     int hl, hr;
//     hl = p && p->lchild ? p->lchild->height : 0;
//     hr = p && p->rchild ? p->rchild->height : 0;

//     return hl > hr ? hl + 1 : hr + 1;
// }

// int BalanceFactor(struct Node *p)
// {
//     int hl, hr;
//     hl = p && p->lchild ? p->lchild->height : 0;
//     hr = p && p->rchild ? p->rchild->height : 0;

//     return hl - hr;
// }

// struct Node *LLRotation(struct Node *p)
// {
//     struct Node *pl = p->lchild;
//     struct Node *plr = pl->rchild;

//     pl->rchild = p;
//     p->lchild = plr;

//     p->height = NodeHeight(p);
//     pl->height = NodeHeight(pl);

//     if (root == p)
//         root = pl;

//     return pl;
// }

// struct Node *LRRotation(struct Node *p)
// {
//     struct Node *pl = p->lchild;
//     struct Node *plr = pl->rchild;

//     pl->rchild = plr->lchild;
//     p->lchild = plr->rchild;

//     plr->lchild = pl;
//     plr->rchild = p;

//     pl->height = NodeHeight(pl);
//     p->height = NodeHeight(p);
//     plr->height = NodeHeight(plr);

//     if (root == p)
//         root = plr;

//     return plr;
// }

// struct Node *RRRotation(struct Node *p)
// {
//     struct Node *pr = p->rchild;
//     struct Node *prl = pr->lchild;

//     pr->lchild = p;
//     p->rchild = prl;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);

//     if (root == p)
//         root = pr;

//     return pr;
// }

// struct Node *RLRotation(struct Node *p)
// {
//     struct Node *pr = p->rchild;
//     struct Node *prl = pr->lchild;

//     pr->lchild = prl->rchild;
//     p->rchild = prl->lchild;

//     prl->rchild = pr;
//     prl->lchild = p;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);
//     prl->height = NodeHeight(prl);

//     if (root == p)
//         root = prl;

//     return prl;
// }

// struct Node *RInsert(struct Node *p, int key, int *leftRotations, int *rightRotations)
// {
//     if (p == NULL)
//     {
//         struct Node *t = (struct Node *)malloc(sizeof(struct Node));
//         t->data = key;
//         t->height = 1;
//         t->lchild = t->rchild = NULL;
//         return t;
//     }

//     if (key < p->data)
//         p->lchild = RInsert(p->lchild, key, leftRotations, rightRotations);
//     else if (key > p->data)
//         p->rchild = RInsert(p->rchild, key, leftRotations, rightRotations);

//     p->height = NodeHeight(p);
//     int balanceFactor = BalanceFactor(p);

//     if (balanceFactor == 2 && BalanceFactor(p->lchild) == 1)
//     {
//         *rightRotations += 1;
//         return LLRotation(p);
//     }
//     else if (balanceFactor == 2 && BalanceFactor(p->lchild) == -1)
//     {
//         *leftRotations += 1;
//         *rightRotations += 1;
//         return LRRotation(p);
//     }
//     else if (balanceFactor == -2 && BalanceFactor(p->rchild) == -1)
//     {
//         *leftRotations += 1;
//         return RRRotation(p);
//     }
//     else if (balanceFactor == -2 && BalanceFactor(p->rchild) == 1)
//     {
//         *leftRotations += 1;
//         *rightRotations += 1;
//         return RLRotation(p);
//     }

//     return p;
// }

// int PrintSubtreeSum(struct Node *p, int x)
// {

//     if (p == NULL)
//     {
//         return 0;
//     }

//     else
//     {
//         return p->data + PrintSubtreeSum(p->lchild, x) + PrintSubtreeSum(p->rchild, x);
//     }
// }

// int main()
// {
//     int Q;
//     scanf("%d", &Q);

//     for (int i = 0; i < Q; i++)
//     {
//         char query[10];
//         int x;

//         scanf("%s %d", query, &x);

//         if (strcmp(query, "insert") == 0)
//         {
//             int leftRotations = 0;
//             int rightRotations = 0;
//             root = RInsert(root, x, &leftRotations, &rightRotations);
//             printf("%d %d\n", leftRotations, rightRotations);
//         }
//         else if (strcmp(query, "subtree") == 0)
//         {
//             int sum = 0;
//             struct Node *p = NULL;
//             p = (struct Node *)malloc(sizeof(struct Node));
//             p = root;
//             while (p != NULL && p->data != x )
//             {
//                 p = p->data > x ? p->lchild : p->rchild;
//             }

//             if (p == NULL)
//                 printf("NA\n");
//             else
//             {
//                 sum = PrintSubtreeSum(p, x);
//                 printf("%d\n", sum);
//             }
//         }

        
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Node {
//     struct Node* left;
//     int data;
//     int height;
//     struct Node* right;
// } *root = NULL;

// int NodeHeight(struct Node* p) {
//     int hl, hr;
//     hl = p && p->left ? p->left->height : 0;
//     hr = p && p->right ? p->right->height : 0;

//     return hl > hr ? hl + 1 : hr + 1;
// }

// int BalanceFactor(struct Node* p) {
//     int hl, hr;
//     hl = p && p->left ? p->left->height : 0;
//     hr = p && p->right ? p->right->height : 0;

//     return hl - hr;
// }

// struct Node* LLRotation(struct Node* p) {
//     struct Node* pl = p->left;
//     struct Node* plr = pl->right;

//     pl->right = p;
//     p->left = plr;

//     p->height = NodeHeight(p);
//     pl->height = NodeHeight(pl);

//     if (root == p)
//         root = pl;

//     return pl;
// }

// struct Node* LRRotation(struct Node* p) {
//     struct Node* pl = p->left;
//     struct Node* plr = pl->right;

//     pl->right = plr->left;
//     p->left = plr->right;

//     plr->left = pl;
//     plr->right = p;

//     pl->height = NodeHeight(pl);
//     p->height = NodeHeight(p);
//     plr->height = NodeHeight(plr);

//     if (root == p)
//         root = plr;

//     return plr;
// }

// struct Node* RRRotation(struct Node* p) {
//     struct Node* pr = p->right;
//     struct Node* prl = pr->left;

//     pr->left = p;
//     p->right = prl;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);

//     if (root == p)
//         root = pr;

//     return pr;
// }

// struct Node* RLRotation(struct Node* p) {
//     struct Node* pr = p->right;
//     struct Node* prl = pr->left;

//     pr->left = prl->right;
//     p->right = prl->left;

//     prl->right = pr;
//     prl->left = p;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);
//     prl->height = NodeHeight(prl);

//     if (root == p)
//         root = prl;

//     return prl;
// }

// struct Node* RInsert(struct Node* p, int key) {
//     if (p == NULL) {
//         struct Node* t = (struct Node*)malloc(sizeof(struct Node));
//         t->data = key;
//         t->height = 1;
//         t->left = t->right = NULL;
//         return t;
//     }

//     if (key < p->data)
//         p->left = RInsert(p->left, key);
//     else if (key > p->data)
//         p->right = RInsert(p->right, key);

//     p->height = NodeHeight(p);
//     int balanceFactor = BalanceFactor(p);

//     if (balanceFactor == 2 && BalanceFactor(p->left) == 1)
//         return LLRotation(p);
//     else if (balanceFactor == 2 && BalanceFactor(p->left) == -1)
//         return LRRotation(p);
//     else if (balanceFactor == -2 && BalanceFactor(p->right) == -1)
//         return RRRotation(p);
//     else if (balanceFactor == -2 && BalanceFactor(p->right) == 1)
//         return RLRotation(p);

//     return p;
// }

// int PrintSubtreeSum(struct Node* p, int x) {
//     if (p == NULL)
//         return 0;
//     else
//         return p->data + PrintSubtreeSum(p->left, x) + PrintSubtreeSum(p->right, x);
// }

// int main() {
//     int Q;
//     scanf("%d", &Q);

//     for (int i = 0; i < Q; i++) {
//         char query[10];
//         int x;

//         scanf("%s %d", query, &x);

//         if (strcmp(query, "insert") == 0) {
//             root = RInsert(root, x);
//             printf("%d %d\n", BalanceFactor(root->left), BalanceFactor(root->right));
//         } else if (strcmp(query, "subtree") == 0) {
//             struct Node* p = root;
//             while (p != NULL && p->data != x) {
//                 p = p->data > x ? p->left : p->right;
//             }

//             if (p == NULL)
//                 printf("NA\n");
//             else
//                 printf("%d\n", PrintSubtreeSum(p, x));
//         }
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Node {
//     struct Node* left;
//     long long data;
//     int height;
//     struct Node* right;
// } *root = NULL;

// int NodeHeight(struct Node* p) {
//     int hl, hr;
//     hl = p && p->left ? p->left->height : 0;
//     hr = p && p->right ? p->right->height : 0;

//     return hl > hr ? hl + 1 : hr + 1;
// }

// int BalanceFactor(struct Node* p) {
//     int hl, hr;
//     hl = p && p->left ? p->left->height : 0;
//     hr = p && p->right ? p->right->height : 0;

//     return hl - hr;
// }

// struct Node* LLRotation(struct Node* p) {
//     struct Node* pl = p->left;
//     struct Node* plr = pl->right;

//     pl->right = p;
//     p->left = plr;

//     p->height = NodeHeight(p);
//     pl->height = NodeHeight(pl);

//     if (root == p)
//         root = pl;

//     return pl;
// }

// struct Node* LRRotation(struct Node* p) {
//     struct Node* pl = p->left;
//     struct Node* plr = pl->right;

//     pl->right = plr->left;
//     p->left = plr->right;

//     plr->left = pl;
//     plr->right = p;

//     pl->height = NodeHeight(pl);
//     p->height = NodeHeight(p);
//     plr->height = NodeHeight(plr);

//     if (root == p)
//         root = plr;

//     return plr;
// }

// struct Node* RRRotation(struct Node* p) {
//     struct Node* pr = p->right;
//     struct Node* prl = pr->left;

//     pr->left = p;
//     p->right = prl;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);

//     if (root == p)
//         root = pr;

//     return pr;
// }

// struct Node* RLRotation(struct Node* p) {
//     struct Node* pr = p->right;
//     struct Node* prl = pr->left;

//     pr->left = prl->right;
//     p->right = prl->left;

//     prl->right = pr;
//     prl->left = p;

//     p->height = NodeHeight(p);
//     pr->height = NodeHeight(pr);
//     prl->height = NodeHeight(prl);

//     if (root == p)
//         root = prl;

//     return prl;
// }

// struct Node* RInsert(struct Node* p, int key, int* leftRotations, int* rightRotations) {
//     if (p == NULL) {
//         struct Node* t = (struct Node*)malloc(sizeof(struct Node));
//         t->data = key;
//         t->height = 1;
//         t->left = t->right = NULL;
//         return t;
//     }

//     if (key < p->data)
//         p->left = RInsert(p->left, key, leftRotations, rightRotations);
//     else if (key > p->data)
//         p->right = RInsert(p->right, key, leftRotations, rightRotations);

//     p->height = NodeHeight(p);
//     int balanceFactor = BalanceFactor(p);

//     if (balanceFactor == 2 && BalanceFactor(p->left) == 1) {
//         ++(*rightRotations);
//         return LLRotation(p);
//     } else if (balanceFactor == 2 && BalanceFactor(p->left) == -1) {
//         ++(*leftRotations);
//         ++(*rightRotations);
//         return LRRotation(p);
//     } else if (balanceFactor == -2 && BalanceFactor(p->right) == -1) {
//         ++(*leftRotations);
//         return RRRotation(p);
//     } else if (balanceFactor == -2 && BalanceFactor(p->right) == 1) {
//         ++(*leftRotations);
//         ++(*rightRotations);
//         return RLRotation(p);
//     }

//     return p;
// }

// long long PrintSubtreeSum(struct Node* p, long long x) {
//     if (p == NULL)
//         return 0;
//     else
//         return p->data + PrintSubtreeSum(p->left, x) + PrintSubtreeSum(p->right, x);
// }

// int main() {
//     int Q;
//     scanf("%d", &Q);

//     for (int i = 0; i < Q; i++) {
//         char query[10];
//         long long x;

//         scanf("%s %d", query, &x);

//         if (strcmp(query, "insert") == 0) {
//             int leftRotations = 0;
//             int rightRotations = 0;
//             root = RInsert(root, x, &leftRotations, &rightRotations);
//             printf("%d %d\n", leftRotations, rightRotations);
//         } else if (strcmp(query, "subtree") == 0) {
//             struct Node* p = root;
//             while (p != NULL && p->data != x) {
//                 p = p->data > x ? p->left : p->right;
//             }

//             if (p == NULL)
//                 printf("NA\n");
//             else
//                 printf("%lld\n", PrintSubtreeSum(p, x));
//         }
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node* left;
    long long data;
    int height;
    struct Node* right;
} *root = NULL;

int NodeHeight(struct Node* p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node* p) {
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}

struct Node* LLRotation(struct Node* p) {
    struct Node* pl = p->left;
    struct Node* plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node* LRRotation(struct Node* p) {
    struct Node* pl = p->left;
    struct Node* plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node* RRRotation(struct Node* p) {
    struct Node* pr = p->right;
    struct Node* prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node* RLRotation(struct Node* p) {
    struct Node* pr = p->right;
    struct Node* prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

struct Node* RInsert(struct Node* p, long long key, int* leftRotations, int* rightRotations) {
    if (p == NULL) {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }

    if (key < p->data)
        p->left = RInsert(p->left, key, leftRotations, rightRotations);
    else if (key > p->data)
        p->right = RInsert(p->right, key, leftRotations, rightRotations);

    p->height = NodeHeight(p);
    int balanceFactor = BalanceFactor(p);

    if (balanceFactor == 2 && BalanceFactor(p->left) == 1) {
        ++(*rightRotations);
        return LLRotation(p);
    } else if (balanceFactor == 2 && BalanceFactor(p->left) == -1) {
        ++(*leftRotations);
        ++(*rightRotations);
        return LRRotation(p);
    } else if (balanceFactor == -2 && BalanceFactor(p->right) == -1) {
        ++(*leftRotations);
        return RRRotation(p);
    } else if (balanceFactor == -2 && BalanceFactor(p->right) == 1) {
        ++(*leftRotations);
        ++(*rightRotations);
        return RLRotation(p);
    }

    return p;
}

long long PrintSubtreeSum(struct Node* p, long long x) {
    if (p == NULL)
        return 0;
    else
        return p->data + PrintSubtreeSum(p->left, x) + PrintSubtreeSum(p->right, x);
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        char query[10];
        long long x;

        scanf("%s %lld", query, &x);

        if (strcmp(query, "insert") == 0) {
            int leftRotations = 0;
            int rightRotations = 0;
            root = RInsert(root, x, &leftRotations, &rightRotations);
            printf("%d %d\n", leftRotations, rightRotations);
        } else if (strcmp(query, "subtree") == 0) {
            struct Node* p = root;
            while (p != NULL && p->data != x) {
                p = p->data > x ? p->left : p->right;
            }

            if (p == NULL)
                printf("NA\n");
            else
                printf("%lld\n", PrintSubtreeSum(p, x));
        }
    }

    return 0;
}
