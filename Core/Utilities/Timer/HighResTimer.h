/**
 * @file HighResTimer.h
 * @author matthewpoletin
 */

#include <chrono>

namespace liman {

	class HighResTimer {
	public:
		inline void Start() {
			tBegin = std::chrono::steady_clock::now();
		}

		inline void Stop() {
			tEnd = std::chrono::steady_clock::now();
		}

		inline int GetDelta() {
			tDelta = tEnd - tBegin;
			int Delta =
					int(tDelta.count()) * std::chrono::steady_clock::period::num /
					std::chrono::steady_clock::period::den;
			return Delta;
		}

	protected:
	private:
		std::chrono::steady_clock::time_point tBegin;
		std::chrono::steady_clock::time_point tEnd;
		std::chrono::steady_clock::duration tDelta;
	};

}
