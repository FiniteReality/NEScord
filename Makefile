.PHONY: all clean cc65 src

cc65:
	make -s -C cc65 all >/dev/null

clean:
	make -C cc65 clean
	make -C src clean

src: cc65
	make -C src

all: src
