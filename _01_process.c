#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("Original Parent PID = %d\n", getpid());
    for (int i = 0; i < 3; i++) {
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            return 1;
        }
        if (pid == 0) {
            // This is the CHILD process
            printf("Child %d: My PID = %d, My Parent PID = %d\n", i + 1, getpid(), getppid());
            return 0;
        }
    }
    for (i = 0; i < 3; i++) wait(NULL);
    printf("All children finished. Parent exiting.\n");
    return 0;
}
