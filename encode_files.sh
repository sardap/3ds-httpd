#!/bin/bash

cd 3ds-site && npm run build && cd ..

function encode_file() {
  echo "#include \"content.h\"" > $2
  # Convert file to C array
  xxd -i $1 | sed 's/^unsigned char/const unsigned char/' | sed 's/^unsigned int/const unsigned int/' >> $2
}

# Loop over files in dir
TARGET_DIR=3ds-site/dist/books

for file in $TARGET_DIR/*; do
  # Get filename
  filename=$(basename -- "$file")
  # Get extension
  extension="${filename##*.}"
  # Get filename without extension
  filename="${filename%.*}"

  c_file="src/encoded_books_$filename.c"

  encode_file $file $c_file
done


encode_file 3ds-site/dist/favicon.ico "src/encoded_favicon.c"
encode_file 3ds-site/dist/index.html "src/encoded_index.c"
encode_file 3ds-site/dist/2ds.jpg "src/encoded_2ds.c"
