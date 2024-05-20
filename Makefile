# List of programs
PROGRAMS = exe1 exe2 exe3 exe4 exe5 exe6

# Build all programs
all: $(PROGRAMS)

# Pattern rule for building each program
$(PROGRAMS):
	$(MAKE) -C $@ all

# Clean all programs
clean:
	@for dir in $(PROGRAMS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean $(PROGRAMS)
