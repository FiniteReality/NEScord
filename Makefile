.PHONY: all clean cc65

cc65:
	make -s -C cc65 all >/dev/null

clean:
	make -C cc65 clean
	rm -rf src/*.s

src:
	make -C src

all: cc65 src
