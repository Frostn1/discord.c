#ifndef DICT_H
#define DICT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Find a way to compare types when adding pairs to the dict
// typedef struct _value {
//     void* data;
//     char* type;
// } value;
// typedef struct _dict {
//     char** keys;
//     struct _value* values;
// } dict;
// struct _dict Dict(char* valuetype) {
//     struct _dict newDict;
    
// }

typedef struct _dict {
    char** _keys;
    char** _values;
    int _size;
} dict;

struct _dict* Dict() {
    struct _dict* newDict = (struct _dict*)malloc(sizeof(struct _dict));
    newDict->_keys = (char**)malloc(sizeof(char));
    newDict->_values = (char**)malloc(sizeof(char));
    newDict->_size = 0;
    return newDict;
}

void add(struct _dict* dict, char* key,char* value) {
    if(!strcmp(key, "")) {
        printf("dict error : key empty\n");
        exit(0);
    }
    if(has(dict, key)) {
        printf("dict error : key exists\n");
        exit(0);
    }
    dict->_keys = (char**)realloc(dict->_keys,sizeof(char)*(dict->_size+1));
    dict->_keys[dict->_size] = (char*)malloc(sizeof(char)*strlen(key));
    dict->_values = (char**)realloc(dict->_keys,sizeof(char)*(dict->_size+1));
    dict->_values[dict->_size] = (char*)malloc(sizeof(char)*strlen(value));
    strcpy(dict->_keys[dict->_size], key);
    strcpy(dict->_values[dict->_size], value);

}
int has(struct _dict* dict, char* key) {
    for (int i = 0; i < dict->_size; i++)
        if(!strcmp(dict->_keys[i], key)) return 1;
    return 0;
    
}
char* get(struct _dict* dict, char* key) {
    if(!strcmp(key, "")) {
        printf("dict error : key empty\n");
        exit(0);
    }
    if(!has(dict, key)) {
        printf("dict error : key doesn't exists\n");
        exit(0);
    }
    for (int i = 0; i < dict->_size; i++)
        if(!strcmp(dict->_keys[i], key)) return dict->_values[i];
}
#endif // !DICT_H