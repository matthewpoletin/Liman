#include <chrono>

class Timer
{
public:
	inline void Start(void)
	{
		tBegin = std::chrono::steady_clock::now();
	}
	inline void Stop(void)
	{
		tEnd = std::chrono::steady_clock::now();
	}
	inline int GetDelta()
	{
		tDelta = tEnd - tBegin;
		int Delta = int(tDelta.count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
		return Delta;
	}
protected:
private:
	std::chrono::steady_clock::time_point tBegin;
	std::chrono::steady_clock::time_point tEnd;
	std::chrono::steady_clock::duration  tDelta;
};