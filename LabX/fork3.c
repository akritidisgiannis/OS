#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
            return 0;
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        }
    }
    return 0;
}
