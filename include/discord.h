#ifndef DISCORD_H
#define DISCORD_H
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <direct.h>
#include <limits.h>
#include <Windows.h>
#include "env.h"
#include "dict.h"


typedef struct _client {
    void (*on)(struct _client*, char* ,void(*)(struct _client*));
} client;

typedef void(*onFunction)(struct _client*);

struct _client* Client();
void on_f(struct _client*, char*, onFunction);

#endif // !DISCORD_H