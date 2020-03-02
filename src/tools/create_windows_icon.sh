#!/bin/sh

# This script depends on imagemagick being installed

for imgsize in 16 32 64 128
do
	convert ../icons/app_icon.png -resize "$imgsize"x"$imgsize" -background transparent icon"$imgsize".png
	files="$files icon$imgsize.png"
done

convert $files ../app_icon.ico
rm $files
