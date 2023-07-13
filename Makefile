CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = bin/kaban

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
INCLUDES = -I $(INCDIR)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@$(RM) -r $(BUILDDIR) $(TARGET)
