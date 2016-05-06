/*
** rootbash.h for ROOTBASH in /home/schlipak/misc/c/rootbash
**
** Made by Guillaume de Matos
** Login   <de-mat_b@epitech.net>
**
** Started on  Sun May  1 19:54:41 2016 Guillaume de Matos
** Last update Sun May  1 20:52:45 2016 Guillaume de Matos
*/

#pragma             once

#include            <stdio.h>
#include            <stdlib.h>
#include            <sys/types.h>
#include            <unistd.h>
#include            <errno.h>
#include            <string.h>

static const char   *SHELLS_PATH = "/etc/shells";
static const char   *DEFAULT_PATH = "/bin/bash";

static const char   *MSG_USAGE = "USAGE: %s [PATH_TO_SHELL]\n";

static const char	*ERR_ISROOT = "No need to \x1b[1;31mroot\x1b[0m, bby ;)";
static const char   *ERR_NOTSHELL = "%s: Error: %s is not a registered shell\n";
