#include <stdio.h>
#include "../include/discord.h"

void onOverload(struct _client* client) {
    printf("ready");
}

int main(int argc, char** argv, char** envio) {
    struct _env* currentEnv = Env_a("D:\\Programming\\Projects\\discord.c\\src\\e.env");
    currentEnv->config(currentEnv);
    struct _client* newClient = Client();
    newClient->on(newClient, "ready", onOverload);
    return 0;
}