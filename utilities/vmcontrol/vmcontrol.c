#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vmcontrol.h"

int main(int argc, char **argv)
{

    if(argc == 1) return 0;

    if(!strcmp(argv[1], "create")) {
        
        if(argc == 3) {
            char *xml_desc = readXml(argv[2]);
            createAndRunDomain(xml_desc);
        }

    } else if(!strcmp(argv[1], "list")) {
    
        showDomainList();
    
    } else if(!strcmp(argv[1], "help")) {
    
        printHelp();
    
    } else if(!strcmp(argv[1], "destroy")) {
    
        if(argc == 3)
            destroyDomain(argv[2]);
    
    } else {
    
        printf("Unsupported argument: %s\n", argv[1]);
        printf("For more information use: vmcontrol help\n");
    
    }

    return 0;

}
