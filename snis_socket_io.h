/*

Copyright (c) 2010 Stephen M. Cameron 

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */
#ifndef __SNIS_SOCKET_IO_H__
#define __SNIS_SOCKET_IO_H__

#ifdef DEFINE_SNIS_SOCKET_IO_GLOBALS
#define GLOBAL
#else
#define GLOBAL extern
#endif

struct network_stats {
	uint64_t bytes_sent;
	uint64_t bytes_recd;
	struct timeval start;
	uint32_t nobjects, nships;
};

/* Functions to read/write from a socket, restarting if EINTR... */
GLOBAL int snis_readsocket(int fd, void *buffer, int buflen);
GLOBAL int snis_writesocket(int fd, void *buffer, int buflen);
GLOBAL void ignore_sigpipe(void);
GLOBAL void snis_collect_netstats(struct network_stats *ns);
GLOBAL void snis_protocol_debugging(int enable);
GLOBAL void snis_print_last_buffer(char *title, int socket);
#undef GLOBAL
#endif

 
