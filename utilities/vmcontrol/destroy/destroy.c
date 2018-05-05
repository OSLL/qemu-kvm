#include <libvirt/libvirt.h>
#include "destroy.h"

int destroyDomain(char *name) {
    virConnectPtr conn = virConnectOpen("qemu:///system");
    virDomainPtr domain = virDomainLookupByName(conn, name);
    
    if(domain) {
        virDomainDestroy(domain);
        virDomainFree(domain);
    }

    return 0;
}
