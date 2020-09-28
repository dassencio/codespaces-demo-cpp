#include <zengithub.h>
#include <git2.h>
#include <stdio.h>

int main() {
    git_libgit2_init();
    if (git_repository_open_ext(
        NULL, ".", GIT_REPOSITORY_OPEN_NO_SEARCH, NULL) == 0) {
          zen_of_github();
    } else {
        printf ("%s\n%s\n",
          "You're not in a git repo so the octocat will stay silent.",
          "Create a git repo and the Zen of GitHub will be revealed to you.");
    }
    git_libgit2_shutdown();
}
