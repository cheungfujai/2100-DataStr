#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10

typedef struct {
    int key;         // in this example, key is some long id
    char* value;     // value is a string
} KeyValuePair;

void printHashtable(KeyValuePair* table[]) {
    // print out the hash table so that you will see if you have done
    // things correctly!
    
    int i;
    for (i=0;i<HASHTABLE_SIZE;i++) {
        if (table[i] == NULL) {
            printf("%2d: -\n",i);
        } else {
            printf("%2d: <%d,%s>\n",i,table[i]->key,table[i]->value);
        }
    }
}

int hashFunc(int key) {
    // turns the key into hash and returns it
    return (5 * key % 11) % HASHTABLE_SIZE;   // a very bad hash function
}



void insert(KeyValuePair* table[], int key, char value[]) {
    // insert a key and value
    printf("inserting %d,%s to the table...\n",key, value);
    int hash = hashFunc(key);
    int index = hash;
    while (table[index] != NULL) {
        index++;
        if (index > 9){
            index = 0;
        }
        printf("/////// collision! I refuse to do anything!\n\n");
        // return;
    }
    
    // add the new key-value pair to the correct position
    printf("Entry inserted at position %d\n\n",index);
    KeyValuePair* newEntry = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    newEntry->key = key;
    newEntry->value = value;
    table[index] = newEntry;
    
}


char* lookup(KeyValuePair *table[], int key) {
    // look up a key and return the value
    int hash = hashFunc(key);
    int index = hash;
    if (table[index] != NULL) {
        if (table[index]->key == key)
            return table[index]->value;
        else
            // collision happened? should we do something?
            return NULL;
    } else {
        return NULL;
    }
}

int main()
{
    
    KeyValuePair* hashtable[HASHTABLE_SIZE] = {NULL};
    
    insert(hashtable,1450017, "Ted");
    insert(hashtable,1450345, "Jerry");
    insert(hashtable,1450191, "Bill");
    insert(hashtable,1450677, "Perry");
    insert(hashtable,1450922, "Claire");
    insert(hashtable,1450957, "Arthur");
    
    printHashtable(hashtable);
    
    printf("Lookup %d - result: %s\n", 1450017, lookup(hashtable,1450017));
    printf("Lookup %d - result: %s\n", 9999999, lookup(hashtable,9999999));
    printf("Lookup %d - result: %s\n", 1450677, lookup(hashtable,1450677));
    printf("Lookup %d - result: %s\n", 1450957, lookup(hashtable,1450957));
    
    return 0;
}
