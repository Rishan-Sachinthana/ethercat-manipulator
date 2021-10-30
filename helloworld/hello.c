#include <stdio.h>
#include <stdlib.h>
#include "ecrt.h"
int main(void) {
static ec_master_t *master = NULL;
printf("Starting ecat test.\n");
master = ecrt_request_master(0);
if (!master) {
printf("Failed to get a master instance!\n");
return EXIT_FAILURE;
}
else {
ecrt_release_master(master);
printf("Master get/release ok.\n");
return EXIT_SUCCESS;
}
}
