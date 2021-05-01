/*
Title IDs stolen from: https://wiiubrew.org/wiki/Title_database
*/

#include <stdint.h>

#define numTitles sizeof(titles) / sizeof(struct titleStringLutEntry)

typedef struct titleStringLutEntry
{
	uint64_t tid;
	char name[80];
}titleStringLutEntry;

struct titleStringLutEntry titles[] = 
{
	// Test entry
	{
		0x00050000101436FF,
		"Test"
	},

	// The Wind Waker HD (EU)
	{
		0x0005000010143600,
		"The Legend of Zelda: The Wind Waker HD"
	},

	// Internet Browser (EU)
	{
		0x0005003010012200,
		"Internet Browser"
	},

	// eShop (EU)
	{
		0x00005003010014200,
		"Nintendo eShop"
	},

	// Mii Maker (EU)
	{
		0x000500101004a200,
		"Mii Maker"
	},

	// Lego City Undercover (EU)
	{
		0x0005000010101b00,
		"Lego City Undercover"
	},

	// Mario Kart 8 (EU)
	{
		0x000500001010eb00,
		"Mario Kart 8"
	},

	//  Hyrule Warriors (EU)
	{
		0x000500001017D900,
		"Hyrule Warriors"
	},

	// ZombiU (EU)
	{
		0x000500001011A700,
		"ZombiU"
	},

	// Twilight Princess HD (EU)
	{
		0x000500001019E600,
		"The Legend of Zelda: Twilight Princess HD"
	},

	//Breath of the Wild (EU)
	{
		0x00050000101C9500,
		"The Legend of Zelda: Breath of the Wild"
	},

	// Watch Dogs (EU)
	{
		0x0005000010140500,
		"Watch_Dogs"
	},

	// NSMBU (EU)
	{
		0x0005000010101E00,
		"New Super Mario Bros. U"
	},

	// Smash for Wii U (EU)
	{
		0x0005000010145000,
		"Super Smash Bros. for Wii U"
	},

	// Super Mario 3D World (EU)
	{
		0x00050000010145D00,
		"Super Mario 3D World"
	},

	//Xenoblade X (EU)
	{
		0x00050000101C4C00,
		"Xenoblade Chronicles X"
	}
};
