#include "../include/env.h"

void config_env(struct _env* current) {
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