#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <btrfsutil.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s [path to btrfs subvolume]\n", argv[0]);
    exit(1);
  }

  enum btrfs_util_error err =
    btrfs_util_delete_subvolume(argv[1], BTRFS_UTIL_DELETE_SUBVOLUME_RECURSIVE);

  if (err) {
    const char *btrfs_err_str = btrfs_util_strerror(err);
    const char *err_str = strerror(errno);

    if (btrfs_err_str && err_str && strcmp(btrfs_err_str, err_str) != 0) {
      fprintf(stderr, "%s: %s: %s\n", argv[0], btrfs_err_str, err_str);
    } else if (btrfs_err_str) {
      fprintf(stderr, "%s: %s\n", argv[0], btrfs_err_str);
    } else if (err_str) {
      fprintf(stderr, "%s: %s\n", argv[0], err_str);
    } else {
      fprintf(stderr, "%s: unknown error\n", argv[0]);
    }
  }
}
