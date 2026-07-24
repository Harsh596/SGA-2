#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
void sigchld_handler(int sig) { while (waitpid(-1, NULL, WNOHANG) > 0); }
int main() {
    signal(SIGCHLD, sigchld_handler);
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process (PID: %d) simulating task...\n", getpid());
        sleep(20); exit(0);
    } else if (pid > 0) {
        sleep(2); 
        printf("Parent detected unresponsive child (PID: %d). Terminating...\n", pid);
        kill(pid, SIGTERM);
        sleep(1); printf("Cleanup complete.\n");
    }
    return 0;
}
