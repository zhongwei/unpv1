#ifndef	__unp_h
#define	__unp_h

#include	<sys/types.h>	/* basic sytem data types */
#include	<sys/socket.h>	/* basic socket definitions */

#if TIME_WITH_SYS_TIME
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselec() */
#else
#if HAVE_SYS_TIME_H
#include	<sys/time.h>	/* includes <time.h> unsafely */
#else
#include	<time.h>		/* old system? */
#endif
#endif

#include	<netinet/in.h>	/* sockaddr_in{} and other Internaet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>		/* for Unix domain sockets */

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
 * kernels still #define it as 5, while actually supporting many more */
#define LISTENQ		1024	/* 2nd argument to listen() */

/* Miscellaneous constants */
#define MAXLINE		4096	/* max text line length */
#define BUFFSIZE	8192	/* buffer size for reads and writes */

#define	SA	struct sockaddr

			/* prototypes for out socket wrapper functions: see {Sec errors} */
int		Accept(int, SA *, socklen_t *);
void	Bind(int, const SA *, socklen_t);
void	Connect(int, const SA *, socklen_t);
void	Listen(int, int);
int		Socket(int, int, int);

void	err_sys(const char *, ...);

#endif	/* __unp_h */

