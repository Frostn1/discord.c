#include "../include/discord.h"

void on_f(struct _client* client, char* command, onFunction func) {
    command = lower(command);
    if(!strcmp(command, "")) {
        printf("on error : command empty");
        exit(0);
    } else if(!strcmp(command, "ready")) {
        func(client);
    }
}
struct _client* Client() {
    struct _client* newClient = (struct _client*)malloc(sizeof(struct _client));
    newClient->on = &on_f;
    return newClient;
}

