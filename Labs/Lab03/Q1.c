#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int dirnum;
    char name[5];
    struct Node* nextdirs[20];
    struct Node* prev;
}Node;

int LinearSearchNode(Node* A[], char dirname[5], int size){
    // int flag = 0;
    for(int i=0; i<size; i++){
        if(A[i]==NULL){
            continue;
        }
        if(strcmp(dirname,A[i]->name)==0){
            return i;
            break;
        }
    }
    return -1;
}

void pwd(Node* curr){
    char str[500] = "";
    char result[500];
    // char temp[5];
    // strcpy(temp,curr->name);
    while(curr!=NULL){
        if (strlen(str) == 0) {
            sprintf(result, "%s", curr->name);
        }
        else{
            sprintf(result, "%s/%s", curr->name,str);
        }
        strcpy(str,result);
        curr = curr->prev;
    }
    // strcat(str,temp);
    printf("%s\n",str);
}

void ls(Node* curr){
    for(int i=0; i<curr->dirnum; i++){
        Node* temp = curr->nextdirs[i];
        printf("%s ",temp->name);
    }
    printf("\n");
}

// void cd(Node** curr, char dirname[5]){
//     if(strcmp(dirname,"..")==0){
//         if(curr->prev!=NULL){
//             curr = curr->prev;
//         }
//         else {
//             printf("-1\n");
//         }
//     }
//     else{
//         int index = LinearSearchNode(curr->nextdirs,dirname,curr->dirnum);
//         if(index==-1){
//             printf("-1\n");
//         }
//         else{
//             curr = curr->nextdirs[index];
//         }
//     }
// }

void cd(Node** curr, char dirname[5]){
    if(strcmp(dirname,"..")==0){
        if((*curr)->prev!=NULL){
            *curr = (*curr)->prev;
        }
        else {
            printf("-1\n");
        }
    }
    else{
        int index = LinearSearchNode((*curr)->nextdirs,dirname,(*curr)->dirnum);
        if(index==-1){
            printf("-1\n");
        }
        else{
            *curr = (*curr)->nextdirs[index];
        }
    }
}

void mkdir(Node* curr, char dirname[5]){
    int index = LinearSearchNode(curr->nextdirs,dirname,curr->dirnum);
    if(index != -1){
        printf("-1\n");
        return;
    }
    if(curr->dirnum<20){

        Node* new_dir = malloc(sizeof(Node));
        new_dir->dirnum=0;
        new_dir->prev=curr;
        memset(new_dir->nextdirs, 0, sizeof(new_dir->nextdirs));
        strcpy(new_dir->name,dirname);

        curr->nextdirs[curr->dirnum]=new_dir;
        curr->dirnum+=1;
        return;
    }

    else{
        printf("-1\n");
        return;
    }
}

void rm(Node** curr, char dirname[5]){
    if ((*curr)->dirnum>0){
        int index = LinearSearchNode((*curr)->nextdirs,dirname,(*curr)->dirnum);
        // printf("%d\n",index);
        if(index==-1){
            printf("-1\n");
            return;
        }
        else{
            Node* dir_to_delete = (*curr)->nextdirs[index];

            for (int i = index; i < (*curr)->dirnum - 1; i++) {
                (*curr)->nextdirs[i] = (*curr)->nextdirs[i+1];
            }

            (*curr)->nextdirs[(*curr)->dirnum - 1] = NULL;
            (*curr)->dirnum--;
        }
    }
    else{
        printf("-1\n");
        return;
    }
}

// void rm(Node* curr, char dirname[5]){
//     int index = LinearSearchNode(curr->nextdirs,dirname,curr->dirnum);
//     if (index==-1){
//         printf("-1\n");
//         return;
//     }

//     Node* dir_to_delete = curr->nextdirs[index];

//     // recursively delete all subsequent directories within
//     // for (int i=0; i<dir_to_delete->dirnum; i++){
//     //     rm(dir_to_delete, dir_to_delete->nextdirs[i]->name);
//     // }

//     // delete current directory
//     free(dir_to_delete);
//     curr->nextdirs[index] = NULL;
//     curr->dirnum--;
// }

int main(){
    int n, q;
    scanf("%d", &n);

    Node* root = (Node*)malloc(sizeof(Node));
    strcpy(root->name,"root");
    root->prev=NULL;
    root->dirnum=0;
    // root->nextdirs = malloc(20*sizeof(Node));
    Node* current = root;

    while(n--){
        char dir[20], op[20];
        scanf("%d", &q);

        if(q==1){
            scanf("%s",op);
            
            //pwd
            if(strcmp(op,"pwd")==0) pwd(current);
            //ls
            else if (strcmp(op,"ls")==0) ls(current);
        }

        else if(q==2){
            scanf("%s %s",op,dir);

            //cd
            if(strcmp(op,"cd")==0) cd(&current,dir);
            //mkdir
            else if(strcmp(op,"mkdir")==0) mkdir(current, dir);
        }

        else if(q==3){
            char temp[2];
            scanf("%s %s %s",op,temp,dir);

            //rm
            if(strcmp(op,"rm")==0) rm(&current,dir);
        }

        if (n == 0) {
        break;
        }
    }
    return 0;
}
