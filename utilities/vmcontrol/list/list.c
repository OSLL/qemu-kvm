#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "list.h"

#define printLine() for(int j = 0; j < 40; j++) printf("=");

int showDomainList()
{

    virDomainPtr *domains;
    int ret, state;
    
    virConnectPtr conn = virConnectOpen("qemu:///system");    
    ret = virConnectListAllDomains(conn, &domains, 0);
    if (ret < 0) {
        printf("Error: can't get the list of domains\n");
        exit(EXIT_FAILURE);
    }
    
    printf("%5s\t%20s\t%5s\n", "ID", "Name", "State");
    
    printLine();
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

