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

	static char* ToString(Size size);
	static char* ToString(State state);
	static char* ToString(Furniture furniture);
};