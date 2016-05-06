/*
** rootbash.c for ROOTBASH in /home/schlipak/misc/c/rootbash
**
** Made by Guillaume de Matos
** Login   <de-mat_b@epitech.net>
**
** Started on  Sun May  1 19:55:23 2016 Guillaume de Matos
** Last update Sun May  1 20:52:32 2016 Guillaume de Matos
*/

#include        "rootbash.h"

int             parse_args(int ac, char **av)
{
  if (ac > 2 || (ac == 2 && strcmp(av[1], "-h") == 0))
    {
      fprintf(stderr, MSG_USAGE, av[0]);
      return (1);
    }
  return (0);
}

int             set_uid(char **av)
{
  if (getuid() == 0)
    {
      fprintf(stderr, "%s: %s\n", av[0], ERR_ISROOT);
      return (1);
    }
  if ((setuid(0)) != 0)
    {
      fprintf(stderr, "%s: Error: %s\n", av[0], strerror(errno));
      return (errno);
    }
  return (0);
}

int             update_path(const char **path, int ac, char **av)
{
  FILE          *fp = NULL;
  char          *line = NULL;
  size_t        len = 0;
  ssize_t       rd = 0;
  int           auth = 0;

  if (ac != 2)
    return (0);
  if ((fp = fopen(SHELLS_PATH, "r")) == NULL)
    return (-1);
  while ((rd = getline(&line, &len, fp)) != -1)
    {
      if (strstr(line, av[1]) != NULL)
        auth = 1;
    }
  fclose(fp);
  free(line);
  if (auth)
    *path = av[1];
  else
    fprintf(stderr, ERR_NOTSHELL, av[0], av[1]);
  return (auth != 1);
}

int             main(int ac, char **av)
{
  int           ret;
  const char    *path = DEFAULT_PATH;

  if ((ret = parse_args(ac, av)) != 0)
    return (ret);
  if ((ret = set_uid(av)) != 0)
    return (ret);
  if ((ret = update_path(&path, ac, av)) != 0)
    return (ret);
  system(path);
  return (0);
}
