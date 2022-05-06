#pragma once
#include <future>

namespace testFor_Future
{
	typedef long int ull;
	void findodd(std::promise<ull>&& Oddsumpromise, ull start, ull end) {
		ull sum = 0;
		for (ull i = start; i <= end; ++i) {
			if (i & 1) {
				sum += i;
			}
		}
		Oddsumpromise.set_value(sum);  //value setter
	}
}