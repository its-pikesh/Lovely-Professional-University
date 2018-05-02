#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>


int main() {
    int msgId;
    char buff[100];

    msgId = msgget((key_t)13, 0666);
    printf("Message read from queue is: ");
    msgrcv(msgId, &buff, sizeof(buff), 0, 0);
    printf("%s", buff);

    exit(EXIT_SUCCESS);
}