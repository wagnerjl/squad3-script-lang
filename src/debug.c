#include "debug.h"

extern VTABLE_ENTRY *first_entry;

void print_vtable(void) {
  VTABLE_ENTRY *entry = first_entry;
  while (entry != NULL) {
    char content[1024];
    content[0] = '\0';

    if (entry->ref != NULL)
      to_string(entry->ref, content);

    printf("%s | %d | %s\n", entry->varname, entry->scope, content);
    entry = entry->next;
  }
}
