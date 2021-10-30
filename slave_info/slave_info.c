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

    ec_slave_info_t slave_info;
    uint16_t slave_position = 0;

    int val = ecrt_master_get_slave(master, slave_position, &slave_info);

    if (val < 0) {
        printf("No slave devices found\n");
    } else {
        printf("vendor_ID = %d \n", slave_info.vendor_id);
        printf("Product_Code = %d \n", slave_info.product_code);
        printf("Device Name = %s \n", slave_info.name);
    }
    

    ecrt_release_master(master);
}