#include <stdio.h>
#include <unistd.h>
extern char **environ;
int main(){
	char **env=environ;
	int i=0;
	while (*env) {
        	printf("%s\n", *env);
        	env++;
    }
}