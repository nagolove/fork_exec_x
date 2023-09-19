#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>

int main() {

    char ** line = __environ;
    while (*line) {
        printf("%s\n", *line);
        line++;
    }
    //return;
    // */

    printf("hi\n");

    pid_t ret = fork();

    printf("aloha\n");

    if (ret == -1) {
        printf("fork() is failed\n");
        exit(EXIT_FAILURE);
    }

    const char *display = getenv("DISPLAY");
    printf("DISPLAY '%s'\n", display);

    const char *xauth = getenv("XAUTHORITY");

    char buf_display[64] = {};
    sprintf(buf_display, "DISPLAY=%s", display);

    char buf_auth[64] = {};
    sprintf(buf_auth, "XAUTHORITY=%s", xauth);


    if (!ret) {
        execve(
            "/usr/bin/rofi",
            (char *const []){ "-show", "window", NULL },
            (char *const []){ buf_display, buf_auth, NULL }
            //(char *const []){ "DISPLAY=:0" , NULL }
            //(char *const []){ ":0" , NULL }
            //__environ
        );
    }
    //getenv();
    
    while (true) {
        //printf("hi\n");
    }

    return EXIT_SUCCESS;
}
