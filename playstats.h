#include <stdint.h>

typedef struct title
{
	uint64_t tid;
	uint32_t playtime;
	uint16_t launches;
	char unknown[6];
}__attribute__((packed)) title;

typedef struct playstats
{
	char unknown[4];
	struct title entry[256];
}__attribute__ ((packed)) playstats;
