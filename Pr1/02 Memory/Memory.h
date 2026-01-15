struct Memory1
{
	char * _s;
	Memory1(const char * const s);
};

struct Memory2
{
	char * _s;
	Memory2(const char * const s);
	~Memory2();
};
struct Memory3
{
	int* _s;
	Memory3(const int n);
	~Memory3();
};