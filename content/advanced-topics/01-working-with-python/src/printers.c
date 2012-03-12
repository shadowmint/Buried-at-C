/** 
 * Copyright 2012 Douglas Linder
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <printers.h>

/** Total thing */
int __total;

/** Print # map for each item in lengths, vertically. */
int *print_vertical(int *lengths, int count) {
  
  __total = 0;

  /* for each item, print that many #'s */
  for (int i = 0; i < count; ++i) {
    for (int j = 0; j < lengths[i]; ++j) {
      printf("#");
    }

    /* move to the next line. */
    printf("\n");
    __total += lengths[i];
  }

  return &__total;
}

/** Print # map for each item in lengths, horizontally. */
int *print_horizontal(int *lengths, int count) {

  __total = 0;

  /* find the maximum height */
  int max = 0;
  for (int i = 0; i < count; ++i) {
    __total += lengths[i];
    if (lengths[i] > max)
      max = lengths[i];
  }

  /* print #'s, line by line. */
  for (int line = max; line > 0; --line) {
    for (int i = 0; i < count; ++i) {
      if (lengths[i] >= line)
        printf("#");
      else
        printf(" ");
    }
    printf("\n");
  }

  return &__total;
}

/** Print the total from a pointer */
void print_total (int *total) {
  printf("Total: %d\n\n", *total);
}
