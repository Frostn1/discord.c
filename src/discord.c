#include <stdio.h>
#include "../include/discord.h"
#include "../include/env.h"
#include "../include/dict.h"
struct _client Client() {
    struct _client newClient;
    return newClient;
}

int main(int argc, char** argv, char** envio) {
    struct _env* currentEnv = Env_a("D:\\Programming\\Projects\\discord.c\\src\\e.env");
    char* key = get(currentEnv->currentDict, "DISCORDBOT_ID");
    printf("key is %s\n",key);
    free(key);
    return 0;
}