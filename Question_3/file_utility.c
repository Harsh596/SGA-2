#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    int fd = open("database.dat", O_CREAT | O_RDWR, 0600);
    write(fd, "Record_A", 8);
    lseek(fd, 0, SEEK_SET); 
    write(fd, "Record_B", 8); 
    lseek(fd, 0, SEEK_SET); 
    char buffer[9];
    read(fd, buffer, 8);
    buffer[8] = '\0';
    printf("Read from disk: %s\n", buffer);
    close(fd);
    return 0;
}
