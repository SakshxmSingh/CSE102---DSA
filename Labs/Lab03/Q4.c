#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    char nData[20];
    struct BTNode *pLeft;
    struct BTNode *pRight;
} BTNode;

int StringCompare(char str1[20], char str2[20]){
    int i=0;
    while(str1[i]==str2[i] && str1[i]!='\0' && str2[i]!='\0'){
        i++;
    }
    if(str1[i]=='\0' && str2[i]=='\0'){
        return 0;
    }
    else if(str1[i]=='\0'){
        return -1;
    }
    else if(str2[i]=='\0'){
        return 1;
    }
    else if(str1[i]<str2[i]){
        return -1;
    }
    else{
        return 1;
    }
}

void StringCopy(char str1[20], char str2[20]){
    int i=0;
    while(str2[i]!='\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

int StringLength(char str[20]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int PrefixMatch(char *str1, char *str2, int PrefixLen) {
    int i;
    for (i = 0; i < PrefixLen && i < StringLength(str1) && i < StringLength(str2); i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

BTNode* InsertBSTRecur(BTNode* pRoot, char str[20]) {
    if (pRoot == NULL){
        pRoot = malloc(sizeof(BTNode));
        pRoot->pLeft = NULL;
        pRoot->pRight = NULL;
        StringCopy(pRoot->nData, str);
        return pRoot;
    }
    if (StringCompare(pRoot->nData, str) == 0) {
    return pRoot;
    }
    else if (StringCompare(pRoot->nData, str) == 1) {
        pRoot->pLeft = InsertBSTRecur(pRoot->pLeft, str);
    }
    else if (StringCompare(pRoot->nData, str) == -1) {
        pRoot->pRight = InsertBSTRecur(pRoot->pRight, str);
    }

    return pRoot;
}

void InOrderTraversal(BTNode* pRoot){
    if (pRoot != NULL) {
        InOrderTraversal(pRoot->pLeft);
        printf("%s\n", pRoot->nData);
        InOrderTraversal(pRoot->pRight);
    }
}

void SortMatches(char **matches, int matchCount) {
    for (int i = 0; i < matchCount - 1; i++) {
        for (int j = i + 1; j < matchCount; j++) {
            if (StringCompare(matches[i], matches[j]) > 0) {
                char temp[20];
                StringCopy(temp, matches[i]);
                StringCopy(matches[i], matches[j]);
                StringCopy(matches[j], temp);
            }
        }
    }
}

int FindPre(BTNode* pRoot, char pref[20], int PrefixLen, char **matches, int* matchCount) {
    if (pRoot == NULL) {
        return 0;
    }
    int cmp = PrefixMatch(pRoot->nData, pref, PrefixLen);
    if (cmp == 0) {
        return FindPre(pRoot->pLeft, pref, PrefixLen,matches,matchCount) || FindPre(pRoot->pRight, pref, PrefixLen, matches, matchCount);
    } else if (cmp < 0) {
        return FindPre(pRoot->pRight, pref, PrefixLen, matches, matchCount);
    } else {
        // printf("%s\n", pRoot->nData);
        // matches[*matchCount] = pRoot->nData;
        matches[*matchCount] = malloc(StringLength(pRoot->nData) + 1);
        StringCopy(matches[*matchCount], pRoot->nData);
        (*matchCount)++;
        FindPre(pRoot->pLeft, pref, PrefixLen, matches, matchCount);
        FindPre(pRoot->pRight, pref, PrefixLen, matches, matchCount);

        if (*matchCount == 0) {
            free(matches);
        }

        return 1;
    }
}

int DeletePre(BTNode **pRoot, char pref[20], int PrefixLen) {
    if (*pRoot == NULL) {
        return 0;
    }

    int deleted = 0;
    deleted += DeletePre(&((*pRoot)->pLeft), pref, PrefixLen);
    deleted += DeletePre(&((*pRoot)->pRight), pref, PrefixLen);

    if (PrefixMatch((*pRoot)->nData, pref, PrefixLen)) {
        BTNode *temp = *pRoot;
        *pRoot = (*pRoot)->pLeft; 
        free(temp); 
        deleted++;
    }

    return deleted;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    BTNode *pRoot = NULL;

    while(n--){
        char str[20];
        scanf("%s", str);
        pRoot = InsertBSTRecur(pRoot, str);
    }

    // InOrderTraversal(pRoot);

    while(q--){
        char pref[20], op[10];
        scanf("%s", op);

        if(StringCompare(op,"Find")==0){
            scanf("%s", pref);
            char **matches = malloc(100000 * sizeof(char*));
            int matchCount = 0;
            int found = FindPre(pRoot, pref, StringLength(pref), matches, &matchCount);
            if (!found) {
                printf("-1\n");
            }
            else {
                SortMatches(matches, matchCount);
                for (int i = 0; i < matchCount; i++) {
                    printf("%s\n", matches[i]);
                }
            }
            matchCount = 0;
            free(matches);
        }

        else if(StringCompare(op,"Delete")==0){
            scanf("%s", pref);
            int deleted = DeletePre(&pRoot, pref, StringLength(pref));
            if (deleted==0) {
                printf("-1\n");
            }
        }
        else if(StringCompare(op,"Print")==0){
            InOrderTraversal(pRoot);
        }
        else{
            printf("Invalid operation\n");
        }
    }

    return 0;
}
