#include "stdafx.h"
#include "RoomDescriptions.h"
#include "Random.h"

char* RoomDescriptions::GetRandomDescription()
{
	char size[13]; 
	ToString(size, GetRandomSize());
	char state[10];
	ToString(state, GetRandomState());
	char furniture[35];
	ToString(furniture, GetRandomFurniture());

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

void RoomDescriptions::ToString(char* outstr, Size size)
{
	switch (size)
	{
	case SMALL:
		strcpy_s(outstr, 12, "small sized");
		break;
	case MEDIUM:
		strcpy_s(outstr, 13, "medium sized");
		break;
	case LARGE:
		strcpy_s(outstr, 12, "large sized");
		break;
	// default:
	// 	return;
	}
}

void RoomDescriptions::ToString(char* outstr, State state)
{
	switch (state)
	{
	case TIDY:
		strcpy_s(outstr, 5, "tidy");
		break;
	case CLUTTERED:
		strcpy_s(outstr, 10, "cluttered");
		break;
	// default:
	// 	return;
	}
}

void RoomDescriptions::ToString(char* outstr, Furniture furniture)
{
	switch (furniture)
	{
	case TABLE:
		strcpy_s(outstr, 35, "small table with two wooden chairs");
		break;
	case ARMCHAIR:
		strcpy_s(outstr, 19, "luxurious armchair");
		break;
	case BED:
		strcpy_s(outstr, 16, "comfortable bed");
		break;
	// default:
	// 	return;
	}
}
