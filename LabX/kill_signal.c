#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, handle_signal);
        pause(); // Wait for signal
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Ensure child is ready
        kill(pid, SIGUSR1);
        wait(NULL);
    }
    return 0;
}
