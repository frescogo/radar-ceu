#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

int main (void) {
    int fd = open("/dev/ttyACM0", O_RDONLY);
    assert(fd != -1 && "serial error");
    //close(fd);
    {
        int flags = fcntl(fd, F_GETFL, 0);
        int ok    = fcntl(fd, F_SETFL, flags|O_NONBLOCK);
        assert(ok == 0 && "serial error");
    }
    {
        struct termios options;
        tcgetattr(fd, &options);
        cfsetispeed(&options, B9600);
        cfsetospeed(&options, B9600);
    //}
    //{
        //options.c_cflag |= CS8;
        options.c_cflag |= CS8;
        options.c_cflag &= ~CRTSCTS;
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
        tcsetattr(fd, TCSANOW, &options);
        ioctl(fd, TCFLSH, 2);
    }

    while (1) {
        char c;
        int ret = read(fd,&c,1);
//printf(">>> %d : %d : %d : %d\n", errno, ret, c, EAGAIN);
if (ret<0 && errno!=EAGAIN) {
    printf("%s\n", strerror(errno));
}
        assert((ret>=0 || errno==EAGAIN) && "serial error");
        if (ret == 1) {
            putchar(c);
            fflush(stdout);
        }
    }
}
