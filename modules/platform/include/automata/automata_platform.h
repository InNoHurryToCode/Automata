#ifndef AUTOMATA_PLATFORM_H
#define AUTOMATA_PLATFORM_H

/* operating system */
#if defined(_WIN64) || defined (_WIN32)
	#define AUTOMATA_PLATFORM_WINDOWS 1
#elif defined(__APPLE__) && defined (__MACH__)
	#define AUTOMATA_PLATFORM_OSX 1
#elif defined(__linux__) && defined(__unix__)
	#define AUTOMATA_PLATFORM_LINUX 1
#endif

/* architecture */
#if defined(_M_IX86) || defined(__i386__)
	#define AUTOMATA_ARCHITECTURE_X86 1
#elif defined(_M_AMD64) || defined(__x86_64__)
	#define AUTOMATA_ARCHITECTURE_X64 1
#endif

/* standards */
#if defined(_POSIX_VERSION)
	#define AUTOMATA_STANDARD_POSIX 1
#endif

/* compilers */
#if defined(_MSC_VER)
	#define AUTOMATA_COMPILER_MSVC 1
#endif

#endif