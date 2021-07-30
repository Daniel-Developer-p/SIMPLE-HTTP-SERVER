#include <evhttp.h>

event_base * serv_base = (event_base *)event_init();

evvhttp * http_server = evhttp_new(serv_base);
evhttp_accept_socket(http_server, server_sock);
evhttp_set_cb(http_server, "/news", on_request_news, NULL);
evhttp_get_gencb(http_server, on_request, NULL);

event_base_dispatch(serv_base);

signal(SIGPIPE, SIG_IGN);