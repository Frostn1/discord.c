#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "discord.h"
#include "env.h"
#include "dict.h"
struct _client Client() {
    struct _client newClient = {0};
    return newClient;
}

int main(int argc, char** argv, char** envio) {
    struct _env* currentEnv = Env_a("D:\\Programming\\Projects\\discord.c\\src\\e.env");
    char* key = get(currentEnv->currentDict, "DISCORDBOT_ID");
    printf("key is %s\n",key);
    return 0;
}