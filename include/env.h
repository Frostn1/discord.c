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
    void (*config)(struct _env*);
    // Dict of keys and values
}env;

void config_env(struct _env* current) {
    printf("got here\n");
    filedict(current->currentDict, current->currentdir, '=', '\n');
}

struct _env* Env_a(char* filePath) {
    struct _env* current = (struct _env*)malloc(sizeof(struct _env));
    if(!strcmp(filePath, "")) {
        char filePath[_MAX_PATH];
        if(!_getcwd(filePath, sizeof(filePath))) {
            printf("_getcwd error\n");
            exit(0);
        }
    }
    current->currentdir = (char*)malloc(sizeof(char) * (strlen(filePath) + 1));
    strcpy(current->currentdir, filePath);
    current->currentDict = Dict();
    current->config = &config_env;
    return current;
}

char* grab(struct _env dispatcher,char* token) {
    return get(dispatcher.currentDict, token);
}

#endif // !ENV_H