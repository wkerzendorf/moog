#     makefile for MOOG with all of the common block assignments;
PREFIX = /usr/local

#        here are the compilation and linking commands
all:
	cd src; make
	@echo -----------------------------------------------------------------
	@echo
	@echo NOTE: the isotop driver has been eliminated;
	@echo your synthesis needs for elemental and isotopic
	@echo abundances now can be handled with the synth driver
	@echo
	@echo -----------------------------------------------------------------

install: all
	mkdir -p $(PREFIX)/bin
	install -m 0755 src/moog $(PREFIX)/bin
	mkdir -p $(PREFIX)/share/moog
	install -m 0644 data/*.dat $(PREFIX)/share/moog

clean:
	-rm -f src/*.o src/moog

        
