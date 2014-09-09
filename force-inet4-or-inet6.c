/*
    force-inet4-or-inet6.c - hack to force applications to use IPv4 or IPv6 exclusively

    compilation: cc -fPIC -shared -DUSE_INET4 -o force-inet4.so force-inet4-or-inet6.c
                 cc -fPIC -shared -DUSE_INET6 -o force-inet6.so force-inet4-or-inet6.c

    usage: LD_PRELOAD=/path/to/library.so program args ...

    This file is in the public domain.
 */

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <dlfcn.h>
#include <stdio.h>

int
getaddrinfo(const char *hostname, const char *servname,
		const struct addrinfo *hints, struct addrinfo **res)
{
	int (*getaddrinfo_original)();
	struct addrinfo *hints2 = hints;

	getaddrinfo_original = dlsym(RTLD_NEXT, "getaddrinfo");
#if defined USE_INET4
	hints2->ai_family = PF_INET;
#elif defined USE_INET6
	hints2->ai_family = PF_INET6;
#else
#error You must define USE_INET4 or USE_INET6.
#endif

	printf("foo!\n");
	return (getaddrinfo_original(hostname, servname, hints2, res));
}
