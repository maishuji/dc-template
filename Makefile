DC_IP ?= 192.168.0.84 # Please set the IP address of your dreamcast here ( or through env var DC_IP )

# This target is for running the program on dreamcast, given that you are using BBA or a LAN adapter
run-dc-remote:
	dc-tool-ip -t $(DC_IP) -x build/Debug/src/udjourney/upown-journey.elf