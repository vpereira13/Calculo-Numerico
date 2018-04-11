# Makefile 05 - Automatic header dependences (non-strict POSIX)

# Copyright (c) 2015, Monaco F. J. <moanco@icmc.usp.br>
#
# This file is part of POSIXeg.
#
# POSIXeg is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Objects

OBJECTS = main.o gauss_seidel.o

BIN = main


# Default target

all: main

# Binary

$(BIN) : $(OBJECTS)
	gcc $^ -o $@

# Pattern rule for object-source dependences

%.o : %.c
	gcc -I. -c $<

# Automatic object-header dependences

makefiles = $(OBJECTS:%.o=%.d)

include $(makefiles)

%.d : %.c
	gcc -I. -MM -MT '$(<:.c=.o) $@' $< >$@

# Cleaning

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(BIN)
	rm -f *~ \#*
