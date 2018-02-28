all : read_image get_images

read_image : read_image.c
	cc rdjpeg.c read_image.c -o read_image

get_images : get_images.o
	gcc -o get_images get_images.o

get_images.o : get_images.c
	gcc -o get_images.o -c get_images.c -W -Wall -ansi -pedantic

test :
	./read_image 2008_000015.jpg

clean:
	rm -rf read_image get_images *.o

cleanout :
	rm -rf out/*
