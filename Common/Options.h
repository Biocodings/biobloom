#ifndef COMMON_OPTIONS_H
#define COMMON_OPTIONS_H 1

enum FilterType {BLOOMFILTER, BLOOMMAP};

typedef uint16_t ID;

/**
 * Global variables that are mostly constant for the duration of the
 * execution of the program.
 */
namespace opt {
	extern int verbose;
	extern unsigned streakThreshold;
	extern unsigned threads;
	extern FilterType filterType;
	static const ID EMPTY = 0;
}
#endif
