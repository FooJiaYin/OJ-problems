
if [ -d "$1" ]; then
    # Change the current directory to the specified folder
    cd "$1"
fi

mkdir -p "out"

# Iterate over files matching the pattern
for file in testcase/sin/*.txt; do
    filename=$(basename "$file")
    # Run the executable with input from the file and redirect output
    ./a.exe < "$file" > "out/$filename"
done

cd ..