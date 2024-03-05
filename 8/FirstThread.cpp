#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

const int buf_size = 5000;

const char firtPipeName[] = "first.fifo";
const char secondPipeName[] = "second.fifo";

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Неверное количество аргументов!\n");
        return 0;
    }
    char str_buf[buf_size];

    mknod(firtPipeName, S_IFIFO | 0666, 0);
    mknod(secondPipeName, S_IFIFO | 0666, 0);

    int fd_read;

    (void)umask(0);

    if ((fd_read = open(argv[1], O_RDONLY, 0555)) < 0)
    {
        printf("Can\'t open reading file\n");
        exit(0);
    }

    // reading file
    int read_size = read(fd_read, str_buf, buf_size);

    if (read_size == -1)
    {
        printf("Can\'t read this file\n");
        exit(0);
    }

    int fd_write = 0;

    if ((fd_write = open(firtPipeName, O_WRONLY)) < 0)
    {
        printf("Can\'t open first pipe for writting\n");
        exit(0);
    }

    size_t size = write(fd_write, str_buf, read_size);

    if (size != read_size)
    {
        printf("Can\'t write all string to first pipe\n");
        exit(0);
    }
    if (close(fd_write) < 0)
    {
        printf("Can\'t close writing side of first pipe\n");
        exit(0);
    }
    if (close(fd_read) < 0)
    {
        printf("Can\'t close file\n");
    }

    if ((fd_read = open(secondPipeName, O_RDONLY)) < 0)
    {
        printf("Can\'t open second pipe\n");
        exit(0);
    }

    int size_read = read(fd_read, str_buf, buf_size);
    if (size_read < 0)
    {
        printf("Can\'t read string from second pipe\n");
        exit(0);
    }

    (void)umask(0);

    if ((fd_write = open(argv[1], O_WRONLY | O_CREAT, 0333)) < 0)
    {
        printf("Can\'t open file\n");
        exit(0);
    }

    int write_bytes = write(fd_write, str_buf, size_read);
    if (write_bytes == -1)
    {
        printf("Can\'t write this file\n");
        exit(0);
    }
    if (write_bytes != size_read)
    {
        printf("Can\'t write all string to second pipe\n");
        exit(0);
    }

    if (close(fd_read) < 0)
    {
        printf("Can\'t close reading side of second pipe\n");
        exit(-1);
    }
    if (close(fd_write) < 0)
    {
        printf("Can\'t close writting file\n");
    }
    printf("Everything is ok\n");
    return 0;
}