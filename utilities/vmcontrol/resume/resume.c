#include <libvirt/libvirt.h>
#include "resume.h"

int resumeDomain(char *name) {
    virConnectPtr conn = virConnectOpen("qemu:///system");
    virDomainPtr domain = virDomainLookupByName(conn, name);
    
    if(domain) {
        virDomainResume(domain);
        virDomainFree(domain);
    }

    return 0;
}

