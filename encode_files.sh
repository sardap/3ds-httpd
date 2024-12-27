#!/bin/bash

cd 3ds-site && npm run build && cd ..

# Loop over files in dir
TARGET_DIR=3ds-site/public/books

for file in $TARGET_DIR/*; do
  # Get filename
  filename=$(basename -- "$file")
  # Get extension
  extension="${filename##*.}"
  # Get filename without extension
  filename="${filename%.*}"

  c_file="src/encoded_books_$filename.c"

  # Create header file
  echo "#include \"content.h\"" > $c_file
  # Convert file to C array
  xxd -i $file | sed 's/^unsigned char/const unsigned char/' | sed 's/^unsigned int/const unsigned int/' >> $c_file
done

c_file="src/encoded_index.c"

echo "#include \"content.h\"" > $c_file
xxd -i 3ds-site/dist/index.html | sed 's/^unsigned char/const unsigned char/' | sed 's/^unsigned int/const unsigned int/' >> $c_file
