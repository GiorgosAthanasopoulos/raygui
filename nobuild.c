#define NOBUILD_IMPLEMENTATION
#include "nobuild.h"

#define CC "g++"
#define CFLAGS \
  "-Wall", "-Wextra", "-pedantic", "-std=c++11", "-g", "-ggdb", "-DDEBUG"
#define BUILD_DIR "build/"
#define TARGET BUILD_DIR "RaylibGUI"
#define SRC "src/Main.cpp"
#define LDFLAGS "-lraylib", "-lm"

void build(void)
{
  CMD("mkdir", "-p", BUILD_DIR);
  CMD(CC, CFLAGS, "-o", TARGET, SRC, LDFLAGS);
}

void run(void) { CMD(TARGET); }

int main(int argc, char **argv)
{
  GO_REBUILD_URSELF(argc, argv);

  build();
  run();

  return 0;
}
