#pragma once
class RoomDescriptions
{
public:
	enum Size
	{
		SMALL,
		MEDIUM,
		LARGE
	};

	enum State
	{
		TIDY,
		CLUTTERED
	};

	enum Furniture
	{
		TABLE,
		ARMCHAIR,
		BED
	};

	static char* GetRandomDescription();

private:
	static Size GetRandomSize();
	static State GetRandomState();
	static Furniture GetRandomFurniture();

	static void ToString(char* outstr, Size size);
	static void ToString(char* outstr, State state);
	static void ToString(char* outstr, Furniture furniture);
};