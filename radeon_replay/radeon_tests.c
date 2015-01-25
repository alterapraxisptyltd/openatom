#include <stdio.h>

#include "radeon_util.h"
#include "trinity.h"

static void test_revision(void)
{
	uint32_t rev;

	rev = radeon_read(HW_REV);
	rev = (rev & ATI_REV_ID_MASK) >> ATI_REV_ID_SHIFT;

	printf("Hardware says it is revision %x\n", rev);
}

void run_radeon_tests(void)
{
	printf("Starting a set of radeon tests to see if VGA responds\n");
	test_revision();
}
