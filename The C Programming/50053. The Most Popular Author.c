#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct AuthorSelling {
  char author[64];
  int copies;
} AuthorSelling;

int Find(AuthorSelling author_sellings[], int size, char author[]) {
  for (int i = 0; i < size; i++) {
    if (strcmp(author_sellings[i].author, author) == 0) {
      return i;
    }
  }
  return -1;
}

bool GreaterThan(const AuthorSelling lhs, const AuthorSelling rhs) {
  if (lhs.copies == rhs.copies) {
    return strcmp(lhs.author, rhs.author) < 0;
  }
  return lhs.copies > rhs.copies;
}

int main() {
  int M;
  scanf("%d", &M);
  char authors[M][64], books[M][64];
  for (int i = 0; i < M; i++) {
    scanf("%s %s", authors[i], books[i]);
  }

  AuthorSelling author_sellings[M];
  int size = 0;
  for (int i = 0; i < M; i++) {
    char book[64];
    int selling;
    scanf("%s %d", book, &selling);
    int pair_index = 0;
    while (strcmp(book, books[pair_index]) != 0) {
      ++pair_index;
    }

    int found = Find(author_sellings, size, authors[pair_index]);
    if (found == -1) {
      strcpy(author_sellings[size].author, authors[pair_index]);
      author_sellings[size++].copies = selling;
    } else {
      author_sellings[found].copies += selling;
    }
  }

  int answer_index = -1;
  for (int i = 0; i < size; ++i) {
    if (answer_index == -1 ||
        GreaterThan(author_sellings[i], author_sellings[answer_index])) {
      answer_index = i;
    }
  }
  printf("%s %d\n", author_sellings[answer_index].author,
         author_sellings[answer_index].copies);

  return 0;
}
