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

int main()
{
    int result;
    char str_buf[buf_size];

    mknod(firtPipeName, S_IFIFO | 0666, 0);
    mknod(secondPipeName, S_IFIFO | 0666, 0);

    int fd_read = 0;
    if ((fd_read = open(firtPipeName, O_RDONLY)) < 0)
    {
        printf("third thread: Can\'t open file\n");
        exit(0);
    }
    int size_read = read(fd_read, str_buf, buf_size);
    if (close(fd_read) < 0)
    {
        printf("thread 2: Can\'t close reading side of pipe 1\n");
        exit(0);
    }
    if (size_read < 0)
    {
        printf("second thread: Can\'t read string from pipe 2\n");
        exit(0);
    }
    char word[size_read];
    int wordLength = 0;
    for (size_t i = 0; i < size_read; i++)
    {
        if (str_buf[i] == '\b' || str_buf[i] == ' ' || str_buf[i] == '\t' || str_buf[i] == '\n')
        {
            for (size_t j = wordLength; j > 0; j--)
            {
                str_buf[i - j] = word[j - 1];
            }
            wordLength = 0;
            continue;
        }
        else
        {
            word[wordLength] = str_buf[i];
            ++wordLength;
        }
    }
    for (size_t j = wordLength; j > 0; j--)
    {
        str_buf[size_read - j] = word[j - 1];
    }
    int fd_write = 0;
    if ((fd_write = open(secondPipeName, O_WRONLY)) < 0)
    {
        printf("third thread: Can\'t open file\n");
        exit(0);
    }
    int size_write = write(fd_write, str_buf, size_read);
    if (size_write != size_read)
    {
        printf("thread 2: Can\'t write all string to pipe\n");
        exit(0);
    }
    if (close(fd_write) < 0)
    {
        printf("thread 2: Can\'t close writing side of pipe\n");
        exit(0);
    }
    printf("finish");
    return 0;
}