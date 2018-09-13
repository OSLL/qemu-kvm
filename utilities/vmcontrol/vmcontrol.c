#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "vmcontrol.h"

int main(int argc, char **argv)
{
    struct globalArgs_t {
        char *xml_desc;
    } globalArgs;

    static const char *optString = "c:d:s:r:lh?";
    static const struct option longOpts[] = {
        { "create", required_argument, NULL, 'c' },
        { "destroy", required_argument, NULL, 'd' },
        { "suspend", required_argument, NULL, 's' },
        { "resume", required_argument, NULL, 'r' },
        { "list", no_argument, NULL, 'l' },
        { "help", no_argument, NULL, 'h' },
        { NULL, no_argument, NULL, 0 }
    };
    
    int longIndex;
    int opt = getopt_long( argc, argv, optString, longOpts, &longIndex );

    while( opt != -1 ) {
        switch( opt ) {
            case 'c':
                globalArgs.xml_desc = readXml(optarg);
                createAndRunDomain(globalArgs.xml_desc);
                break;
                 
            case 'd':
                destroyDomain(optarg);
                break;
                 
            case 's':
                suspendDomain(optarg);
                break;
                 
            case 'r':
                resumeDomain(optarg);
                break;
                 
            case 'l':
                showDomainList();
                break;

            case 'h':
            case '?':
                printHelp();
                break;
                 
            default:
                break;
        }
         
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }
/*
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
    
    } else if(!strcmp(argv[1], "suspend")) {

        if(argc == 3)
            suspendDomain(argv[2]);
    
    } else if(!strcmp(argv[1], "resume")) {

        if(argc == 3)
            resumeDomain(argv[2]);

    } else {
    
        printf("Unsupported argument: %s\n", argv[1]);
        printf("For more information use: vmcontrol help\n");
    
    }
*/
    return 0;

}
