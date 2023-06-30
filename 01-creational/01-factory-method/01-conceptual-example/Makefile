all: run
	@echo ""

build:
	cmake -S . -B build
	cmake --build build -- -j8
	@echo ""

run: build
	@./build/app/app
	@echo ""

clean:
	rm -rf build
	@echo ""

.PHONY: all build run clean