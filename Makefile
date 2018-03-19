all : read_image get_images

read_image : read_image.c
	cc rdjpeg.c read_image.c -o read_image

get_images : get_images.o
	gcc -o get_images get_images.o

get_images.o : get_images.c
	gcc -o get_images.o -c get_images.c

image :
	./read_image 2008_000015.jpg train_result

url :
	./get_images train/urls.txt

clean:
	rm -rf read_image get_images *.o

cleanout :
	rm -rf out/*
