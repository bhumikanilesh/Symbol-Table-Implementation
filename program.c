#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define HASH_SIZE 100

typedef struct symbolentry{
    int value;
    char* name;
    struct symbolentry *next;

}symbolentry;

typedef struct symboltable{
    symbolentry *entries[HASH_SIZE];
}symboltable;

symboltable *scopestack[MAX_SIZE];
int top = -1;

int hash(const char* name){
    if (name == NULL) {
        return -1;
    }
    
    int hashval=0;
    for(;*name != '\0'; name++){
        hashval =(*name) + (31*hashval);
    }
    return hashval % HASH_SIZE;
}

symboltable *createsymboltable() {
    symboltable *newtable = (symboltable *)malloc(sizeof(symboltable));
    if (newtable == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        newtable->entries[i] = NULL;
    }
    return newtable;
}

void insert(const char *varname, int varvalue) {
    if (varname == NULL) {
        printf("ERROR: Variable name cannot be NULL\n");
        return;
    }
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    int hashvalue = hash(varname);
    symbolentry *entry = (symbolentry *)malloc(sizeof(symbolentry));
    if (entry == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    entry->value = varvalue;
    entry->name = strdup(varname);
    entry->next = scopestack[top]->entries[hashvalue];// basically insert at head
    scopestack[top]->entries[hashvalue] = entry;
}

void begin(){
    if(top == MAX_SIZE - 1 ){
        printf("overflow");
        return;
    }
    symboltable *newscope = createsymboltable();
    scopestack[++top]=newscope;
}

void end() {
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        symbolentry *entry = scopestack[top]->entries[i];
        while (entry != NULL) {
            symbolentry *temp = entry;
            entry = entry->next;
            free(temp->name);
            free(temp);
        }
    }
    free(scopestack[top--]);
}


symbolentry *lookup(const char *vname){
    int hashval = hash(vname);
    int found = 0;
    for(int i=top; i>=0; i--){
        symbolentry *entry = scopestack[i]->entries[hashval]; 
        while(entry != NULL){
            if(strcmp(entry->name,vname) == 0){
                return entry;
            }
            entry=entry->next;
        }
    }
    return NULL;
}

void print(const char* name){
    symbolentry *entry = lookup(name);
    if(lookup(name)!=NULL){
        printf("%s = %d\n", name, entry->value);
    }
    else{
        printf("ERROR: not found");
    }
}

int main() {
    
    printf("begin\n");
    begin();

    printf("assign a 1\n");
    insert("a", 1);

    printf("assign b 2\n");
    insert("b", 2);

    printf("begin\n");
    begin();

    printf("assign a 3\n");
    insert("a", 3);

    printf("assign c 4\n");
    insert("c", 4);

    printf("print b\n");
    print("b");

    printf("begin\n");
    begin();

    printf("assign c 5\n");
    insert("c", 5);

    printf("print b\n");
    print("b");

    printf("print a\n");
    print("a");

    printf("print c\n");
    print("c");

    printf("end\n");
    end();

    printf("print a\n");
    print("a");

    printf("print c\n");
    print("c");

    printf("end\n");
    end();

    printf("print a\n");
    print("a");

    end();

    return 0;
}