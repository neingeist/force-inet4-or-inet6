.PHONY: all
all: force-inet4.so force-inet6.so

.PHONY: install
install: all
	install force-inet4.so /usr/local/lib/
	install force-inet6.so /usr/local/lib/
	install force-inet4 /usr/local/bin/
	install force-inet6 /usr/local/bin/

.PHONY: clean
clean:
	rm -f *.so

force-inet4.so: force-inet4-or-inet6.c
	$(CC) -fPIC -shared -DUSE_INET4 -o $@ $^

force-inet6.so: force-inet4-or-inet6.c
	$(CC) -fPIC -shared -DUSE_INET6 -o $@ $^
