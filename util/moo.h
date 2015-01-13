/*
 * Empty macro file for our semantic patches. The default macro file is stupid.
 * It's so stupid in fact, that it defines as nothing things we want to remove.
 * That prevents us from renaming macros like "__packed". To make sure the
 * semantic patch works as expected, we override the built-in macro file.
 *
 * The cow is here to make sure we don't provide a completely useless file.
 */

#define __MOO 			\
	"         (__) \n"	\
	"         (oo) \n"	\
	"   /------\/  \n"	\
	"  / |    ||   \n"	\
	" *  /\---/\   \n"	\
	"    ~~   ~~   \n"
