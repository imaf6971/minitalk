SERVERNAME		=	server
CLIENTNAME		=	client

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

HEADER			=	minitalk.h

SERVERSRCS 		=	server.c puts.c
CLIENTSRCS		=	client.c puts.c

SERVEROBJ		=	$(patsubst %.c, %.o, $(SERVERSRCS))
CLIENTOBJ		=	$(patsubst %.c, %.o, $(CLIENTSRCS))

.PHONY			:	all clean fclean re

all				:	$(SERVERNAME) $(CLIENTNAME)

$(SERVERNAME)	:	$(SERVEROBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SERVEROBJ) -I $(HEADER) -o $(SERVERNAME)

$(CLIENTNAME)	:	$(CLIENTOBJ) $(HEADER)
	$(CC) $(CFLAGS) $(CLIENTOBJ) -I $(HEADER) -o $(CLIENTNAME)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SERVEROBJ) $(CLIENTOBJ)

fclean:
	@rm -f $(SERVEROBJ) $(CLIENTOBJ) $(SERVERNAME) $(CLIENTNAME)

re:	fclean $(SERVERNAME) $(CLIENTNAME)
