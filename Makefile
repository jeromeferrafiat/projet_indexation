read_image : read_image.c
	cc rdjpeg.c read_image.c -o read_image

test :
	
	./read_image 2008_000015.jpg

clean:
	rm -rf read_image

cleanout :
	rm -rf out/*
