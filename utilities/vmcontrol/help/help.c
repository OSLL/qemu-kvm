#include <stdio.h>
#include "help.h"

void printHelp() {

    printf("Domain Management:\n");
    printf("\t%-20s%-30s%-30s\n", "--create", "required argument", "Create a domain from an XML file");
    printf("\t%-20s%-30s%-30s\n", "--destroy", "required argument", "Destroy (delete) a domain");
    printf("\t%-20s%-30s%-30s\n", "--resume", "required argument", "Resume a domain");
    printf("\t%-20s%-30s%-30s\n", "--suspend", "required argument", "Suspend a domain");

    printf("\nDomain Monitoring:\n");
    printf("\t%-20s%-30s%-30s\n", "--list", "no argument", "Show domains list");

    printf("\nSupporting:\n");
    printf("\t%-20s%-30s%-30s\n", "--help", "no argument", "Print help");

    printf("\n\n");

}
