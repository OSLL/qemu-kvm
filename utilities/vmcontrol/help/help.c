#include <stdio.h>
#include "help.h"

void printHelp() {

    printf("Domain Management:\n");
    printf("\t%-30s%-30s\n", "create", "Create a domain from an XML file");
    printf("\t%-30s%-30s\n", "destroy", "Destroy (delete) a domain");
    printf("\t%-30s%-30s\n", "resume", "Resume a domain");
    printf("\t%-30s%-30s\n", "suspend", "Suspend a domain");

    printf("\nDomain Monitoring:\n");
    printf("\t%-30s%-30s\n", "list", "Show domains list");

    printf("\nSupporting:\n");
    printf("\t%-30s%-30s\n", "help", "Print help");

    printf("\n\n");

}
