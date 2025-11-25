#include <string>
#include <CLI/CLI.hpp>
#include <git2.h>

int main(int argc, char* argv[]) {
  CLI::App app{"libgit2 example"};
  argv = app.ensure_utf8(argv);

  std::string repo_path;
  app.add_option("-r", repo_path, "git repo");
  CLI11_PARSE(app, argc, argv);

  git_libgit2_init();

  git_repository *repo = nullptr;
  git_object *head_commit = nullptr;
  git_commit *commit = nullptr;
  int error = git_repository_open(&repo, repo_path.c_str());
  if (error < 0) {
    std::cerr << "Error opening repository at " << repo_path << ": " << git_error_last()->message << std::endl;
    goto cleanup;
  }

  error = git_revparse_single(&head_commit, repo, "HEAD^{commit}");
  if (error < 0) {
    std::cerr << "Error finding HEAD commit: " << git_error_last()->message << std::endl;
    goto cleanup;
  }

  commit = (git_commit*)head_commit;

  std::cout << "Successfully opened repository and found HEAD." << std::endl;
  std::cout << "Commit message: " << git_commit_message(commit) << std::endl;
  std::cout << "Author: "
    << git_commit_author(commit)->name << "<"
    << git_commit_author(commit)->email << ">" << std::endl;;

cleanup:
  if (head_commit) {
    git_object_free(head_commit); 
  }
  if (repo) {
    git_repository_free(repo);
  }

  git_libgit2_shutdown();
  return 0;
}
