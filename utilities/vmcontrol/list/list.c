#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "list.h"

int showDomainList()
{

    virDomainPtr *domains;
    int ret, state;
    
    virConnectPtr conn = virConnectOpen("qemu:///system");    
    ret = virConnectListAllDomains(conn, &domains, 0);
    if (ret < 0)
        printf("Error\n");
    
    printf("%5s\t%20s\t%5s\n", "ID", "Name", "State");
    
    for(int j = 0; j < 40; j++) printf("=");
    printf("\n\n");

    for (int i = 0; i < ret; i++) {
        virDomainGetState(domains[i], &state, NULL, 0);
        printf("%5u\t%20s\t%5d\n", virDomainGetID(domains[i]), virDomainGetName(domains[i]), state);
        virDomainFree(domains[i]);
    }
    free(domains);
    printf("\n");
    
    return 0;

}

