#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int dirnum;
    char name[100];
    struct Node* nextdirs[20];
    struct Node* prev;
}Node;

void sort_strings(char names[20][100], int n) {
    int i, j;
    char temp[100];

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(names[j], names[j+1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
}

int LinearSearchNode(Node* A[], char dirname[100], int size){
    // int flag = 0;
    for(int i=0; i<size; i++){
        // if(A[i]==NULL){
        //     continue;
        // }
        if(strcmp(dirname,A[i]->name)==0){
            return i;
        }
    }
    return -1;
}

void pwd(Node* curr){
    char str[500000] = "";
    char result[500000];
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
    char names[20][100];
    for(int i=0; i<curr->dirnum; i++){
        Node* temp = curr->nextdirs[i];
        strcpy(names[i],temp->name);
        // Node* temp = curr->nextdirs[i];
        // printf("%s ",temp->name);
    }

    // sort_strings(names,curr->dirnum);
    int i, j;
    char temp[100];

    for (i = 0; i < curr->dirnum-1; i++) {
        for (j = 0; j < curr->dirnum-i-1; j++) {
            if (strcmp(names[j], names[j+1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }

    for(int i=0; i<curr->dirnum; i++){
        printf("%s ",names[i]);
    }
    printf("\n");
}

void cd(Node** curr, char dirname[100]){
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

void mkdir(Node* curr, char dirname[100]){
    if(curr->dirnum<20 && LinearSearchNode(curr->nextdirs,dirname,curr->dirnum)==-1){

        Node* new_dir = malloc(sizeof(Node));
        new_dir->dirnum=0;
        new_dir->prev=curr;
        memset(new_dir->nextdirs, 0, sizeof(new_dir->nextdirs));
        strcpy(new_dir->name,dirname);

        curr->nextdirs[curr->dirnum]=new_dir;
        curr->dirnum++;
        return;
    }

    else{
        printf("-1\n");
        return;
    }
}

Node* rm(Node* curr, char dirname[100]) {
    int index = LinearSearchNode((curr)->nextdirs, dirname, (curr)->dirnum);

    if (index == -1) {
        printf("-1\n");
        return curr;
    }

    Node* dir_to_delete = malloc(sizeof(Node));
    dir_to_delete = (curr)->nextdirs[index];

    // if (dir_to_delete->dirnum > 0) {
    //     for (int i = 0; i < dir_to_delete->dirnum; i++) {
    //         rm(&(dir_to_delete->nextdirs[i]), dir_to_delete->nextdirs[i]->name);
    //     }
    // }

    for (int i = index; i < (curr)->dirnum - 1; i++) {
        Node* temp = malloc(sizeof(Node));
        temp = ((curr)->nextdirs[i + 1]);
        (curr)->nextdirs[i] = temp;
        printf("%s ", (curr)->nextdirs[i]->name);
    }
    (curr)->nextdirs[(curr)->dirnum - 1] = NULL;
    (curr)->dirnum = (curr)->dirnum - 1;
    // free(dir_to_delete);

    return curr;
}

// void rm_2(Node* arr[20], int *len, int index, Node* temp[20]){
//     if (index == -1 || index >= *len) {
//         printf("-1\n");
//         return;
//     }

//     for(int i=index; i<*len-1; i++){
//         Node temp_2 = *arr[i+1];
//         arr[i] = &temp_2;
//     }
//     *len = *len - 1;
    
//     for(int i = 0; i<*len; i++){
//         temp[i]= arr[i];
//         // printf("%s ", temp[i]->name);
//     }
//     // printf("\n");
//     return;
// }

// void rm_2(Node** arr, int *len, int index, Node** temp){
//     if (index == -1 || index >= *len) {
//         printf("-1\n");
//         return;
//     }

//     for(int i=index; i<*len-1; i++){
//         Node* temp_2 = arr[i+1];
//         arr[i] = temp_2;
//     }
//     *len = *len - 1;

//     // allocate memory for the temp array
//     Node** new_temp = malloc((*len) * sizeof(Node*));

//     // copy the pointers to the new temp array
//     for(int i = 0; i<*len; i++){
//         new_temp[i]= arr[i];
//     }

//     // free the old temp array and set the new temp array
//     free(temp);
//     *temp = new_temp;

//     return;
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
        char op[20];
        char *dir_3;
        char dir[100];

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

            // free(dir);
        }

        else if(q==3){
            char temp[2];
            scanf("%s %s %s",op,temp,dir);

            //rm
            if(strcmp(op,"rm")==0) {
                (current) = rm(current,dir);
                // Node** temp = malloc((current->dirnum) * sizeof(Node*));
                // for(int i = 0; i<current->dirnum; i++){
                //     temp[i] = current->nextdirs[i];
                // }
                // rm_2(temp, &(current->dirnum), LinearSearchNode(current->nextdirs, dir, current->dirnum), &temp);
                // for(int i = 0; i<current->dirnum; i++){
                //     current->nextdirs[i] = temp[i];
                // }
            }
            // scanf("rm -r %s", dir_3);
            // rm(&current, dir_3);
        }
    }
    return 0;
}