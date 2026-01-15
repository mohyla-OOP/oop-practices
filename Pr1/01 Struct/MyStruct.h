//#define NDEBUG

struct MyFirstStruct
{
	bool _b;
	int _i;
	char _c;
};
void create (MyFirstStruct &s);

struct MySecondStruct
{
	bool _b;
	int _i;
	char _c;
	static void construct (MySecondStruct &s);
};

struct MyThirdStruct
{
	bool _b;
	int _i;
	char _c;
// parameter s is not needed anymore
	void construct ();
};

struct MyForthStruct
{
	bool _b;
	int _i;
	char _c;
// special name is not needed anymore
	MyForthStruct ();
};

struct MyFifthStruct
{
	bool _b;
	int _i;
	char _c;
// sofort initialisation
	MyFifthStruct ();
};