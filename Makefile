read_image : read_image.c
	cc rdjpeg.c read_image.c -o read_image

clean:
	rm -rf read_image
