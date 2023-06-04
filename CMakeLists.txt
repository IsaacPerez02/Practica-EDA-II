cmake_minimum_required(VERSION 3.24)
project(untitled4 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 sources/main.c headers/user.h sources/user.c headers/user_list.h sources/user_list.c sources/friends_stack.c headers/friends_stack.h sources/requests_queue.c headers/requests_queue.h sources/dicctionary_topic.c headers/dicctionary_topic.h sources/publications_users.c headers/publications_users.h sources/manage_requests_queue.c headers/manage_requests_queue.h)
