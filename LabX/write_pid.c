#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "a");
    if (!file) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        fclose(file);
    } else if (pid > 0) {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
        fclose(file);
        wait(NULL);
    }
    return 0;
}
