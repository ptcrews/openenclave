# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

all: getdist

getdist:
	$(MAKE) -s distclean
	$(MAKE) get-driver

distclean:
	- rm -f sgx_linux_x64_driver.bin

build:

clean:

install:
	$(MAKE) -s uninstall
	./sgx_linux_x64_driver.bin
	$(MAKE) check-running

uninstall:
	- /opt/intel/sgxdriver/uninstall.sh

##==============================================================================
##
## Helper subroutines
##
##==============================================================================

DEV=$(wildcard /dev/sgx)

RUNNING=$(shell lsmod | grep intel_sgx)

get-driver:
	apt-get -y install wget
ifdef USE_PKGS_IN
	cp $(USE_PKGS_IN)/sgx_linux_x64_driver.bin .
else
	@ wget https://download.01.org/intel-sgx/dcap-1.0/sgx_linux_x64_driver_dcap_36594a7.bin -O sgx_linux_x64_driver.bin
endif
	chmod 744 sgx_linux_x64_driver.bin

check-running:
ifeq ($(RUNNING),)
	@ echo "*** Failed to start driver: intel_sgx not found by lsmod"
	@ exit 1
endif
ifeq ($(DEV),)
	@ echo "*** Failed to start driver: /dev/sgx does not exist"
	@ exit 1
endif
	@echo "Verified: intel_sgx driver is installed and running"
