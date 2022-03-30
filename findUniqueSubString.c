#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int map[26] ;

void 
 resetMap() {
	for (int i = 0; i < 26; i++)
		map[i] = 0;
  return;
}

char *
uniquestr(char *str) {
	int len = strlen(str);
	int i = 0;
	int max_cnt  = INT_MIN;
	int cnt = 0;
	int start = 0;
	int ret_start = 0;
	if (!str) return NULL;
	resetMap();
  while (i < len) {
		char k = str[i] - 'a';
		if (str[i] == ' ') {
			// space , continue
			cnt++;
			i++;
			continue;
		}

		if (map[k] == 0) {
				// character not present in the map
				map[k] = 1;
				cnt++;
		} else {
			// character presnet in map (duplicate)
			if (cnt >= max_cnt) {
				max_cnt = cnt;
				ret_start = start;
			}

			while ((str[start] != str[i])) {
				start++;
			}
			start++;
			cnt = i - start;
			resetMap();
			map[k] = 1;
			cnt = cnt + 1;
		}
	i++;
	}

	if (cnt >= max_cnt) {
		max_cnt = cnt;
		ret_start = start;
	}
#if 0
// Print string
	printf("printing string of size: %d \n", max_cnt);
	 while (max_cnt > 0) {
		 printf("%c", str[ret_start++]);
		 max_cnt--;
	}
	printf("\n");
#endif

	char *ret = (char*)malloc(max_cnt+1);
	int j = 0;
	 while (max_cnt > 0) {
		 ret[j++] = str[ret_start++];
		 max_cnt--;
	}
	ret[j]='\0';

	return ret;
}

int main()
{
	printf("Hello World");
	printf("\n");
	char *ret;
	ret = uniquestr("hello world");

	printf("%s\n", ret);

	ret = uniquestr("abheqpxl world");
	printf("%s\n", ret);

	ret = uniquestr("hello");
	printf("%s\n", ret);
	return 0;
}

