#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libvirt/libvirt.h>
#include <getopt.h>
#include "vmcontrol.h"

static const char *optString = "x:lh?";

static const struct option longOpts[] = {
    { "xml-config", required_argument, NULL, 'x' },
    { "help", no_argument, NULL, 'h' },
    { NULL, no_argument, NULL, 0 }
};

int main(int argc, char **argv)
{

    char opt;
    int longIndex;

    if(argc == 1) return 0;

    if(!strcmp(argv[1], "create")) {
        
        if(argc == 3) {
            char *xml_desc = readXml(argv[2]);
            createAndRunDomain(xml_desc);
        }

    } else if(!strcmp(argv[1], "list")) {
    
        showDomainList();
    
    } else if(!strcmp(argv[1], "help")) {
    
        printf("Help\n");
    
    } else if(!strcmp(argv[1], "destroy")) {
    
        if(argc == 3)
            destroyDomain(argv[2]);
    
    } else {
    
        printf("Error\n");
    
    }

}
