#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include "create.h"

char *readXml(char *path)
{

    FILE *xml_file = fopen(path, "r");
    if( !xml_file ) {
        printf("Error: can't open XML file\n");
        exit(EXIT_FAILURE);
    }
    if(fseek(xml_file, 0, SEEK_END)) {
        printf("Error: can't read XML file\n");
        exit(EXIT_FAILURE);
    }
    long fsize = ftell(xml_file);
    if(fsize < 0) {
        printf("Error: can't read XML file\n");
        exit(EXIT_FAILURE);
    }
    if(fseek(xml_file, 0, SEEK_SET)) {
        printf("Error: can't read XML file\n");
        exit(EXIT_FAILURE);
    }

    char *content = (char*)malloc(fsize + 1);
    if(!content) {
        printf("Error: can't allocate memory\n");
        exit(EXIT_FAILURE);
    }
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
