#!/bin/sh

# This script depends on imagemagick being installed

for imgsize in 16 32 64 128
do
	convert ../icons/basicqtapp.png -resize "$imgsize"x"$imgsize" -background transparent icon"$imgsize".png
	files="$files icon$imgsize.png"
done

convert $files ../basicqtapp.ico
rm $files
