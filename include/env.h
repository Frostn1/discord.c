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

struct _env Env_e() {
    struct _env current;
    char filePath[_MAX_PATH];
    if(!_getcwd(filePath, sizeof(filePath))) {
        printf("_getcew error\n");
        exit(0);
    }
    strcpy(current.currentdir, filePath);
    current.currentDict = Dict();
    filedict(current.currentDict, filePath, '=', '\n');
}

struct _env Env_a(char* filePath) {
    struct _env current;
    strcpy(current.currentdir, filePath);
    current.currentDict = Dict();
    filedict(current.currentDict, filePath, '=', '\n');
}

char* grab(struct _env dispatcher,char* token) {

}


#define Env(...) OVERLOAD(Env, (__VA_ARGS__), \
    (Env_e, (void)), \
    (Env_a, (char*)), \
)

#define OVERLOAD_ARG_TYPES (void, char*)
#define OVERLOAD_FUNCTIONS (Env)
#endif // !ENV_H