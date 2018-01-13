#include <stdio.h>
#include <unistd.h>

int main() {
	int pid = fork();
	if (pid == 0) {
		int pid1 = fork();
		if (pid1 == 0){
			printf("Launching ps -ef\n");
			char *args[]= { "/bin/ps", "-ef" , NULL};
			execvp("/bin/ps", args);
			printf("Finished launching ps -ef\n");
		}
		else{
			printf("Launching free -h\n");
			char *args[]= { "free", "-h" , NULL};
			execvp("free", args);
			printf("Finished launching free -h\n");
		}
	}	
	return 0;
}
