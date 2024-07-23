#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

int main(){
    char data[1024];
    char dev[] = "/dev/ttyACM0";
    int fd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
    fcntl(fd, F_SETFL, FNDELAY);
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag |= CS8;
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tcsetattr(fd, TCSANOW, &options);
    ioctl(fd, TCFLSH, 2);
    while(1){
        read(fd, data, sizeof(data));
        printf("%s\n", data);
    }
    //write(fd, data, sizeof(data));
}
