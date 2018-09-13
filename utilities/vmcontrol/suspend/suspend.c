#include <libvirt/libvirt.h>
#include <stdlib.h>
#include "suspend.h"

int suspendDomain(char *name) {

    virConnectPtr conn = virConnectOpen("qemu:///system");
    virDomainPtr domain = virDomainLookupByName(conn, name);
    
    if(domain) {
        virDomainSuspend(domain);
        virDomainFree(domain);
    }

    return 0;

}

