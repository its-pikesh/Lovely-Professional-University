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

    msgId = msgget((key_t)13, 0666|IPC_CREAT);

    printf("Enter message: ");
    fflush(stdout);
    read(0, buff, sizeof(buff));

    msgsnd(msgId, &buff, strlen(buff), 0);
    printf("Message sent!\n");

    exit(EXIT_SUCCESS);
}