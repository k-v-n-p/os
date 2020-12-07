#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct mesgq
{
	long type;
	char text[200]; 
} mq;
int main()
{
	int msqid, len;
	key_t key = 2013;
	if ((msqid = msgget(key, 0644)) == -1)
		{
			printf("Server not active\n"); 
			exit(1);
		}
	printf("Client process to read:\n");
	while (msgrcv(msqid, &mq, sizeof(mq.text), 0, 0) != -1)
		{
			printf("Message recieved: \"%s\"\n", mq.text);
			fgets(mq.text, sizeof(mq.text),stdin); 
			len = strlen(mq.text);
			if (mq.text[len-1] == '\n')
			mq.text[len-1] = '\0';
			msgsnd(msqid, &mq, len+1, 0);
		}
	printf("Server Disconnected\n");
}
