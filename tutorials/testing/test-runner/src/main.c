#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

#define UNUSED(x) (void) x;

int main (int argc, char *argv[]) {

  DIR *d = opendir(".");
  struct dirent *dt;
  while ((dt = readdir(d)) != NULL) {
    if ((strcmp(".", dt->d_name) != 0) && (strcmp("..", dt->d_name) != 0))
      printf(": %s\n", dt->d_name);
  }
  closedir(d);

  UNUSED(argc);
  UNUSED(argv);

  return 0;
}

void query() {

  DIR *d = opendir(".");
  struct dirent *dt;
  while ((dt = readdir(d)) != NULL) {
    if ((strcmp(".", dt->d_name) != 0) && (strcmp("..", dt->d_name) != 0))
      printf(": %s\n", dt->d_name);
  }
  closedir(d);

  UNUSED(argc);
  UNUSED(argv);

  return 0;
}




