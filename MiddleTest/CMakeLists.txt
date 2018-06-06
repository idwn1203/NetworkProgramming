set(CMAKE_BUILD_TYPE Debug)
add_executable(C_tcp Tcp_client.c)
add_executable(C_udp udp_client.c)
add_executable(server server.c)
