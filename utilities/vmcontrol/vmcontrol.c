#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <getopt.h>

static const char *optString = "x:lh?";

static const struct option longOpts[] = {
    { "xml-config", required_argument, NULL, 'x' },
    { "list", no_argument, NULL, 'l' },
    { "help", no_argument, NULL, 'h' },
    { NULL, no_argument, NULL, 0 }
};

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

int runVm(char *xml_desc)
{
    virConnectPtr conn = virConnectOpen("qemu:///system");
    virDomainPtr vm = virDomainCreateXML(conn, xml_desc, VIR_DOMAIN_START_PAUSED);
    virDomainResume(vm);
    virConnectClose(conn);
    return 0;
}

int main(int argc, char **argv)
{
    char opt;
    int longIndex;

    opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    while( opt != -1 ) {
        switch( opt ) {
            case 'x': {
                char *xml_desc = readXml(optarg);
                runVm(xml_desc);
                break;
            }

            case 'l':
                printf("Show VMs\n");
                break;
                 
            case 'h':
            case '?':
                printf("Show help\n");
                break;
 
            default:
                break;
        }
         
        opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    }
}
