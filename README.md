Force a program to use IPv4 or IPv6 by overriding getaddrinfo().

Example:

     $ force-inet4 curl -v http://www.google.de 2>&1 | grep 'Connected to'
     Connected to www.google.de (173.194.113.120) port 80 (#0)

Caveats
-------
Does not work with ping:

    $ getcap /usr/bin/ping
    /usr/bin/ping = cap_net_admin,cap_net_raw+ep

Credits
-------
Based on this gist by @winny-: https://gist.github.com/winny-/7367518
