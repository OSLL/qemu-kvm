# Vmcontrol
Vmcontrol is the main interface for managing guest domains. The program can be used to create, pause, and shutdown domains. It can also be used to list current domains. Libvirt is a C toolkit to interact with the virtualization capabilities of recent versions of Linux (and other OSes).

# Build
You must ensure that libvirt is installed on your computer.
Clone the project from github:
```
git clone git://github.com/OSLL/qemu-kvm.git
cd ./qemu-kvm/utilities/vmcontrol
```
Compile executable file:
```
make
```
This will build the executable file vmcontrol from the source files and put them in the current folder.

# Usage
To create and run a domain, use the following command:
```
vmcontrol --create *%PASS_TO_DESCRIPTION_FILE%*
```
You can see examples of XML configuration files in the examples folder.
To see list of all running domain use:
```
vmcontrol --list
```
To connect to the virtual machine desktop, you can use the VNC Viewer utility, with IP 0.0.0.0, if you used the configuration file from the examples.