#include "stdafx.h"
#include "RoomDescriptions.h"
#include "Random.h"

char* RoomDescriptions::GetRandomDescription()
{
	const char* size = ToString(GetRandomSize());
	const char* state = ToString(GetRandomState());
	const char* furniture = ToString(GetRandomFurniture());

	char description[150] = "You take a look around the "; //27
	strcat_s(description, state);
	strcat_s(description, ", "); // 2
	strcat_s(description, size);
	strcat_s(description, " room. In the room, you see a "); //30
	strcat_s(description, furniture);
	strcat_s(description, "."); //1

	return description;
}

RoomDescriptions::Size RoomDescriptions::GetRandomSize()
{
	Random r = Random();

	// second param = number of items in enum.
	const int furniturePicker = r.Generate(1, 3);
	switch (furniturePicker)
	{
	case 1:
		return SMALL;
	case 2:
		return MEDIUM;
	case 3:
		return LARGE;
	// default:
	// 	return;
	}
}

RoomDescriptions::State RoomDescriptions::GetRandomState()
{
	Random r = Random();

	// second param = number of items in enum.
	const int furniturePicker = r.Generate(1, 2);
	switch (furniturePicker)
	{
	case 1:
		return TIDY;
	case 2:
		return CLUTTERED;
	// default:
	// 	return;
	}
}

RoomDescriptions::Furniture RoomDescriptions::GetRandomFurniture()
{
	Random r = Random();

	// second param = number of items in enum.
	const int furniturePicker = r.Generate(1, 3);
	switch (furniturePicker)
	{
	case 1:
		return TABLE;
	case 2:
		return ARMCHAIR;
	case 3:
		return BED;
	// default:
	// 	return;
	}
}

char* RoomDescriptions::ToString(Size size)
{
	switch (size)
	{
	case SMALL:
	{
		char smallSize[12] = "small sized";
		return smallSize;
	}
	case MEDIUM:
	{
		char mediumSize[13] = "medium sized";
		return mediumSize;
	}
	case LARGE:
	{
		char largeSize[12] = "large sized";
		return largeSize;
	}
	// default:
	// 	return;
	}
}

char* RoomDescriptions::ToString(State state)
{
	switch (state)
	{
	case TIDY:
	{
		char tidy[5] = "tidy";
		return tidy;
	}
	case CLUTTERED:
	{
		char cluttered[10] = "cluttered";
		return cluttered;
	}
	// default:
	// 	return;
	}
}

char* RoomDescriptions::ToString(Furniture furniture)
{
	switch (furniture)
	{
	case TABLE:
	{
		char table[35] = "small table with two wooden chairs";
		return table;
	}
	case ARMCHAIR:
	{
		char armchair[19] = "luxurious armchair";
		return armchair;
	}
	case BED:
	{
		char bed[16] = "comfortable bed";
		return bed;
	}
	// default:
	// 	return;
	}
}
