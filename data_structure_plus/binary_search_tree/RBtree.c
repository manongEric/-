/*************************************************************************
	> File Name: binary_search_tree.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 May 2022 04:19:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct Node{
    int val, color;
    struct Node *lchild, *rchild;
}Node;
Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->val = -1;
    NIL->color = 1; // 0 Red, 1 black, 2 double black
    NIL->lchild = NIL->rchild = NIL;
    return;
}

Node *initNode(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->color = 0;
    n->lchild = n->rchild = NIL;
    return n;
}

Node *left_rotate(Node *root) {
    printf("left rotate %d\n", root->val);
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}
Node *right_rotate(Node *root) {
    printf("right rotate %d\n", root->val);
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

void output(Node *root) {
    if (root == NIL) return ;
    
    printf("(%d | %d, (%d, %d))\n", 
           root->val, root->color, 
           root->lchild->val, root->rchild->val);
    output(root->lchild);
    output(root->rchild);

}
char *maintain_str[] = {"", "LL", "LR", "RL", "RR"};
Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
        //situation 1
        printf("Situation 1 : change color\n");
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
    }
    if (root->lchild->color == 0 && !has_red_child(root->lchild)) return root;//红色孩子的那一边要继续有红色
    if (root->rchild->color == 0 && !has_red_child(root->rchild)) return root;
    //situation 2
    int Maintain_type = 0;
    printf("Situation 2\n");
    if (root->lchild->color == 0) {
        if (root->lchild->rchild->color== 0) {
            root->lchild = left_rotate(root->lchild);
            Maintain_type = 2;
        }else {
            Maintain_type = 1;
        }
            root = right_rotate(root);
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
            Maintain_type = 3;
        } else {
            Maintain_type = 4;
        }
        root = left_rotate(root);
    }
    printf("Maintain Type : %s\n", maintain_str[Maintain_type]);
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}
Node *__insertNode(Node *root, int val) {
    if (root == NIL)
        return initNode(val);
    if (root->val == val) return root;
    if (val > root->val)  root->rchild = __insertNode(root->rchild, val);
    else root->lchild = __insertNode(root->lchild, val);
    return insert_maintain(root);//回溯调整
}
Node *insertNode(Node *root, int val) {
    root = __insertNode(root, val);
    root->color = 1;
    return root;
}


Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) {
        printf("situation X : brother is red\n");
        int flag = 0;
        root->color = 0;
        if (root->lchild->color == 0) {//双黑节点的兄弟红色在左边
            root = right_rotate(root);
            flag = 0;
        } else {
            root = left_rotate(root);
            flag = 1;
        }
        root->color = 1;
        if (flag == 0) root->rchild = erase_maintain(root->rchild);//跟着双黑的方向走，右旋往右
        else root->lchild = erase_maintain(root->lchild);
        return root;
    }
    //situation 1
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) || 
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
            printf("situation 1 : change color done\n");
            root->color += 1;;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
    }
    //rl & rr & lr & ll
    int Maintain_type = 0;
    if (root->rchild->color == 2) {
        root->rchild->color = 1;
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = 1;
            Maintain_type = 2;
        } else {
            Maintain_type = 1;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    } else {
        root->lchild->color = 1;
        if (root->rchild->rchild->color != 0) {
            root->rchild->color = 0;
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = 1;
            Maintain_type = 3;
        } else {
            Maintain_type = 4;
        }
        root = left_rotate(root);
        root->color = root->lchild->color;
    }
    root->lchild->color = root->rchild->color = 1;
    printf("Maintain Type : %s\n", maintain_str[Maintain_type]);
    return root;
}
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}  
Node *__erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key > root->val) root->rchild = __erase(root->rchild, key);
    else if (key < root->val) root->lchild = __erase(root->lchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->val = temp->val;
            root->lchild = __erase(root->lchild, temp->val);
        }
    }
    return erase_maintain(root);
}
Node *erase(Node *root, int key) {
    printf("\nerase %d to RBtree\n", key);
    root = __erase(root, key);
    root->color = 1;
    output(root);
    return root;
}

Node *rand_insert(Node *root) {
    int val = rand() % 100;
    printf("\ninsert %d to RBtree\n", val);
    root = insertNode(root, val);
    output(root);
    return root;
}
void freeNode(Node *n) {
    if (n == NIL)
        return;
    freeNode(n->lchild);
    freeNode(n->rchild);
    free(n);
    return;
}

int main() {
    int a;
    srand(time(0));
    Node *root = NIL;
    scanf("%d", &a);
    for (int i = 0; i  < a; i++) {
        root = rand_insert(root);
    }
    while (~scanf("%d", &a)) {
        root = erase(root, a);
    }
    freeNode(root);
    return 0;
}
