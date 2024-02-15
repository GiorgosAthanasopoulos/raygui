#define NOBUILD_IMPLEMENTATION
#include "nobuild.h"

#define CC "g++"
#define CFLAGS \
  "-Wall", "-Wextra", "-pedantic", "-std=c++11", "-g", "-ggdb"
#define BUILD_DIR "build/"
#define SRC_DIR "src/"
#define LDFLAGS "-lraylib", "-lm"
#define TARGET BUILD_DIR "example"
#define TARGET_LIB BUILD_DIR "libraygui.a"

void build(void)
{
  CMD("mkdir", "-p", BUILD_DIR);
  CMD(CC, CFLAGS, "-c", "-o", BUILD_DIR "Utils.o", SRC_DIR "Utils.cpp", LDFLAGS);
  CMD(CC, CFLAGS, "-c", "-o", BUILD_DIR "Button.o", SRC_DIR "Button.cpp", LDFLAGS);
  CMD("ar", "rvs", TARGET_LIB, BUILD_DIR "Utils.o", BUILD_DIR "Button.o");
  CMD(CC, CFLAGS, "-L" BUILD_DIR, "-o", TARGET, SRC_DIR "Main.cpp", LDFLAGS, "-lraygui");
}

int main(int argc, char **argv)
{
  GO_REBUILD_URSELF(argc, argv);

  build();

  const char *program = shift_args(&argc, &argv);
  if (argc == 0)
  {
    return 0;
  }

  const char *subcmd = shift_args(&argc, &argv);

  if (!strcmp(subcmd, "example"))
  {
    CMD(TARGET);
  }

  return 0;
}
