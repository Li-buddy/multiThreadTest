#pragma once

namespace testFor_async
{
	typedef long int ull;
	ull findOdd(ull start, ull end) {
		ull oddsum = 0;
		for (ull i = start; i < end; ++i) {
			if (i & 1) {
				oddsum += i;
			}
		}
		return oddsum;
	}
}