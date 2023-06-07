cmake_minimum_required(VERSION 3.24)
project(untitled4 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 sources/main.c headers/user.h sources/user.c headers/user_list.h sources/user_list.c sources/requests_queue.c headers/requests_queue.h sources/dicctionary_topic.c headers/dicctionary_topic.h sources/publications_users.c headers/publications_users.h sources/friends_graph.c headers/friends_graph.h headers/defines.h sources/requests_stack.c headers/requests_stack.h)
