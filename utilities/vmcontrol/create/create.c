#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "create.h"

char *readXml(char *path)
{

    FILE *xml_file = fopen(path, "r");
    fseek(xml_file, 0, SEEK_END);
    long fsize = ftell(xml_file);
    fseek(xml_file, 0, SEEK_SET);

    char *content = (char*)malloc(fsize + 1);
    fread(content, fsize, 1, xml_file);
    fclose(xml_file);
    
    content[fsize] = 0;

    return content;

}

int createAndRunDomain(char *xml_desc)
{

    virConnectPtr conn = virConnectOpen("qemu:///system");
    virDomainPtr domain = virDomainCreateXML(conn, xml_desc, VIR_DOMAIN_START_PAUSED);
    virDomainResume(domain);
    virConnectClose(conn);
    virDomainFree(domain);

    return 0;

}
