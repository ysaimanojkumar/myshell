/* 
 * File:   myshell.h
 * Author: saimanoj
 *
 * Created on 23 October, 2012, 11:18 AM
 */

#ifndef MYSHELL_H
#define	MYSHELL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>
#include<string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <regex.h>
#include <errno.h>
#include <signal.h>
#include <sys/fcntl.h>

    typedef enum {
        false, true
    } boolean;

    struct component {
        char body[256]; //The string that represents the command of that component.
        char *args[16];
        boolean bg;
        boolean is_pipe;
        int input; //Source of input of this process
        int output; //Where output of this process should go
        
    };

    struct command {
        char command[64];
        boolean builtin;
    };

    struct process {
        pid_t pid;
        char command[50]; //command which generated it.
    } running_jobs[50], done[50];
    int num_running, num_done;

    char host_name[256], current_path[256], initial_path[256];
    size_t len;
    __uid_t uid;
    struct passwd *current_user;
    char user_name[256]; // Username of the current user
    char *home_dir; // Home directory of the current user.
    char *details; // Details of the current user.
    char *shell; // Details of the current user.
    __gid_t gid; // group id of the current user.
    boolean killed_bg_ps;



    void myshell_init();

    int myshell_exit(int status);

    char* rl_read();

    int validate_input(char input[]);

    int parse_input(char input[], struct component *components);

    int myshell_process(struct component *components, int count);

    int call_builtin(char command[], char *args[]);

    int myshell_spawn(char *args[], boolean bg, int input, int output);

    int cd(char *args[]);

    int jobs();

    void handler(int sig);

#ifdef	__cplusplus
}
#endif

#endif	/* MYSHELL_H */

