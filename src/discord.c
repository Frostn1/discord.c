#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../include/discord.h"
#include "../include/env.h"
#include "../include/dict.h"
struct _client Client() {
    struct _client newClient = {0};
    return newClient;
}

int main(int argc, char** argv, char** envio) {
    struct _env* currentEnv = Env_a("D:\\Programming\\Projects\\discord.c\\src\\e.env");
    currentEnv->config(currentEnv);
    char* key = get(currentEnv->currentDict, "DISCORDBOT_ID");
    printf("key is %s\n",key);
    return 0;
}