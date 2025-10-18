// Author: Muhammad Shamoon Saleem
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include <syslog.h>

int main (int argc, char* argv[])
{
	//struct iovec iov[3];
	ssize_t nr;
	int fd;
	size_t count;
	
	openlog("writer", LOG_PID, LOG_USER);
	if (argc != 3) 
	{
          syslog(LOG_USER, "LOG_USER: Argument count = %d in file: %s", argc, __FILE__);
          closelog();
          return 1;
        }	
	fd = open (argv[1], O_WRONLY|O_CREAT | O_TRUNC , S_IRWXU);
	if (fd == -1) {
		perror ("open");
		syslog(LOG_ERR, "LOG_ERR: Error opening file %s", __FILE__);
		closelog();
		return 1;
	}
	if (fd == -1) {
		perror ("open");
		syslog(LOG_ERR, "LOG_ERR: Error opening file %s", __FILE__);
		closelog();
		return 1;
	}
	else if (fd != -1) 
	{
		syslog(LOG_DEBUG, "LOG_DEBUG: Opening file %s", __FILE__);
	}
	count = strlen (argv[2]);// + 1;
	nr = write(fd, argv[2], count);
	if (nr != -1)
	{
	syslog(LOG_DEBUG, "LOG_DEBUG: Writing %s to file %s", argv[2], __FILE__);
	}
	else if (nr == -1) 
	{
	  perror ("writer");
	  syslog(LOG_ERR, "LOG_ERR: Error writing to file  %s", __FILE__);
	  return 1;
	}
	
	printf("wrote %ld bytes\n", nr);
	if (close (fd) == -1) {
		perror ("close");
		printf("close fd \n");
		return 1;
	}
    closelog();
	return 0;
}
