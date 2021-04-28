#include <stdio.h>
#include <malloc.h>
#include <byteswap.h>
#include "playstats.h"

int main(int argc, char* argv[])
{
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
		if (stats->entry[i].tid == 0)
		{
			break;
		}

		printf("--- Entry #%03d ---\n", i);
		printf("Title: %016lx\n", bswap_64(stats->entry[i].tid));
		
		int time_hrs, time_mins;
		
		time_hrs = bswap_32(stats->entry[i].playtime) / 60;
		time_mins = bswap_32(stats->entry[i].playtime) % 60;

		printf("Playtime: %dh %02dm\n", time_hrs, time_mins);
		printf("Total launches: %d", bswap_16(stats->entry[i].launches));
		printf("\n\n");
	}

	fclose(pstats);
	free(stats);
	return 0;
}
