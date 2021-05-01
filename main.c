#include <stdio.h>
#include <malloc.h>
#include <byteswap.h>
#include <string.h>
#include "playstats.h"
#include "titles.h"

int main(int argc, char* argv[])
{
	uint64_t tid;
	int time_mins, time_hrs, launches;
	char titleString[160];

	FILE* pstats = fopen(argv[1], "rb");
	struct playstats* stats;

	if (!pstats)
	{
		printf("Error: Unable to open file %s for reading!\n", argv[1]);
		return -1;
	}

	stats = malloc(sizeof(struct playstats));
	fread(stats, sizeof(struct playstats), 1, pstats);

	for (int i = 0; i < 256; i++)
	{
		tid = bswap_64(stats->entry[i].tid);
		time_hrs = bswap_32(stats->entry[i].playtime) / 60;
		time_mins = bswap_32(stats->entry[i].playtime) % 60;
		launches = bswap_16(stats->entry[i].launches);

		strcpy(titleString, "No title string available.");

		if (tid == 0)
		{
			break;
		}

		for (int findTitleString = 0; findTitleString < numTitles; findTitleString++)
		{
			if (tid == titles[findTitleString].tid)
			{
				strcpy(titleString, titles[findTitleString].name);
				break;
			}
		}

		printf("--- Entry #%03d ---\n", i);
		printf("%s (%016lx)\n", titleString, tid);

		printf("Played: %d times for a total of %dh %02dm\n", launches, time_hrs, time_mins);
		printf("\n\n");
	}

	fclose(pstats);
	free(stats);
	return 0;
}
