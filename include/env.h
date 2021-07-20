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

void config_env(struct _env* current);
struct _env* Env_a(char* filePath);
char* grab(struct _env dispatcher,char* token);

#endif // !ENV_H