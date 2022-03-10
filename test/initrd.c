// Copyright (c) 2022 myl7
// SPDX-License-Identifier: Apache-2.0

#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdnoreturn.h>

int main() {
  printf("Start\n");

  // sizeof("Hello, world!\n") == 15
  char buf1[16];
  char buf2[10];

  long int ret1 = syscall(548, buf1, 15);
  long int ret2 = syscall(548, buf2, 10);

  assert(ret1 == 0);
  assert(ret2 == -1);
  assert(strcmp(buf1, "Hello, world!\n") == 0);
  printf("%s", buf1);

  while (1) {}
  return 0;
}
