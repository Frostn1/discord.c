#ifndef ENV_H
#define ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <direct.h>
#include "dict.h"

typedef struct _env {
    char* currentdir;
    struct _dict* currentDict;
    // Dict of keys and values
}env;

struct _env* Env_e() {
    struct _env* current = (struct _env*)malloc(sizeof(struct _env));
    char filePath[_MAX_PATH];
    if(!_getcwd(filePath, sizeof(filePath))) {
        printf("_getcwd error\n");
        exit(0);
    }
    strcpy(current->currentdir, filePath);
    current->currentDict = Dict();
    filedict(current->currentDict, current->currentdir, '=', '\n');
    return current;
}

struct _env* Env_a(char* filePath) {
    if(!strcmp(filePath, "")) {
        return Env_e();
    }
    struct _env* current = (struct _env*)malloc(sizeof(struct _env));
    strcpy(current->currentdir, filePath);
    current->currentDict = Dict();
    filedict(current->currentDict, filePath, '=', '\n');
    return current;
}

char* grab(struct _env dispatcher,char* token) {
    return get(dispatcher.currentDict, token);
}

#endif // !ENV_H